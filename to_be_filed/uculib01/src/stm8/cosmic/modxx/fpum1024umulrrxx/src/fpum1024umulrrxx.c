//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/fpum1024umulrrxx/src/fpum1024umulrrxx.c,v 1.5 2010/02/22 17:52:59 dashley Exp $
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

#include "uculib.h"


UCU_UINT16 UcuFpUm1024uMulRRxx(UCU_UINT16 arg1, UCU_UINT16 arg2)
   {
   UCU_UINT32 rv;

   //Clip arg1
   if (arg1 > 1024)
      arg1 = 1024;
      
   //Clip arg2
   if (arg2 > 1024)
      arg2 = 1024;
      
   //The product   
   rv = (UCU_UINT32)arg1 * (UCU_UINT32)arg2;
   
   //Round
   rv += 511;

   //Divide by 1024.  1024 is 2**10.  Found that ten shifts by 1 generates better code (inline,
   //no subroutine call or looping).
   //
   //Notes on optimization:  can shift 32 bit data until result is provably <=65535 then 
   //shift only lower 16 bits.  Also, can assign bytes downward, giving a shift of 8,
   //then do remaining two shifts.
   rv >>= 1;  //1
   rv >>= 1;  //2
   rv >>= 1;  //3
   rv >>= 1;  //4
   rv >>= 1;  //5
   rv >>= 1;  //6
   rv >>= 1;  //7
   rv >>= 1;  //8
   rv >>= 1;  //9
   rv >>= 1;  //10
   
   //At this point it should be impossible for the result to exceed 1024.  The reason is that
   //1024 * 1024 + 511 = 1,049,087, and dividing this by 1024 should give via shifting
   //1024.  However, need to check this during unit test.
   return(rv);
   }

//-------------------------------------------------------------------------------
//End of $Id: fpum1024umulrrxx.c,v 1.5 2010/02/22 17:52:59 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: fpum1024umulrrxx.c,v $
//Revision 1.5  2010/02/22 17:52:59  dashley
//Comments removed.
//
//Revision 1.4  2010/02/22 15:52:44  dashley
//Function name change.
//
//Revision 1.3  2010/01/30 23:21:43  dashley
//Addition of UcuFpUm1024uMulFRxx() function.
//
//Revision 1.2  2010/01/22 17:40:55  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 17:40:34  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

