//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/fpum1024uprojintoru16arxx/src/fpum1024uprojintoru16arxx.c,v 1.6 2010/02/22 02:40:27 dashley Exp $
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


UCU_UINT16 UcuFpUm1024uProjIntoRU16aRxx(UCU_UINT16 arg, UCU_UINT16 arg_outof)
   {
   UCU_UINT32 rv;

   if (arg_outof == 0)
      {
      return(0);
      }
   else if (arg >= arg_outof)
      {
      return(1024);
      }
   else
      {
      rv    = arg;
         //Start with the 32-bit version of the input.
      rv  <<= 1;  // 1
      rv  <<= 1;  // 2
      rv  <<= 1;  // 3
      rv  <<= 1;  // 4
      rv  <<= 1;  // 5
      rv  <<= 1;  // 6
      rv  <<= 1;  // 7
      rv  <<= 1;  // 8
      rv  <<= 1;  // 9
      rv  <<= 1;  //10
         //Shift left 10 bits, effectively multiplying by 1024.  It was found from
         //earlier similar constructs that separating the shifts generates more
         //time-efficient code.  This could be optimized by rearranging bytes
         //(giving a left shift of 8), then doing the remaining 2 by shifting.
         //Also, because of the constrained input, the whole 32-bit quantity
         //may not need to be shifted for all of the left shifts.
         
      rv += ((arg_outof-1) >> 1);
         //The subtraction can't underflow because arg_outof==0 was tested
         //earlier.
         //
         //The addition step above can't overflow.  We only multiplied by 1024,
         //so we can't be in striking distance of 2**32.

      rv /= arg_outof;
      return(rv);
      }
   }

//-------------------------------------------------------------------------------
//End of $Id: fpum1024uprojintoru16arxx.c,v 1.6 2010/02/22 02:40:27 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: fpum1024uprojintoru16arxx.c,v $
//Revision 1.6  2010/02/22 02:40:27  dashley
//Comments added.
//
//Revision 1.5  2010/02/21 04:55:49  dashley
//a)Comments removed.
//b)Rounding rewritten.
//c)Unnecessary guards on inputs removed.
//
//Revision 1.4  2010/02/01 18:01:13  dashley
//FpUm1024uProjIntoU16aRxx() renamed to FpUm1024uProjIntoRU16aRxx() to
//reflect that fact that output is rounded.
//
//Revision 1.3  2010/01/30 21:52:37  dashley
//Addition of UcuFpUm1024uProjIntoU16aRxx() function.
//
//Revision 1.2  2010/01/22 16:59:08  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 16:58:45  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

