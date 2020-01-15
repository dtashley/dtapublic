rem $Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/webprojs/pamc/gen_a/docs/manual/man_a/recomp.bat,v 1.2 2007/07/07 03:31:53 dashley Exp $
rem
latex man_a
makeindex man_a
dvips -T 8.5in,11in man_a
rem
rem $Log: recomp.bat,v $
rem Revision 1.2  2007/07/07 03:31:53  dashley
rem Edits.
rem
rem Revision 1.1  2007/04/09 03:14:00  dashley
rem Initial checkin.
rem
rem End of $RCSfile: recomp.bat,v $.