//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/lfu16filtafiltrxn/unittest/ut_project/stm8/cosmic/modx0/utfu_lfu16filtafiltrxn.c,v 1.7 2010/02/25 21:50:41 dashley Exp $
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
#define MODULE_UTFU_LFU16FILTAFILTRXN

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_lfu16filtafiltrxn.h"


UCU_UINT16 fv;

UCU_UINT8  utfu_lfu16filtafiltrxn_tb[20];

typedef struct
   {
   UCU_UINT8 op16[2];
   UCU_UINT8 op48[6];
   UCU_UINT8 result64[8];
   } LFU16FILTAFILTRXN_TV_A;

const LFU16FILTAFILTRXN_TV_A lfu16filtafiltrxn_tvs_a[] =
   {
      //Vector 0
      {
         { 0x00, 0x00},
         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
      },
      //Vector 1
      {
         { 0x11, 0x13},
         { 0x02, 0x03, 0x05, 0x07, 0x0B, 0x0D},
         { 0x00, 0x22, 0x59, 0x8E, 0xD7, 0x41, 0xAE, 0xF7 }
      },
      //Vector 2
      {
         { 0xDF, 0xD3},
         { 0xFB, 0xF1, 0xEF, 0xE9, 0xE5, 0xE3},
         { 0xDC, 0x47, 0x68, 0x65, 0x7D, 0x09, 0x37, 0x19 }
      },
      //Vector 3
      {
         { 0xFF, 0xFF},
         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
      },
      //Vector 4
      {
         { 0x00, 0x00},
         { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
      },
      //Vector 5
      {
         { 0xFF, 0xFF},
         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x01},
         { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF }
      },
      //Vector 6
      {
         { 0x00, 0x01},
         { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
         { 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }
      },
      //Vector 7
      {
         { 0xFF, 0xFF},
         { 0x01, 0x00, 0x00, 0x00, 0x00, 0x00},
         { 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00 }
      },
      //Vector 8
      {
         { 0x01, 0x00},
         { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
         { 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 }
      },
      //Vector 9
      {
         { 0xFF, 0xFF},
         { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
         { 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01 }
      },
   };

//Unit Test Plan Step 2
//
//This only causes the function to be linked in.  For the purposes of this
//test step, running the function isn't relevant.
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S002(void)
   {
   UCU_UNION48 ts;

   UcuLfU16FiltAInitRxn(&ts, 0);

   fv = UcuLfU16FiltAFiltRxn(&ts, 1000, 2000);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 3
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S003(void)
   {
   UCU_UNION48 ts;

   UcuLfU16FiltAInitRxn(&ts, 0);

   fv = UcuLfU16FiltAFiltRxn(&ts, 1000, 2000);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 4
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S004(void)
   {
   UCU_UINT8  i;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 0);

   //One filtering test.  Need to look for memory corruption with debugger.
   fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 1000, 2000);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 9
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S009(void)
   {
   UCU_UINT16  i, j;
   UCU_BOOLEAN rv;

   rv = UCU_TRUE;

   for (i=0; i<sizeof(lfu16filtafiltrxn_tvs_a)/sizeof(lfu16filtafiltrxn_tvs_a[0]); i++)
      {
      //Set the array to detect accidental memory corruptions outside the block
      //of 6.
      //
      for (j=0; j<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); j++) 
         {
         utfu_lfu16filtafiltrxn_tb[j] = 0xA5;  //Sentinal value to detect memory corruption
                                               //by the function.
         }

      //Init the block of 6 to y(k-1).  This way the multiplication will become the
      //new filter state.
      utfu_lfu16filtafiltrxn_tb[4] = lfu16filtafiltrxn_tvs_a[i].op48[0];
      utfu_lfu16filtafiltrxn_tb[5] = lfu16filtafiltrxn_tvs_a[i].op48[1];
      utfu_lfu16filtafiltrxn_tb[6] = lfu16filtafiltrxn_tvs_a[i].op48[2];
      utfu_lfu16filtafiltrxn_tb[7] = lfu16filtafiltrxn_tvs_a[i].op48[3];
      utfu_lfu16filtafiltrxn_tb[8] = lfu16filtafiltrxn_tvs_a[i].op48[4];
      utfu_lfu16filtafiltrxn_tb[9] = lfu16filtafiltrxn_tvs_a[i].op48[5];

      //Run the filter
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 0, lfu16filtafiltrxn_tvs_a[i].op16[0] * 256 + lfu16filtafiltrxn_tvs_a[i].op16[1]);

      //Inspect the result.  We can only get the 48 bits without a debugger.
      for (j=0; j<6; j++) 
         {
         if (utfu_lfu16filtafiltrxn_tb[j+4] != lfu16filtafiltrxn_tvs_a[i].result64[j])
            {
            rv = UCU_FALSE;
            }
         }
      }

   return(rv);
   }


//Unit Test Plan Step 11
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S011(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 0);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 32768);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 12
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S012(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 0, 32768);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 13
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S013(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 0);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 58982);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 14
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S014(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 0, 58982);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 15
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S015(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 0);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 6554);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 23A
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S023A(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 1);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 23B
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S023B(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 32768);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 23C
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S023C(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 65534);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 23D
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S023D(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 65535);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 24A
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S024A(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65000);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 1);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 24B
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S024B(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65000);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 32768);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 24C
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S024C(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65000);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 65534);
      } while (--n);

   return(UCU_TRUE);
   }


//Unit Test Plan Step 24D
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn_S024D(void)
   {
   UCU_UINT16 n;
   UCU_UINT8  i;

   n = 1000;

   //Set the array to detect accidental memory corruptions outside the block
   //of 6.
   //
   for (i=0; i<sizeof(utfu_lfu16filtafiltrxn_tb)/sizeof(utfu_lfu16filtafiltrxn_tb[0]); i++) 
      {
      utfu_lfu16filtafiltrxn_tb[i] = 0xA5;  //Sentinal value to detect memory corruption
                                            //by the function.
      }

   //Init the block of 6.
   UcuLfU16FiltAInitRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65000);

   do
      {
      fv = UcuLfU16FiltAFiltRxn((UCU_UNION48 *)(utfu_lfu16filtafiltrxn_tb+4), 65535, 65535);
      } while (--n);

   return(UCU_TRUE);
   }



//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuLfU16FiltAFiltRxn(void)
   {
   UCU_BOOLEAN rv;

   rv = UCU_TRUE;

   if (! UtfuLfU16FiltAFiltRxn_S002())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S003())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S004())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S009())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S011())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S012())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S013())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S014())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S015())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S023A())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S023B())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S023C())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S023D())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S024A())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S024B())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S024C())
      rv = UCU_FALSE;

   if (! UtfuLfU16FiltAFiltRxn_S024D())
      rv = UCU_FALSE;

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_lfu16filtafiltrxn.c,v $
//Revision 1.7  2010/02/25 21:50:41  dashley
//Unit test complete.
//
//Revision 1.6  2010/02/25 20:51:07  dashley
//Edits.
//
//Revision 1.5  2010/02/25 20:33:29  dashley
//Test cases added.
//
//Revision 1.4  2010/02/25 18:22:51  dashley
//Edits.
//
//Revision 1.3  2010/02/25 18:08:31  dashley
//Edits.
//
//Revision 1.2  2010/02/25 17:48:41  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/25 17:47:57  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_lfu16filtafiltrxn.c,v $
//-------------------------------------------------------------------------------

