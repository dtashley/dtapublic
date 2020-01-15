;-------------------------------------------------------------------------------
;$Header: /home/dashley/cvsrep/uculib01/uculib01/src/stm8/cosmic/modx0/lfu16filtafiltrxn/src/lfu16filtafiltrxn.s,v 1.9 2010/02/25 16:58:33 dashley Exp $
;-------------------------------------------------------------------------------
;Copyright (c)2010 David T. Ashley
;
;Permission is hereby granted, free of charge, to any person obtaining a copy
;of this software source code and associated documentation files (the
;"Software"), to deal in the Software without restriction, including without
;limitation the rights to use, copy, modify, merge, publish, distribute,
;sublicense, and/or sell copies of the Software, and to permit persons to whom
;the Software is furnished to do so, subject to the following conditions:
;
;The above copyright notice and this permission notice shall be included in
;all copies or substantial portions of the Software.
;
;THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
;THE SOFTWARE.
;-------------------------------------------------------------------------------
;This function doesn't use any static storage, so it is OK for either mods0 or
;modsl0 memory models.  However, it does assume call/ret (rather than callf/retf)
;which affects both instructions used, stack offsets, and numerical values in
;the .dcall directive.  For this reason, must error out if being assembled
;for the wrong memory model.
#ifndef UCU_BD_MMBP
   #error "Program memory model define not provided on command line (UCU_BD_MMBP)."
#endif
#if (UCU_BD_MMBP != 1)
   #error "Attempt to assemble module for wrong program memory model (UCU_BD_MMBP != 1)."
#endif
;
            switch .text
            xdef   _UcuLfU16FiltAFiltRxn
;
;Per discussion with Cosmic, the first integer is the stack space used by the
;call instruction plus any automatic storage used by the function.  The second integer
;is the number of bytes stacked by the caller.  Haven't yet discussed the scenario
;of one assembly-language function called by another.  I've noticed that some
;assembly-language functions have a larger first integer than the stack they
;used, so there may be a special convention if C calls .S which then calls .S,
;as maybe the tools don't detect the .S calling the .S.  Will need to investigate
;further with Cosmic.
            .dcall  "18,4,_UcuLfU16FiltAFiltRxn"
