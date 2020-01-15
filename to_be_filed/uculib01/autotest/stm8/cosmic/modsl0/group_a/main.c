//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/autotest/stm8/cosmic/modsl0/group_a/main.c,v 1.28 2010/02/17 23:01:14 dashley Exp $
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
#include <stddef.h>

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "\uculib01\src\stm8\cosmic\modxx\atu8sqrtfrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_atu8sqrtfrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\atu16sqrtfrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_atu16sqrtfrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\atu16sqrtx10frxx\unittest\ut_project\stm8\cosmic\modx0\utfu_atu16sqrtx10frxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\atu16cmpdiffabsgtrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_atu16cmpdiffabsgtrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\atu16lsczyifaxdaxrrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_atu16lsczyifaxdaxrrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\atu16lsczyiraxdaxrrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_atu16lsczyiraxdaxrrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\atu16ratadjrrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_atu16ratadjrrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\btu8bytecardnibplut\unittest\ut_project\stm8\cosmic\modx0\utfu_btu8bytecardnibplut.h"
#include "\uculib01\src\stm8\cosmic\modxx\btu32rmasklut\unittest\ut_project\stm8\cosmic\modx0\utfu_btu32rmasklut.h"
#include "\uculib01\src\stm8\cosmic\modxx\btu32bitbyindexlut\unittest\ut_project\stm8\cosmic\modx0\utfu_btu32bitbyindexlut.h"
#include "\uculib01\src\stm8\cosmic\modxx\btu8bitcardrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_btu8bitcardrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\btu16bitcardrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_btu16bitcardrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\btu32bitcardrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_btu32bitcardrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\btu32bitcardrnrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_btu32bitcardrnrxx.h"
#include "\uculib01\src\stm8\cosmic\modxx\amu8adnbzu16nrxn\unittest\ut_project\stm8\cosmic\modx0\utfu_amu8adnbzu16nrxn.h"
#include "\uculib01\src\stm8\cosmic\modxx\amu16adnbzu16nrxn\unittest\ut_project\stm8\cosmic\modx0\utfu_amu16adnbzu16nrxn.h"
#include "\uculib01\src\stm8\cosmic\modxx\amu32adnbzu16nrxn\unittest\ut_project\stm8\cosmic\modx0\utfu_amu32adnbzu16nrxn.h"
#include "\uculib01\src\common\common\mflibvermajrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_mflibvermajrxx.h"
#include "\uculib01\src\common\common\mflibverminmicrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_mflibverminmicrxx.h"
#include "\uculib01\src\common\common\mflibvercpurxx\unittest\ut_project\stm8\cosmic\modx0\utfu_mflibvercpurxx.h"
#include "\uculib01\src\common\common\mflibvercmprxx\unittest\ut_project\stm8\cosmic\modx0\utfu_mflibvercmprxx.h"
#include "\uculib01\src\stm8\cosmic\modx0\mfcpuccrgetrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_mfcpuccrgetrxx.h"
#include "\uculib01\src\stm8\cosmic\modx0\mfcpusptrpcgetrxx\unittest\ut_project\stm8\cosmic\modx0\utfu_mfcpusptrpcgetrxx.h"


//Test vector set for one particular library function.
typedef struct
   {
   const char   *func_name;
   UCU_BOOLEAN (*ut_ptr)(void);                          //Unit test, UCU_TRUE means passed.
   UCU_UINT32  (*st_enum_ptr)(void);                     //Returns the number of speed test vectors available.
   void        (*st_ptr)(UCU_UINT32 test_no,             //Performs a speed test for the passed test_no, with
                         void (*start_pointer)(void),    //callbacks to get more accurate timing.
                         void (*end_pointer)(void));
   } AUTOTEST_POINTER_VECTOR;


