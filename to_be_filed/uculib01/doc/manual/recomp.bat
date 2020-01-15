rem $Header: /home/dashley/cvsrep/uculib01/uculib01/doc/manual/recomp.bat,v 1.3 2007/08/30 14:11:50 dtashley Exp $
rem ---------------------------------------------------------------------------
rem When producing a final document, this batch file should be run at least 
rem three times to resolve all references and index entries.  During
rem development, once may be enough depending on what references and/or
rem index entries have changed.
rem ---------------------------------------------------------------------------
latex man_20070828
makeindex man_20070828
dvips -T 8.5in,11in man_20070828
rem ---------------------------------------------------------------------------
rem End of $RCSfile: recomp.bat,v $.