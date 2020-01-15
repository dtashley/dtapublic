;-------------------------------------------------------------------------------
;$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/bas16diffboundedrxx/src/bas16diffboundedrxx.s,v 1.4 2010/03/21 04:50:34 dashley Exp $
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
            xdef   _UcuBaS16DiffBoundedRxx
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
;2 bytes pushed on the stack by the CALL, 2 bytes stacked by the caller.
            .dcall  "2,2,_UcuBaS16DiffBoundedRxx"
;
_UcuBaS16DiffBoundedRxx:
        ;X contains Parameter 1.
        ;Stack frame now:
        ;  ( 1,SP)     :      Return address MSB.
        ;  ( 2,SP)     :      Return address LSB.
        ;  ( 3,SP)     :      Parameter 2 MSB.
        ;  ( 4,SP)     :      Parameter 2 LSB.
        ;----------
        ldw   y,x             ;Save X in Y because we have to remember the
                              ;sign of Parameter 1.
        subw  x,(3,sp)        ;Form P1-P2, setting overflow and other flags.
        jrv   overflow        ;Branch if overflow, meaning we need to rail the result.
        ;----------
        ;The result is perfectly legal to return, and is already in X.
        ret
        ;----------
overflow:
        ;Result overflowed signed representation.  Need to adjust based on sign of P1.
        ;If P1 was at least 0, only possible overflow is positive.  If P1 was -1 or less,
        ;only possible overflow is negative.
        tnzw  y               ;Set flags based on copy of P1.
        jrmi  negative_rail
        ;----------
        ;Positive overflow.
        ldw   x,#32767        ;Return 32767.
        ret
        ;----------
negative_rail:
        ;Negative overflow.
        ldw   x,#32768        ;Return -32768.
        ret
;
        end
;
;-------------------------------------------------------------------------------
;End of $Id: bas16diffboundedrxx.s,v 1.4 2010/03/21 04:50:34 dashley Exp $
;-------------------------------------------------------------------------------
;$Log: bas16diffboundedrxx.s,v $
;Revision 1.4  2010/03/21 04:50:34  dashley
;Comments corrected.
;
;Revision 1.3  2010/03/21 03:10:00  dashley
;Semicolon added (should have no effect on generated code).
;
;Revision 1.2  2010/03/20 20:40:35  dashley
;Extra line removed.
;
;Revision 1.1  2010/03/20 20:40:08  dashley
;Initial checkin.
;-------------------------------------------------------------------------------