//Table of function pointers to perform unit tests and speed tests.
AUTOTEST_POINTER_VECTOR autotest_ptrs[] =
   {
      //Function UcuAtU8SqrtFRxx().
      {
      "UcuAtU8SqrtFRxx()",
      UtfuAtU8SqrtFRxx,
      UtsnAtU8SqrtFRxx,
      UtspAtU8SqrtFRxx
      },
      //Function UcuAtU16SqrtFRxx().
      {
      "UcuAtU16SqrtFRxx()",
      UtfuAtU16SqrtFRxx,
      UtsnAtU16SqrtFRxx,
      UtspAtU16SqrtFRxx
      },
      //Function UcuAtU16SqrtX10FRxx().
      {
      "UcuAtU16SqrtX10FRxx()",
      UtfuAtU16SqrtX10FRxx,
      UtsnAtU16SqrtX10FRxx,
      UtspAtU16SqrtX10FRxx
      },
      //Function UcuAtU16CmpDiffAbsGtRxx().
      {
      "UcuAtU16CmpDiffAbsGtRxx()",
      UtfuAtU16CmpDiffAbsGtRxx,
      UtsnAtU16CmpDiffAbsGtRxx,
      UtspAtU16CmpDiffAbsGtRxx
      },
      //Function UcuAtU16LscZyiFAxdAxrRxx().
      {
      "UcuAtU16LscZyiFAxdAxrRxx()",
      UtfuAtU16LscZyiFAxdAxrRxx,
      UtsnAtU16LscZyiFAxdAxrRxx,
      UtspAtU16LscZyiFAxdAxrRxx
      },
      //Function UcuAtU16LscZyiRAxdAxrRxx().
      {
      "UcuAtU16LscZyiRAxdAxrRxx()",
      UtfuAtU16LscZyiRAxdAxrRxx,
      UtsnAtU16LscZyiRAxdAxrRxx,
      UtspAtU16LscZyiRAxdAxrRxx
      },
      //Function UcuAtU16RatAdjRRxx().
      {
      "UcuAtU16RatAdjRRxx()",
      UtfuAtU16RatAdjRRxx,
      UtsnAtU16RatAdjRRxx,
      UtspAtU16RatAdjRRxx
      },
      //Lookup Table UcuBtU8ByteCardNibpLut[].
      {
      "UcuBtU8ByteCardNibpLut[]",
      UtfuBtU8ByteCardNibpLut,
      NULL,
      NULL
      },
      //Lookup Table UcuBtU32RmaskLut[].
      {
      "UcuUcuBtU32RmaskLut[]",
      UtfuBtU32RmaskLut,
      NULL,
      NULL
      },
      //Lookup Table UcuBtU32BitByIndexLut[].
      {
      "UcuUcuBtU32BitByIndexLut[]",
      UtfuBtU32BitByIndexLut,
      NULL,
      NULL
      },
      //Function UcuBtU8BitCardRxx().
      {
      "UcuBtU8BitCardRxx()",
      UtfuBtU8BitCardRxx,
      UtsnBtU8BitCardRxx,
      UtspBtU8BitCardRxx
      },
      //Function UcuBtU16BitCardRxx().
      {
      "UcuBtU16BitCardRxx()",
      UtfuBtU16BitCardRxx,
      UtsnBtU16BitCardRxx,
      UtspBtU16BitCardRxx
      },
      //Function UcuBtU32BitCardRxx().
      {
      "UcuBtU32BitCardRxx()",
      UtfuBtU32BitCardRxx,
      UtsnBtU32BitCardRxx,
      UtspBtU32BitCardRxx
      },
      //Function UcuBtU32BitCardRnRxx().
      {
      "UcuBtU32BitCardRnRxx()",
      UtfuBtU32BitCardRnRxx,
      UtsnBtU32BitCardRnRxx,
      UtspBtU32BitCardRnRxx
      },
      //Function UcuAmU8aDnbzU16nRxn().
      {
      "UcuAmU8aDnbzU16nRxn()",
      UtfuAmU8aDnbzU16nRxn,
      NULL,
      NULL
      },
      //Function UcuAmU16aDnbzU16nRxn().
      {
      "UcuAmU16aDnbzU16nRxn()",
      UtfuAmU16aDnbzU16nRxn,
      NULL,
      NULL
      },
      //Function UcuAmU32aDnbzU16nRxn().
      {
      "UcuAmU32aDnbzU16nRxn()",
      UtfuAmU32aDnbzU16nRxn,
      NULL,
      NULL
      },
      //Function UcuMfLibVerMajRxx().
      {
      "UcuMfLibVerMajRxx()",
      UtfuMfLibVerMajRxx,
      UtsnMfLibVerMajRxx,
      UtspMfLibVerMajRxx
      },
      //Function UcuMfLibVerMinMicRxx().
      {
      "UcuMfLibVerMinMicRxx()",
      UtfuMfLibVerMinMicRxx,
      UtsnMfLibVerMinMicRxx,
      UtspMfLibVerMinMicRxx
      },
      //Function UcuMfLibVerCpuRxx().
      {
      "UcuMfLibVerCpuRxx()",
      UtfuMfLibVerCpuRxx,
      UtsnMfLibVerCpuRxx,
      UtspMfLibVerCpuRxx
      },
      //Function UcuMfLibVerCmpRxx().
      {
      "UcuMfLibVerCmpRxx()",
      UtfuMfLibVerCmpRxx,
      UtsnMfLibVerCmpRxx,
      UtspMfLibVerCmpRxx
      },
      //Function UcuMfCpuCcrGetRxx().
      {
      "UcuMfCpuCcrGetRxx()",
      UtfuMfCpuCcrGetRxx,
      UtsnMfCpuCcrGetRxx,
      UtspMfCpuCcrGetRxx
      },
      //Function UcuMfCpuSptrPcGetRxx().
      {
      "UcuMfCpuSptrPcGetRxx()",
      UtfuMfCpuSptrPcGetRxx,
      UtsnMfCpuSptrPcGetRxx,
      UtspMfCpuSptrPcGetRxx
      },
   };


