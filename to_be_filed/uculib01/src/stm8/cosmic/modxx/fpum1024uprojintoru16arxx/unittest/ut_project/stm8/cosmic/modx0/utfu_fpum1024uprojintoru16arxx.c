//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/fpum1024uprojintoru16arxx/unittest/ut_project/stm8/cosmic/modx0/utfu_fpum1024uprojintoru16arxx.c,v 1.4 2010/02/22 03:50:34 dashley Exp $
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
#define MODULE_UTFU_FPUM1024UPROJINTORU16ARXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_fpum1024uprojintoru16arxx.h"


typedef struct
   {
   UCU_UINT16  arg;
   UCU_UINT16  arg_outof;
   UCU_UINT16  expected_result;
   } FPUM1024UPROJINTORU16ARXX_TV;


//This is the table of test vectors.
//
const FPUM1024UPROJINTORU16ARXX_TV FpUm1024uProjIntoRU16aRxx_Tvs[] =
   {
      {  1000,   2000,    512},   //Half should give half.
      {  1000,      0,      0},   //arg_outof==0 should return 0.
      { 65535,  65535,   1024},   //Max value case.
      { 65534,  65535,   1024},   //Max value case.
      { 65533,  65535,   1024},   //Max value case.
      {     0,  65535,      0},   //Max value case.
      {     1,  65535,      0},   //Max value case.
      {     2,  65535,      0},   //Max value case.
      { 32767,  65535,    512},   //Rounding test.
      { 32768,  65535,    512},   //Rounding test.
      { 32799,  65535,    512},   //Rounding test.
      { 32800,  65535,    513},   //Rounding test.
      {     0,      1,      0},   //Extreme contraction test.
      {     1,      1,   1024},   //Extreme contraction test.
      {     0,     10,      0},   //Contraction test.
      {     1,     10,    102},   //Contraction test.
      {     2,     10,    205},   //Contraction test.
      {     3,     10,    307},   //Contraction test.
      {     4,     10,    410},   //Contraction test.
      {     5,     10,    512},   //Contraction test.
      {     6,     10,    614},   //Contraction test.
      {     7,     10,    717},   //Contraction test.
      {     8,     10,    819},   //Contraction test.
      {     9,     10,    922},   //Contraction test.
      {    10,     10,   1024},   //Contraction test.
      {    11,     10,   1024},   //Arg > Arg_outof test.
   };


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnFpUm1024uProjIntoRU16aRxx(void)
   {
   return(sizeof(FpUm1024uProjIntoRU16aRxx_Tvs)/sizeof(FpUm1024uProjIntoRU16aRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspFpUm1024uProjIntoRU16aRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT16  arg;
   UCU_UINT16  arg_outof;
   UCU_UINT16  actual_value;

   //Error out if the index is invalid.
   //
   if (test_no >= (sizeof(FpUm1024uProjIntoRU16aRxx_Tvs)/sizeof(FpUm1024uProjIntoRU16aRxx_Tvs[0])))
      {
      while(UCU_TRUE)  //Can't allow this scenario and dereference an invalid vector.
         ;
      }

   //Fetch the parameters.  This removes all of the array indexing and so on from the
   //elapsed time calculation.
   arg            = FpUm1024uProjIntoRU16aRxx_Tvs[test_no].arg;
   arg_outof      = FpUm1024uProjIntoRU16aRxx_Tvs[test_no].arg_outof;
   
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   actual_value = UcuFpUm1024uProjIntoRU16aRxx(arg, arg_outof);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuFpUm1024uProjIntoRU16aRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT16  arg;
   UCU_UINT16  arg_outof;
   UCU_UINT16  expected_result;
   UCU_UINT16  actual_result;

   rv = UCU_TRUE;

   for (i=0; i<(sizeof(FpUm1024uProjIntoRU16aRxx_Tvs)/sizeof(FpUm1024uProjIntoRU16aRxx_Tvs[0])); i++)
      {
      arg             = FpUm1024uProjIntoRU16aRxx_Tvs[i].arg;
      arg_outof       = FpUm1024uProjIntoRU16aRxx_Tvs[i].arg_outof;
      expected_result = FpUm1024uProjIntoRU16aRxx_Tvs[i].expected_result;

      actual_result = UcuFpUm1024uProjIntoRU16aRxx(arg, arg_outof);

      if (actual_result != expected_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_fpum1024uprojintoru16arxx.c,v $
//Revision 1.4  2010/02/22 03:50:34  dashley
//Unit testing passed.
//
//Revision 1.3  2010/02/22 03:27:26  dashley
//Edits.
//
//Revision 1.2  2010/02/22 03:18:02  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/22 03:17:11  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_fpum1024uprojintoru16arxx.c,v $
//-------------------------------------------------------------------------------

