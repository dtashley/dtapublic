rem $Header: /cvsroot/esrg/sfesrg/esrgpcpj/batbuild/releases.bat,v 1.18 2002/05/22 08:31:33 dtashley Exp $
rem
rem This batch file builds releases, assuming that Microsoft Visual Studio
rem is installed in the default locations.  This is a huge labor-saver when
rem preparing a new version of the tool set.
rem
rem *************************************************************************
rem CFBRAPAB
    cd c:\esrgpcpj\cfbrapab
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" cfbrapab.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem CFRATNUM
    cd c:\esrgpcpj\cfratnum
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" cfratnum.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem CRC32
    cd c:\esrgpcpj\crc32
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" crc32.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem ESRGCONSOLE
    cd c:\esrgpcpj\egc
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" egc.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem ESRGSCRIPTER
    cd c:\esrgpcpj\egs
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" egs.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem GFSW
    cd c:\esrgpcpj\gfsw
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" gfsw.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem HYREACH
    cd c:\esrgpcpj\hyreach
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" hyreach.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTADD
    cd c:\esrgpcpj\intadd
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intadd.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTDIV
    cd c:\esrgpcpj\intdiv
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intdiv.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTEXP
    cd c:\esrgpcpj\intexp
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intexp.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTFAC
    cd c:\esrgpcpj\intfac
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intfac.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTGCD
    cd c:\esrgpcpj\intgcd
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intgcd.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTLCM
    cd c:\esrgpcpj\intlcm
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intlcm.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTMOD
    cd c:\esrgpcpj\intmod
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intmod.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTMUL
    cd c:\esrgpcpj\intmul
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intmul.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem INTSUB
    cd c:\esrgpcpj\intsub
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" intsub.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem MD5
    cd c:\esrgpcpj\md5
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" md5.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem RANDFILE
    cd c:\esrgpcpj\randfile
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" randfile.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem RNADD
    cd c:\esrgpcpj\rnadd
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" rnadd.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem RNDEQ
    cd c:\esrgpcpj\rndeq
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" rndeq.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem RNDIV
    cd c:\esrgpcpj\rndiv
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" rndiv.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem RNMUL
    cd c:\esrgpcpj\rnmul
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" rnmul.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
    RNRED
    cd c:\esrgpcpj\rnred
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" rnred.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem RNSUB
    cd c:\esrgpcpj\rnsub
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" rnsub.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
rem UNITTEST
    cd c:\esrgpcpj\unittest
    "c:\program files\microsoft visual studio\common\msdev98\bin\msdev.exe" unittest.dsp /MAKE "ALL" /REBUILD
rem
rem *************************************************************************
    cd c:\esrgpcpj\batbuild
rem *************************************************************************
rem $Log: releases.bat,v $
rem Revision 1.18  2002/05/22 08:31:33  dtashley
rem Miscellaneous edits, and MD5 command-line utility ready for review.
rem
rem Revision 1.17  2002/05/16 04:24:29  dtashley
rem Addition of UNITTEST.
rem
rem Revision 1.16  2002/05/15 11:17:37  dtashley
rem Edits.
rem
rem Revision 1.15  2002/04/28 06:15:48  dtashley
rem Safety checkin.
rem
rem Revision 1.14  2002/01/30 10:47:11  dtashley
rem MD5 utility, although not implemented, enabled in build.
rem
rem Revision 1.13  2002/01/28 13:42:22  dtashley
rem Completion of EGC port.
rem
rem Revision 1.12  2002/01/28 08:41:09  dtashley
rem EGS (replacement for IJS) successfully added.
rem
rem Revision 1.11  2002/01/28 05:27:49  dtashley
rem RNDIV, RNMUL, RNRED, and RNSUB brought under new directory structure.
rem
rem Revision 1.10  2002/01/27 17:58:15  dtashley
rem CRC32, other programs modified to work under new directory structure.
rem
rem Revision 1.9  2002/01/27 15:04:14  dtashley
rem HYREACH added to batch build (which required some changes in other programs.
rem
rem Revision 1.8  2002/01/27 11:41:45  dtashley
rem INTDIV, INTEXP, INTFAC, INTGCD, INTLCM, INTMOD, INTMUL, and INTSUB ported to new directory structure.
rem
rem Revision 1.7  2002/01/27 10:51:04  dtashley
rem Intadd changed over to new directory structure.
rem
rem Revision 1.6  2002/01/27 10:45:41  dtashley
rem Intadd changed over to new directory structure.
rem
rem Revision 1.5  2001/08/12 10:20:57  dtashley
rem Safety check-in.  Substantial progress.
rem
rem Revision 1.4  2001/08/10 01:59:31  dtashley
rem Renaming of INTLCD to INTLCM.
rem
rem Revision 1.3  2001/07/26 04:55:48  dtashley
rem Addition of CRC32 and MD5 command-line utilities.  Addition of
rem software module to support CRC and HASH functions.
rem
rem Revision 1.2  2001/07/26 03:53:17  dtashley
rem Utilities that are under constructions stubbed to announce this,
rem batch build file enhanced.
rem
rem Revision 1.1  2001/07/25 22:02:10  dtashley
rem Initial check-in.
rem
rem *************************************************************************
rem End of RELEASES.BAT.

