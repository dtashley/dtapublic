//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/common/common/mflibvercmprxx/unittest/ut_project/stm8/cosmic/modx0/utfu_mflibvercmprxx.c,v 1.4 2010/02/05 20:52:51 dashley Exp $
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
#define MODULE_UTFU_MFLIBVERCMPRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_mflibvercmprxx.h"

typedef struct
   {
   UCU_UINT16  majorversion;
   UCU_UINT8   minorversion;
   UCU_UINT8   microversion;
   UCU_UINT8   cpucore;
   UCU_UINT8   cpucorevariant;
   UCU_BOOLEAN expected_result;
   } MFLIBVERCMPRXX_TV;


//This is the table of test vectors.
//
const MFLIBVERCMPRXX_TV MfLibVerCmpRxx_Tvs[] =
   {
      //All correct parameter should yield UCU_TRUE.
      {
      UCU_LIBVER_MAJOR,
      UCU_LIBVER_MINOR,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR,
      UCU_TRUE
      },
      //Anything perturbed should yield UCU_FALSE.
      {
      UCU_LIBVER_MAJOR+1,
      UCU_LIBVER_MINOR,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR,
      UCU_FALSE
      },
      {
      UCU_LIBVER_MAJOR,
      UCU_LIBVER_MINOR+1,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR,
      UCU_FALSE
      },
      {
      UCU_LIBVER_MAJOR,
      UCU_LIBVER_MINOR,
      UCU_LIBVER_MICRO+1,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR,
      UCU_FALSE
      },
      {
      UCU_LIBVER_MAJOR,
      UCU_LIBVER_MINOR,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE+1,
      UCU_LIBVER_CPUCOREVAR,
      UCU_FALSE
      },
      {
      UCU_LIBVER_MAJOR,
      UCU_LIBVER_MINOR,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR+1,
      UCU_FALSE
      },
      //Any of the "ignore" values should still yield UCU_TRUE.
      {
      65535,
      UCU_LIBVER_MINOR,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR,
      UCU_TRUE
      },
      {
      UCU_LIBVER_MAJOR,
      255,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR,
      UCU_TRUE
      },
      {
      UCU_LIBVER_MAJOR,
      UCU_LIBVER_MINOR,
      255,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR,
      UCU_TRUE
      },
      {
      UCU_LIBVER_MAJOR,
      UCU_LIBVER_MINOR,
      UCU_LIBVER_MICRO,
      255,
      UCU_LIBVER_CPUCOREVAR,
      UCU_TRUE
      },
      {
      UCU_LIBVER_MAJOR,
      UCU_LIBVER_MINOR,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE,
      255,
      UCU_TRUE
      },
      //An "ignore" plus a wrong parameter should yield UCU_FALSE.  Can't economically
      //test all combinations.
      {
      UCU_LIBVER_MAJOR+1,
      UCU_LIBVER_MINOR,
      255,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR,
      UCU_FALSE
      },
      {
      UCU_LIBVER_MAJOR,
      255,
      UCU_LIBVER_MICRO,
      UCU_LIBVER_CPUCORE,
      UCU_LIBVER_CPUCOREVAR+1,
      UCU_FALSE
      },
   };


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnMfLibVerCmpRxx(void)
   {
   return(sizeof(MfLibVerCmpRxx_Tvs)/sizeof(MfLibVerCmpRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspMfLibVerCmpRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {

   UCU_UINT16  majorversion;
   UCU_UINT8   minorversion;
   UCU_UINT8   microversion;
   UCU_UINT8   cpucore;
   UCU_UINT8   cpucorevariant;
   UCU_BOOLEAN expected_result, actual_result;

   //Error out if the index is invalid.
   //
   if (test_no >= (sizeof(MfLibVerCmpRxx_Tvs)/sizeof(MfLibVerCmpRxx_Tvs[0])))
      {
      while(UCU_TRUE)  //Can't allow this scenario and dereference an invalid vector.
         ;
      }

   //Fetch the parameters.  This removes all of the array indexing and so on from the
   //elapsed time calculation.
   majorversion     =    MfLibVerCmpRxx_Tvs[test_no].majorversion;
   minorversion     =    MfLibVerCmpRxx_Tvs[test_no].minorversion;
   microversion     =    MfLibVerCmpRxx_Tvs[test_no].microversion;
   cpucore          =    MfLibVerCmpRxx_Tvs[test_no].cpucore;
   cpucorevariant   =    MfLibVerCmpRxx_Tvs[test_no].cpucorevariant;
   expected_result  =    MfLibVerCmpRxx_Tvs[test_no].expected_result;
   
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   actual_result = UcuMfLibVerCmpRxx(majorversion, minorversion, microversion, cpucore, cpucorevariant);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuMfLibVerCmpRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT16  majorversion;
   UCU_UINT8   minorversion;
   UCU_UINT8   microversion;
   UCU_UINT8   cpucore;
   UCU_UINT8   cpucorevariant;
   UCU_BOOLEAN expected_result, actual_result;

   rv = UCU_TRUE;

   for (i=0; i<(sizeof(MfLibVerCmpRxx_Tvs)/sizeof(MfLibVerCmpRxx_Tvs[0])); i++)
      {
      majorversion     =    MfLibVerCmpRxx_Tvs[i].majorversion;
      minorversion     =    MfLibVerCmpRxx_Tvs[i].minorversion;
      microversion     =    MfLibVerCmpRxx_Tvs[i].microversion;
      cpucore          =    MfLibVerCmpRxx_Tvs[i].cpucore;
      cpucorevariant   =    MfLibVerCmpRxx_Tvs[i].cpucorevariant;
      expected_result  =    MfLibVerCmpRxx_Tvs[i].expected_result;

      actual_result = UcuMfLibVerCmpRxx(majorversion, minorversion, microversion, cpucore, cpucorevariant);

      if (actual_result != expected_result)
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_mflibvercmprxx.c,v $
//Revision 1.4  2010/02/05 20:52:51  dashley
//Automated test vector system changed from maximum of 2^16-1 cases to
//2^32-1 cases.
//
//Revision 1.3  2010/02/05 20:37:05  dashley
//Project modified for unit testing.
//
//Revision 1.2  2010/02/04 20:44:02  dashley
//Edits.
//
//Revision 1.1  2010/02/04 20:09:50  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_mflibvercmprxx.c,v $
//-------------------------------------------------------------------------------

