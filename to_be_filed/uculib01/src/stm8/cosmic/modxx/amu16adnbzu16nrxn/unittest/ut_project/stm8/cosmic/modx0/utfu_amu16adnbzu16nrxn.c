//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/amu16adnbzu16nrxn/unittest/ut_project/stm8/cosmic/modx0/utfu_amu16adnbzu16nrxn.c,v 1.3 2010/02/17 21:11:23 dashley Exp $
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
#define MODULE_UTFU_AMU16ADNBZU16NRXN

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_amu16adnbzu16nrxn.h"


UCU_UINT16 amu16adnbzu16nrxn_ta[12];
   //The actual RAM used for the test.

//Defines a test array state.
typedef struct
   {
   UCU_UINT16 tas[12];
   } UTFU_AMU16ADNBZU16NRXN_TAS;


//Defines an individual test vector.
typedef struct
   {
   UCU_UINT16 *a;                      //Pointer to array passed to function.
   UCU_UINT16  n;                      //Element count passed to function.
   UCU_UINT16  nfuncruns;              //Number of times to run the function.
   UTFU_AMU16ADNBZU16NRXN_TAS ab;       //Initial state of array.  This is set up before the function call(s).
   UTFU_AMU16ADNBZU16NRXN_TAS aa;       //Expected final state of the array.  This is what should be in the array
                                       //after the function calls.
   } UTFU_AMU16ADNBZU16NRXN_TV;


const UTFU_AMU16ADNBZU16NRXN_TV amu16adnbzu16nrxn_tvs[] =
   {
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //No array accesses with an input parameter of 0.
      amu16adnbzu16nrxn_ta+5,  //Approximate center of the array.
      0,                      //Zero parameter.
      1117,                   //Arbitrary large prime number.  Using a prime so no modulo effects if something isn't as
                              //expected.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41}
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //Single decrement, single element works as expected.
      amu16adnbzu16nrxn_ta+5,
      1,
      1,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   12,   17,   19,   23,   31,   37,   41}
      },

      {
      //Double decrement, single element works as expected.
      amu16adnbzu16nrxn_ta+5,
      1,
      2,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   11,   17,   19,   23,   31,   37,   41}
      },
      {
      //Decrement down to 1.
      amu16adnbzu16nrxn_ta+5,
      1,
      12,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    1,   17,   19,   23,   31,   37,   41}
      },
      {
      //Decrement down to 0.
      amu16adnbzu16nrxn_ta+5,
      1,
      13,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    0,   17,   19,   23,   31,   37,   41}
      },
      {
      //Decrement down to below zero.
      amu16adnbzu16nrxn_ta+5,
      1,
      14,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    0,   17,   19,   23,   31,   37,   41}
      },
      {
      //Decrement down to below zero.
      amu16adnbzu16nrxn_ta+5,
      1,
      15,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    0,   17,   19,   23,   31,   37,   41}
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //Single decrement, double element works as expected.
      amu16adnbzu16nrxn_ta+5,
      2,
      1,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   12,   16,   19,   23,   31,   37,   41}
      },
      {
      //Double decrement, double element works as expected.
      amu16adnbzu16nrxn_ta+5,
      2,
      2,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   11,   15,   19,   23,   31,   37,   41}
      },
      {
      //Decrement down to 1.
      amu16adnbzu16nrxn_ta+5,
      2,
      12,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    1,    5,   19,   23,   31,   37,   41}
      },
      {
      //Decrement down to 0.
      amu16adnbzu16nrxn_ta+5,
      2,
      13,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    0,    4,   19,   23,   31,   37,   41}
      },
      {
      //Decrement down to below zero.
      amu16adnbzu16nrxn_ta+5,
      2,
      14,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    0,    3,   19,   23,   31,   37,   41}
      },
      {
      //Decrement down to below zero.
      amu16adnbzu16nrxn_ta+5,
      2,
      15,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    0,    2,   19,   23,   31,   37,   41}
      },
      {
      //Decrement both elements down to below zero.
      amu16adnbzu16nrxn_ta+5,
      2,
      20,
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,    0,    0,   19,   23,   31,   37,   41}
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      //Decrement many elements.
      {
      amu16adnbzu16nrxn_ta+2,
      5,
      17,
         {    2,    3,   23,   19,   17,   13,   11,    7,   23,   31,   37,   41},
         {    2,    3,    6,    2,    0,    0,    0,    7,   23,   31,   37,   41}
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      //Test propagation between LSB and MSB.  All of the test vectors above were
      //copied from the 8-bit case.  Need a few specific to the 16-bit case.
      {
      amu16adnbzu16nrxn_ta+2,
      5,
      10,
         {    2,    3, 3527, 3359,   17,  683,   11,    7,   23,   31,   37,   41},
         {    2,    3, 3517, 3349,    7,  673,    1,    7,   23,   31,   37,   41}
      },
      {
      amu16adnbzu16nrxn_ta+2,
      5,
      680,
         {    2,    3, 3527, 3359,   17,  683,   11,    7,   23,   31,   37,   41},
         {    2,    3, 2847, 2679,    0,    3,    0,    7,   23,   31,   37,   41}
      },
      {
      amu16adnbzu16nrxn_ta+2,
      5,
      3526,
         {    2,    3, 3527, 3359,   17,  683,   11,    7,   23,   31,   37,   41},
         {    2,    3,    1,    0,    0,    0,    0,    7,   23,   31,   37,   41}
      },
   };


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAmU16aDnbzU16nRxn(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  test_no;
   UCU_UINT16  i;
   UCU_UINT16  func_iteration;

   rv = UCU_TRUE;

   for (test_no=0; test_no<(sizeof(amu16adnbzu16nrxn_tvs)/sizeof(amu16adnbzu16nrxn_tvs[0])); test_no++)
      {
      //Zero the array in case the initialization vector of the array is incomplete.
      for (i=0; i<(sizeof(amu16adnbzu16nrxn_ta)/sizeof(amu16adnbzu16nrxn_ta[0])); i++)
         amu16adnbzu16nrxn_ta[i] = 0;

      //Copy in the initializer.
      for (i=0; i<(sizeof(amu16adnbzu16nrxn_ta)/sizeof(amu16adnbzu16nrxn_ta[0])); i++)
         amu16adnbzu16nrxn_ta[i] = amu16adnbzu16nrxn_tvs[test_no].ab.tas[i];

      //Run the function the specified number of times.
      func_iteration = amu16adnbzu16nrxn_tvs[test_no].nfuncruns;
      while(func_iteration)
         {
         UcuAmU16aDnbzU16nRxn(amu16adnbzu16nrxn_tvs[test_no].a, amu16adnbzu16nrxn_tvs[test_no].n);
         func_iteration--;
         }

      //Verify that the array contents are as expected.
      for (i=0; i<(sizeof(amu16adnbzu16nrxn_ta)/sizeof(amu16adnbzu16nrxn_ta[0])); i++)
         {
         if (amu16adnbzu16nrxn_ta[i] != amu16adnbzu16nrxn_tvs[test_no].aa.tas[i])
            rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_amu16adnbzu16nrxn.c,v $
//Revision 1.3  2010/02/17 21:11:23  dashley
//All unit tests passed.
//
//Revision 1.2  2010/02/17 20:57:37  dashley
//Extra lines removed.
//
//Revision 1.1  2010/02/17 20:56:47  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_amu16adnbzu16nrxn.c,v $
//-------------------------------------------------------------------------------