void start_timer_func(void)
   {
   }


void stop_timer_func(void)
   {
   }


volatile UCU_UINT8 dummy_volatile_variable;
volatile UCU_BOOLEAN regression_tests_passed;


main(void)
   {
   UCU_UINT16 i;
	 UCU_UINT32 j, k;

   //First do the regression correctness test.  This may take a large amount of compute time.
   regression_tests_passed = UCU_TRUE;
   for (i=0; i<(sizeof(autotest_ptrs)/sizeof(autotest_ptrs[0])); i++)
      {
      if (autotest_ptrs[i].ut_ptr)  //Don't dare run a NULL pointer.
         {
         if (! (*autotest_ptrs[i].ut_ptr)())
            {
            regression_tests_passed = UCU_FALSE;
            }
         else
            {
            //No logical function, just a breakpoint to stop on.
            dummy_volatile_variable = 0x01;
            }
         }

      //No logical function, just a breakpoint to stop on.
      dummy_volatile_variable = 0x02;
      }

   //No logical function, just a breakpoint to stop on.
   dummy_volatile_variable = 0x03;
   
   //Now do the speed tests.  This is just a compile test--don't know how this will be implemented.
   for (i=0; i<(sizeof(autotest_ptrs)/sizeof(autotest_ptrs[0])); i++)
      {
      if ((autotest_ptrs[i].st_enum_ptr) && (autotest_ptrs[i].st_ptr))
         {
         k = (*autotest_ptrs[i].st_enum_ptr)();
   
         for (j=0; j<k; j++)
            {
            (*autotest_ptrs[i].st_ptr)(j, start_timer_func, stop_timer_func);
            }
         }
      }

   //Pause at the end so can have a breakpoint to stop on with the debugger.
   while(UCU_TRUE)
      {
      dummy_volatile_variable = 0x04;
      }
   }


//-------------------------------------------------------------------------------
//$Log: main.c,v $
//Revision 1.28  2010/02/17 23:01:14  dashley
//Function added.
//
//Revision 1.27  2010/02/17 21:25:36  dashley
//Function added.
//
//Revision 1.26  2010/02/17 18:58:57  dashley
//Function added.
//
//Revision 1.25  2010/02/15 22:14:09  dashley
//One unit test failing.
//
//Revision 1.24  2010/02/15 17:43:34  dashley
//Unit test passed.
//
//Revision 1.23  2010/02/15 01:47:55  dashley
//Function added.
//
//Revision 1.22  2010/02/14 22:58:29  dashley
//Functions added.
//
//Revision 1.21  2010/02/14 18:23:15  dashley
//Function added.
//
//Revision 1.20  2010/02/14 00:41:16  dashley
//Function added.
//-------------------------------------------------------------------------------
//End of $RCSfile: main.c,v $
//-------------------------------------------------------------------------------
