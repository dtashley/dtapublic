//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16sqrtx10frxx/unittest/ut_project/stm8/cosmic/modx0/utfu_atu16sqrtx10frxx.c,v 1.3 2010/02/16 22:00:05 dashley Exp $
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
#define MODULE_UTFU_ATU16SQRTX10FRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_atu16sqrtx10frxx.h"


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnAtU16SqrtX10FRxx(void)
   {
   return(65536);
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspAtU16SqrtX10FRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT16 arg;
   UCU_UINT8  rv;

   arg = test_no & 0xFFFF;  //Can't go above 65535 for the input to the function.
      
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   rv = UcuAtU16SqrtX10FRxx(arg);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAtU16SqrtX10FRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT32  i;
   UCU_UINT32  result;

   rv = UCU_TRUE;

   for (i=0; i<65536; i++)
      {
      result = UcuAtU16SqrtX10FRxx(i);

      if (result > 2559)
         {
         //Shouldn't be possible but is definitely unacceptable.
         rv = UCU_FALSE;
         }
      else if ((result > 0) && (((result-1) * (result-1)) > (i * 100))) //This condition anticipates the fact that
         {                                                              //returned value can be larger than floor or 10*sqrt().
         //Result is too large.
         rv = UCU_FALSE;
         }
      else if ((result < 65535) && (((result+1) * (result+1)) <= (i * 100)))
         {
         //Result is too small.
         rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_atu16sqrtx10frxx.c,v $
//Revision 1.3  2010/02/16 22:00:05  dashley
//Changed to be more liberal about return value.  It was determined that
//function may return one larger than floor(sqrt(x)*10).
//
//Revision 1.2  2010/02/15 21:46:13  dashley
//Edits.
//
//Revision 1.1  2010/02/15 21:42:16  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_atu16sqrtx10frxx.c,v $
//-------------------------------------------------------------------------------

