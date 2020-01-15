//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/fpum1024umulrrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_fpum1024umulrrxx.c,v 1.2 2010/02/22 19:13:54 dashley Exp $
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
#define MODULE_UTFU_FPUM1024UMULRRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_fpum1024umulrrxx.h"


typedef struct
   {
   UCU_UINT16  arg1;
   UCU_UINT16  arg2;
   UCU_UINT16  expected_result;
   } FPUM1024UMULRRXX_TV;


//This is the table of test vectors.
//
const FPUM1024UMULRRXX_TV FpUm1024uMulRRxx_Tvs[] =
   {
      {     0,      0,      0},   //Zero cases.  Zero times anything should be zero.
      {     0,      1,      0},
      {     0,    500,      0},
      {     0,   1024,      0},
      {     0,  65535,      0},
      {     1,      0,      0},
      {   500,      0,      0},
      {  1024,      0,      0},
      { 65535,      0,      0},
      {  1024,      0,      0},   //Identity cases.
      {  1024,      1,      1},
      {  1024,    319,    319},
      {  1024,    700,    700},
      {  1024,   1023,   1023},
      {  1024,   1024,   1024},
      {     0,   1024,      0},
      {     1,   1024,      1},
      {   319,   1024,    319},
      {   700,   1024,    700},
      {  1023,   1024,   1023},
      {  1024,   1024,   1024},
      {  1024,     10,     10},   //Rounding tests
      {   665,     10,      6},
      {   666,     10,      7},
      {  1024,   1024,   1024},   //Maximum cases.
      {  1050,   1050,   1024},
      { 65535,  65535,   1024},
   };


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnFpUm1024uMulRRxx(void)
   {
   return(sizeof(FpUm1024uMulRRxx_Tvs)/sizeof(FpUm1024uMulRRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspFpUm1024uMulRRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT16  arg1, arg2;
   UCU_UINT16  actual_value;

   //Error out if the index is invalid.
   //
   if (test_no >= (sizeof(FpUm1024uMulRRxx_Tvs)/sizeof(FpUm1024uMulRRxx_Tvs[0])))
      {
      while(UCU_TRUE)  //Can't allow this scenario and dereference an invalid vector.
         ;
      }

   //Fetch the parameters.  This removes all of the array indexing and so on from the
   //elapsed time calculation.
   arg1           = FpUm1024uMulRRxx_Tvs[test_no].arg1;
   arg2           = FpUm1024uMulRRxx_Tvs[test_no].arg2;
   
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   actual_value = UcuFpUm1024uMulRRxx(arg1, arg2);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuFpUm1024uMulRRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT16  arg1, arg2;
   UCU_UINT16  expected_result;
   UCU_UINT16  actual_result;

   rv = UCU_TRUE;

   for (i=0; i<(sizeof(FpUm1024uMulRRxx_Tvs)/sizeof(FpUm1024uMulRRxx_Tvs[0])); i++)
      {
      arg1            = FpUm1024uMulRRxx_Tvs[i].arg1;
      arg2            = FpUm1024uMulRRxx_Tvs[i].arg2;
      expected_result = FpUm1024uMulRRxx_Tvs[i].expected_result;

      actual_result = UcuFpUm1024uMulRRxx(arg1, arg2);

      if (actual_result != expected_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_fpum1024umulrrxx.c,v $
//Revision 1.2  2010/02/22 19:13:54  dashley
//Edits.
//
//Revision 1.1  2010/02/22 18:59:13  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_fpum1024umulrrxx.c,v $
//-------------------------------------------------------------------------------

