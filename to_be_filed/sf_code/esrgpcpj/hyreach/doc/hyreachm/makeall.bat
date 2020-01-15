echo on
rem Be sure see all output.
rem 
rem $Header: /cvsroot/esrg/sfesrg/esrgpcpj/hyreach/doc/hyreachm/makeall.bat,v 1.3 2001/10/31 04:31:37 dtashley Exp $
rem
rem LaTeX compile three times in a row, to resolve any complex
rem dependencies where page formatting is affected by the definition of
rem a label.
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" hyreachm.tex
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" hyreachm.tex
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" hyreachm.tex
rem
rem Now run MakeIndex once to get the index entries right.
c:\4tex5.0\bin\win32\makeindex.exe hyreachm.idx
rem
rem Another 3 LaTeX compiles to iron out any formatting issues.
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" hyreachm.tex
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" hyreachm.tex
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" hyreachm.tex
rem
rem Now create the PostScript files.  These can be used either to
rem make Adobe Acrobat files or to print.
c:\4tex5.0\bin\win32\dvips.exe -t letter -o"hyreachm.ps" hyreachm.dvi
c:\4tex5.0\bin\win32\dvips.exe -t letter -A -o"hy_a.ps" hyreachm.dvi
c:\4tex5.0\bin\win32\dvips.exe -t letter -r -B -o"hy_brev.ps" hyreachm.dvi
rem
rem We are done.
rem
rem $Log: makeall.bat,v $
rem Revision 1.3  2001/10/31 04:31:37  dtashley
rem Nightly safety checkin.
rem
rem Revision 1.2  2001/10/30 22:08:24  dtashley
rem Edits.
rem
rem Revision 1.1  2001/10/30 21:15:57  dtashley
rem Initial checkin.
rem
rem End of MAKEALL.BAT
