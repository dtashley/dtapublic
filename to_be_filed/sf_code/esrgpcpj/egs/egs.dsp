# Microsoft Developer Studio Project File - Name="egs" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=egs - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "egs.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "egs.mak" CFG="egs - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "egs - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "egs - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "egs - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\shared\tcl_base" /I "..\shared\c_datd" /I "..\shared\c_cmode" /I "..\shared\tclxtens" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "STATIC_BUILD" /D "IJS_SM_EXEC_VERSION_TCL_BASE" /D "APP_TYPE_IJUSCRIPTER_IJUCONSOLE" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "egs - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MT /W3 /Gm /GX /ZI /Od /I "..\shared\tcl_base" /I "..\shared\c_datd" /I "..\shared\c_cmode" /I "..\shared\tclxtens" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "STATIC_BUILD" /D "IJS_SM_EXEC_VERSION_TCL_BASE" /D "APP_TYPE_IJUSCRIPTER_IJUCONSOLE" /FR /FD /GZ /c
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

# Name "egs - Win32 Release"
# Name "egs - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Tcl_Base"

# PROP Default_Filter ".c,.cpp"
# Begin Source File

SOURCE=..\shared\tcl_base\regcomp.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\regerror.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\regexec.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\regfree.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\strftime.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclalloc.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclappinit.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclasync.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclbasic.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclbinary.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclckalloc.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclclock.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclcmdah.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclcmdil.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclcmdmz.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclcompcmds.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclcompexpr.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclcompile.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tcldate.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclencoding.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclenv.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclevent.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclexecute.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclfcmd.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclfilename.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclget.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclhash.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclhistory.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclindexobj.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclinterp.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclio.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tcliocmd.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tcliosock.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclioutil.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tcllink.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tcllistobj.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclliteral.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclload.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclmain.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclnamesp.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclnotify.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclobj.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclpanic.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclparse.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclparseexpr.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclpipe.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclpkg.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclposixstr.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclpreserve.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclproc.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclregexp.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclresolve.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclresult.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclscan.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclstringobj.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclstubinit.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclstublib.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclthread.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tcltimer.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclunidata.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclutf.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclutil.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclvar.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwin32dll.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinchan.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinconsole.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwindde.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinerror.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinfcmd.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinfile.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwininit.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinload.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinmtherr.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinnotify.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinpipe.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinreg.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinserial.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinsock.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwinthrd.c
# End Source File
# Begin Source File

SOURCE=..\shared\tcl_base\tclwintime.c
# End Source File
# End Group
# Begin Group "Msvc_Main"

# PROP Default_Filter ".c,.cpp"
# Begin Source File

SOURCE=.\egs_main.cpp
# End Source File
# End Group
# Begin Group "Extensions"

# PROP Default_Filter ".c,.cpp"
# Begin Source File

SOURCE=..\shared\tclxtens\arblenints.c
# End Source File
# Begin Source File

SOURCE=..\shared\tclxtens\build_config.c
# End Source File
# Begin Source File

SOURCE=..\shared\tclxtens\crchashextns.c
# End Source File
# Begin Source File

SOURCE=..\shared\tclxtens\credits.c
# End Source File
# Begin Source File

SOURCE=..\shared\tclxtens\extninit.c
# End Source File
# Begin Source File

SOURCE=..\shared\tclxtens\msgstrs.c
# End Source File
# Begin Source File

SOURCE=..\shared\tclxtens\pr_randa.c
# End Source File
# Begin Source File

SOURCE=..\shared\tclxtens\vcinfo.c
# End Source File
# End Group
# Begin Group "Shared_C_Data_Driven_Modules"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\shared\c_datd\bstrfunc.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\charfunc.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\crchashfuncs.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\fcmiof.c
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

SOURCE=..\shared\c_datd\intfunc.c
# End Source File
# Begin Source File

SOURCE=..\shared\c_datd\strfuncs.c
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
