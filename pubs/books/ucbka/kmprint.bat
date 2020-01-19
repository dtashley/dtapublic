echo off
rem Line above suppresses echoing immediately, so as not to fill up the console window.
rem 
rem $Header: svn://localhost/dtapublic/pubs/books/ucbka/trunk/kmprint.bat 140 2017-07-03 01:59:16Z dashley $
rem
rem
rem
rem
rem
rem This batch file uses Ghostscript to print to the default Windows printer (which
rem for Dave Ashley is the LaserJet 6 in 2326).  GhostScript 7.00 must be installed
rem to use this batch file verbatim (GhostScript is available for free off the Web).
rem
rem To use this batch file, first print to a file from 4AllTex, then run this
rem file.
rem
rem Remarks on the command-line below:
rem   (a)  The printing process with 4AllTex creates the _DUMP_.PS file.
rem        That is used.
rem   (b)  The LaserJet families are upward compatible.  One only needs 
rem        to specify the LaserJet 4 and it will work with an LJ6MP.
rem   (c)  "NOPAUSE" means don't pause after every page.
rem   (d)  "-q" means "quiet".
rem   (e)  "c quit" means to quit when done.  This gets the page(s) released
rem        to the printer queue.
rem  
c:\gs\gs7.04\bin\gswin32 -q -sDEVICE=ljet4 -dNOPAUSE _DUMP_.ps -c quit
rem
rem $Log: kmprint.bat,v $
rem Revision 1.6  2002/04/21 22:50:04  dtashley
rem Safety checkin before working on laptop.
rem
rem Revision 1.5  2002/01/23 10:10:37  dtashley
rem Test.
rem
rem Revision 1.4  2002/01/23 06:41:11  dtashley
rem Test.
rem
rem Revision 1.3  2002/01/23 06:38:55  dtashley
rem Test.
rem
rem Revision 1.2  2002/01/23 06:37:43  dtashley
rem Test checkin.
rem
rem Revision 1.1  2001/12/01 01:06:12  dtashley
rem Initial checkin.
rem
rem End of KMPRINT.BAT
