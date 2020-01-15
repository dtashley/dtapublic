echo on
rem Be sure see all output.
rem 
rem $Header: /cvsroot/esrg/sfesrg/esrgpcpj/doc/engman01/makeall.bat,v 1.2 2002/06/24 08:18:31 dtashley Exp $
rem
rem LaTeX compile three times in a row, to resolve any complex
rem dependencies where page formatting is affected by the definition of
rem a label.
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" engman01.tex
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" engman01.tex
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" engman01.tex
rem
rem Now run MakeIndex once to get the index entries right.
c:\4tex5.0\bin\win32\makeindex.exe engman01.idx
rem
rem Another 3 LaTeX compiles to iron out any formatting issues.
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" engman01.tex
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" engman01.tex
c:\4tex5.0\bin\win32\hugetex.exe -progname=latex "&latex" engman01.tex
rem
rem Now create the PostScript files.  These can be used either to
rem make Adobe Acrobat files or to print.
c:\4tex5.0\bin\win32\dvips.exe -t letter -o"engman01.ps" engman01.dvi
c:\4tex5.0\bin\win32\dvips.exe -t letter -A -o"em_a.ps" engman01.dvi
c:\4tex5.0\bin\win32\dvips.exe -t letter -r -B -o"em_brev.ps" engman01.dvi
rem
rem We are done.
rem
rem $Log: makeall.bat,v $
rem Revision 1.2  2002/06/24 08:18:31  dtashley
rem Minor spacing change in log section of file.
rem
rem Revision 1.1  2002/06/24 08:17:05  dtashley
rem Initial checkin.
rem
rem End of MAKEALL.BAT
