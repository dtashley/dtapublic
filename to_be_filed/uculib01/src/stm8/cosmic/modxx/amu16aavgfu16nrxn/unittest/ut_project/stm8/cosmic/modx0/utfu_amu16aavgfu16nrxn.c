//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/amu16aavgfu16nrxn/unittest/ut_project/stm8/cosmic/modx0/utfu_amu16aavgfu16nrxn.c,v 1.3 2010/02/24 15:19:50 dashley Exp $
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
#define MODULE_UTFU_AMU16AAVGFU16NRXN

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_amu16aavgfu16nrxn.h"


UCU_UINT16 amu16aavgfu16nrxn_ta[18];
   //The actual RAM used for the test.

//Defines a test array state.
typedef struct
   {
   UCU_UINT16 tas[18];
   } UTFU_AMU16AAVGFU16NRXN_TAS;


//Defines an individual test vector.
typedef struct
   {
   UCU_UINT16 *a;                      //Pointer to array passed to function.
   UCU_UINT16  n;                      //Element count passed to function.
   UCU_UINT16  er;                     //Expected result from the function.
   UTFU_AMU16AAVGFU16NRXN_TAS ab;      //Initial state of array.  This is set up before the function call(s).  As the
                                       //function is expected not to change array contents, the RAM array should have the
                                       //same contents after the function call.
   } UTFU_AMU16AAVGFU16NRXN_TV;


const UTFU_AMU16AAVGFU16NRXN_TV amu16aavgfu16nrxn_tvs[] =
   {
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //0 leads to 0.
      amu16aavgfu16nrxn_ta+5,  //Approximate center of the array.
      0,                       //Number of array elements.
      0,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //1 leads to identity.
      amu16aavgfu16nrxn_ta+5,  //Approximate center of the array.
      1,                       //Number of array elements.
      3121,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      {
      //1 leads to identity.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      1,                       //Number of array elements.
      4079,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //2 leads to shift.
      amu16aavgfu16nrxn_ta+5,  //Approximate center of the array.
      2,                       //Number of array elements.
      4890,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      {
      //2 leads to shift.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      2,                       //Number of array elements.
      3054,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
			{
      //In the case of two, the addition is properly propagated to higher-order bytes.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      2,                       //Number of array elements.
      35040,                   //Expected return value.
         { 3229, 40790, 29291, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //3 leads to division.
      amu16aavgfu16nrxn_ta+5,  //Approximate center of the array.
      3,                       //Number of array elements.
      3266,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      {
      //3 leads to division.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      3,                       //Number of array elements.
      4663,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
			{
      //Proper carry propagation.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      3,                       //Number of array elements.
      42567,                   //Expected return value.
         { 3229, 40790, 29029, 57883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
			{
      //Max element test.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      3,                       //Number of array elements.
      65535,                    //Expected return value.
         { 3229, 65535, 65535, 65535, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //4 leads to shift.
      amu16aavgfu16nrxn_ta+5,  //Approximate center of the array.
      4,                       //Number of array elements.
      2455,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      {
      //Max element test.
      amu16aavgfu16nrxn_ta+5,  //Approximate center of the array.
      4,                       //Number of array elements.
      65535,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 65535, 65535, 65535, 65535,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //8 leads to shift.
      amu16aavgfu16nrxn_ta+5,  //Approximate center of the array.
      8,                       //Number of array elements.
      1732,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //16 leads to shift.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      16,                      //Number of array elements.
      3103,                    //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129},
      },
      {
      //Max element test.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      16,                      //Number of array elements.
      65535,                    //Expected return value.
         { 3229, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 3129},
      },
      {
      //Floor test.
      amu16aavgfu16nrxn_ta+1,  //Approximate center of the array.
      16,                      //Number of array elements.
      65534,                    //Expected return value.
         { 3229, 65535, 65535, 65535, 65535, 65533, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 3129},
      },
   };

//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAmU16aAvgFU16nRxn(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  test_no;
   UCU_UINT16  i;
   UCU_UINT16  actual_value;

   rv = UCU_TRUE;

   for (test_no=0; test_no<(sizeof(amu16aavgfu16nrxn_tvs)/sizeof(amu16aavgfu16nrxn_tvs[0])); test_no++)
      {
      //Zero the array in case the initialization vector of the array is incomplete.
      for (i=0; i<(sizeof(amu16aavgfu16nrxn_ta)/sizeof(amu16aavgfu16nrxn_ta[0])); i++)
         amu16aavgfu16nrxn_ta[i] = 0;

      //Copy in the initializer.
      for (i=0; i<(sizeof(amu16aavgfu16nrxn_ta)/sizeof(amu16aavgfu16nrxn_ta[0])); i++)
         amu16aavgfu16nrxn_ta[i] = amu16aavgfu16nrxn_tvs[test_no].ab.tas[i];

      //Run the function.
      actual_value = UcuAmU16aAvgFU16nRxn(amu16aavgfu16nrxn_tvs[test_no].a, amu16aavgfu16nrxn_tvs[test_no].n);

      if (actual_value != amu16aavgfu16nrxn_tvs[test_no].er)
         rv = UCU_FALSE;

      //Verify that the array contents are as expected.
      for (i=0; i<(sizeof(amu16aavgfu16nrxn_ta)/sizeof(amu16aavgfu16nrxn_ta[0])); i++)
         {
         if (amu16aavgfu16nrxn_ta[i] != amu16aavgfu16nrxn_tvs[test_no].ab.tas[i])
            rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_amu16aavgfu16nrxn.c,v $
//Revision 1.3  2010/02/24 15:19:50  dashley
//Additional test cases added to test carry propagation into higher
//bytes.
//
//Revision 1.2  2010/02/23 22:23:46  dashley
//Unit testing completed.
//
//Revision 1.1  2010/02/23 22:21:43  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_amu16aavgfu16nrxn.c,v $
//-------------------------------------------------------------------------------

