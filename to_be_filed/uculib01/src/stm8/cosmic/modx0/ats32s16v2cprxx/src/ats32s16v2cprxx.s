;-------------------------------------------------------------------------------
;$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/ats32s16v2cprxx/src/ats32s16v2cprxx.s,v 1.5 2010/04/16 21:22:27 dashley Exp $
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
            xref.b c_lreg   ;We use this for the return value.
;
            switch .text
            xdef   _UcuAtS32S16v2CpRxx
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
;2 bytes pushed on the stack by the call, 11 bytes stacked locally.  6 bytes
;stacked by caller.
            .dcall  "13,6,_UcuAtS32S16v2CpRxx"
;
_UcuAtS32S16v2CpRxx:
        ;********************************************************************************
        ;********************************************************************************
        ;*****  S T A C K    F R A M E    S E T U P  ************************************
        ;********************************************************************************
        ;********************************************************************************
        ;X contains a_x, and the other parameters are on the stack
        ;already.
        ;
        ;Stack frame now:
        ;  ( 1,SP)     :      Return address MSB.
        ;  ( 2,SP)     :      Return address LSB.
        ;  ( 3,SP)     :      a_y MSB.
        ;  ( 4,SP)     :      a_y LSB.
        ;  ( 5,SP)     :      b_x MSB.
        ;  ( 6,SP)     :      b_x LSB.
        ;  ( 7,SP)     :      b_y MSB.
        ;  ( 8,SP)     :      b_y LSB.
        ;----------
        ;Push the X register onto the stack so we won't lose it.
        pushw x
        ;Stack frame now:
        ;  ( 1,SP)     :      a_x MSB.
        ;  ( 2,SP)     :      a_x LSB.
        ;  ( 3,SP)     :      Return address MSB.
        ;  ( 4,SP)     :      Return address LSB.
        ;  ( 5,SP)     :      a_y MSB.
        ;  ( 6,SP)     :      a_y LSB.
        ;  ( 7,SP)     :      b_x MSB.
        ;  ( 8,SP)     :      b_x LSB.
        ;  ( 9,SP)     :      b_y MSB.
        ;  (10,SP)     :      b_y LSB.
        ;----------
        ;Claim 9 additional bytes on the stack.
        subw  sp,#9
        ;Stack frame now:
        ;  ( 1,SP)     :      Bit-packed status byte, used to remember signs of products and special cases.
        ;                        Bit 7 -- 128 -- a_x * b_y is negative.
        ;                        Bit 6 --  64 -- a_y * b_x is negative.
        ;                        Bit 5 --  32 -- a_x is -32768.
        ;                        Bit 4 --  16 -- a_y is -32768.
        ;                        Bit 3 --   8 -- b_x is -32768.
        ;                        Bit 2 --   4 -- b_y is -32768.
        ;  ( 2,SP)     :      a_x * b_y, as a UCU_SINT32.
        ;  ( 3,SP)     :      ""
        ;  ( 4,SP)     :      ""
        ;  ( 5,SP)     :      ""
        ;  ( 6,SP)     :      -(a_y * b_x) as a UCU_SINT32.
        ;  ( 7,SP)     :      ""
        ;  ( 8,SP)     :      ""
        ;  ( 9,SP)     :      ""
        ;  (10,SP)     :      a_x MSB.
        ;  (11,SP)     :      a_x LSB.
        ;  (12,SP)     :      Return address MSB.
        ;  (13,SP)     :      Return address LSB.
        ;  (14,SP)     :      a_y MSB.
        ;  (15,SP)     :      a_y LSB.
        ;  (16,SP)     :      b_x MSB.
        ;  (17,SP)     :      b_x LSB.
        ;  (18,SP)     :      b_y MSB.
        ;  (19,SP)     :      b_y LSB.
        ;
        ;********************************************************************************
        ;********************************************************************************
        ;*****  C O N V E R S I O N    T O    S I G N - M A G N I T U D E  **************
        ;********************************************************************************
        ;********************************************************************************
        ;----------
        ;Clear the sign status byte.
        clr   (1,sp)
        ;----------
        ;Process the sign of a_x.  This will record the sign and complement if negative to give
        ;a sign-magnitude representation.  a_x is still in the x register.
        tnzw  x
        jrpl  ax_is_nonnegative
        ld    a,(1,sp)        ;Invert the a_x * b_y product neg bit.
        xor   a,#128
        ld    (1,sp),a
        negw  x               ;This has the desirable side effect of setting the V bit
                              ;if the input (and output) are -32768.
        ldw   (10,sp),x       ;Store the inverted result back.
        jrnv  ax_is_nonnegative
        ld    a,(1,sp)        ;Set the a_x is -32768 bit.
        or    a,#32
        ld    (1,sp),a
