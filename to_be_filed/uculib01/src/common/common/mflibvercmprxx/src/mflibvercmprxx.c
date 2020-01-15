//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/common/common/mflibvercmprxx/src/mflibvercmprxx.c,v 1.4 2010/02/04 16:15:16 dashley Exp $
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


UCU_BOOLEAN UcuMfLibVerCmpRxx(UCU_UINT16 in_majorversion,
                              UCU_UINT8  in_minorversion,
                              UCU_UINT8  in_microversion,
                              UCU_UINT8  in_cpucore,
                              UCU_UINT8  in_cpucorevariant)
   {
   UCU_BOOLEAN rv;

   rv = UCU_TRUE;

   if ((in_majorversion != 65535U) && (in_majorversion != UCU_LIBVER_MAJOR))
      {
      rv = UCU_FALSE;
      }

   if ((in_minorversion != 255U) && (in_minorversion != UCU_LIBVER_MINOR))
      {
      rv = UCU_FALSE;
      }

   if ((in_microversion != 255U) && (in_microversion != UCU_LIBVER_MICRO))
      {
      rv = UCU_FALSE;
      }

   if ((in_cpucore != 255U) && (in_cpucore != UCU_LIBVER_CPUCORE))
      {
      rv = UCU_FALSE;
      }

   if ((in_cpucorevariant != 255U) && (in_cpucorevariant != UCU_LIBVER_CPUCOREVAR))
      {
      rv = UCU_FALSE;
      }

   return(rv);
   }


//-------------------------------------------------------------------------------
//End of $Id: mflibvercmprxx.c,v 1.4 2010/02/04 16:15:16 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: mflibvercmprxx.c,v $
//Revision 1.4  2010/02/04 16:15:16  dashley
//Constants changed to unsigned.  It was noticed with the constant 65535
//that the compiler converted to a long to do a comparison, which is
//wasteful.
//
//Revision 1.3  2010/01/26 22:18:41  dashley
//Library versioning functions changed to new naming convention.
//
//Revision 1.2  2010/01/26 03:16:07  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/26 03:15:37  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

