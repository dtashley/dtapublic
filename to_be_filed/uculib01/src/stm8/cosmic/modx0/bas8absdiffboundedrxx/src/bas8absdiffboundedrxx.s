;-------------------------------------------------------------------------------
;$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/bas8absdiffboundedrxx/src/bas8absdiffboundedrxx.s,v 1.6 2010/03/21 04:50:34 dashley Exp $
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
            xdef   _UcuBaS8AbsDiffBoundedRxx
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
;2 bytes pushed on the stack by the CALL, 2 additional bytes pushed on the
;stack by this function.
            .dcall  "4,0,_UcuBaS8AbsDiffBoundedRxx"
;
_UcuBaS8AbsDiffBoundedRxx:
        ;ARG1 is in XH, ARG2 is in XL.
        pushw x               ;Must get X on the stack because SUB won't allow accumulator/register
                              ;subtracts, and there is no single-byte PUSH instruction to cover XL only.
                              ;After this, ARG1 is at (1,SP) and ARG2 is at (2,SP).
        ld    a,xh            ;Get ARG1 into A.
        sub   a,(2,sp)        ;Subtract ARG2.
        jrnv  no_overflow     ;No signed overflow, but it still might be -128.
        ;----------
        ;Overflow.  Overflow of a signed operation means the result is <-128 or >127.
        ;In either case, the returned value must be 127.
        ld    a,#127
        popw  x
        ret
        ;----------
no_overflow:
        ;----------
        ;If we have -128, this is too big to complement, so we have to map it to
        ;127.
        cp    a,#128
        jrne  in_range              ;Not -128.
        ld    a,#127
        popw  x
        ret
        ;----------
        ;The difference is in [-127, 127].  We can use it as is if in [0,127], or safely
        ;form the 2's complement.
in_range:
        tnz   a
        jrpl  already_nonnegative   ;Branch around if already nonnegative.
        neg   a                     ;Forms the 2's complement.
already_nonnegative:
        ;Result is now in [0,127].  Just return it.
        popw  x
        ret
;
        end
;
;-------------------------------------------------------------------------------
;End of $Id: bas8absdiffboundedrxx.s,v 1.6 2010/03/21 04:50:34 dashley Exp $
;-------------------------------------------------------------------------------
;$Log: bas8absdiffboundedrxx.s,v $
;Revision 1.6  2010/03/21 04:50:34  dashley
;Comments corrected.
;
;Revision 1.5  2010/03/18 15:08:15  dashley
;Function renamed.
;
;Revision 1.4  2010/03/18 01:49:29  dashley
;Cosmetic change.
;
;Revision 1.3  2010/03/17 21:49:08  dashley
;Speed increased slightly at the expense of FLASH consumption by
;eliminating branches.
;
;Revision 1.2  2010/03/17 21:41:23  dashley
;Extra line removed.
;
;Revision 1.1  2010/03/17 21:40:58  dashley
;Initial checkin.
;-------------------------------------------------------------------------------

