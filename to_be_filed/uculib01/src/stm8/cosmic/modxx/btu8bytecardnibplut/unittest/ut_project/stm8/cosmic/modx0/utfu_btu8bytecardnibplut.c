//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu8bytecardnibplut/unittest/ut_project/stm8/cosmic/modx0/utfu_btu8bytecardnibplut.c,v 1.2 2010/02/10 17:35:24 dashley Exp $
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
#define MODULE_UTFU_BTU8BYTECARDNIBPLUT

#include "\uculib01\include\stm8\cosmic\c\uculib.h"
#include "utfu_btu8bytecardnibplut.h"


//Counts the number of bits in a character.
//
static UCU_UINT8 uchar_cardinality(UCU_UINT8 arg)
   {
   UCU_UINT8 i;
   UCU_UINT8 rv;

   rv = 0;

   for (i=0; i<8; i++)
      {
      if (arg & 1)
         rv++;
 
      arg >>= 1;
      }

   return(rv);
   }


//Runs all test vectors.  Returns TRUE if OK, FALSE if any failed.
//
UCU_BOOLEAN UtfuBtU8ByteCardNibpLut(void)
   {
   UCU_BOOLEAN rv;
   UCU_UINT16  i;
   UCU_UINT8   arg;
   UCU_UINT8   table_value;
   UCU_UINT8   counted_value;

   rv = UCU_TRUE;

   //If the table size is wrong, this needs to be investigated.
   if (sizeof(UcuBtU8ByteCardNibpLut) != 128)
      rv = UCU_FALSE;

   for (i=0; i<(256); i++)
      {
      arg = i;

      //See what the table says about the cardinality.
      if (arg < 128)
         {
         table_value = UcuBtU8ByteCardNibpLut[arg] & 0xF;
         }
      else
         {
         table_value = UcuBtU8ByteCardNibpLut[arg-128] >> 4;
         }

      //Manually count the bits.
      counted_value = uchar_cardinality(arg);

      //The two need to be the same or something is wrong.
      if (table_value != counted_value)
         {
         rv = UCU_FALSE;
         }
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//$Log: utfu_btu8bytecardnibplut.c,v $
//Revision 1.2  2010/02/10 17:35:24  dashley
//Edits.
//
//Revision 1.1  2010/02/10 17:23:51  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_btu8bytecardnibplut.c,v $
//-------------------------------------------------------------------------------