ax_is_nonnegative:
        ;----------
        ;Process the sign of a_y.  This will record the sign and complement if negative to give
        ;a sign-magnitude representation.
        ldw   x,(14,sp)
        tnzw  x
        jrpl  ay_is_nonnegative
        ld    a,(1,sp)        ;Invert the a_y * b_x product neg bit.
        xor   a,#64
        ld    (1,sp),a
        negw  x               ;This has the desirable side effect of setting the V bit
                              ;if the input (and output) are -32768.
        ldw   (14,sp),x       ;Store the inverted result back.
        jrnv  ay_is_nonnegative
        ld    a,(1,sp)        ;Set the a_y is -32768 bit.
        or    a,#16
        ld    (1,sp),a
ay_is_nonnegative:
        ;----------
        ;Process the sign of b_x.  This will record the sign and complement if negative to give
        ;a sign-magnitude representation.
        ldw   x,(16,sp)
        tnzw  x
        jrpl  bx_is_nonnegative
        ld    a,(1,sp)        ;Invert the a_y * b_x product neg bit.
        xor   a,#64
        ld    (1,sp),a
        negw  x               ;This has the desirable side effect of setting the V bit
                              ;if the input (and output) are -32768.
        ldw   (16,sp),x       ;Store the inverted result back.
        jrnv  bx_is_nonnegative
        ld    a,(1,sp)        ;Set the a_x is -32768 bit.
        or    a,#8
        ld    (1,sp),a
bx_is_nonnegative:
        ;----------
        ;Process the sign of b_y.  This will record the sign and complement if negative to give
        ;a sign-magnitude representation.
        ldw   x,(18,sp)
        tnzw  x
        jrpl  by_is_nonnegative
        ld    a,(1,sp)        ;Invert the a_x * b_y product neg bit.
        xor   a,#128
        ld    (1,sp),a
        negw  x               ;This has the desirable side effect of setting the V bit
                              ;if the input (and output) are -32768.
        ldw   (18,sp),x       ;Store the inverted result back.
        jrnv  by_is_nonnegative
        ld    a,(1,sp)        ;Set the b_y is -32768 bit.
        or    a,#4
        ld    (1,sp),a
by_is_nonnegative:
        ;********************************************************************************
        ;********************************************************************************
        ;*****  A _ X    *    B _ Y    C A L C U L A T I O N    *************************
        ;********************************************************************************
        ;********************************************************************************
        ;Form the product of a_x * b_y into (2,SP), (3,SP), (4,SP), and (5,SP).
        ;There are special cases first.
        ;
        ;Look for a_x = b_y = -32768
        ld    a,(1,sp)        ;Grab the status byte.
        and   a,#36
        jreq  ax_by_neither_negmax   ;Branch around in the most typical case, which is that neither
                                     ;a_x nor b_y is -32768.
        cp    a,#36
        jrne  ax_by_not_both_negmax
        ;----------
        ;If we are here, a_x and b_y were both -32768.  The product in this case
        ;is 2^30.
        ldw   x,#16384
        ldw   (2,sp),x
        clrw  x
        ldw   (4,sp),x
        jra   ax_by_done
        ;----------
        ;If we are here, either a_x = -32768 or b_y = -32768, but not both.
        ;
