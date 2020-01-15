;-------------------------------------------------------------------------------
;$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/btu32rotleftninplacerxn/src/btu32rotleftninplacerxn.s,v 1.6 2010/05/14 18:18:50 dashley Exp $
;-------------------------------------------------------------------------------
;Copyright (c)2010 David T. Ashley
;
;Permission is hereby granted, free of charge, to any person obtaining a copy
;of this software source code and associated documentation files (the
;"Software"), to deal in the Software without restriction, including without
;limitation the rights to use, copy, modify, merge, publish, distribute,
;sublicense, and/or sell copies of the Software, and to permit persons to whom
;the Software is furnished to do so, subject to the following conditions:
;
;The above copyright notice and this permission notice shall be included in
;all copies or substantial portions of the Software.
;
;THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
;THE SOFTWARE.
;-------------------------------------------------------------------------------
;This function doesn't use any static storage, so it is OK for either mods0 or
;modsl0 memory models.  However, it does assume call/ret (rather than callf/retf)
;which affects both instructions used, stack offsets, and numerical values in
;the .dcall directive.  For this reason, must error out if being assembled
;for the wrong memory model.
#ifndef UCU_BD_MMBP
   #error "Program memory model define not provided on command line (UCU_BD_MMBP)."
#endif
#if (UCU_BD_MMBP != 1)
   #error "Attempt to assemble module for wrong program memory model (UCU_BD_MMBP != 1)."
#endif
;
            switch .text
            xdef   _UcuBtU32RotLeftNInPlaceRxn
;
;Per discussion with Cosmic, the first integer is the stack space used by the
;call instruction plus any automatic storage used by the function.  The second integer
;is the number of bytes stacked by the caller.  Haven't yet discussed the scenario
;of one assembly-language function called by another.  I've noticed that some
;assembly-language functions have a larger first integer than the stack they
;used, so there may be a special convention if C calls .S which then calls .S,
;as maybe the tools don't detect the .S calling the .S.  Will need to investigate
;further with Cosmic.
;
;2 bytes pushed on the stack by the call, 6 bytes stacked locally.  1 byte
;stacked by caller.
            .dcall  "8,1,_UcuBtU32RotLeftNInPlaceRxn"
;
_UcuBtU32RotLeftNInPlaceRxn:
        ;N (the number of bits to roll) has been pushed on the stack, and X
        ;contains the address of the UCU_UINT32 to roll.
        ;Stack frame now:
        ;  ( 1,SP)     :      Return address MSB.
        ;  ( 2,SP)     :      Return address LSB.
        ;  ( 3,SP)     :      N.
        ;----------
        pushw   x             ;Push X on the stack.  We will need to refer to this
                              ;address later.
        ;Stack frame now:
        ;  ( 1,SP)     :      TGT MSB
        ;  ( 2,SP)     :      TGT LSB
        ;  ( 3,SP)     :      Return address MSB.
        ;  ( 4,SP)     :      Return address LSB.
        ;  ( 5,SP)     :      N.
        ;----------
        subw   sp,#4          ;Reserve another 4 bytes on the stack for the item
                              ;to be rolled.
        ;----------
        ;Stack frame now:
        ;  ( 1,SP)     :      (*TGT) MSB
        ;  ( 2,SP)     :      (*TGT) Intermediate byte
        ;  ( 3,SP)     :      (*TGT) Intermediate byte
        ;  ( 4,SP)     :      (*TGT) LSB
        ;  ( 5,SP)     :      TGT MSB
        ;  ( 6,SP)     :      TGT LSB
        ;  ( 7,SP)     :      Return address MSB.
        ;  ( 8,SP)     :      Return address LSB.
        ;  ( 9,SP)     :      N.
        ;----------
        ;Load *TGT into the stack frame.
        ld    a,(x)
        ld    (1,sp),a
        ld    a,(1,x)
        ld    (2,sp),a
        ld    a,(2,x)
        ld    (3,sp),a
        ld    a,(3,x)
        ld    (4,sp),a
        ;----------
        ;Adjust N by AND'ing it with 31, which forms N mod 32.  The reason for this
        ;is that rolling a 32-bit quantity 32 places leaves it unchanged, so only
        ;N mod 32 matters.
        ld    a,(9,sp)
        and   a,#31
        ld    (9,sp),a
        ;----------
        ;Load X:Y with the 32-bit quantity to be rolled.  Manipulating it in these
        ;registers is probably faster than manipulating it in memory.
        ldw   x,(1,sp)
        ldw   y,(3,sp)
        ;----------
        ;If N >= 16, we can do the 16 counts of the left roll just by exchanging words.
        ld    a,(9,sp)
        cp    a,#16
        jrult n_less_than_16
        ;----------
        ;If we are here, N is 16 or larger.  Should subtract 16, as we will handle
        ;that part of the roll.
        sub   a,#16
        ld    (9,sp),a
        ;
        ;Exchange the words, which effectively rolls by 16.
        exgw  x,y
        ;----------
