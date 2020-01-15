;-------------------------------------------------------------------------------
;$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx/bas16absdiffboundedrxx/src/bas16absdiffboundedrxx.s,v 1.3 2010/03/21 05:08:29 dashley Exp $
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
;This function doesn't use any static storage, so it is OK for either mods or
;modsl memory models.  However, it does assume callf/retf (rather than call/ret)
;which affects both instructions used, stack offsets, and numerical values in
;the .dcall directive.  For this reason, must error out if being assembled
;for the wrong memory model.
#ifndef UCU_BD_MMBP
   #error "Program memory model define not provided on command line (UCU_BD_MMBP)."
#endif
#if (UCU_BD_MMBP != 2)
   #error "Attempt to assemble module for wrong program memory model (UCU_BD_MMBP != 2)."
#endif
;
            switch .text
            xdef   f_UcuBaS16AbsDiffBoundedRxx
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
;3 bytes pushed on the stack by the CALLF, nothing stacked locally.  2 bytes
;stacked by caller.
            .dcall  "3,2,f_UcuBaS16AbsDiffBoundedRxx"
;
f_UcuBaS16AbsDiffBoundedRxx:
        ;X contains Parameter 1.
        ;Stack frame now:
        ;  ( 1,SP)     :      Return address segment.
        ;  ( 2,SP)     :      Return address MSB.
        ;  ( 3,SP)     :      Return address LSB.
        ;  ( 4,SP)     :      Parameter 2 MSB.
        ;  ( 5,SP)     :      Parameter 2 LSB.
        ;----------
        subw  x,(4,sp)        ;Form P1-P2, setting V flag and other flags.
        jrnv  no_overflow     ;No signed overflow, but it still might be -32768.
        ;----------
        ;Overflow.  Overflow of a signed operation means the result is <-32768 or >32767.
        ;In either case, the returned value must be 32767.
        ldw   x,#32767        ;Setup return value of 32767.
        retf                  ;Back to caller.
        ;----------
no_overflow:
        ;----------
        ;If we have -32768, this is too big to complement, so we have to map it to
        ;32767.
        cpw   x,#32768
        jrne  in_range              ;Not -32768.
        ldw   x,#32767
        retf
        ;----------
        ;The difference is in [-32767, 32767].  We can use it as is if in [0,32767], or safely
        ;form the 2's complement.
in_range:
        tnzw  x
        jrpl  already_nonnegative   ;Branch around if already nonnegative.
        negw  x                     ;Form the 2's complement.
already_nonnegative:
        ;Result is now in [0,32767].  Just return it.
        retf
;
        end
;
;-------------------------------------------------------------------------------
;End of $Id: bas16absdiffboundedrxx.s,v 1.3 2010/03/21 05:08:29 dashley Exp $
;-------------------------------------------------------------------------------
;$Log: bas16absdiffboundedrxx.s,v $
;Revision 1.3  2010/03/21 05:08:29  dashley
;Comments corrected.
;
;Revision 1.2  2010/03/20 19:31:53  dashley
;Extra line removed.
;
;Revision 1.1  2010/03/20 19:30:50  dashley
;Initial checkin.
;-------------------------------------------------------------------------------

