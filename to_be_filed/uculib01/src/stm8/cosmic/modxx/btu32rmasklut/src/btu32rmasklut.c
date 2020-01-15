//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/btu32rmasklut/src/btu32rmasklut.c,v 1.4 2010/02/10 18:17:35 dashley Exp $
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


const UCU_UINT32 UcuBtU32RmaskLut[33] 
   =
   {
   0x00000000UL,
   0x00000001UL,
   0x00000003UL,
   0x00000007UL,
   0x0000000FUL,
   0x0000001FUL,
   0x0000003FUL,
   0x0000007FUL,
   0x000000FFUL,
   0x000001FFUL,
   0x000003FFUL,
   0x000007FFUL,
   0x00000FFFUL,
   0x00001FFFUL,
   0x00003FFFUL,
   0x00007FFFUL,
   0x0000FFFFUL,
   0x0001FFFFUL,
   0x0003FFFFUL,
   0x0007FFFFUL,
   0x000FFFFFUL,
   0x001FFFFFUL,
   0x003FFFFFUL,
   0x007FFFFFUL,
   0x00FFFFFFUL,
   0x01FFFFFFUL,
   0x03FFFFFFUL,
   0x07FFFFFFUL,
   0x0FFFFFFFUL,
   0x1FFFFFFFUL,
   0x3FFFFFFFUL,
   0x7FFFFFFFUL,
   0xFFFFFFFFUL
   };


//-------------------------------------------------------------------------------
//End of $Id: btu32rmasklut.c,v 1.4 2010/02/10 18:17:35 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: btu32rmasklut.c,v $
//Revision 1.4  2010/02/10 18:17:35  dashley
//Unnecessary comment removed.
//
//Revision 1.3  2010/01/31 02:46:48  dashley
//Bit cardinality functions added.
//
//Revision 1.2  2010/01/22 15:40:21  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 15:39:46  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

