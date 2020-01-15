;$Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/dtaipubs/cron/2007/cpu08div16by16a/div16e16x16.s,v 1.4 2007/05/26 17:48:46 dashley Exp $:
;------------------------------------------------------------------------------
        xdef        c_udiv, c_umod
        xref.b        c_reg
        .dcall        "9,0,c_umod"
        .dcall        "7,0,c_udiv"
;
;Function Entry Conditions:
;  NH in C_REG (a zero-page, i.e. direct addressing variable)
;  NL in A
;  DH in H
;  DL in X
;
;Function Exit Conditions
;  QH in C_REG
;  QL in A
;  RH in H
;  RL in X
;  Stack pointer (naturally) restored.
;  No restrictions on condition codes (can be arbitrarily changed).
;  No restrictions on other CPU registers (can be arbitrarily changed).
;
c_udiv:
        psha                        ; save NL
        pshh                        ; DH on the stack
        tst        1,sp                ; test zero
        bne        full                ; full division
;
;Short divisor division.
;Divisor <= 255 (and may also be zero).
;
;Note to MJB:  your staff did a better job on this than
;me.  I had 48 clocks, this path seems to be 45.
;        
        pulh            ; clean stack
        lda    c_reg    ; NH in A
        clrh            ; 1st divide 8 X 8
        div             ; divide (H:A)/(X) -> A with remainder H
        sta    c_reg    ; QH in place
        pula            ; complete dividend with NL
        div             ; divide
        pshh            ; move RL
        pulx            ; in X
        clrh            ; RH is zero
        rts             ; and return
;
;Long Divisor Division
;
;Mathematical Assertions
;   Divisor >= 256 (and is definitely not zero).
;   Numerator can be any value.
;   Quotient <= 255.
;   Remainder may be two bytes.
;
;Entry Conditions
;  Stack frame already grown by 2 (and could use 1,SP and 2,SP
;  for intermediate results).
;  NH in C_REG (a zero-page, i.e. direct addressing variable)
;  NL in A and 2,SP
;  DH in H and 1,SP
;  DL in X
;
full:
        pshx            ; save DL
        psha            ; start with
        lda    c_reg    ; dividend
        psha
        ;
        ;Stack condition
        ;  1,SP NH
        ;  2,SP NL
        ;  3,SP DL
        ;  4,SP DH
        ;  5,SP NL
        ;Due to redundancy, can probably re-use 5,SP for
        ;something else.
        ;
        lda    4,sp     ; DH
        ;
        ;Shift the numerator and denominator right until the denominator
        ;just fits in one byte.  At least one shift will be required,
        ;because the denominator is known to be >= 256, hence the
        ;do-while() rather than while() loop.
        ;
sbcl:
        lsr    1,sp
        ror    2,sp
        lsra
        rorx
        tsta
        bne    sbcl
;
;DTA note:  the loop above looks excellent.  No real fat.  The only
;optimizations that seems possible are (a) to use c_reg to shift one byte
;of the numerator in so that a 4-cycle rather than a 5-cycle instruction
;is used, or (b) to use X rather than SP so that have 2 4-cycle rather than
;2 5-cycle instructions.
;
;Do the initial digit estimation division.  Knuth calls out the possibility of
;an overflow, and that an overflow should be replaced by a quotient of 255.
;Not sure if an overflow is possible.  0 <= N <= 65535, and 256 <= D <= 65535.
;Assuming max N and min D after one shift gives 32767/128 = 255, still safe.
;Need to be more rigorous about the math to be sure that overflow not possible
;on the division.  Note also that Knuth's algorithm calls for left-shifting to
;normalize and for the creation of an extra digit (in our case, extra byte).
;Because we have bounds on the divisor going in, right-shifting gives the same
;effect for us.  There may be something about the setup that changes Knuth's
;assumptions that overflow is possible.  Will need to revisit this and prove
;it rigorously.
;
        txa
        pulh
        pulx
        div
