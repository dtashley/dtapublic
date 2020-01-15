//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/ats32s16v2cprxx/unittest/ut_project/stm8/cosmic/modx0/utfu_ats32s16v2cprxx.c,v 1.3 2010/04/14 21:44:41 dashley Exp $
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
#define MODULE_UTFU_ATS32S16V2CPRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_ats32s16v2cprxx.h"


//Individual test vector.
typedef struct
   {
   UCU_SINT16  a_x;
   UCU_SINT16  a_y;
   UCU_SINT16  b_x;
   UCU_SINT16  b_y;
   UCU_SINT32  er;   //Expected result
   } ATS32S16V2CPRXX_TV;


//This is the table of test vectors.
//
const ATS32S16V2CPRXX_TV AtS32S16v2CpRxx_Tvs[] =
   {
      //Calling convention check.
      {       1,        2,        3,        4,        5},  //Test to check stacking order.
   };



//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnAtS32S16v2CpRxx(void)
   {
   return(sizeof(AtS32S16v2CpRxx_Tvs)/sizeof(AtS32S16v2CpRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspAtS32S16v2CpRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT16 a_x, a_y, b_x, b_y;
   UCU_SINT32 rv;

   if (test_no >= (sizeof(AtS32S16v2CpRxx_Tvs)/sizeof(AtS32S16v2CpRxx_Tvs[0])))
      {
      while(1);  //Deliberately hang on invalid vector number.
      }

   //Retrieve the parameters.
   a_x = AtS32S16v2CpRxx_Tvs[test_no].a_x;
   a_y = AtS32S16v2CpRxx_Tvs[test_no].a_y;
   b_x = AtS32S16v2CpRxx_Tvs[test_no].b_x;
   b_y = AtS32S16v2CpRxx_Tvs[test_no].b_y;
      
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   rv = UcuAtS32S16v2CpRxx(a_x, a_y, b_x, b_y);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAtS32S16v2CpRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_SINT16  a_x, a_y, b_x, b_y;
   UCU_SINT32  actual_result, expected_result;

   rv = UCU_TRUE;

   //The following test vectors are partially to have the function calls manually examined.  The same
   //test will be run again in the loops.
   //-------------------
   actual_result = UcuAtS32S16v2CpRxx(1, 2, 3, 4);
   if (actual_result != 0)
      rv = UCU_FALSE;
   //-------------------

   for (i=0; i<(sizeof(AtS32S16v2CpRxx_Tvs)/sizeof(AtS32S16v2CpRxx_Tvs[0])); i++)
      {
      //Retrieve the parameters and expected result.
      a_x             = AtS32S16v2CpRxx_Tvs[i].a_x;
      a_y             = AtS32S16v2CpRxx_Tvs[i].a_y;
      b_x             = AtS32S16v2CpRxx_Tvs[i].b_x;
      b_y             = AtS32S16v2CpRxx_Tvs[i].b_y;
      expected_result = AtS32S16v2CpRxx_Tvs[i].er;

      //Make the call, capture the result.
      actual_result = UcuAtS32S16v2CpRxx(a_x, a_y, b_x, b_y);

      //If the result is not as expected, generate test failure.
      if (actual_result != expected_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_ats32s16v2cprxx.c,v $
//Revision 1.3  2010/04/14 21:44:41  dashley
//Edits.
//
//Revision 1.2  2010/04/14 15:47:40  dashley
//Extra line removed.
//
//Revision 1.1  2010/04/14 15:46:40  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_ats32s16v2cprxx.c,v $
//-------------------------------------------------------------------------------

