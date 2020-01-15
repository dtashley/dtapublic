;-------------------------------------------------------------------------------
;$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/mfcpuccrsetrxx/src/mfcpuccrsetrxx.s,v 1.3 2010/06/11 18:07:35 dashley Exp $
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
            xdef   _UcuMfCpuCcrSetRxx
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
;2 bytes stacked by the CALL instruction, 1 byte stacked by this function because of the
;mechanism used to set the CCR, 0 bytes stacked by the caller.
        .dcall  "3,0,_UcuMfCpuCcrSetRxx"
;
_UcuMfCpuCcrSetRxx:
        push  a               ;Push the caller's argument.
        pop   cc              ;Get it into the CCR.  This is necessarily atomic.
        ret                   ;Return value set up.  Can return.
;
        end
;
;-------------------------------------------------------------------------------
;End of $Id: mfcpuccrsetrxx.s,v 1.3 2010/06/11 18:07:35 dashley Exp $
;-------------------------------------------------------------------------------
;$Log: mfcpuccrsetrxx.s,v $
;Revision 1.3  2010/06/11 18:07:35  dashley
;Naming error corrected.
;
;Revision 1.2  2010/06/11 15:54:58  dashley
;a)Extra line removed.
;b)Comment added.
;
;Revision 1.1  2010/06/11 15:53:03  dashley
;Initial checkin.
;-------------------------------------------------------------------------------

