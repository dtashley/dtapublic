//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16v2cpdiva2frxx/src/atu16v2cpdiva2frxx.c,v 1.5 2010/02/19 17:27:27 dashley Exp $
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

UCU_UINT16 UcuAtU16v2CpDiva2FRxx(UCU_UINT16 in_a_vec_1, 
                                 UCU_UINT16 in_a_vec_2,
                                 UCU_UINT16 in_g_vec_1,
                                 UCU_UINT16 in_g_vec_2)
   {
   UCU_BOOLEAN_C99 avec1_is_neg = UCU_FALSE;
   UCU_BOOLEAN_C99 avec2_is_neg = UCU_FALSE;
   UCU_BOOLEAN_C99 gvec1_is_neg = UCU_FALSE;
   UCU_BOOLEAN_C99 gvec2_is_neg = UCU_FALSE;
      //Used to remember the signs of the input arguments.  Only their absolute values are
      //retained in the calculations.

   UCU_BOOLEAN_C99 lup_is_neg;
   UCU_BOOLEAN_C99 rup_is_neg;
      //Used to remember if the left and right upper products are negative.  This will
      //simplify the Boolean algebra.  The left upper product is a1*g2, and the right
      //upper product is g1*a2.  (These come from the definition of vector cross-product.)

   UCU_UINT16 g_mag_x10;
      //The magnitude of the gravitational vector, x10.

   UCU_UINT32 left_upper_product;
      //The term a1*g2 from the definition of vector cross-product.

   UCU_UINT32 right_upper_product;
      //The term g1*a2 from the definition of vector cross-product.

   UCU_UINT32 upper_sum_x10;
      //The absolute value of the upper sum (a1*g2 - g1*a2), x10.

   UCU_UINT32 u32temp1, u32temp2;
      //Unsigned 32-bit temporary variables.


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Clip, retain the signs, and take the absolute values of each of the input arguments.
   //The "excess-4096" representation is discarded in favor of a sign-magnitude representation,
   //with the sign maintained separately in an auxiliary variable.  The hope is that doing this
   //is at least a zero-sum move, as it causes simpler and fewer arithmetic functions to be called.
   /*
   ** in_a_vec_1
   */
   if (in_a_vec_1 >= 4096)
      {
      //Non-negative
      if (in_a_vec_1 > 8160)
         {
         //Component is too positive.
         in_a_vec_1   = 4064;               //Clip at +127 * 32.
         }
      else
         {
         //Component is simple positive.
         in_a_vec_1   = in_a_vec_1 - 4096;  //Subtract excess-4096 offset.
         }
      }
   else
      {
      //Negative
      avec1_is_neg = UCU_TRUE;              //Negative.

      if (in_a_vec_1 < 32)
         {
         //Component is too negative.
         in_a_vec_1   = 4064;               //Clip at abs(-127 * 32).
         }
      else
         {
         //Component is simple negative.
         in_a_vec_1   = 4096 - in_a_vec_1;  //Take absolute value.
         }
      }

   /*
   ** in_a_vec_2
   */
   if (in_a_vec_2 >= 4096)
      {
      //Non-negative
      if (in_a_vec_2 > 8160)
         {
         //Component is too positive.
         in_a_vec_2   = 4064;               //Clip at +127 * 32.
         }
      else
         {
         //Component is simple positive.
         in_a_vec_2   = in_a_vec_2 - 4096;  //Subtract excess-4096 offset.
         }
      }
   else
      {
      //Negative
      avec2_is_neg = UCU_TRUE;              //Negative.

      if (in_a_vec_2 < 32)
         {
         //Component is too negative.
         in_a_vec_2   = 4064;               //Clip at abs(-127 * 32).
         }
      else
         {
         //Component is simple negative.
         in_a_vec_2   = 4096 - in_a_vec_2;  //Take absolute value.
         }
      }

   /*
   ** in_g_vec_1
   */
   if (in_g_vec_1 >= 4096)
      {
      //Non-negative
      if (in_g_vec_1 > 8160)
         {
         //Component is too positive.
         in_g_vec_1   = 4064;               //Clip at +127 * 32.
         }
      else
         {
         //Component is simple positive.
         in_g_vec_1   = in_g_vec_1 - 4096;  //Subtract excess-4096 offset.
         }
      }
   else
      {
      //Negative
      gvec1_is_neg = UCU_TRUE;              //Negative.

      if (in_g_vec_1 < 32)
         {
         //Component is too negative.
         in_g_vec_1   = 4064;               //Clip at abs(-127 * 32).
         }
      else
         {
         //Component is simple negative.
         in_g_vec_1   = 4096 - in_g_vec_1;  //Take absolute value.
         }
      }

   /*
   ** in_g_vec_2
   */
   if (in_g_vec_2 >= 4096)
      {
      //Non-negative
      if (in_g_vec_2 > 8160)
         {
         //Component is too positive.
         in_g_vec_2   = 4064;               //Clip at +127 * 32.
         }
      else
         {
         //Component is simple positive.
         in_g_vec_2   = in_g_vec_2 - 4096;  //Subtract excess-4096 offset.
         }
      }
   else
      {
      //Negative
      gvec2_is_neg = UCU_TRUE;              //Negative.

      if (in_g_vec_2 < 32)
         {
         //Component is too negative.
         in_g_vec_2   = 4064;               //Clip at abs(-127 * 32).
         }
      else
         {
         //Component is simple negative.
         in_g_vec_2   = 4096 - in_g_vec_2;  //Take absolute value.
         }
      }


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //If the gravitational vector is 0, we can't establish magnitude or direction or do the
   //division, so must return 0.
   if ((in_g_vec_1 == 0) && (in_g_vec_2 == 0))
      return(0);


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Normalize the gravitational vector to get the best accuracy in calculations, and protect
   //against "g" vectors that are very short but perhaps pointed in the right direction.  The
   //limiting factor in calculation accuracy is calculating the magnitude of g and dividing
   //by it.  A g with small magnitude will introduce accuracy problems.
   //
   //We keep multiplying by two until the absolute value of at least one component reaches
   //1024 or better.  The loop will definitely terminate, as we've established that
   //at least one component is non-zero.
   //
   //The reason for choosing 1024 (rather than 2048) is that if the value is 2047 (for example),
   //left-shifting will give 4094, which is larger than the 4064 = 127*32, the largest value
   //we assume is possible numerically.  1024 is 32 counts from the accelerometer, or
   //0.57g's nominally.
   // 
   //Note that the normalization won't won't affect the theoretical result, as the magnitude of
   //"g" does not affect the theoretical result (only the direction).  The portion of the
   //calculation sensitive to a too-small "g" is the magnitude calculation.
   //
   while (!(in_g_vec_1 & ~1023U) && !(in_g_vec_2 & ~1023U))
      {
      in_g_vec_1 <<= 1;
      in_g_vec_2 <<= 1;
      }


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Calculate the g magnitude x 10.  We can't re-use any of the intermediate results, so just
   //do the magnitude calculation directly.
   //
   //For each of the "g" components, the maximum value is 4064, so the maximum sum of squares
   //is 33,032,192.  The shift by 10 divides by 1024, giving a maximum of 32,258.  I'd like to
   //shift by only 9, but that division is harder to undo after the square root is calculated,
   //so easier to divide by an even power of 2 (which is necessarily a square).
   // 
   //The left shift by 5 undoes the adjustment by 1024 before the square root is taken (32 is the
   //square root of 1024).
   // 
   //The square root of 32,258 is 179.6, so we can't get a value out of the square root function
   //larger than 1800.  1800 shifted right by 5 is 57,600, which is within the range of a UINT16.
   //
   g_mag_x10 = UcuAtU16SqrtX10FRxx(
                                     (
                                        (
                                           (UCU_UINT32)in_g_vec_1 * (UCU_UINT32)in_g_vec_1
                                        ) 
                                        + 
                                        (
                                           (UCU_UINT32)in_g_vec_2 * (UCU_UINT32)in_g_vec_2
                                        )
                                     ) 
                                     >> 
                                     10
                                  ) 
                                  <<
                                  5;


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Be absolutely sure that the denominator of our future division isn't zero.  That
   //shouldn't ever happen because of the g vector normalization (which will ensure that for
   //a non-zero g vector, at least one component will be 1024 or larger), but need to be sure.
   //In such a case, must return 0.
   if (g_mag_x10 == 0)
      return(0);


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Calculate the absolute value of the left upper product.  This potentially will exceed 16
   //bits.  Had to assign temporary variables to avoid a "PANIC!" error from the compiler.
   u32temp1 = in_a_vec_1;
   u32temp2 = in_g_vec_2;
   
   left_upper_product = u32temp1 * u32temp2;


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Calculate the absolute value of the right upper product.  This potentially will exceed 16
   //bits.  Had to assign temporary variables to avoid a "PANIC!" error from the compiler.
   u32temp1 = in_g_vec_1;
   u32temp2 = in_a_vec_2;
   
   right_upper_product = u32temp1 * u32temp2;


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Figure out if the left upper product is negative.  This is used to simplify the Boolean
   //algebra.
   if ((!avec1_is_neg && !gvec2_is_neg) || (avec1_is_neg && gvec2_is_neg))
      lup_is_neg = UCU_FALSE;
   else
      lup_is_neg = UCU_TRUE;


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Figure out if the right upper product is negative.  This is used to simplify the Boolean
   //algebra.
   if ((!gvec1_is_neg && !avec2_is_neg) || (gvec1_is_neg && avec2_is_neg))
      rup_is_neg = UCU_FALSE;
   else
      rup_is_neg = UCU_TRUE;


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Calculate the upper sum.  This is a bit complicated because there are 8 possibilities of the
   //underlying variables.  Must do a truth table followed by two Karnaugh maps, one for each
   //function.  "X" below means "don't care" in the traditional digital logic sense.
   //
   // |abs(right) | lup    | rup    || Invert      | Add Rather |
   // |  >        | is     | is     || Subtraction | Than       |
   // |abs(left)  | neg    | neg    || Order       | Subtract   |
   // +-----------+--------+--------++-------------+------------+
   // |     F     |    F   |    F   ||      F      |     F      |
   // +-----------+--------+--------++-------------+------------+
   // |     F     |    F   |    T   ||      X      |     T      |
   // +-----------+--------+--------++-------------+------------+
   // |     F     |    T   |    F   ||      X      |     T      |
   // +-----------+--------+--------++-------------+------------+
   // |     F     |    T   |    T   ||      F      |     F      |
   // +-----------+--------+--------++-------------+------------+
   // +-----------+--------+--------++-------------+------------+
   // |     T     |    F   |    F   ||      T      |     F      |
   // +-----------+--------+--------++-------------+------------+
   // |     T     |    F   |    T   ||      X      |     T      |
   // +-----------+--------+--------++-------------+------------+
   // |     T     |    T   |    F   ||      X      |     T      |
   // +-----------+--------+--------++-------------+------------+
   // |     T     |    T   |    T   ||      T      |     F      |
   // +-----------+--------+--------++-------------+------------+
   //
   //The Karnaugh maps for the two output functions were done by
   //hand, and are not included here.
   //
   //Reducing the two functions above, the following rules emerge:
   //   a)If the two terms are different in sign, we ALWAYS add.
   //     The reason is that a negative minus a positive makes it more
   //     negative, and a positive minus a negative makes it more
   //     positive.
   //   b)Once we've resigned ourselves to subtract, we invert the
   //     order only if the right term is greater than the left.
   if ((! lup_is_neg && rup_is_neg) || (lup_is_neg && ! rup_is_neg))
      {
      //Two signs are unequal.  Always add the two absolute values to get
      //the resultant absolute value.  We use the x10 variable to avoid
      //creating too many temporaries.
      upper_sum_x10 = left_upper_product + right_upper_product;
      }
   else if (right_upper_product > left_upper_product)
      {
      //The two signs are equal, and the magnitude of the second 
      //is greater than the first.  Use out-of-order subtraction
      //to get the absolute value of the result directly.
      upper_sum_x10 = right_upper_product - left_upper_product;
      }
   else
      {
      //The signs are equal, and the magnitude of the first is at least as
      //large as the second.  Perform in-order subtraction to get the absolute
      //value.
      upper_sum_x10 = left_upper_product - right_upper_product;
      }


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Multiply the upper sum x 10 to get the x10 result.  Shift code is probably a faster
   //than multiplication code.
   upper_sum_x10 = (upper_sum_x10 << 3) + (upper_sum_x10 << 1);


   /********************************************************************************************/
   /********************************************************************************************/
   /********************************************************************************************/
   //Return the return value.  For now, I'll clip at 65535, but it may be possible to limit
   //this algebraically and not have to do the test.
   u32temp1 = upper_sum_x10 / g_mag_x10;
   if (u32temp1 > 65535)
      u32temp1 = 65535;

   return(u32temp1);
   }

//-------------------------------------------------------------------------------
//End of $Id: atu16v2cpdiva2frxx.c,v 1.5 2010/02/19 17:27:27 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: atu16v2cpdiva2frxx.c,v $
//Revision 1.5  2010/02/19 17:27:27  dashley
//Comments removed.
//
//Revision 1.4  2010/01/31 04:18:51  dashley
//Incorrect function name corrected.
//
//Revision 1.3  2010/01/30 21:29:05  dashley
//Addition of function.
//
//Revision 1.2  2010/01/22 18:22:46  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 18:22:25  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

