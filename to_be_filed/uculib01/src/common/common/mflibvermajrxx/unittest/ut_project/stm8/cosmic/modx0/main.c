//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/common/common/mflibvermajrxx/unittest/ut_project/stm8/cosmic/modx0/main.c,v 1.2 2010/02/14 20:01:17 dashley Exp $
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
//This program links with the library and performs automated unit tests on the
//UcuAtU16CmpDiffAbsGtRxx() function.
//-------------------------------------------------------------------------------

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_mflibvermajrxx.h"


volatile UCU_BOOLEAN result;

void main(void)
   {
   result = UtfuMfLibVerMajRxx();

   //May examine the result assignment above to figure out if the unit test passed.

	while (1);
   }


//-------------------------------------------------------------------------------
//$Log: main.c,v $
//Revision 1.2  2010/02/14 20:01:17  dashley
//Unit testing completed (and passed).
//
//Revision 1.1  2010/02/14 19:51:56  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: main.c,v $
//-------------------------------------------------------------------------------

