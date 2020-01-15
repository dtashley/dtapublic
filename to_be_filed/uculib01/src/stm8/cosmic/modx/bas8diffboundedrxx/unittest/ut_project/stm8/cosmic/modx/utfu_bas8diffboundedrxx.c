//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx/bas8diffboundedrxx/unittest/ut_project/stm8/cosmic/modx/utfu_bas8diffboundedrxx.c,v 1.2 2010/02/18 19:58:53 dashley Exp $
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
#define MODULE_UTFU_BAS8DIFFBOUNDEDRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_bas8diffboundedrxx.h"


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnBaS8DiffBoundedRxx(void)
   {
   return(65536);
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspBaS8DiffBoundedRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
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
   rv = UcuBaS8DiffBoundedRxx(arg1, arg2);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuBaS8DiffBoundedRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_SINT16  i, j, predicted_value_long;
   UCU_SINT8   arg1, arg2, predicted_value_short;
   UCU_SINT8   result;

   rv = UCU_TRUE;

   //The following test vectors are partially to have the function calls manually examined.  The same
   //test will be run again in the loops.
   //-------------------
   result = UcuBaS8DiffBoundedRxx(   0,    0);
   if (result != 0)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx(   0, -101);
   if (result != 101)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx(   0,  101);
   if (result != -101)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx(   0, -127);
   if (result != 127)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx(   0, -128);
   if (result != 127)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx( 101,   20);
   if (result != 81)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx( 101,  -20);
   if (result != 121)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx( 101,  -30);
   if (result != 127)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx(-101,  -20);
   if (result != -81)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx(-101,   20);
   if (result != -121)
      rv = UCU_FALSE;
   //-------------------
   result = UcuBaS8DiffBoundedRxx(-101,   30);
   if (result != -128)
      rv = UCU_FALSE;
   //-------------------

   for (i=-128; i<128; i++)
      {
      for (j=-128; j<128; j++)
         {
         arg1 = i;
         arg2 = j;
         result = UcuBaS8DiffBoundedRxx(arg1, arg2);

         predicted_value_long = i-j;
         if (predicted_value_long <= -128)
            predicted_value_short = -128;
         else if (predicted_value_long >= 127)
            predicted_value_short = 127;
         else
            predicted_value_short = predicted_value_long;

         if (result != predicted_value_short)
            rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_bas8diffboundedrxx.c,v $
//Revision 1.2  2010/02/18 19:58:53  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/18 19:57:58  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_bas8diffboundedrxx.c,v $
//-------------------------------------------------------------------------------

