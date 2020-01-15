//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16cmpdiffabsgtrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_atu16cmpdiffabsgtrxx.c,v 1.8 2010/02/05 21:35:16 dashley Exp $
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
#define MODULE_UTFU_ATU16CMPDIFFABSGTRXX

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_atu16cmpdiffabsgtrxx.h"

typedef struct
   {
   UCU_UINT16  a1;
   UCU_UINT16  a2;
   UCU_UINT16  d;
   UCU_BOOLEAN er;
   } ATU16CMPDIFFABSGTRXX_TV;


//This is the table of test vectors.
//
const ATU16CMPDIFFABSGTRXX_TV AtU16CmpDiffAbsGtRxx_Tvs[] =
   {
      //Tests near 0.
      {     0,      0,      0,     UCU_FALSE },    //     0 distance from 0 should not exceed 0.
      {     0,      1,      0,     UCU_TRUE  },    //     1 distance from 0 should exceed 0.
      {     1,      0,      0,     UCU_TRUE  },    //     1 distance from 0 should exceed 0.
      {     0,      2,      0,     UCU_TRUE  },    //     2 distance from 0 should exceed 0.
      {     2,      0,      0,     UCU_TRUE  },    //     2 distance from 0 should exceed 0.
      {     0,  65535,      0,     UCU_TRUE  },    //     Large distance from 0 should exceed 0.
      { 65535,      0,      0,     UCU_TRUE  },    //     Large distance from 0 should exceed 0.
      {     0,     10,     10,     UCU_FALSE },    //     10 distance from 0 should not exceed 10.
      {    10,      0,     10,     UCU_FALSE },    //     10 distance from 0 should not exceed 10.
      //Tests near 65535.
      { 65535,  65535,      0,     UCU_FALSE },    //     0 distance from 65535 should not exceed 0.
      { 65535,  65534,      0,     UCU_TRUE  },    //     1 distance from 65535 should exceed 0.
      { 65534,  65535,      0,     UCU_TRUE  },    //     1 distance from 65535 should exceed 0.
      { 65535,  65533,      0,     UCU_TRUE  },    //     2 distance from 65535 should exceed 0.
      { 65533,  65535,      0,     UCU_TRUE  },    //     2 distance from 65535 should exceed 0.
      { 65535,  65525,     10,     UCU_FALSE },    //     10 distance from 65535 should not exceed 10.
      { 65525,  65535,     10,     UCU_FALSE },    //     10 distance from 65535 should not exceed 10.
      { 65535,  65524,     10,     UCU_TRUE  },    //     11 distance from 65535 should exceed 10.
      { 65524,  65535,     10,     UCU_TRUE  },    //     11 distance from 65535 should exceed 10.
      //Tests spanning a byte boundary.
      {   200,    300,    100,     UCU_FALSE },
      {   200,    301,    100,     UCU_TRUE  },
      {   200,    900,    700,     UCU_FALSE },
      {   200,    901,    700,     UCU_TRUE  },
   };


//Returns the number of test vectors that may be used for a speed test.
//
UCU_UINT32 UtsnAtU16CmpDiffAbsGtRxx(void)
   {
   return(sizeof(AtU16CmpDiffAbsGtRxx_Tvs)/sizeof(AtU16CmpDiffAbsGtRxx_Tvs[0]));
   }


//Runs a selected test vector.  This is used for automated speed testing.
//
void UtspAtU16CmpDiffAbsGtRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void))
   {
   UCU_UINT16  sig1;
   UCU_UINT16  sig2;
   UCU_UINT16  threshold;
   UCU_BOOLEAN actual_value;

   //Error out if the index is invalid.
   //
   if (test_no >= (sizeof(AtU16CmpDiffAbsGtRxx_Tvs)/sizeof(AtU16CmpDiffAbsGtRxx_Tvs[0])))
      {
      while(UCU_TRUE)  //Can't allow this scenario and dereference an invalid vector.
         ;
      }

   //Fetch the parameters.  This removes all of the array indexing and so on from the
   //elapsed time calculation.
   sig1           = AtU16CmpDiffAbsGtRxx_Tvs[test_no].a1;
   sig2           = AtU16CmpDiffAbsGtRxx_Tvs[test_no].a2;
   threshold      = AtU16CmpDiffAbsGtRxx_Tvs[test_no].d;
   
   //We are ready to make the call.  Start the caller's timer.
   (*start_pointer)();

   //Call the function.
   actual_value = UcuAtU16CmpDiffAbsGtRxx(sig1, sig2, threshold);

   //The call is finished.  Stop the caller's timer.
   (*end_pointer)();
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAtU16CmpDiffAbsGtRxx(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT16  sig1;
   UCU_UINT16  sig2;
   UCU_UINT16  threshold;
   UCU_BOOLEAN expected_value;
   UCU_BOOLEAN actual_value;

   rv = UCU_TRUE;

   for (i=0; i<(sizeof(AtU16CmpDiffAbsGtRxx_Tvs)/sizeof(AtU16CmpDiffAbsGtRxx_Tvs[0])); i++)
      {
      sig1           = AtU16CmpDiffAbsGtRxx_Tvs[i].a1;
      sig2           = AtU16CmpDiffAbsGtRxx_Tvs[i].a2;
      threshold      = AtU16CmpDiffAbsGtRxx_Tvs[i].d;
      expected_value = AtU16CmpDiffAbsGtRxx_Tvs[i].er;

      actual_value = UcuAtU16CmpDiffAbsGtRxx(sig1, sig2, threshold);

      if (((expected_value) && (! actual_value)) || ((! expected_value) && (actual_value)))
         rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_atu16cmpdiffabsgtrxx.c,v $
//Revision 1.8  2010/02/05 21:35:16  dashley
//a)Project updated for correct processor and debugging options.
//b)Two near-duplicate erroneous test vectors removed.
//
//Revision 1.7  2010/02/05 20:52:51  dashley
//Automated test vector system changed from maximum of 2^16-1 cases to
//2^32-1 cases.
//
//Revision 1.6  2010/02/04 03:25:00  dashley
//Missing preprocessor directive added.
//
//Revision 1.5  2010/02/04 02:13:45  dashley
//Missing const keywords added.
//
//Revision 1.4  2010/02/03 19:36:34  dashley
//Addition of automated speed testing functionality.
//
//Revision 1.3  2010/02/02 21:38:55  dashley
//Additional test cases added.
//
//Revision 1.2  2010/02/02 21:27:26  dashley
//Basic project in place.
//
//Revision 1.1  2010/02/02 21:01:10  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_atu16cmpdiffabsgtrxx.c,v $
//-------------------------------------------------------------------------------

