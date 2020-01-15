//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/common/common/mflibverminmicrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_mflibverminmicrxx.h,v 1.2 2010/02/14 21:47:29 dashley Exp $
//-------------------------------------------------------------------------------
//Copyright (c)2010 David T. Ashley
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software source code and associated documentation files (the
//"Software"), to deal in the Software without restriction, including without
//limitation the rights to use, copy, modify, merge, publish, distribute,
//sublicense, and/or sell copies of the Software, and to permit persons to whom
//the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.
//-------------------------------------------------------------------------------
#ifndef UTFU_MFLIBVERMINMICRXX_H
#define UTFU_MFLIBVERMINMICRXX_H

#ifdef MODULE_UTFU_MFLIBVERMINMICRXX
   #define DECMOD_UTFU_MFLIBVERMINMICRXX
#else
   #define DECMOD_UTFU_MFLIBVERMINMICRXX extern
#endif

DECMOD_UTFU_MFLIBVERMINMICRXX UCU_UINT32  UtsnMfLibVerMinMicRxx(void);
DECMOD_UTFU_MFLIBVERMINMICRXX void        UtspMfLibVerMinMicRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void));
DECMOD_UTFU_MFLIBVERMINMICRXX UCU_BOOLEAN UtfuMfLibVerMinMicRxx(void);

#endif

//-------------------------------------------------------------------------------
//$Log: utfu_mflibverminmicrxx.h,v $
//Revision 1.2  2010/02/14 21:47:29  dashley
//Unit test complete.
//
//Revision 1.1  2010/02/14 21:43:41  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_mflibverminmicrxx.h,v $
//-------------------------------------------------------------------------------

