# Microsoft Developer Studio Project File - Name="unittest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=unittest - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "unittest.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "unittest.mak" CFG="unittest - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "unittest - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "unittest - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "unittest - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\shared\c_datd" /I "..\shared\c_cmode" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "APP_TYPE_SIMPLE_DOS_CONSOLE" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "unittest - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "../shr_c_cm" /I "..\shared\c_datd" /I "..\shared\c_cmode" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "APP_TYPE_SIMPLE_DOS_CONSOLE" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "unittest - Win32 Release"
# Name "unittest - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\bsf_test.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\bstrfunc.c
# End Source File
# Begin Source File

SOURCE=.\c_main.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_cmode\ccmalloc.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_cmode\ccmfatal.c
# End Source File
# Begin Source File

SOURCE=.\cf_test.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\charfunc.c
# End Source File
# Begin Source File

SOURCE=.\cmiotest.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\esrg_int_def.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\esrg_rand_int.c
# End Source File
# Begin Source File

SOURCE=.\esrg_rand_int_test.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\esrg_win_int64.c
# End Source File
# Begin Source File

SOURCE=.\esrg_win_int64_test.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\fcmiof.c
# End Source File
# Begin Source File

SOURCE=.\ginttest.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\gmp_ialg.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\gmp_ints.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\gmp_ralg.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\gmp_rats.c
# End Source File
# Begin Source File

SOURCE=.\grattest.c
# End Source File
# Begin Source File

SOURCE=.\if_test.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\intfunc.c
# End Source File
# Begin Source File

SOURCE=.\unittest.cpp
# End Source File
# Begin Source File

SOURCE=.\vs_test.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\vstrings.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
