//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu32bitcardrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_btu32bitcardrxx.c,v 1.3 2010/02/12 16:39:34 dashley Exp $
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
#define MODULE_UTFU_BTU32BITCARDRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_btu32bitcardrxx.h"


typedef struct
   {
   UCU_UINT32  arg;
      //It isn't necessary to store any expected results along with the test vectors because 
      //for the function involved, the program can check itself.
   } BTU32BITCARDRXX_TV;


//This is the table of test vectors.
//
const BTU32BITCARDRXX_TV BtU32BitCardRxx_Tvs[] =
   {
      { 0x00000000UL },  //Zero, obvious choice.
      { 0xFFFFFFFFUL },  //All 1's, obvious choice.
      { 0x01000000UL },  //1's in first byte only.
      { 0x00010000UL },  //1's in second byte only.
      { 0x00000100UL },  //1's in third byte only.
      { 0x00000001UL },  //1's in fourth byte only.
      { 0xF7000000UL },  //7 1's in first byte only.
      { 0x00F70000UL },  //7 1's in second byte only.
      { 0x0000F700UL },  //7 1's in third byte only.
      { 0x000000F7UL },  //7 1's in fourth byte only.
   };


//Counts the number of bits in a UCU_UINT32.
//
static UCU_UINT8 uint32_cardinality(UCU_UINT32 arg)
   {
   UCU_UINT8 i;
   UCU_UINT8 rv;

   rv = 0;

   for (i=0; i<32; i++)
      {
      if (arg & 1)
         rv++;
 
      arg >>= 1;
      }

   return(rv);
   }


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnBtU32BitCardRxx(void)
   {
   return(sizeof(BtU32BitCardRxx_Tvs)/sizeof(BtU32BitCardRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspBtU32BitCardRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT32 arg;
   UCU_UINT8  rv;

   //Can't allow a test vector with the index too large.  This would indicate a
   //logical error on the part of the caller.
   //
   if (test_no > (sizeof(BtU32BitCardRxx_Tvs)/sizeof(BtU32BitCardRxx_Tvs[0])))
      {
      while (1) ;
      }

   //Form the argument.
   arg = BtU32BitCardRxx_Tvs[test_no].arg;
      
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   rv = UcuBtU32BitCardRxx(arg);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuBtU32BitCardRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT32  arg;
   UCU_UINT8   func_result;
   UCU_UINT8   calcd_result;

   rv = UCU_TRUE;

   for (i=0; i < sizeof(BtU32BitCardRxx_Tvs)/sizeof(BtU32BitCardRxx_Tvs[0]); i++)
      {
      arg = BtU32BitCardRxx_Tvs[i].arg;

      func_result  = UcuBtU32BitCardRxx(arg);

      calcd_result = uint32_cardinality(arg);

      if (func_result != calcd_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_btu32bitcardrxx.c,v $
//Revision 1.3  2010/02/12 16:39:34  dashley
//Unit testing complete.
//
//Revision 1.2  2010/02/12 16:22:53  dashley
//Edits.
//
//Revision 1.1  2010/02/12 14:53:31  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_btu32bitcardrxx.c,v $
//-------------------------------------------------------------------------------