;
;UCU_UINT16 UcuLfU16FiltAFiltRxn(UCU_UNION48 *in_fs, UCU_UINT16 in_x_k, UCU_UINT16 in_h)
;   {
;
_UcuLfU16FiltAFiltRxn:
;
;***********************************************************************
;***********************************************************************
;***** NOTE ON PROCESSING CARRIES WHEN PERFORMING MULTIPLICATION *******
;***********************************************************************
;***********************************************************************
;In implementing the filter, a 16-bit operand (either "h" or "65536-h")
;is multiplied by a second operand that is either 16 bits or 48 bits.
;The order of performing the multiplications is from the least
;significant result terms up.
;
;Let's cover the case of h * y(k-1).  The bytes of h are denoted h1 and
;h0 and the bytes of y(k-1) are denoted y5 through y0, with h1 and y5
;being the most significant bytes.  Similarly, I'll denote the 64-bit
;result as r7 through r0.
;
;The results of the multiplication are added up as shown below.
;
;  |  r7  |  r6  |  r5  |  r4  |  r3  |  r2  |  r1  |  r0  | Order | Line  |
;  +------+------+------+------+------+------+------+------+-------+-------+
;                                            |   h0 * y0   |    0      1
;                                     +------+------+------+
;                                     |   h0 * y1   |           1      2
;                                     +------+------+
;                                     |   h1 * y0   |           1      3
;                              +------+------+------+
;                              |   h0 * y2   |                  2      4
;                              +------+------+
;                              |   h1 * y1   |                  2      5
;                       +------+------+------+
;                       |   h0 * y3   |                         3      6
;                       +------+------+
;                       |   h1 * y2   |                         3      7
;                +------+------+------+
;                |   h0 * y4   |                                4      8
;                +------+------+
;                |   h1 * y3   |                                4      9
;         +------+------+------+
;         |   h0 * y5   |                                       5     10
;         +------+------+
;         |   h1 * y4   |                                       5     11
;  +------+------+------+
;  |   h1 * y5   |                                              6     12
;  +------+------+
;
;Note that the (65536-h) * x(k) case is the same as the diagram above but
;only lines 1 through 4 are performed.
;
;Note that the lines are performed in order to avoid unnecessary additions
;and propagation of carries.  For example, once Line 1 is done, the r0 byte
;is never touched again.  Similarly, when Lines 2 and 3 are done, the r1
;byte is never touched again.
;
;The question that needs to be answered is whether and how far up the
;carries need to be propagated.
;
;Lines 1, 2, 4, 6, 8, 10, and 12
;-------------------------------
;In each of these cases, this is the first term of the given order to be added
;into the product.  0xFF * 0xFF is 0xFE01, so the maximum result from adding together
;the two MSB's of the lower-order words is 2 * 0xFE = 508.  There may also be
;at most one carry, giving 509.  The maximum multiplication result is 0xFE01
;=65025.  65025 + 509 = 65534, less than the 65535 maximum that may be held
;in 16 bits.  Thus, a carry may never propagate out from these lines.
;
;For example, when adding in Line 8, a carry may never propagate into r6.
;
;Lines 3, 5, 7, 9, and 11
;------------------------
;A carry may always propagate out of this addition.
;
;For example, when adding in Line 9, a carry may propagate into r6.
;
;***********************************************************************
;***********************************************************************
            ;================================================================================
            ;State at entry:
            ; X Register      :Pointer to filter state block (64 bits).
            ;     (SP)        :Next usable stack location.
            ;   (1,SP)        :MSB of CALL return address.
            ;   (2,SP)        :LSB of CALL return address.
            ;   (3,SP)        :MSB of x(k) input variable to be filtered.
            ;   (4,SP)        :LSB of x(k) input variable to be filtered.
            ;   (5,SP)        :MSB of "h" (time constant).
            ;   (6,SP)        :LSB of "h" (time constant).
            ;================================================================================
            subw   sp,#16     ;Claim 16 bytes of temporary variables on the stack.
            ;State now (with reserved locations for temporary variables):
            ;     (SP)        :Next usable stack location.
            ;   (1,SP)        :Byte [0] of h * y(k-1).  This is the MSB.
            ;   (2,SP)        :Byte [1] of h * y(k-1).
            ;   (3,SP)        :Byte [2] of h * y(k-1).
            ;   (4,SP)        :Byte [3] of h * y(k-1).
            ;   (5,SP)        :Byte [4] of h * y(k-1).
            ;   (6,SP)        :Byte [5] of h * y(k-1).
            ;   (7,SP)        :Byte [6] of h * y(k-1).
            ;   (8,SP)        :Byte [7] of h * y(k-1).  This is the LSB.
            ;   (9,SP)        :Byte [0] of (65536-h)*x(k).  This is the MSB.
            ;  (10,SP)        :Byte [1] of (65536-h)*x(k).
            ;  (11,SP)        :Byte [2] of (65536-h)*x(k).
            ;  (12,SP)        :Byte [3] of (65536-h)*x(k).  This is the LSB.
            ;  (13,SP)        :MSB of "65536-h" (2's complement of filter time constant).
            ;  (14,SP)        :LSB of "65536-h" (2's complement of filter time constant).
            ;  (15,SP)        :MSB of pointer to filter state data block.
            ;  (16,SP)        :LSB of pointer to filter state data block.
            ;  (17,SP)        :MSB of CALL return address.
            ;  (18,SP)        :LSB of CALL return address.
            ;  (19,SP)        :MSB of x(k) input data to be filtered.
            ;  (20,SP)        :LSB of x(k) input data to be filtered.
            ;  (21,SP)        :MSB of "h" (time constant).
            ;  (22,SP)        :LSB of "h" (time constant).
            ;================================================================================
            ;Store the pointer to the filter state block in the temporary stack frame.
            ;It was passed by the compiler in the X register.
            ldw    (15,sp),x
            ;================================================================================
            ;Calculate and store 65536-h.
            ldw    x,(21,sp)  ;Load h.
            cplw   x          ;One's complement.
            incw   x          ;Two's complement is one's complement plus one.
            ldw    (13,sp),x
            ;================================================================================
            ;Calculate and store (65536 - h) * x(k).  Since x(k) is 16 bits and 65536-h is 16 bits,
            ;we need 4 muls and can use the classic pattern.
            ;----------
            ;Clear higher-order two bytes.
            clrw   x
            ldw    (9,sp),x   ;Upper two bytes of result are now cleared.
            ;----------
            ;h'(0)*x(0)
            ld     a,(14,sp)  ;LSB of 65536-h
            ld     xl,a
            ld     a,(20,sp)  ;LSB of x(k)
            mul    x,a        ;Result now in X.
            ldw    (11,sp),x  ;Lower-order result now in place.
            ;----------
            ;h'(0)*x(1)
            ld     a,(14,sp)  ;LSB of 65536-h
            ld     xl,a
            ld     a,(19,sp)  ;MSB of x(k)
            mul    x,a        ;Result now in X.
            addw   x,(10,sp)  ;Add the middle bytes.  Do not need to propagate the carry out,
                              ;as the maximum value possible at this stage is 255^2 + 256*255^2,
                              ;which will fit in 24 bits.  There is no possibility of a carry
                              ;into the most significant byte.
            ldw    (10,sp),x  ;Stuff the result back in the right place.
            ;----------
            ;h'(1)*x(0)
            ld     a,(13,sp)  ;MSB of 65536-h
            ld     xl,a
            ld     a,(20,sp)  ;LSB of x(k)
            mul    x,a        ;Result now in X.
            addw   x,(10,sp)  ;Add the middle bytes.  Must propagate the carry out.
            ldw    (10,sp),x  ;Stuff the middle result back in the right place.  This does
                              ;not affect the carry flag.
            jrnc   lpa_f_10   ;If the carry is clear, we don't need to increment the upper
                              ;byte.  This byte will assume the value of 0 if there is not a
                              ;carry or 1 if there is a carry, so either assign or increment
                              ;will do.
            inc    (9,sp)
lpa_f_10:
            ;----------
            ;h'(1)*x(1)
            ld     a,(13,sp)  ;MSB of 65536-h
            ld     xl,a
            ld     a,(19,sp)  ;MSB of x(k)
            mul    x,a        ;Result now in X.
            addw   x,(9,sp)   ;Add the top bytes.
            ldw    (9,sp),x   ;Stuff the top result back in the right place.
            ;================================================================================
            ;Calculate and store h * y(k-1)
            ;----------
            ;Clear out the result except for the lower two bytes.
            clrw   x
            ldw    (1,sp),x
            ldw    (3,sp),x
            ldw    (5,sp),x
            ;----------
            ;Load the pointer to the 48-bit state block into the Y register.
            ;This will make subsequent operations a bit more efficient.
            ldw    y,(15,sp)
            ;----------
            ;h(0)*y(0), Line 1
            ld     a,(22,sp)  ;h(0).
            ld     xl,a
            ld     a,(5,y)    ;y(0)
            mul    x,a
            ldw    (7,sp),x
            ;==========
            ;h(0)*y(1), Line 2
            ld     a,(22,sp)  ;h(0).
            ld     xl,a
            ld     a,(4,y)    ;y(1)
            mul    x,a
            addw   x,(6,sp)
            ldw    (6,sp),x   ;Don't need to process carry out.
            ;----------
            ;h(1)*y(0), Line 3
            ld     a,(21,sp)  ;h(1).
            ld     xl,a
            ld     a,(5,y)    ;y(0)
            mul    x,a
            addw   x,(6,sp)
            ldw    (6,sp),x   ;Stuff the result back in the right place.  This does
                              ;not affect the carry flag.
            jrnc   lpa_f_15
            inc    (5,sp)
lpa_f_15:
            ;==========
            ;h(0)*y(2), Line 4
            ;----------
            ld     a,(22,sp)  ;h(0).
            ld     xl,a
            ld     a,(3,y)    ;y(2)
            mul    x,a
            addw   x,(5,sp)
            ldw    (5,sp),x   ;Stuff the result back in the right place.
            ;----------
            ;h(1)*y(1), Line 5
            ld     a,(21,sp)  ;h(1).
            ld     xl,a
            ld     a,(4,y)    ;y(1)
            mul    x,a
            addw   x,(5,sp)
            ldw    (5,sp),x   ;Stuff the result back in the right place.  This does
                              ;not affect the carry flag.
            jrnc   lpa_f_25
            inc    (4,sp)
lpa_f_25:
            ;==========
            ;h(0)*y(3), Line 6
            ld     a,(22,sp)  ;h(0).
            ld     xl,a
            ld     a,(2,y)    ;y(3)
            mul    x,a
            addw   x,(4,sp)
            ldw    (4,sp),x   ;Stuff the result back in the right place.
            ;----------
            ;h(1)*y(2), Line 7
            ld     a,(21,sp)  ;h(1).
            ld     xl,a
            ld     a,(3,y)    ;y(2)
            mul    x,a
            addw   x,(4,sp)
            ldw    (4,sp),x   ;Stuff the result back in the right place.  This does
                              ;not affect the carry flag.
            jrnc   lpa_f_35
            inc    (3,sp)
lpa_f_35:
            ;==========
            ;h(0)*y(4), Line 8
            ld     a,(22,sp)  ;h(0).
            ld     xl,a
            ld     a,(1,y)    ;y(4)
            mul    x,a
            addw   x,(3,sp)
            ldw    (3,sp),x   ;Stuff the result back in the right place.
            ;----------
            ;h(1)*y(3), Line 9
            ld     a,(21,sp)  ;h(1).
            ld     xl,a
            ld     a,(2,y)    ;y(3)
            mul    x,a
            addw   x,(3,sp)
            ldw    (3,sp),x   ;Stuff the result back in the right place.  This does
                              ;not affect the carry flag.
            jrnc   lpa_f_45
            inc    (2,sp)
lpa_f_45:
            ;==========
            ;h(0)*y(5), Line 10
            ld     a,(22,sp)  ;h(0).
            ld     xl,a
            ld     a,(0,y)    ;y(5)
            mul    x,a
            addw   x,(2,sp)
            ldw    (2,sp),x   ;Stuff the result back in the right place.
            ;----------
            ;h(1)*y(4), Line 11
            ld     a,(21,sp)  ;h(1).
            ld     xl,a
            ld     a,(1,y)    ;y(4)
            mul    x,a
            addw   x,(2,sp)
            ldw    (2,sp),x   ;Stuff the result back in the right place.  This does
                              ;not affect the carry flag.
            jrnc   lpa_f_55
            inc    (1,sp)
lpa_f_55:
            ;==========
            ;h(1)*y(5), Line 12
            ld     a,(21,sp)  ;h(1).
            ld     xl,a
            ld     a,(0,y)    ;y(5)
            mul    x,a
            addw   x,(1,sp)
            ldw    (1,sp),x   ;Stuff the result back in the right place.
            ;================================================================================
            ;Add the integer multiplication results together into the 64-bit area.  This is
            ;the addition of (65536-h)*x(k) + h*y(k-1).  It can't overflow because of the
            ;complementary nature of h and (65536-h).
            ;----------
            ldw    x,(11,sp)  ;X has LSW of 32-bit multiplication result.
            ldw    y,(9,sp)   ;Y has MSW of 32-bit multiplication result.
            addw   x,(3,sp)   ;Add in the least significant word.  Carry may be set.
            jrnc   lpa_f_60
            incw   y          ;Propagate carry if appropriate.
lpa_f_60:   addw   y,(1,sp)   ;Add in most significant word.
            ldw    (1,sp),y   ;Stuff back MSW of result.
            ldw    (3,sp),x   ;Stuff back LSW of result.
            ;================================================================================
            ;Copy the addition result to the filter state block.
            ldw    y,(15,sp)  ;Must reload Y with the pointer to the filter state block.
            ldw    x,(1,sp)   ;Most significant word.
            ldw    (0,y),x
            ldw    x,(3,sp)   ;Middle word.
            ldw    (2,y),x
            ldw    x,(5,sp)   ;Least significant word.
            ldw    (4,y),x
            ;================================================================================
            ;Round the result to be returned to the caller.  We can just test the first
            ;fractional bit in the filter state and increment the return result if (a)it isn't
            ;already 65535 and (b)the fractional bit is set.
            ldw    x,(1,sp)
            cpw    x, #65535   ;If the value is already at the maximum, must not increment it.
            jreq   lpa_f_99
            ld     a,#128
            bcp    a,(3,sp)
            jreq   lpa_f_99    ;If first fractional bit is zero, don't round up.
            ;----------
            ;Increment the planned return value.  This is a rounding up operation, done
            ;when appropriate.
            incw   x
lpa_f_99:
            ;================================================================================
            ;Deallocate the stack frame and return.            
            addw   sp,#16     ;Unclaim 16 bytes of temporary variables on the stack.
            ret
;
            end

;-------------------------------------------------------------------------------
;End of $Id: lfu16filtafiltrxn.s,v 1.9 2010/02/25 16:58:33 dashley Exp $
;-------------------------------------------------------------------------------
;$Log: lfu16filtafiltrxn.s,v $
;Revision 1.9  2010/02/25 16:58:33  dashley
;Capitalization consistency error corrected.
;
;Revision 1.8  2010/02/20 16:07:22  dashley
;Missing switch directive added.
;
;Revision 1.7  2010/01/28 17:06:05  dashley
;Linear Filter A build mechanisms changed.
;
;Revision 1.6  2010/01/28 03:19:12  dashley
;Linear Filter A function name change.
;
;Revision 1.5  2010/01/27 00:37:52  dashley
;Name change of Linear Filter A functions.
;-------------------------------------------------------------------------------

