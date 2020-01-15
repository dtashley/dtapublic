//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu8bitcardrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_btu8bitcardrxx.h,v 1.2 2010/02/11 20:20:41 dashley Exp $
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
#ifndef UTFU_BTU8BITCARDRXX_H
#define UTFU_BTU8BITCARDRXX_H

#ifdef MODULE_UTFU_BTU8BITCARDRXX
   #define DECMOD_UTFU_BTU8BITCARDRXX
#else
   #define DECMOD_UTFU_BTU8BITCARDRXX extern
#endif

DECMOD_UTFU_BTU8BITCARDRXX UCU_UINT32  UtsnBtU8BitCardRxx(void);
DECMOD_UTFU_BTU8BITCARDRXX void        UtspBtU8BitCardRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void));
DECMOD_UTFU_BTU8BITCARDRXX UCU_BOOLEAN UtfuBtU8BitCardRxx(void);

#endif

//-------------------------------------------------------------------------------
//$Log: utfu_btu8bitcardrxx.h,v $
//Revision 1.2  2010/02/11 20:20:41  dashley
//Edits.
//
//Revision 1.1  2010/02/11 20:14:26  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_btu8bitcardrxx.h,v $
//-------------------------------------------------------------------------------

