//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/ats32s16v2cpdiva2frxx/src/ats32s16v2cpdiva2frxx.c,v 1.3 2010/04/16 15:38:59 dashley Exp $
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

UCU_SINT32 UcuAtS32S16v2CpDiva2FRxx(UCU_SINT16 a_x, 
                                    UCU_SINT16 a_y,
                                    UCU_SINT16 b_x,
                                    UCU_SINT16 b_y)
   {
   UCU_SINT32  cross_product;
   UCU_BOOLEAN cp_is_negative;
   UCU_UINT32  denominator;
   UCU_UINT32  quotient;
   UCU_UINT16  square_root;
   UCU_UNION64 numerator;

   //If both b_x and b_y are zero, we can't establish direction of the vector and will
   //have a zero denominator.  Must return 0.
   if ((! b_x) && (! b_y))
      return(0);

   //Calculate the signed magnitude of the cross product.  The maximum
   //magnitude is 2^31-2^15, so it can't reach the maximum negative
   //integer for a UCU_SINT32.
   cross_product = UcuAtS32S16v2CpRxx(a_x, a_y, b_x, b_y);

   //Adjust if the cross-product is negative.  It might seem like it is unnececessary
   //to call custom functions here, but the compiler does a suboptimal
   //job on negation of S32's.
   if (UcuAtS32IsNegRxx(cross_product))
      {
      //The cross-product is negative.  Remember this and form the negation (the absolute
      //value in this context).  We can't overflow because the variable can't reach the
      //negative limit of -2^31.
      cp_is_negative = UCU_TRUE;
      cross_product  = UcuAtS32NegationRxx(cross_product);
      }
   else
      {
      //The cross-product is not negative.  Remember this.
      cp_is_negative = UCU_FALSE;
      }

   //Load the absolute value of the cross-product into the 64-bit buffer for squaring
   //in place.  The upper 32 bits are ignored and don't need to be touched.
   numerator.ula.ul[1] = (UCU_UINT32)cross_product;

   //Square the absolute value of the cross-product.  This completes the calculation
   //of the numerator.
   UcuLoU64U32SquareInPlaceRxn(&numerator);

   //Calculate the denominator.  This is a sum of squares.  Because we know that
   //b_x and b_y can't both be zero (this was tested earlier), the result here
   //is guaranteed to be greater than zero.
   denominator = UcuAtU32S16v2MagSquaredRxx(b_x, b_y);

   //Form the floor of the quotient.  It can be proved mathematically that
   //that quotient cannot exceed a 32-bit unsigned integer (despite the 64-bit
   //unsigned dividend).
   UcuLoU32U64U32DivQFRxn(&quotient, &numerator, &denominator);

   //Take the square root.  We are re-using the cross-product variable as the
   //return value also.
   // 
   //It is obvious intuitively that the square root might exceed the magnitude
   //available for an S16.  Two long vectors inclined at 45 degrees would
   //give a magnitude too big by a factor of approximately sqrt(2).  However,
   //this result won't exceed the range for an S32.
   cross_product = UcuAtU32SqrtFRxx(quotient);

   //Restore the sign of the cross-product.  This will probably be discarded
   //by the caller by taking the absolute value, but it is part of the definition
   //of this function.
   if (cp_is_negative)
      cross_product = UcuAtS32NegationRxx(cross_product);

   //Return the expected value to the caller.
   return(cross_product);
   }

//-------------------------------------------------------------------------------
//End of $Id: ats32s16v2cpdiva2frxx.c,v 1.3 2010/04/16 15:38:59 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: ats32s16v2cpdiva2frxx.c,v $
//Revision 1.3  2010/04/16 15:38:59  dashley
//Addition of zero tests for b_x and b_y, and additional documentation.
//
//Revision 1.2  2010/04/15 21:01:00  dashley
//Edits.
//
//Revision 1.1  2010/04/15 20:17:59  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

