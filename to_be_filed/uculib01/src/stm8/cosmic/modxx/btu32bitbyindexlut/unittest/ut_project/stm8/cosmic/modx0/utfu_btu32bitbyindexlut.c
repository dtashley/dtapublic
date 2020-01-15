//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu32bitbyindexlut/unittest/ut_project/stm8/cosmic/modx0/utfu_btu32bitbyindexlut.c,v 1.2 2010/02/10 20:55:03 dashley Exp $
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
#define MODULE_UTFU_BTU32BITBYINDEXLUT

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_btu32bitbyindexlut.h"


//Returns bit "arg".
//
static UCU_UINT32 u32_bitbyindex(UCU_UINT8 arg)
   {
   UCU_UINT32 rv;

   rv = 0x01;

   while(arg)
      {
      rv   <<= 1;
      arg  --;
      }

   return(rv);
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuBtU32BitByIndexLut(void)
   {
   UCU_BOOLEAN  rv;
   UCU_UINT8    i;
   UCU_UINT32   table_value;
   UCU_UINT32   calcd_value;

   rv = UCU_TRUE;

   //If the table size is wrong, this needs to be investigated.
   if (sizeof(UcuBtU32BitByIndexLut) != (32 * sizeof(UCU_UINT32)))
      rv = UCU_FALSE;

   for (i=0; i<32; i++)
      {
      //See what the table says.
      table_value = UcuBtU32BitByIndexLut[i];

      //Calculate the value.
      calcd_value = u32_bitbyindex(i);

      //The two need to be the same or something is wrong.
      if (table_value != calcd_value)
         {
         rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_btu32bitbyindexlut.c,v $
//Revision 1.2  2010/02/10 20:55:03  dashley
//Extra lines removed.
//
//Revision 1.1  2010/02/10 20:54:02  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_btu32bitbyindexlut.c,v $
//-------------------------------------------------------------------------------