;
;Let:
;  N be the numerator in to the function.
;  D be the denominator in to the function.
;  Q be the actual quotient.
;  R be the actual remainder.
;  Z(0) be the first trial quotient we calculated.
;  Z(-1) be the trial quotient reduced by one.
;  Z(-2) be the trial quotient reduced by two.
;  Z() be the trial quotient we are working with at some
;     point in time.
;
;The original MJB approach was to reconstruct Z * D, then
;subtract D up to twice to get Z(-1) * D and Z(-2) * D.  That seemed to
;bloat the code.  Let's try instead (to save FLASH) to loop using
;multiplication until N - (Z() * D) < D, or equivalently
;that Z() * D > N - D.  We've gotta use the first expression, however,
;because the second would require either an exception case or 2's
;complement arithmetic and a third byte if N < D.
;
;
;                     +-------------------------------------+
;                     | Entry Condition: have Z(0)          |
;                     | calculated.                         |
;                     +-------------------------------------+ 
;                                       | 
;                                       |
;                                      \|/
;                     +-------------------------------------+/
;                     | Calculate Z() * D                   |------+
;                     +-------------------------------------+\     |
;                                       |                          |
;                                       |                          |
;                                      \|/                         |
;                   Y +-------------------------------------+      |
;               +-----| Z() * D > 65535 ?                   |      |
;               |     +-------------------------------------+      |
;               |                       | N                        |
;               |                       |                          |
;               |                      \|/                         |
;               |     +-------------------------------------+      |
;               |     | Calculate N - Z() * D               |      |
;               |     +-------------------------------------+      |
;               |                       |                          |
;               |                       |                          |
;               |                      \|/                         |
;               |     +-------------------------------------+      |
;               |     | N - Z() * D < D ?                   |------------+
;               |     +-------------------------------------+      |     |
;               |                       |                          |     |
;               |                       |                          |     |
;               |                      \|/                         |     |
;               |    \+-------------------------------------+      |     |
;               +-----| Z() --                              |------+     |
;                    /+-------------------------------------+            |
;                                                                        |
;                                       +--------------------------------+
;                                       |
;                                      \|/
;                                     Done
;
;Stack Frame Setup
;  Keeping track of the stack frame is a lot of work before everything is
;  refined, so will just use the instructions and pretend the stack frame
;  has been enlarged via AIS.  (Note that I've swapped DH and DL below--they
;  seemed to be out of order from before.)
;
;  Imaginary Stack Setup
;    1,SP NH
;    2,SP NL
;    3,SP DH
;    4,SP DL
;    5,SP Z(0)
;    6,SP Z() * D, High Byte
;    7,SP Z() * D, Low Byte
;    8,SP N - Z() * D, High Byte
;    9,SP N - Z() * D, Low Byte
;    
;
        sta    5,sp     ;Save Z(0).
        ;
nextz:        
        ;-------------------
        ;Calculate Z() * D
        ;-------------------
        ldx    4,sp
        mul             ;Lower product in X:A.
        sta    7,sp
        stx    8,sp
        lda    5,sp
        ldx    3,sp
        mul             ;Upper product in X:A.
        tstx
        bne    p2big    ;If the MSB of the upper product (byte 3) isn't zero,
                        ;this automatically implies that Z() is too big.  It may
                        ;be possible to shave out this test ... requires more
                        ;analysis.
        add    6,sp
        bcs    p2big    ;If there is a carry out of adding the MSB in, this is
                        ;also an automatic cue that Z() is too big.  It may
                        ;be possible to shave out this test ... requires more
                        ;analysis.
        sta    6,sp     ;Put result back.  (6,sp):(7,sp) now contains product,
                        ;and it definitely fits in 16 bits.
        ;
        ;-----------------------
        ;Calculate N - Z() * D
        ;-----------------------
        lda    2,sp
        sub    7,sp
        sta    9,sp
        lda    1,sp
        sub    6,sp
        sta    8,sp
        bcs    p2big    ;If N-Z()*D is negative, Z() is too big.
        
        ;-------------------------------
        ;Compare N - Z() * D against D
        ;-------------------------------
        ;Branches below are imaginary -- too lazy to look up the
        ;instructions right now.
        ;-------------------------------
        lda    3,sp
        cmp    8,sp
        bcc    zwrong   ;Need to look up right branches.
        lda    4,sp
        cmp    9,sp
        bcc    zwrong   ;Need to look up right branches.
        bra    zright
        
        ;-------------------------------
        ;Z() --
        ;-------------------------------
p2big:        
zwrong:
        dec    5,sp
        lda    5,sp
        bra    nextz                                
                        
;At this point, the remainder is definitely is (8,sp):(9,sp), and
;the quotient is in 5,sp.  Set up and return.
zright:
        lda    8,sp
        psha
        pulh            ;MSB of remainder in H.
        ldx    9,sp     ;LSB of remainder in X.
        
        clr    c_reg    ;MSB of quotient zero.
        lda    5,sp     ;LSB of quotient in A.
                
        ais     #8      ;Adjust stack.  Imaginary offset.
        
        rts             ;And return
;
        end
;------------------------------------------------------------------------------
;$Log: div16e16x16.s,v $
;Revision 1.4  2007/05/26 17:48:46  dashley
;Preliminary alternate solution in place.
;
;Revision 1.3  2007/05/26 16:13:10  dashley
;Safety checkin after substantial edits.
;
;Revision 1.2  2007/05/25 23:34:31  dashley
;Proposed Knuth solution integrated into version-control system.
