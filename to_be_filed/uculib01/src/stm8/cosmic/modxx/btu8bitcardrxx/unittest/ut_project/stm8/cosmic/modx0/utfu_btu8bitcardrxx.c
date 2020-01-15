//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu8bitcardrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_btu8bitcardrxx.c,v 1.2 2010/02/11 20:20:41 dashley Exp $
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
#define MODULE_UTFU_BTU8BITCARDRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_btu8bitcardrxx.h"


//Counts the number of bits in a character.
//
static UCU_UINT8 uchar_cardinality(UCU_UINT8 arg)
   {
   UCU_UINT8 i;
   UCU_UINT8 rv;

   rv = 0;

   for (i=0; i<8; i++)
      {
      if (arg & 1)
         rv++;
 
      arg >>= 1;
      }

   return(rv);
   }


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnBtU8BitCardRxx(void)
   {
   return(256);
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspBtU8BitCardRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT8 arg;
   UCU_UINT8 rv;

   arg = test_no & 0xFF;  //Can't go above 255 for the input to the function.
      
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   rv = UcuBtU8BitCardRxx(arg);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuBtU8BitCardRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT8   arg;
   UCU_UINT8   func_result;
   UCU_UINT8   calcd_result;

   rv = UCU_TRUE;

   for (i=0; i<256; i++)
      {
      arg = i;

      func_result  = UcuBtU8BitCardRxx(arg);

      calcd_result = uchar_cardinality(arg);

      if (func_result != calcd_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_btu8bitcardrxx.c,v $
//Revision 1.2  2010/02/11 20:20:41  dashley
//Edits.
//
//Revision 1.1  2010/02/11 20:14:26  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_btu8bitcardrxx.c,v $
//-------------------------------------------------------------------------------