ax_by_not_both_negmax:
        cp    a,#4
        jreq  by_is_negmax
        ;----------
        ;If we are here here, a_x = -32768, but b_y is another value.
        ;Multiplication by 32768 is equivalent to left-shifting by 15 places.  The approach
        ;used is to left-shift by 16 places, then to back off 1 by right-shifting once.
        ;
        ldw   x,(18,sp)
        sraw  x
        clrw  y
        jrnc  ax_is_negmax_01
        ldw   y,#32768
ax_is_negmax_01:
        ;
        ;X and Y are loaded with the unsigned product now.  Need to negate if the
        ;ax * by neg bit is set.
        ld    a,(1,sp)
        and   a,#128
        jreq  ax_is_negmax_nonegate
        cplw  x
        cplw  y
        incw  y
        jrne  ax_is_negmax_nonegate
        incw  x               ;Incrementing Y (the LSW) generated a carry into X (the MSW).
ax_is_negmax_nonegate:
        ldw   (2,sp),x
        ldw   (4,sp),y
        jra   ax_by_done      ;We are done with calculating the ax * by term.

        ;----------
by_is_negmax:
        ;If we are here, b_y = -32768, but a_x is another value.
        ;Multiplication by 32768 is equivalent to left-shifting by 15 places.  The approach
        ;used is to left-shift by 16 places, then to back off 1 by right-shifting once.
        ;
        ldw   x,(10,sp)
        sraw  x
        clrw  y
        jrnc  by_is_negmax_01
        ldw   y,#32768
by_is_negmax_01:
        ;
        ;X and Y are loaded with the unsigned product now.  Need to negate if the
        ;ax * by neg bit is set.
        ld    a,(1,sp)
        and   a,#128
        jreq  by_is_negmax_nonegate
        cplw  x
        cplw  y
        incw  y
        jrne  by_is_negmax_nonegate
        incw  x               ;Incrementing Y (the LSW) generated a carry into X (the MSW).
by_is_negmax_nonegate:
        ldw   (2,sp),x
        ldw   (4,sp),y
        jra   ax_by_done      ;We are done with calculating the ax * by term.
        ;----------
ax_by_neither_negmax:
        ;If we are here, neither a_x nor b_y are at the negative limit.  This is a simple
        ;multiplication with optional negation.
        ;
        ;Clear most significant word of result in preparation for multiplication.
        clrw  x
        ldw   (2,sp),x
        ;
        ;a_x(0) * b_y(0)
        ld    a,(11,sp)       ;a_x(0)
        ld    xl,a
        ld    a,(19,sp)       ;b_y(0)
        mul   x,a
        ldw   (4,sp),x        ;Store result.
        ;
        ;a_x(0) * b_y(1)
        ld    a,(11,sp)       ;a_x(0)
        ld    xl,a
        ld    a,(18,sp)       ;b_y(1)
        mul   x,a
        addw  x,(3,sp)        ;Add in term.  Note that carry isn't possible on this first
                              ;addition.
        ldw   (3,sp),x        ;Store result.
        ;
        ;a_x(1) * b_y(0)
        ld    a,(10,sp)       ;a_x(1)
        ld    xl,a
        ld    a,(19,sp)       ;b_y(0)
        mul   x,a
        addw  x,(3,sp)        ;Add in term.  Carry is possible.
        ldw   (3,sp),x        ;Store result.
        jrnc  ax_by_neither_negmax_nc
        inc   (2,sp)          ;Propagate carry
ax_by_neither_negmax_nc:
        ;
        ;a_x(1) * b_y(1)
        ld    a,(10,sp)       ;a_x(1)
        ld    xl,a
        ld    a,(18,sp)       ;b_y(1)
        mul   x,a
        addw  x,(2,sp)        ;Add in term.  Carry is not possible.
        ldw   (2,sp),x        ;Store result.
        ;
        ;Need to negate if the ax * by neg bit is set.
        ld    a,(1,sp)
        and   a,#128
        jreq  ax_by_done
        ldw   x,(2,sp)
        ldw   y,(4,sp)
        cplw  x
        cplw  y
        incw  y
        jrne  ax_by_neither_negmax_noinc
        incw  x               ;Incrementing Y (the LSW) generated a carry into X (the MSW).