n_less_than_16:
        ;Check if N >= 8.  If so, can do the left roll by careful register exchanges.
        ld    a,(9,sp)
        cp    a,#8
        jrult n_less_than_8
        ;----------
        ;If we are here, N is 8 or larger.  Should subtract 8, as we will handle
        ;that part of the left roll.
        sub   a,#8
        ld    (9,sp),a
        ;
        ;Do the register exchanges to roll left by 8.
                              ;
                              ;  XH      XL      YH      YL       A
                              ;------------------------------------
                              ;  XH      XL      YH      YL       -
        ld    a,xh            ;  XH      XL      YH      YL      XH
        swapw x               ;  XL      XH      YH      YL      XH
        swapw y               ;  XL      XH      YL      YH      XH
        exg   a,yl            ;  XL      XH      YL      XH      YH
        exg   a,xl            ;  XL      YH      YL      XH      XH
        ;
        ;Fall through to final sequence, which handles 7 or fewer left roll operations.
        ;----------
n_less_than_8:
        ;----------
        ;Skip loop entry if count is 0.
        tnz   (9,sp)
        jreq  done
loop_top:
        ;Get the MSB of X into the carry bit.  This has to be done to prime the
        ;pump so that it makes it into the LSB of Y.
        ld    a,xh
        rlc   a
        ;Roll the 32-bit quantity.
        rlcw  y
        rlcw  x
        dec   (9,sp)
        jrne  loop_top
        ;----------
done:
        ;Restore X:Y to its place in the stack frame.
        ldw   (1,sp),x
        ldw   (3,sp),y
        ;
        ;Copy the result to the caller's *TGT location.  The LDW instruction isn't
        ;fully orthogonal, so it is easier to move things through the accumulator.
        ldw   x,(5,sp)        ;Get the TGT pointer.
        ld    a,(1,sp)
        ld    (x),a
        ld    a,(2,sp)
        ld    (1,x),a
        ld    a,(3,sp)
        ld    (2,x),a
        ld    a,(4,sp)
        ld    (3,x),a
        ;
        ;Restore the stack pointer.
        addw  sp,#6
        ;
        ;And return.
        ret
;
        end
;
;-------------------------------------------------------------------------------
;End of $Id: btu32rotleftninplacerxn.s,v 1.6 2010/05/14 18:18:50 dashley Exp $
;-------------------------------------------------------------------------------
;$Log: btu32rotleftninplacerxn.s,v $
;Revision 1.6  2010/05/14 18:18:50  dashley
;Minor comment enhancements.
;
;Revision 1.5  2010/05/14 17:14:25  dashley
;Defect corrected.
;
;Revision 1.4  2010/05/13 18:33:56  dashley
;Edits.
;
;Revision 1.3  2010/05/13 16:42:36  dashley
;Edits.
;
;Revision 1.2  2010/05/13 16:14:09  dashley
;Edits.
;
;Revision 1.1  2010/05/13 13:59:23  dashley
;Initial checkin.
;-------------------------------------------------------------------------------

