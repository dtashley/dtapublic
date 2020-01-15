//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/amu16aavgfdmmu16nrxn/unittest/ut_project/stm8/cosmic/modx0/utfu_amu16aavgfdmmu16nrxn.c,v 1.3 2010/02/24 16:48:27 dashley Exp $
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
#define MODULE_UTFU_AMU16AAVGFDMMU16NRXN

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_amu16aavgfdmmu16nrxn.h"


UCU_UINT16 amu16aavgfdmmu16nrxn_ta[20];
   //The actual RAM used for the test.

//Defines a test array state.
typedef struct
   {
   UCU_UINT16 tas[20];
   } UTFU_AMU16AAVGFDMMU16NRXN_TAS;


//Defines an individual test vector.
typedef struct
   {
   UCU_UINT16 *a;                      //Pointer to array passed to function.
   UCU_UINT16  n;                      //Element count passed to function.
   UCU_UINT16  er;                     //Expected result from the function.
   UTFU_AMU16AAVGFDMMU16NRXN_TAS ab;   //Initial state of array.  This is set up before the function call(s).  As the
                                       //function is expected not to change array contents, the RAM array should have the
                                       //same contents after the function call.
   } UTFU_AMU16AAVGFDMMU16NRXN_TV;


const UTFU_AMU16AAVGFDMMU16NRXN_TV amu16aavgfdmmu16nrxn_tvs[] =
   {
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //0 leads to 0.
      amu16aavgfdmmu16nrxn_ta+5,  //Approximate center of the array.
      0,                          //Number of array elements.
      0,                          //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //1 leads to identity.
      amu16aavgfdmmu16nrxn_ta+5,  //Approximate center of the array.
      1,                          //Number of array elements.
      3121,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //1 leads to identity.
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      1,                          //Number of array elements.
      4079,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //2 leads to shift.
      amu16aavgfdmmu16nrxn_ta+5,  //Approximate center of the array.
      2,                          //Number of array elements.
      4890,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //2 leads to shift.
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      2,                          //Number of array elements.
      3054,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
			{
      //In the case of two, the addition is properly propagated to higher-order bytes.
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      2,                          //Number of array elements.
      35040,                      //Expected return value.
         { 3229, 40790, 29291, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //3 leads to the middle element being returned.
      amu16aavgfdmmu16nrxn_ta+5,  //Approximate center of the array.
      3,                          //Number of array elements.
      3121,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //3 leads to the middle element being returned.
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      3,                          //Number of array elements.
      4079,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //4 leads to shift.
      amu16aavgfdmmu16nrxn_ta+5,  //Approximate center of the array.
      4,                          //Number of array elements.
      1572,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //Max element and carry propagation test.
      amu16aavgfdmmu16nrxn_ta+5,  //Approximate center of the array.
      4,                          //Number of array elements.
      65533,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 65531, 65535, 65532, 65535,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //6 leads to shift.
      amu16aavgfdmmu16nrxn_ta+5,  //Approximate center of the array.
      6,                          //Number of array elements.
      803,                        //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //10 leads to shift.
      amu16aavgfdmmu16nrxn_ta+5,  //Approximate center of the array.
      10,                         //Number of array elements.
      1668,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //18 leads to shift.
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      18,                         //Number of array elements.
      3187,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
      {
      //Max element test.
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      18,                         //Number of array elements.
      65535,                       //Expected return value.
         { 3229, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 49554},
      },
      {
      //Floor test #1
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      18,                         //Number of array elements.
      65535,                      //Expected return value.
         { 3229, 65535, 65535, 65535, 65535, 65533, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 49554},
      },
      {
      //Floor test #2
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      18,                         //Number of array elements.
      65534,                      //Expected return value.
         { 3229, 65535, 65535, 65535, 65535, 65533, 65535, 65535, 65535, 65527, 65535, 65535, 1000, 65535, 65535, 65535, 65535, 65535, 65535, 49554},
      },
      //******************************************************************************
      //******************************************************************************
      //******************************************************************************
      {
      //7 leads to division.
      amu16aavgfdmmu16nrxn_ta+1,  //Approximate center of the array.
      7,                          //Number of array elements.
      4043,                       //Expected return value.
         { 3229, 4079, 2029, 7883, 4327, 3121, 6659,   19,   23,   31,   37,   41, 3929, 4070, 2099, 7083, 4227, 3129, 6122, 49554},
      },
   };

//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuAmU16aAvgFDmmU16nRxn(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  test_no;
   UCU_UINT16  i;
   UCU_UINT16  actual_value;

   rv = UCU_TRUE;

   for (test_no=0; test_no<(sizeof(amu16aavgfdmmu16nrxn_tvs)/sizeof(amu16aavgfdmmu16nrxn_tvs[0])); test_no++)
      {
      //Zero the array in case the initialization vector of the array is incomplete.
      for (i=0; i<(sizeof(amu16aavgfdmmu16nrxn_ta)/sizeof(amu16aavgfdmmu16nrxn_ta[0])); i++)
         amu16aavgfdmmu16nrxn_ta[i] = 0;

      //Copy in the initializer.
      for (i=0; i<(sizeof(amu16aavgfdmmu16nrxn_ta)/sizeof(amu16aavgfdmmu16nrxn_ta[0])); i++)
         amu16aavgfdmmu16nrxn_ta[i] = amu16aavgfdmmu16nrxn_tvs[test_no].ab.tas[i];

      //Run the function.
      actual_value = UcuAmU16aAvgFDmmU16nRxn(amu16aavgfdmmu16nrxn_tvs[test_no].a, amu16aavgfdmmu16nrxn_tvs[test_no].n);

      if (actual_value != amu16aavgfdmmu16nrxn_tvs[test_no].er)
         rv = UCU_FALSE;

      //Verify that the array contents are as expected.
      for (i=0; i<(sizeof(amu16aavgfdmmu16nrxn_ta)/sizeof(amu16aavgfdmmu16nrxn_ta[0])); i++)
         {
         if (amu16aavgfdmmu16nrxn_ta[i] != amu16aavgfdmmu16nrxn_tvs[test_no].ab.tas[i])
            rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_amu16aavgfdmmu16nrxn.c,v $
//Revision 1.3  2010/02/24 16:48:27  dashley
//Unit test passed.
//
//Revision 1.2  2010/02/24 15:47:08  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/24 15:46:07  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_amu16aavgfdmmu16nrxn.c,v $
//-------------------------------------------------------------------------------

