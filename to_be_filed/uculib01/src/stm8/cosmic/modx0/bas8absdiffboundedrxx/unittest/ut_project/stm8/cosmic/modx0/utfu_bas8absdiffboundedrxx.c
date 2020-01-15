//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/bas8absdiffboundedrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_bas8absdiffboundedrxx.c,v 1.3 2010/03/18 15:50:08 dashley Exp $
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
#define MODULE_UTFU_BAS8ABSDIFFBOUNDEDRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_bas8absdiffboundedrxx.h"


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnBaS8AbsDiffBoundedRxx(void)
   {
   return(65536);
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspBaS8AbsDiffBoundedRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT8 arg1unsigned, arg2unsigned;
   UCU_SINT8 arg1, arg2;
   UCU_SINT8 rv;

   arg1unsigned = test_no >> 8;
   arg2unsigned = test_no;
   arg1 = arg1unsigned;
   arg2 = arg2unsigned;
      
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   rv = UcuBaS8AbsDiffBoundedRxx(arg1, arg2);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuBaS8AbsDiffBoundedRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_SINT16  i, j, predicted_value_long;
   UCU_SINT8   arg1, arg2, predicted_value_short;
   UCU_SINT8   result;

   rv = UCU_TRUE;

   for (i=-128; i<128; i++)
      {
      for (j=-128; j<128; j++)
         {
         arg1 = i;
         arg2 = j;
         result = UcuBaS8AbsDiffBoundedRxx(arg1, arg2);

         predicted_value_long = i - j;
         if (predicted_value_long <= -128)
            predicted_value_short = 127;
         else if (predicted_value_long >= 127)
            predicted_value_short = 127;
         else if (predicted_value_long < 0)
            predicted_value_short = - predicted_value_long;
         else
            predicted_value_short = predicted_value_long;

         if (result != predicted_value_short)
            rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_bas8absdiffboundedrxx.c,v $
//Revision 1.3  2010/03/18 15:50:08  dashley
//Unit testing completed.
//
//Revision 1.2  2010/03/18 15:28:15  dashley
//Extra line removed.
//
//Revision 1.1  2010/03/18 15:27:08  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_bas8absdiffboundedrxx.c,v $
//-------------------------------------------------------------------------------

