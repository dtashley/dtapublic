//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/amu8ars1u16nrxn/unittest/ut_project/stm8/cosmic/modx0/utfu_amu8ars1u16nrxn.c,v 1.4 2010/02/23 17:50:52 dashley Exp $
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
#define MODULE_UTFU_AMU8ARS1U16NRXN

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_amu8ars1u16nrxn.h"


UCU_UINT8 amu8ars1u16nrxn_ta[12];
   //The actual RAM used for the test.

//Defines a test array state.
typedef struct
   {
   UCU_UINT8 tas[12];
   } UTFU_AMU8ARS1U16NRXN_TAS;


//Defines an individual test vector.
typedef struct
   {
   UCU_UINT8  *a;                      //Pointer to array passed to function.
   UCU_UINT16  n;                      //Element count passed to function.
   UCU_UINT8   pushval;                //Value to be pushed into [0] position.
   UCU_UINT16  nfuncruns;              //Number of times to run the function.
   UTFU_AMU8ARS1U16NRXN_TAS ab;        //Initial state of array.  This is set up before the function call(s).
   UTFU_AMU8ARS1U16NRXN_TAS aa;        //Expected final state of the array.  This is what should be in the array
                                       //after the function calls.
   } UTFU_AMU8ARS1U16NRXN_TV;


const UTFU_AMU8ARS1U16NRXN_TV amu8ars1u16nrxn_tvs[] =
   {
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //No array accesses with an input parameter of 0.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      0,                      //Number of array elements.
      57,                     //Push value.
      1117,                   //Arbitrary large prime number.  Using a prime so no modulo effects if something isn't as
                              //expected.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41}
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //Pushing while specifying one element.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      1,                      //Number of array elements.
      57,                     //Push value.
      1,                      //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   17,   19,   23,   31,   37,   41}
      },
      {
      //Pushing while specifying one element.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      1,                      //Number of array elements.
      57,                     //Push value.
      1117,                   //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   17,   19,   23,   31,   37,   41}
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //Pushing while specifying two elements.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      2,                      //Number of array elements.
      57,                     //Push value.
      1,                      //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   13,   19,   23,   31,   37,   41}
      },
      {
      //Pushing while specifying two elements.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      2,                      //Number of array elements.
      57,                     //Push value.
      2,                      //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   57,   19,   23,   31,   37,   41}
      },
      {
      //Pushing while specifying two elements.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      2,                      //Number of array elements.
      57,                     //Push value.
      1117,                   //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   57,   19,   23,   31,   37,   41}
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //Pushing while specifying three elements.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      3,                      //Number of array elements.
      57,                     //Push value.
      1,                      //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   13,   17,   23,   31,   37,   41}
      },
      {
      //Pushing while specifying three elements.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      3,                      //Number of array elements.
      57,                     //Push value.
      2,                      //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   57,   13,   23,   31,   37,   41}
      },
      {
      //Pushing while specifying three elements.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      3,                      //Number of array elements.
      57,                     //Push value.
      3,                      //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   57,   57,   23,   31,   37,   41}
      },
      {
      //Pushing while specifying three elements.
      amu8ars1u16nrxn_ta+5,   //Approximate center of the array.
      3,                      //Number of array elements.
      57,                     //Push value.
      1117,                   //Number of times to run the function.
         {    2,    3,    5,    7,   11,   13,   17,   19,   23,   31,   37,   41},
         {    2,    3,    5,    7,   11,   57,   57,   57,   23,   31,   37,   41}
      },
   };

//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAmU8aRs1U16nRxn(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  test_no;
   UCU_UINT16  i;
   UCU_UINT16  func_iteration;

   rv = UCU_TRUE;

   for (test_no=0; test_no<(sizeof(amu8ars1u16nrxn_tvs)/sizeof(amu8ars1u16nrxn_tvs[0])); test_no++)
      {
      //Zero the array in case the initialization vector of the array is incomplete.
      for (i=0; i<(sizeof(amu8ars1u16nrxn_ta)/sizeof(amu8ars1u16nrxn_ta[0])); i++)
         amu8ars1u16nrxn_ta[i] = 0;

      //Copy in the initializer.
      for (i=0; i<(sizeof(amu8ars1u16nrxn_ta)/sizeof(amu8ars1u16nrxn_ta[0])); i++)
         amu8ars1u16nrxn_ta[i] = amu8ars1u16nrxn_tvs[test_no].ab.tas[i];

      //Run the function the specified number of times.
      func_iteration = amu8ars1u16nrxn_tvs[test_no].nfuncruns;
      while(func_iteration)
         {
         UcuAmU8aRs1U16nRxn(amu8ars1u16nrxn_tvs[test_no].a, amu8ars1u16nrxn_tvs[test_no].n, amu8ars1u16nrxn_tvs[test_no].pushval);
         func_iteration--;
         }

      //Verify that the array contents are as expected.
      for (i=0; i<(sizeof(amu8ars1u16nrxn_ta)/sizeof(amu8ars1u16nrxn_ta[0])); i++)
         {
         if (amu8ars1u16nrxn_ta[i] != amu8ars1u16nrxn_tvs[test_no].aa.tas[i])
            rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_amu8ars1u16nrxn.c,v $
//Revision 1.4  2010/02/23 17:50:52  dashley
//Minor error corrected.  Unit test complete.
//
//Revision 1.3  2010/02/23 16:59:28  dashley
//Unit test passed.
//
//Revision 1.2  2010/02/23 16:22:13  dashley
//Edits.
//
//Revision 1.1  2010/02/23 16:20:24  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_amu8ars1u16nrxn.c,v $
//-------------------------------------------------------------------------------

