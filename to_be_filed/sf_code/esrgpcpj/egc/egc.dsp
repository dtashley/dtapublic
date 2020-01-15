# Microsoft Developer Studio Project File - Name="egc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=egc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "egc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "egc.mak" CFG="egc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "egc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "egc - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "egc - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\shared\tcl_base" /I "..\shared\tk_base" /I "..\shared\c_datd" /I "..\shared\c_cmode" /I "..\shared\tclxtens" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "STATIC_BUILD" /D "IJS_SM_EXEC_VERSION_TCL_BASE" /D "APP_TYPE_IJUSCRIPTER_IJUCONSOLE" /FR /FD /Zm200 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "egc - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MT /W3 /Gm /GX /ZI /Od /I "." /I "..\shared\tcl_base" /I "..\shared\tk_base" /I "..\shared\c_datd" /I "..\shared\c_cmode" /I "..\shared\tclxtens" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "STATIC_BUILD" /D "IJS_SM_EXEC_VERSION_TCL_BASE" /D "APP_TYPE_IJUSCRIPTER_IJUCONSOLE" /FR /FD /GZ /Zm200 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "egc - Win32 Release"
# Name "egc - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Msvc_Main"

# PROP Default_Filter ".c,.cpp,.rc"
# Begin Source File

SOURCE=.\egc.rc
# End Source File
# Begin Source File

SOURCE=.\egc_main.cpp
# End Source File
# End Group
# Begin Group "Tcl_Base"

# PROP Default_Filter ""
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
# Begin Group "Tcl_Extensions"

# PROP Default_Filter ".c,.h"
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

# PROP Default_Filter ".c,.h"
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
# Begin Group "Tk_Base"

# PROP Default_Filter ".c,.h"
# Begin Source File

SOURCE=..\shared\tk_base\appinit.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\stubs.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tk3d.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkargv.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkatom.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkbind.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkbitmap.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkbutton.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvarc.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvas.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvbmap.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvimg.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvline.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvpoly.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvps.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvtext.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvutil.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcanvwind.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkclipboard.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcmds.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcolor.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkconfig.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkconsole.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkcursor.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkentry.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkerror.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkevent.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkfilefilter.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkfocus.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkfont.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkframe.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkgc.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkgeometry.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkget.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkgrab.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkgrid.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkimage.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkimgbmap.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkimggif.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkimgphoto.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkimgppm.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkimgutil.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tklistbox.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkmacwinmenu.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkmain.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkmenu.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkmenubutton.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkmenudraw.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkmessage.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkobj.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkoldconfig.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkoption.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkpack.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkplace.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkpointer.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkrectoval.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkscale.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkscrollbar.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkselect.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkstubinit.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkstublib.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktext.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktextbtree.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktextdisp.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktextimage.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktextindex.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktextmark.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktexttag.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktextwind.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tktrig.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkunixmenubu.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkunixscale.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkutil.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkvisual.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwin32dll.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwin3d.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinbutton.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinclipboard.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwincolor.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinconfig.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwincursor.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwindialog.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwindow.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwindraw.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinembed.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinfont.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinimage.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwininit.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinkey.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinmenu.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinpixmap.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinpointer.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinregion.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinscrlbr.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinsend.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinwindow.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinwm.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\tkwinx.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\winmain.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\xcolors.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\xdraw.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\xgc.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\ximage.c
# End Source File
# Begin Source File

SOURCE=..\shared\tk_base\xutil.c
# End Source File
# End Group
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\egc.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\egc_icon_01_sm.ico
# End Source File
# Begin Source File

SOURCE=.\egc_icon_01_st.ico
# End Source File
# End Target
# End Project
