rem $Header: /home/dashley/cvsrep/e3ft_gpl01/e3ft_gpl01/winprojs/scirfmmon/docs/man20081211a/recomp.bat,v 1.1 2008/12/11 19:46:06 dashley Exp $
rem
latex man20081211a
makeindex man20081211a
dvips -T 8.5in,11in man20081211a
rem
rem $Log: recomp.bat,v $
rem Revision 1.1  2008/12/11 19:46:06  dashley
rem Initial checkin.
rem
rem End of $RCSfile: recomp.bat,v $.