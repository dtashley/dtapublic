;-------------------------------------------------------------------------------
;$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/bas8diffboundedrxx/src/bas8diffboundedrxx.s,v 1.6 2010/03/21 04:50:34 dashley Exp $
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
            xdef   _UcuBaS8DiffBoundedRxx
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
            .dcall  "4,0,_UcuBaS8DiffBoundedRxx"
;
;UCU_SINT8 UCU_s8_diff_bounded( UCU_SINT8 arg1, UCU_SINT8 arg2 )
;   {
;
_UcuBaS8DiffBoundedRxx:
        ;ARG1 is in XH, ARG2 is in XL.
        pushw x               ;After this, ARG1 is at (1,SP) and ARG2 is at (2,SP).
        ld    a,xh            ;Get ARG1 into A.
        sub   a,(2,sp)        ;Subtract ARG2.
        jrnv  mfs8dbend       ;If no overflow, we are done.  Correct result is in A.
        ;----------
        ;If we are here, we overflowed.  This means we took a negative operand too negative
        ;and overflowed it, or we took a positive operand too positive and overflowed it.
        ;If ARG1 is negative, we return -128.  If ARG1 is positive, we return 127.
        ld    a,#-128
        tnz   (1,sp)
        jrmi  mfs8dbend       ;The correct value is loaded.  We are ready to return with it in A.
        ld    a,#127          ;If the minus flag is not set, ARG1 was zero or positive, so we
                              ;must have overflowed in the positive direction.  127 is the right
                              ;return value.
mfs8dbend:
        popw  x
        ret
;
        end

;-------------------------------------------------------------------------------
;End of $Id: bas8diffboundedrxx.s,v 1.6 2010/03/21 04:50:34 dashley Exp $
;-------------------------------------------------------------------------------
;$Log: bas8diffboundedrxx.s,v $
;Revision 1.6  2010/03/21 04:50:34  dashley
;Comments corrected.
;
;Revision 1.5  2010/02/20 16:07:22  dashley
;Missing switch directive added.
;
;Revision 1.4  2010/02/18 17:22:17  dashley
;Documentation changes.
;
;Revision 1.3  2010/01/28 21:57:20  dashley
;Addition of the UcuBaS8DiffBoundedRxx() function.
;
;Revision 1.2  2010/01/21 21:31:13  dashley
;Minor whitespace correction.
;
;Revision 1.1  2010/01/21 21:30:26  dashley
;Initial checkin.
;-------------------------------------------------------------------------------

