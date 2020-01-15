//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu8sqrtfrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_atu8sqrtfrxx.h,v 1.3 2010/02/05 20:52:51 dashley Exp $
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
#ifndef UTFU_ATU8SQRTFRXX_H
#define UTFU_ATU8SQRTFRXX_H

#ifdef MODULE_UTFU_ATU8SQRTFRXX
   #define DECMOD_UTFU_ATU8SQRTFRXX
#else
   #define DECMOD_UTFU_ATU8SQRTFRXX extern
#endif

DECMOD_UTFU_ATU8SQRTFRXX UCU_UINT32  UtsnAtU8SqrtFRxx(void);
DECMOD_UTFU_ATU8SQRTFRXX void        UtspAtU8SqrtFRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void));
DECMOD_UTFU_ATU8SQRTFRXX UCU_BOOLEAN UtfuAtU8SqrtFRxx(void);

#endif

//-------------------------------------------------------------------------------
//$Log: utfu_atu8sqrtfrxx.h,v $
//Revision 1.3  2010/02/05 20:52:51  dashley
//Automated test vector system changed from maximum of 2^16-1 cases to
//2^32-1 cases.
//
//Revision 1.2  2010/02/05 15:54:58  dashley
//Extra line(s) removed.
//
//Revision 1.1  2010/02/05 15:53:26  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_atu8sqrtfrxx.h,v $
//-------------------------------------------------------------------------------

