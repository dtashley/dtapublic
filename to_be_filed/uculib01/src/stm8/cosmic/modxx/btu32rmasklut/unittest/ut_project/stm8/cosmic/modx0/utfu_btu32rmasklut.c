//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu32rmasklut/unittest/ut_project/stm8/cosmic/modx0/utfu_btu32rmasklut.c,v 1.2 2010/02/10 19:20:57 dashley Exp $
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
#define MODULE_UTFU_BTU32RMASKLUT

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_btu32rmasklut.h"


//Returns the UCU_UINT32 with the number of bits specified masked in from
//the right.  This should match the table entry.
//
static UCU_UINT32 u32_rmask(UCU_UINT8 arg)
   {
   UCU_UINT32 mask;
   UCU_UINT32 rv;

   rv = 0;
   mask = 1;

   while(arg)
      {
      rv   |=  mask;
      mask <<= 1;
      arg  --;
      }

   return(rv);
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuBtU32RmaskLut(void)
   {
   UCU_BOOLEAN  rv;
   UCU_UINT8    i;
   UCU_UINT32   table_value;
   UCU_UINT32   calcd_value;

   rv = UCU_TRUE;

   //If the table size is wrong, this needs to be investigated.
   if (sizeof(UcuBtU32RmaskLut) != (33 * sizeof(UCU_UINT32)))
      rv = UCU_FALSE;

   for (i=0; i<33; i++)
      {
      //See what the table says.
      table_value = UcuBtU32RmaskLut[i];

      //Calculate the value.
      calcd_value = u32_rmask(i);

      //The two need to be the same or something is wrong.
      if (table_value != calcd_value)
         {
         rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_btu32rmasklut.c,v $
//Revision 1.2  2010/02/10 19:20:57  dashley
//Unit testing completed.
//
//Revision 1.1  2010/02/10 18:39:51  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_btu32rmasklut.c,v $
//-------------------------------------------------------------------------------

