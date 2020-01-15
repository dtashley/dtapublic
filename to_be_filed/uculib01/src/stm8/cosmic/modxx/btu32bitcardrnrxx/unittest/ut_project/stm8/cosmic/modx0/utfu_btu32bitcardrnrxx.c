//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu32bitcardrnrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_btu32bitcardrnrxx.c,v 1.2 2010/02/12 21:33:10 dashley Exp $
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
#define MODULE_UTFU_BTU32BITCARDRNRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_btu32bitcardrnrxx.h"


typedef struct
   {
   UCU_UINT32  arg;
   UCU_UINT8   n;
      //It isn't necessary to store any expected results along with the test vectors because 
      //for the function involved, the program can check itself.
   } BTU32BITCARDRNRXX_TV;


//This is the table of test vectors.
//
const BTU32BITCARDRNRXX_TV BtU32BitCardRnRxx_Tvs[] =
   {
      { 0x00000000UL,  0 },
      { 0xFFFFFFFFUL,  0 },
      { 0xFFFFFFFFUL,  1 },
      { 0xFFFFFFFFUL,  2 },
      { 0xFFFFFFFFUL,  3 },
      { 0xFFFFFFFFUL,  4 },
      { 0xFFFFFFFFUL,  5 },
      { 0xFFFFFFFFUL,  6 },
      { 0xFFFFFFFFUL,  7 },
      { 0xFFFFFFFFUL,  8 },
      { 0xFFFFFFFFUL,  9 },
      { 0xFFFFFFFFUL, 10 },
      { 0xFFFFFFFFUL, 11 },
      { 0xFFFFFFFFUL, 12 },
      { 0xFFFFFFFFUL, 13 },
      { 0xFFFFFFFFUL, 14 },
      { 0xFFFFFFFFUL, 15 },
      { 0xFFFFFFFFUL, 16 },
      { 0xFFFFFFFFUL, 17 },
      { 0xFFFFFFFFUL, 18 },
      { 0xFFFFFFFFUL, 19 },
      { 0xFFFFFFFFUL, 20 },
      { 0xFFFFFFFFUL, 21 },
      { 0xFFFFFFFFUL, 22 },
      { 0xFFFFFFFFUL, 23 },
      { 0xFFFFFFFFUL, 24 },
      { 0xFFFFFFFFUL, 25 },
      { 0xFFFFFFFFUL, 26 },
      { 0xFFFFFFFFUL, 27 },
      { 0xFFFFFFFFUL, 28 },
      { 0xFFFFFFFFUL, 29 },
      { 0xFFFFFFFFUL, 30 },
      { 0xFFFFFFFFUL, 31 },
      { 0xFFFFFFFFUL, 32 },
      { 0xFFFFFFFFUL, 33 },
      { 0xFFFFFFFFUL,  0 },
      { 0xFFFFFFFEUL,  1 },
      { 0xFFFFFFFCUL,  2 },
      { 0xFFFFFFF8UL,  3 },
      { 0xFFFFFFF0UL,  4 },
      { 0xFFFFFFE0UL,  5 },
      { 0xFFFFFFC0UL,  6 },
      { 0xFFFFFF80UL,  7 },
      { 0xFFFFFF00UL,  8 },
      { 0xFFFFFE00UL,  9 },
      { 0xFFFFFC00UL, 10 },
      { 0xFFFFF800UL, 11 },
      { 0xFFFFF000UL, 12 },
      { 0xFFFFE000UL, 13 },
      { 0xFFFFC000UL, 14 },
      { 0xFFFF8000UL, 15 },
      { 0xFFFF0000UL, 16 },
      { 0xFFFE0000UL, 17 },
      { 0xFFFC0000UL, 18 },
      { 0xFFF80000UL, 19 },
      { 0xFFF00000UL, 20 },
      { 0xFFE00000UL, 21 },
      { 0xFFC00000UL, 22 },
      { 0xFF800000UL, 23 },
      { 0xFF000000UL, 24 },
      { 0xFE000000UL, 25 },
      { 0xFC000000UL, 26 },
      { 0xF8000000UL, 27 },
      { 0xF0000000UL, 28 },
      { 0xE0000000UL, 29 },
      { 0xC0000000UL, 30 },
      { 0x80000000UL, 31 },
      { 0x00000000UL, 32 },
      { 0x00000000UL, 33 },
      {~0xFFFFFFFFUL,  0 },
      {~0xFFFFFFFEUL,  1 },
      {~0xFFFFFFFCUL,  2 },
      {~0xFFFFFFF8UL,  3 },
      {~0xFFFFFFF0UL,  4 },
      {~0xFFFFFFE0UL,  5 },
      {~0xFFFFFFC0UL,  6 },
      {~0xFFFFFF80UL,  7 },
      {~0xFFFFFF00UL,  8 },
      {~0xFFFFFE00UL,  9 },
      {~0xFFFFFC00UL, 10 },
      {~0xFFFFF800UL, 11 },
      {~0xFFFFF000UL, 12 },
      {~0xFFFFE000UL, 13 },
      {~0xFFFFC000UL, 14 },
      {~0xFFFF8000UL, 15 },
      {~0xFFFF0000UL, 16 },
      {~0xFFFE0000UL, 17 },
      {~0xFFFC0000UL, 18 },
      {~0xFFF80000UL, 19 },
      {~0xFFF00000UL, 20 },
      {~0xFFE00000UL, 21 },
      {~0xFFC00000UL, 22 },
      {~0xFF800000UL, 23 },
      {~0xFF000000UL, 24 },
      {~0xFE000000UL, 25 },
      {~0xFC000000UL, 26 },
      {~0xF8000000UL, 27 },
      {~0xF0000000UL, 28 },
      {~0xE0000000UL, 29 },
      {~0xC0000000UL, 30 },
      {~0x80000000UL, 31 },
      {~0x00000000UL, 32 },
      {~0x00000000UL, 33 },
      { 0x01000000UL,  1 },
      { 0x00010000UL,  2 },
      { 0x00000100UL,  3 },
      { 0x00000001UL,  4 },
      { 0xF7000000UL,  5 },
      { 0x00F70000UL,  6 },
      { 0x0000F700UL,  7 },
      { 0x000000F7UL,  8 },
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


//Mimics what the function under test should return.
static UCU_UINT8 uint32_mimic(UCU_UINT32 arg, UCU_UINT8 n)
   {
   UCU_UINT32 mask;

   mask = 0xFFFFFFFFUL;

   if (n > 32)
      n = 32;

   mask >>= (32-n);

   arg &= mask;

   return(uint32_cardinality(arg));
   }


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnBtU32BitCardRnRxx(void)
   {
   return(sizeof(BtU32BitCardRnRxx_Tvs)/sizeof(BtU32BitCardRnRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspBtU32BitCardRnRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT32 arg;
   UCU_UINT8  n;
   UCU_UINT8  rv;

   //Can't allow a test vector with the index too large.  This would indicate a
   //logical error on the part of the caller.
   //
   if (test_no > (sizeof(BtU32BitCardRnRxx_Tvs)/sizeof(BtU32BitCardRnRxx_Tvs[0])))
      {
      while (1) ;
      }

   //Form the argument.
   arg = BtU32BitCardRnRxx_Tvs[test_no].arg;

   //And the "n" value.
   n = BtU32BitCardRnRxx_Tvs[test_no].n;
      
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   rv = UcuBtU32BitCardRnRxx(arg, n);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuBtU32BitCardRnRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT32  arg;
   UCU_UINT8   n;
   UCU_UINT8   func_result;
   UCU_UINT8   calcd_result;

   rv = UCU_TRUE;

   for (i=0; i < sizeof(BtU32BitCardRnRxx_Tvs)/sizeof(BtU32BitCardRnRxx_Tvs[0]); i++)
      {
      arg = BtU32BitCardRnRxx_Tvs[i].arg;
      n   = BtU32BitCardRnRxx_Tvs[i].n;

      func_result  = UcuBtU32BitCardRnRxx(arg, n);

      calcd_result = uint32_mimic(arg, n);

      if (func_result != calcd_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_btu32bitcardrnrxx.c,v $
//Revision 1.2  2010/02/12 21:33:10  dashley
//Unit testing completed.
//
//Revision 1.1  2010/02/12 20:33:30  dashley
//Edits.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_btu32bitcardrnrxx.c,v $
//-------------------------------------------------------------------------------

