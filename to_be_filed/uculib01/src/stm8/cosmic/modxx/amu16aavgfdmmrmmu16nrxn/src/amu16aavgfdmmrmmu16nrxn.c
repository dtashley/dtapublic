//-------------------------------------------------------------------------------
//$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modxx/amu16aavgfdmmrmmu16nrxn/src/amu16aavgfdmmrmmu16nrxn.c,v 1.4 2010/02/24 17:06:45 dashley Exp $
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


void UcuAmU16aAvgFDmmRmmU16nRxn(const UCU_UINT16 *in_array, 
                                      UCU_UINT16  in_nelem,
                                      UCU_UINT16 *out_avg,
                                      UCU_UINT16 *out_el_min,
                                      UCU_UINT16 *out_el_max)
   {
   UCU_UINT32 l_sum;
   UCU_UINT16 l_min;
   UCU_UINT16 l_max;
   UCU_UINT16 l_avg;
   UCU_UINT16 l_i;

   l_sum = 0;
   l_min = 0xFFFF;
   l_max = 0;

   if (in_nelem == 0) 
      {
      //Illegal, but should give the caller some sane return values.
      *out_avg    = 0;
      *out_el_min = 0;
      *out_el_max = 0;
      }
   else if (in_nelem == 1)
      {
      //Sanest return value is just the single element.
      *out_avg    = in_array[0];
      *out_el_min = in_array[0];
      *out_el_max = in_array[0];
      }
   else if (in_nelem == 2)
      {
      //We can't discard the min and max in this case.  Appropriate return value is
      //average of two elements.
      l_sum      = in_array[0];
      l_sum     += in_array[1];
      l_sum    >>= 1;
      *out_avg   = l_sum;

      //Need to figure out which element is bigger to decide how to assign min and max.
      if (in_array[0] > in_array[1])
         {
         *out_el_min = in_array[1];
         *out_el_max = in_array[0];
         }
      else
         {
         *out_el_min = in_array[0];
         *out_el_max = in_array[1];
         }
      }
   else
      {
      //At least 3 elements.
      //
      //Total up the elements, taking note of the min and max.
      //
      l_i = in_nelem;
      while (l_i) 
         {
         //Add to the total.
         l_sum += *in_array;

         //Form min and max.  Note that a given value may become both the
         //min and max.  This isn't harmful because there are at least 3
         //elements if at the end min and max are the same it means there
         //were 3 duplicates, and it is proper to remove 2.  The logic
         //below can _probably_ be changed to if-else, but would need to
         //think before I'm confident about this.
         if (*in_array > l_max)
            {
            l_max = *in_array;
            }
         if (*in_array < l_min) 
            {
            l_min = *in_array;
            }

         in_array++;
         l_i--;
         }

      //Discard min and max from the sum.
      l_sum -= l_min;
      l_sum -= l_max;

      //Calculate average of what is left, optimizing for popular buffer sizes.
      switch(in_nelem)
         {
         case  4:  //Were 4 elements originally, but with min and max removed
                   //treat it as 2 elements.
                   l_avg = l_sum >> 1;
                   break;
         case  6:  //6 - 2 = 4
                   l_avg = l_sum >> 2;
                   break;
         case  10: //10 - 2 = 8
                   l_avg = l_sum >> 3;
                   break;
         case  18: //18 - 2 = 16
                   l_avg = l_sum >> 4;
                   break;
         default:  l_avg = l_sum/(in_nelem-2);  //General case:  division.  Slowest of all.
                   break;
         }

      //Set up the return values for the caller.
      *out_avg    = l_avg;
      *out_el_min = l_min;
      *out_el_max = l_max;
      }
   }

//-------------------------------------------------------------------------------
//End of $Id: amu16aavgfdmmrmmu16nrxn.c,v 1.4 2010/02/24 17:06:45 dashley Exp $
//-------------------------------------------------------------------------------
//$Log: amu16aavgfdmmrmmu16nrxn.c,v $
//Revision 1.4  2010/02/24 17:06:45  dashley
//Comments removed.
//
//Revision 1.3  2010/01/29 23:07:41  dashley
//Addition of two functions.
//
//Revision 1.2  2010/01/22 21:01:00  dashley
//Extra line removed.
//
//Revision 1.1  2010/01/22 21:00:43  dashley
//Initial checkin.
//-------------------------------------------------------------------------------

