//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/amu16aavgfdmmrmmu16nrxn/unittest/ut_project/stm8/cosmic/modx0/utfu_amu16aavgfdmmrmmu16nrxn.c,v 1.3 2010/02/24 18:43:43 dashley Exp $
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
#define MODULE_UTFU_AMU16AAVGFDMMRMMU16NRXN

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_amu16aavgfdmmrmmu16nrxn.h"


UCU_UINT16 amu16aavgfdmmrmmu16nrxn_ta[20];
   //The actual RAM used for the test.

//Defines a test array state.
typedef struct
   {
   UCU_UINT16 tas[20];
   } UTFU_AMU16AAVGFDMMRMMU16NRXN_TAS;


//Defines an individual test vector.
typedef struct
   {
   UCU_UINT16 *a;                          //Pointer to array passed to function.
   UCU_UINT16  n;                          //Element count passed to function.
   UCU_UINT16  e_avg;                      //Expected average from the function.
   UCU_UINT16  e_min;                      //Expected minimum from the function.
   UCU_UINT16  e_max;                      //Expected maximum from the function.
   UTFU_AMU16AAVGFDMMRMMU16NRXN_TAS ab;    //Initial state of array.  This is set up before the function call(s).  As the
                                           //function is expected not to change array contents, the RAM array should have the
                                           //same contents after the function call.
   } UTFU_AMU16AAVGFDMMRMMU16NRXN_TV;


