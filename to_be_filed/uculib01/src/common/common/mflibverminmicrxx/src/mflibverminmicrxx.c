//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/common/common/mflibverminmicrxx/src/mflibverminmicrxx.c,v 1.5 2010/01/26 22:18:41 dashley Exp $
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


UCU_UINT16 UcuMfLibVerMinMicRxx(void)
   {
   return((UCU_LIBVER_MINOR << 8) | UCU_LIBVER_MICRO);
   }


//-------------------------------------------------------------------------------
//End of $Id: mflibverminmicrxx.c,v 1.5 2010/01/26 22:18:41 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: mflibverminmicrxx.c,v $
//Revision 1.5  2010/01/26 22:18:41  dashley
//Library versioning functions changed to new naming convention.
//
//Revision 1.4  2010/01/26 03:17:46  dashley
//Function name and type change.
//
//Revision 1.3  2010/01/26 02:54:50  dashley
//Type error corrected.
//
//Revision 1.2  2010/01/26 02:52:46  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/26 02:52:24  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