ax_by_neither_negmax_noinc:
        ldw   (2,sp),x
        ldw   (4,sp),y
        ;----------
ax_by_done:
        ;We are done with calculating a_x * b_y term.
        ;----------
        ;********************************************************************************
        ;********************************************************************************
        ;*****  - ( A _ Y    *    B _ X )    C A L C U L A T I O N    *******************
        ;********************************************************************************
        ;********************************************************************************
        ;Form the product of a_y * b_x into (6,SP), (7,SP), (8,SP), and (9,SP).
        ;There are special cases first.
        ;
        ;Look for a_y = b_x = -32768
        ld    a,(1,sp)        ;Grab the status byte.
        and   a,#24
        jreq  ay_bx_neither_negmax   ;Branch around in the most typical case, which is that neither
                                     ;a_y nor b_x is -32768.
        cp    a,#24
        jrne  ay_bx_not_both_negmax
        ;----------
        ;If we are here, a_y and b_x were both -32768.  The product in this case
        ;is 2^30.
        ldw   x,#16384
        ldw   (6,sp),x
        clrw  x
        ldw   (8,sp),x
        jra   ay_bx_done
        ;----------
        ;If we are here, either a_y = -32768 or b_x = -32768, but not both.
        ;
ay_bx_not_both_negmax:
        cp    a,#16
        jreq  bx_is_negmax
        ;----------
        ;If we are here here, a_y = -32768, but b_x is another value.
        ;Multiplication by 32768 is equivalent to left-shifting by 15 places.  The approach
        ;used is to left-shift by 16 places, then to back off 1 by right-shifting once.
        ;
        ldw   x,(16,sp)
        sraw  x
        clrw  y
        jrnc  ay_is_negmax_01
        ldw   y,#32768
ay_is_negmax_01:
        ;
        ;X and Y are loaded with the unsigned product now.  Need to negate if the
        ;ay * bx neg bit is NOT set.  (The inverted logic is because we are forming
        ;the negative product.)
        ld    a,(1,sp)
        and   a,#64
        jrne  ay_is_negmax_nonegate
        cplw  x
        cplw  y
        incw  y
        jrne  ay_is_negmax_nonegate
        incw  x               ;Incrementing Y (the LSW) generated a carry into X (the MSW).
ay_is_negmax_nonegate:
        ldw   (6,sp),x
        ldw   (8,sp),y
        jra   ay_bx_done      ;We are done with calculating the ay * bx term.

        ;----------
bx_is_negmax:
        ;If we are here, b_x = -32768, but a_y is another value.
        ;Multiplication by 32768 is equivalent to left-shifting by 15 places.  The approach
        ;used is to left-shift by 16 places, then to back off 1 by right-shifting once.
        ;
        ldw   x,(14,sp)
        sraw  x
        clrw  y
        jrnc  by_is_negmax_01
        ldw   y,#32768
bx_is_negmax_01:
        ;
        ;X and Y are loaded with the unsigned product now.  Need to negate if the
        ;ay * bx neg bit is NOT set.
        ld    a,(1,sp)
        and   a,#64
        jrne  bx_is_negmax_nonegate
        cplw  x
        cplw  y
        incw  y
        jrne  bx_is_negmax_nonegate
        incw  x               ;Incrementing Y (the LSW) generated a carry into X (the MSW).
bx_is_negmax_nonegate:
        ldw   (6,sp),x
        ldw   (8,sp),y
        jra   ay_bx_done      ;We are done with calculating the ay * bx term.
        ;----------
