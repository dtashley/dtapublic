echo off
rem Line above suppresses echoing immediately, so as not to fill up the console window.
rem 
rem $Header: /cvsroot/esrg/sfesrg/esrgpcpj/doc/engman01/aprint.bat,v 1.3 2002/06/25 02:44:15 dtashley Exp $
rem
rem This batch file uses Ghostscript to print to the default Windows printer (which
rem for Dave Ashley is the LaserJet 6 in 2326).  GhostScript 7.00 must be installed
rem to use this batch file verbatim (GhostScript is available for free off the Web).
rem
rem Only "A" sides are printed by this batch file.
rem
rem To use this batch file, first use the MAKEALL.BAT
rem batch file to generate the postscript files, then use the BPRINT.BAT
rem batch file to print the B sides in reverse order, then re-insert
rem the paper in the manual feed tray and use this batch file to print
rem the A sides.
rem
c:\gs\gs7.04\bin\gswin32 -q -sDEVICE=ljet4 -dNOPAUSE em_a.ps -c quit
rem
rem $Log: aprint.bat,v $
rem Revision 1.3  2002/06/25 02:44:15  dtashley
rem Edits.
rem
rem Revision 1.2  2002/06/24 08:18:30  dtashley
rem Minor spacing change in log section of file.
rem
rem Revision 1.1  2002/06/24 08:17:05  dtashley
rem Initial checkin.
rem
rem End of APRINT.BAT
