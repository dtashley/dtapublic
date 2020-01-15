//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16ratadjrrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_atu16ratadjrrxx.c,v 1.4 2010/02/09 16:48:17 dashley Exp $
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
#define MODULE_UTFU_ATU16RATADJRRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_atu16ratadjrrxx.h"


typedef struct
   {
   UCU_UINT16  arg;
   UCU_UINT16  arg_max;
   UCU_UINT16  adj_in;
   UCU_UINT16  adj_nom;
   UCU_UINT16  expected_result;
   } ATU16RATADJRRXX_TV;


//This is the table of test vectors.
//
const ATU16RATADJRRXX_TV AtU16RatAdjRRxx_Tvs[] =
   {
      //adj_in=0 with arg=0 should result in 0.
      {     0,   2000,      0,   3000,      0},
      //adj_in=0 with arg=1023 should result in 2057.
      {  1023,   2057,      0,   3000,   2057},
      //adj_nom=0 should result in 0.
      {  1023,   2057,   3000,      0,      0},
      //Max multiplicative result case.
      { 65535,  65535,  65535,  65535,  65535},
      //Clip at arg_max case.
      {  1000,   1900,   8000,  20000,   1900},
      //Rounding cases.
      {  1000,   1900,  20010,  20000,   1000},
      {  1000,   1900,  20011,  20000,    999},
   };


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnAtU16RatAdjRRxx(void)
   {
   return(sizeof(AtU16RatAdjRRxx_Tvs)/sizeof(AtU16RatAdjRRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspAtU16RatAdjRRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT16  arg;
   UCU_UINT16  arg_max;
   UCU_UINT16  adj_in;
   UCU_UINT16  adj_nom;
   UCU_BOOLEAN actual_value;

   //Error out if the index is invalid.
   //
   if (test_no >= (sizeof(AtU16RatAdjRRxx_Tvs)/sizeof(AtU16RatAdjRRxx_Tvs[0])))
      {
      while(UCU_TRUE)  //Can't allow this scenario and dereference an invalid vector.
         ;
      }

   //Fetch the parameters.  This removes all of the array indexing and so on from the
   //elapsed time calculation.
   arg            = AtU16RatAdjRRxx_Tvs[test_no].arg;
   arg_max        = AtU16RatAdjRRxx_Tvs[test_no].arg_max;
   adj_in         = AtU16RatAdjRRxx_Tvs[test_no].adj_in;
   adj_nom        = AtU16RatAdjRRxx_Tvs[test_no].adj_nom;
   
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   actual_value = UcuAtU16RatAdjRRxx(arg, arg_max, adj_in, adj_nom);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAtU16RatAdjRRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT16  arg;
   UCU_UINT16  arg_max;
   UCU_UINT16  adj_in;
   UCU_UINT16  adj_nom;
   UCU_UINT16  expected_result;
   UCU_UINT16  actual_result;

   rv = UCU_TRUE;

   for (i=0; i<(sizeof(AtU16RatAdjRRxx_Tvs)/sizeof(AtU16RatAdjRRxx_Tvs[0])); i++)
      {
      arg             = AtU16RatAdjRRxx_Tvs[i].arg;
      arg_max         = AtU16RatAdjRRxx_Tvs[i].arg_max;
      adj_in          = AtU16RatAdjRRxx_Tvs[i].adj_in;
      adj_nom         = AtU16RatAdjRRxx_Tvs[i].adj_nom;
      expected_result = AtU16RatAdjRRxx_Tvs[i].expected_result;

      actual_result = UcuAtU16RatAdjRRxx(arg, arg_max, adj_in, adj_nom);

      if (actual_result != expected_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_atu16ratadjrrxx.c,v $
//Revision 1.4  2010/02/09 16:48:17  dashley
//Test vectors updated, unit test completed.
//
//Revision 1.3  2010/02/09 16:19:12  dashley
//Edits.
//
//Revision 1.2  2010/02/09 16:05:10  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/09 16:01:15  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_atu16ratadjrrxx.c,v $
//-------------------------------------------------------------------------------