ay_bx_neither_negmax:
        ;If we are here, neither a_y nor b_x are at the negative limit.  This is a simple
        ;multiplication with optional negation.
        ;
        ;Clear most significant word of result in preparation for multiplication.
        clrw  x
        ldw   (6,sp),x
        ;
        ;a_y(0) * b_x(0)
        ld    a,(15,sp)       ;a_y(0)
        ld    xl,a
        ld    a,(17,sp)       ;b_x(0)
        mul   x,a
        ldw   (8,sp),x        ;Store result.
        ;
        ;a_y(0) * b_x(1)
        ld    a,(15,sp)       ;a_y(0)
        ld    xl,a
        ld    a,(16,sp)       ;b_x(1)
        mul   x,a
        addw  x,(7,sp)        ;Add in term.  Note that carry isn't possible on this first
                              ;addition.
        ldw   (7,sp),x        ;Store result.
        ;
        ;a_y(1) * b_x(0)
        ld    a,(14,sp)       ;a_y(1)
        ld    xl,a
        ld    a,(17,sp)       ;b_x(0)
        mul   x,a
        addw  x,(7,sp)        ;Add in term.  Carry is possible.
        ldw   (7,sp),x        ;Store result.
        jrnc  ay_bx_neither_negmax_nc
        inc   (6,sp)          ;Propagate carry
ay_bx_neither_negmax_nc:
        ;
        ;a_y(1) * b_x(1)
        ld    a,(14,sp)       ;a_y(1)
        ld    xl,a
        ld    a,(16,sp)       ;b_x(1)
        mul   x,a
        addw  x,(6,sp)        ;Add in term.  Carry is not possible.
        ldw   (6,sp),x        ;Store result.
        ;
        ;Need to negate if the ay * bx neg bit is NOT set.  (The inverted logic is because we are forming
        ;the negative product.)
        ld    a,(1,sp)
        and   a,#64
        jrne  ay_bx_done
        ldw   x,(6,sp)
        ldw   y,(8,sp)
        cplw  x
        cplw  y
        incw  y
        jrne  ay_bx_neither_negmax_noinc
        incw  x               ;Incrementing Y (the LSW) generated a carry into X (the MSW).
ay_bx_neither_negmax_noinc:
        ldw   (6,sp),x
        ldw   (8,sp),y
        ;----------
ay_bx_done:
        ;We are done with calculating -(a_x * b_y) term.
        ;
        ;*************************************************************************************
        ;*************************************************************************************
        ;*****  T E R M    A D D I T I O N ,    R E T U R N    V A L U E    S E T U P    *****
        ;*************************************************************************************
        ;*************************************************************************************
        ;Grab the two terms.  Y is the LSW.
        ldw   x,(2,sp)
        ldw   y,(4,sp)
        ;
        ;Add the terms.  Must propagate the carry.
        addw  y,(8,sp)
        jrnc  ta_rvs_nocarry
        incw  x
ta_rvs_nocarry:
        addw  x,(6,sp)
        ;
        ;Store the result in the location expected by the compiler.
        ldw   c_lreg,x
        ldw   c_lreg+2,y
        ;
        ;********************************************************************************
        ;********************************************************************************
        ;*****  S T A C K    C L E A N U P    *******************************************
        ;********************************************************************************
        ;********************************************************************************
        addw  sp,#11          ;9 bytes explicitly allocated, plus 2 allocated via PUSHW X.
        ;
        ;********************************************************************************
        ;********************************************************************************
        ;*****  F U N C T I O N    R E T U R N    ***************************************
        ;********************************************************************************
        ;********************************************************************************
        ret
;
        end
;
;-------------------------------------------------------------------------------
;End of $Id: ats32s16v2cprxx.s,v 1.5 2010/04/16 21:22:27 dashley Exp $
;-------------------------------------------------------------------------------
;$Log: ats32s16v2cprxx.s,v $
;Revision 1.5  2010/04/16 21:22:27  dashley
;Corrections.
;
;Revision 1.4  2010/04/14 21:41:57  dashley
;Function complete, pending reviews and testing.
;
;Revision 1.3  2010/04/14 20:56:41  dashley
;Edits.
;
;Revision 1.2  2010/04/14 20:10:18  dashley
;Initial checkin.
;
;Revision 1.1  2010/04/14 20:09:53  dashley
;Initial checkin.
;-------------------------------------------------------------------------------

