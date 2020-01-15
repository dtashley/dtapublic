//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx/mfcpusptrpcgetrxx/unittest/ut_project/stm8/cosmic/modx/utfu_mfcpusptrpcgetrxx.c,v 1.2 2010/02/18 16:00:51 dashley Exp $
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
#define MODULE_UTFU_MFCPUSPTRPCGETRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_mfcpusptrpcgetrxx.h"


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnMfCpuSptrPcGetRxx(void)
   {
   return(1);  //There is only one test vector.
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspMfCpuSptrPcGetRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_CPU_SPTR_PC rv;

   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   rv = UcuMfCpuSptrPcGetRxx();

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuMfCpuSptrPcGetRxx(void)
   {
   UCU_CPU_SPTR_PC rv;
   UCU_UINT32      rv_long;

   rv      = UcuMfCpuSptrPcGetRxx();

   rv_long = UcuMfCpuSptrPcGetRxx();

   //Do some dumb stuff to make sure the compiler actually saves the values returned
   //above.  Without some use of the variables, the compiler may simply discard
   //the return values, which makes it hard to use a debugger to double-check
   //the behaviors.  Because the compiler can't verify that the function calls below
   //don't have side effects, these should be effective.
   UcuBtU32BitCardRxx(rv);
   UcuBtU32BitCardRxx(rv_long);

   return(UCU_TRUE);  //No way to really test the return value except with a debugger.
                      //It could legally be just about anything.
   }


//-------------------------------------------------------------------------------
//$Log: utfu_mfcpusptrpcgetrxx.c,v $
//Revision 1.2  2010/02/18 16:00:51  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/18 15:59:25  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_mfcpusptrpcgetrxx.c,v $
//-------------------------------------------------------------------------------