const UTFU_AMU16AAVGFDMMRMMU16NRXN_TV amu16aavgfdmmrmmu16nrxn_tvs[] =
   {
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //0 leads to 0.
      amu16aavgfdmmrmmu16nrxn_ta+5,  //Approximate center of the array.
      0,                             //Number of array elements.
      0,                             //Expected return values.
      0,
      0,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //1 leads to identity.
      amu16aavgfdmmrmmu16nrxn_ta+5,  //Approximate center of the array.
      1,                             //Number of array elements.
      3121,                          //Expected return values.
      3121,
      3121,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //1 leads to identity.
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      1,                             //Number of array elements.
      4079,                          //Expected return values.
      4079,
      4079,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //2 leads to shift.
      amu16aavgfdmmrmmu16nrxn_ta+5,  //Approximate center of the array.
      2,                             //Number of array elements.
      4890,                          //Expected return values.
      3121,
      6659,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //2 leads to shift.
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      2,                             //Number of array elements.
      3054,                          //Expected return values.
      2029,
      4079,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
			{
      //In the case of two, the addition is properly propagated to higher-order bytes.
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      2,                             //Number of array elements.
      35040,                         //Expected return values.
      29291,
      40790,
         { 3229, 40790, 29291, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //3 leads to the middle element being returned.
      amu16aavgfdmmrmmu16nrxn_ta+5,  //Approximate center of the array.
      3,                             //Number of array elements.
      3121,                          //Expected return values.
      19,
      6659,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //3 leads to the middle element being returned.
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      3,                             //Number of array elements.
      4079,                          //Expected return values.
      2029,
      7883,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //4 leads to shift.
      amu16aavgfdmmrmmu16nrxn_ta+5,  //Approximate center of the array.
      4,                             //Number of array elements.
      1572,                          //Expected return values.
      19,
      6659,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //Max element and carry propagation test.
      amu16aavgfdmmrmmu16nrxn_ta+5,  //Approximate center of the array.
      4,                             //Number of array elements.
      65533,                         //Expected return values.
      65531,
      65535,
         { 3229, 4079, 2029, 7883, 4327, 65531, 65535, 65532, 65535,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //6 leads to shift.
      amu16aavgfdmmrmmu16nrxn_ta+5,  //Approximate center of the array.
      6,                             //Number of array elements.
      803,                           //Expected return values.
      19,
      6659,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //10 leads to shift.
      amu16aavgfdmmrmmu16nrxn_ta+5,  //Approximate center of the array.
      10,                            //Number of array elements.
      1668,                          //Expected return values.
      19,
      6659,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //18 leads to shift.
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      18,                            //Number of array elements.
      3187,                          //Expected return values.
      19,
      7883,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //Max element test.
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      18,                            //Number of array elements.
      65535,                         //Expected return values.
      65535,
		  65535,
         { 3229, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 49554},
      },
      {
      //Floor test #1
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      18,                            //Number of array elements.
      65535,                         //Expected return values.
      65533,
      65535,
         { 3229, 65535, 65535, 65535, 65535, 65533, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 49554},
      },
      {
      //Floor test #2
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      18,                            //Number of array elements.
      65534,                         //Expected return values.
      1000,
      65535,
         { 3229, 65535, 65535, 65535, 65535, 65533, 65535, 65535, 65535, 65527, 65535, 65535, 1000, 65535, 65535, 65535, 65535, 65535, 65535, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //7 leads to division.
      amu16aavgfdmmrmmu16nrxn_ta+1,  //Approximate center of the array.
      7,                             //Number of array elements.
      4043,                          //Expected return values.
      19,
      7883,
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
   };


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAmU16aAvgFDmmRmmU16nRxn(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  test_no;
   UCU_UINT16  i;
   UCU_UINT16  out_avg, out_min, out_max;

   rv = UCU_TRUE;

   for (test_no=0; test_no<(sizeof(amu16aavgfdmmrmmu16nrxn_tvs)/sizeof(amu16aavgfdmmrmmu16nrxn_tvs[0])); test_no++)
      {
      //Zero the array in case the initialization vector of the array is incomplete.
      for (i=0; i<(sizeof(amu16aavgfdmmrmmu16nrxn_ta)/sizeof(amu16aavgfdmmrmmu16nrxn_ta[0])); i++)
         amu16aavgfdmmrmmu16nrxn_ta[i] = 0;

      //Copy in the initializer.
      for (i=0; i<(sizeof(amu16aavgfdmmrmmu16nrxn_ta)/sizeof(amu16aavgfdmmrmmu16nrxn_ta[0])); i++)
         amu16aavgfdmmrmmu16nrxn_ta[i] = amu16aavgfdmmrmmu16nrxn_tvs[test_no].ab.tas[i];

      //Set the variables to catch failure to set a value in the function.
      out_avg = 4219;
      out_min = 4111;
      out_max = 6007;

      //Run the function.
      UcuAmU16aAvgFDmmRmmU16nRxn(amu16aavgfdmmrmmu16nrxn_tvs[test_no].a, 
                                 amu16aavgfdmmrmmu16nrxn_tvs[test_no].n,
                                 &out_avg,
                                 &out_min,
                                 &out_max);

      if (
            (out_avg != amu16aavgfdmmrmmu16nrxn_tvs[test_no].e_avg)
            ||
            (out_min != amu16aavgfdmmrmmu16nrxn_tvs[test_no].e_min)
            ||
            (out_max != amu16aavgfdmmrmmu16nrxn_tvs[test_no].e_max)
         )
         rv = UCU_FALSE;

      //Verify that the array contents are as expected.
      for (i=0; i<(sizeof(amu16aavgfdmmrmmu16nrxn_ta)/sizeof(amu16aavgfdmmrmmu16nrxn_ta[0])); i++)
         {
         if (amu16aavgfdmmrmmu16nrxn_ta[i] != amu16aavgfdmmrmmu16nrxn_tvs[test_no].ab.tas[i])
            rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_amu16aavgfdmmrmmu16nrxn.c,v $
//Revision 1.3  2010/02/24 18:43:43  dashley
//Unit test complete.
//
//Revision 1.2  2010/02/24 18:11:35  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/24 18:02:01  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_amu16aavgfdmmrmmu16nrxn.c,v $
//-------------------------------------------------------------------------------

