//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atatanix100odegx1rrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_atatanix100odegx1rrxx.c,v 1.3 2010/02/21 00:10:50 dashley Exp $
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
#define MODULE_UTFU_ATATANIX100ODEGX1RRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_atatanix100odegx1rrxx.h"


typedef struct
   {
   UCU_UINT16  arg;
   UCU_UINT8   expected_result;
   } ATATANIX100ODEGX1RRXX_TV;


//This is the table of test vectors.
//
const ATATANIX100ODEGX1RRXX_TV AtAtanIx100Odegx1RRxx_Tvs[] =
   {
      {     0,      0},
      {     1,      1},
      {     2,      1},
      {     3,      2},
      {     4,      2},
      {     5,      3},
      {     6,      3},
      {     7,      4},
      {     8,      5},
      {     9,      5},
      {    10,      6},
      { 11458,     89},
      { 11459,     90},
      { 65534,     90},
      { 65535,     90},
   };


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnAtAtanIx100Odegx1RRxx(void)
   {
   return(sizeof(AtAtanIx100Odegx1RRxx_Tvs)/sizeof(AtAtanIx100Odegx1RRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspAtAtanIx100Odegx1RRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT16  arg;
   UCU_UINT8   actual_value;

   //Error out if the index is invalid.
   //
   if (test_no >= (sizeof(AtAtanIx100Odegx1RRxx_Tvs)/sizeof(AtAtanIx100Odegx1RRxx_Tvs[0])))
      {
      while(UCU_TRUE)  //Can't allow this scenario and dereference an invalid vector.
         ;
      }

   //Fetch the parameters.  This removes all of the array indexing and so on from the
   //elapsed time calculation.
   arg            = AtAtanIx100Odegx1RRxx_Tvs[test_no].arg;
   
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   actual_value = UcuAtAtanIx100Odegx1RRxx(arg);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAtAtanIx100Odegx1RRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT16  arg;
   UCU_UINT8   expected_result;
   UCU_UINT8   actual_result;

   rv = UCU_TRUE;

   for (i=0; i<(sizeof(AtAtanIx100Odegx1RRxx_Tvs)/sizeof(AtAtanIx100Odegx1RRxx_Tvs[0])); i++)
      {
      arg             = AtAtanIx100Odegx1RRxx_Tvs[i].arg;
      expected_result = AtAtanIx100Odegx1RRxx_Tvs[i].expected_result;

      actual_result = UcuAtAtanIx100Odegx1RRxx(arg);

      if (actual_result != expected_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_atatanix100odegx1rrxx.c,v $
//Revision 1.3  2010/02/21 00:10:50  dashley
//Edits.
//
//Revision 1.2  2010/02/20 23:26:14  dashley
//Edits.
//
//Revision 1.1  2010/02/20 23:21:37  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_atatanix100odegx1rrxx.c,v $
//-------------------------------------------------------------------------------

