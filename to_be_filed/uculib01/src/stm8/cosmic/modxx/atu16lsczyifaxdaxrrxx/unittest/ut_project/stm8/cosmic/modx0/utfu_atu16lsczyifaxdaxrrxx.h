//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/atu16lsczyifaxdaxrrxx/unittest/ut_project/stm8/cosmic/modx0/utfu_atu16lsczyifaxdaxrrxx.h,v 1.3 2010/02/05 20:52:51 dashley Exp $
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
#ifndef UTFU_ATU16LSCZYIFAXDAXRRXX_H
#define UTFU_ATU16LSCZYIFAXDAXRRXX_H

#ifdef MODULE_UTFU_ATU16LSCZYIFAXDAXRRXX
   #define DECMOD_UTFU_ATU16LSCZYIFAXDAXRRXX
#else
   #define DECMOD_UTFU_ATU16LSCZYIFAXDAXRRXX extern
#endif

DECMOD_UTFU_ATU16LSCZYIFAXDAXRRXX UCU_UINT32  UtsnAtU16LscZyiFAxdAxrRxx(void);
DECMOD_UTFU_ATU16LSCZYIFAXDAXRRXX void        UtspAtU16LscZyiFAxdAxrRxx(UCU_UINT32 test_no, void (*start_pointer)(void), void (*end_pointer)(void));
DECMOD_UTFU_ATU16LSCZYIFAXDAXRRXX UCU_BOOLEAN UtfuAtU16LscZyiFAxdAxrRxx(void);

#endif

//-------------------------------------------------------------------------------
//$Log: utfu_atu16lsczyifaxdaxrrxx.h,v $
//Revision 1.3  2010/02/05 20:52:51  dashley
//Automated test vector system changed from maximum of 2^16-1 cases to
//2^32-1 cases.
//
//Revision 1.2  2010/02/03 21:22:12  dashley
//Extra line removed.
//
//Revision 1.1  2010/02/03 21:21:05  dashley
//Initial checkin.
//-------------------------------------------------------------------------------
//End of $RCSfile: utfu_atu16lsczyifaxdaxrrxx.h,v $
//-------------------------------------------------------------------------------

