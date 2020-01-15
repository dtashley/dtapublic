//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu8bitcardrxx/src/btu8bitcardrxx.c,v 1.4 2010/02/11 18:27:10 dashley Exp $
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

#include "uculib.h"


UCU_UINT8 UcuBtU8BitCardRxx( UCU_UINT8 arg )
   {
   UCU_UINT8 table_value;

   table_value = UcuBtU8ByteCardNibpLut[arg & 0x7F];
      //Get the relevant byte.

   if (arg & 0x80)
      {
      //Argument is >= 128.  Use the upper nibble.
      return(table_value >> 4);
      }
   else
      {
      //Argument is 127 or less.  Use the lower nibble.
      return(table_value & 0xF);
      }
   }


//-------------------------------------------------------------------------------
//End of $Id: btu8bitcardrxx.c,v 1.4 2010/02/11 18:27:10 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: btu8bitcardrxx.c,v $
//Revision 1.4  2010/02/11 18:27:10  dashley
//Documentation removed.
//
//Revision 1.3  2010/01/31 02:46:48  dashley
//Bit cardinality functions added.
//
//Revision 1.2  2010/01/22 03:56:24  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 03:56:03  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

