# Microsoft Developer Studio Project File - Name="ecef" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=ecef - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ecef.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ecef.mak" CFG="ecef - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ecef - Win32 MinSizeRel" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ecef - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ecef - Win32 RelWithDebInfo" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ecef - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# ITK DSP Header file
# This file is read by the build system of itk, and is used as the top part of
# a microsoft project dsp header file
# IF this is in a dsp file, then it is not the header, but has
# already been used, so do not edit here...

# variables to REPLACE
# 
# BUILD_INCLUDES == include path
#   == compiler defines
# E:\ecef\out\runtime == override in output directory
# ecef  == name of output library

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
        
!IF  "$(CFG)" == "ecef - Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "E:\ecef\out\runtime\Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "ecef_EXPORTS" /FD /c
# ADD CPP /nologo /D "WIN32" /D "_WINDOWS" /D "_USRDLL"  /FD /c
# ADD CPP  /I "E:\ecef\src\aquarius2"   /D "ecef_EXPORTS"
# ADD CPP  /DWIN32 /D_WINDOWS /W3 /Zm1000 /GR /GX /MT /D "_MBCS" 
# ADD CPP /MD /O2 /Ob2 /D NDEBUG -DCMAKE_INTDIR=\"Release\"  /MT 
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC  /I "E:\ecef\src\aquarius2" /l 0x409 /d "NDEBUG"
# ADD RSC  
# ADD RSC  
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:I386
# ADD LINK32 /nologo /dll /version:0.0 /machine:I386 /out:"E:\ecef\out\runtime\Release/ecef.fne" /implib:E:\ecef\out\runtime\Release\ecef.lib
# ADD LINK32 /LIBPATH:E:\ecef\src\..\out\runtime\$(IntDir) /LIBPATH:E:\ecef\src\..\out\runtime
# ADD LINK32 aquarius2.lib
# ADD LINK32  /machine:X86  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /INCREMENTAL:NO


# Begin Special Build Tool
# End Special Build Tool


!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "E:\ecef\out\runtime\Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "ecef_EXPORTS" /FD /c
# ADD CPP /nologo /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL"  /FD /c
# ADD CPP  /I "E:\ecef\src\aquarius2"    /D "ecef_EXPORTS"
# ADD CPP  /DWIN32 /D_WINDOWS /W3 /Zm1000 /GR /GX /MT /D "_MBCS" 
# ADD CPP /D_DEBUG /MDd /Zi /Ob0 /Od /GZ -DCMAKE_INTDIR=\"Debug\"  /MT 
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC  /I "E:\ecef\src\aquarius2" /l 0x409 /d "_DEBUG"
# ADD RSC  
# ADD RSC  
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /dll /version:0.0 /debug /machine:I386 /out:"E:\ecef\out\runtime\Debug/ecef.fne" /pdbtype:sept /implib:E:\ecef\out\runtime\Debug\ecef.lib
# ADD LINK32 /LIBPATH:E:\ecef\src\..\out\runtime\$(IntDir) /LIBPATH:E:\ecef\src\..\out\runtime
# ADD LINK32 aquarius2.lib
# ADD LINK32  /machine:X86  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /debug /pdbtype:sept /INCREMENTAL:YES


# Begin Special Build Tool
# End Special Build Tool


!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "MinSizeRel"
# PROP BASE Intermediate_Dir "MinSizeRel"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "E:\ecef\out\runtime\MinSizeRel"
# PROP Intermediate_Dir "MinSizeRel"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /D "WIN32"  /D "_WINDOWS" /D "_USRDLL" /FD /c  /D "ecef_EXPORTS"
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /D "WIN32" /D "_WINDOWS" /D "_USRDLL"  /FD /c
# ADD CPP  /I "E:\ecef\src\aquarius2"   /D "ecef_EXPORTS"
# ADD CPP  /DWIN32 /D_WINDOWS /W3 /Zm1000 /GR /GX /MT /D "_MBCS" 
# ADD CPP /MD /O1 /Ob1 /D NDEBUG -DCMAKE_INTDIR=\"MinSizeRel\"  /MT 
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC  /I "E:\ecef\src\aquarius2" /l 0x409 /d "NDEBUG"
# ADD RSC  
# ADD RSC  
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32  /nologo /dll /machine:I386 
# ADD LINK32 /nologo /dll /version:0.0 /machine:I386 /out:"E:\ecef\out\runtime\MinSizeRel/ecef.fne" /implib:E:\ecef\out\runtime\MinSizeRel\ecef.lib
# ADD LINK32 /LIBPATH:E:\ecef\src\..\out\runtime\$(IntDir) /LIBPATH:E:\ecef\src\..\out\runtime
# ADD LINK32 aquarius2.lib
# ADD LINK32  /machine:X86  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /INCREMENTAL:NO


# Begin Special Build Tool
# End Special Build Tool


!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "RelWithDebInfo"
# PROP BASE Intermediate_Dir "RelWithDebInfo"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1         
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "E:\ecef\out\runtime\RelWithDebInfo"
# PROP Intermediate_Dir "RelWithDebInfo"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /D "WIN32" /D "_WINDOWS" /D "_USRDLL" /D "ecef_EXPORTS" /FD /c
# ADD CPP /nologo /D "WIN32" /D "_WINDOWS" /D "_USRDLL"  /FD /c
# ADD CPP  /I "E:\ecef\src\aquarius2"    /D "ecef_EXPORTS"
# ADD CPP  /DWIN32 /D_WINDOWS /W3 /Zm1000 /GR /GX /MT /D "_MBCS" 
# ADD CPP /MD /Zi /O2 /Ob1 /D NDEBUG -DCMAKE_INTDIR=\"RelWithDebInfo\"  /MT 
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC  /I "E:\ecef\src\aquarius2" /l 0x409 /d "NDEBUG"
# ADD RSC  
# ADD RSC  
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /dll /version:0.0 /debug /machine:I386 /pdbtype:sept /out:"E:\ecef\out\runtime\RelWithDebInfo/ecef.fne" /implib:E:\ecef\out\runtime\RelWithDebInfo\ecef.lib
# ADD LINK32 /LIBPATH:E:\ecef\src\..\out\runtime\$(IntDir) /LIBPATH:E:\ecef\src\..\out\runtime
# ADD LINK32 aquarius2.lib
# ADD LINK32  /machine:X86  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /debug /pdbtype:sept /INCREMENTAL:YES


# Begin Special Build Tool
# End Special Build Tool


!ENDIF 

# Begin Target

# Name "ecef - Win32 Release"
# Name "ecef - Win32 Debug"
# Name "ecef - Win32 MinSizeRel"
# Name "ecef - Win32 RelWithDebInfo"
# Begin Source File

SOURCE=E:\ecef\src\CMakeLists.txt

!IF  "$(CFG)" == "ecef - Win32 Release"
USERDEP__HACK=\
	E:\ecef\src\CMakeLists.txt\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Templates\CMakeVisualStudio6Configurations.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeSystem.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerId.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CompilerId\VS-6.dsp.in\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeFindBinUtils.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeClDeps.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-CXX.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerId.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CompilerId\VS-6.dsp.in\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeFindBinUtils.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeClDeps.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeSystemSpecificInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeGenericSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\WindowsPaths.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC-C.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Templates\CMakeVisualStudio6Configurations.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeRCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeRCInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCommonLanguageInclude.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCompilerCommon.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerABI.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeParseImplicitLinkInfo.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompilerABI.c\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC-CXX.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCommonLanguageInclude.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCompilerCommon.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerABI.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeParseImplicitLinkInfo.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompilerABI.cpp\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCXXCompiler.cmake\
	E:\ecef\src\msvcpch.cmake\
	E:\ecef\src\CMakeLists.txt
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Custom Rule E:/ecef/src/CMakeLists.txt

ecef_static.dsp.cmake :  "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\bin\cmake.exe -HE:/ecef/src -BE:/ecef/build\
	if errorlevel 1 goto :VCReportError

# End Custom Build

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"
USERDEP__HACK=\
	E:\ecef\src\CMakeLists.txt\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Templates\CMakeVisualStudio6Configurations.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeSystem.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerId.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CompilerId\VS-6.dsp.in\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeFindBinUtils.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeClDeps.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-CXX.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerId.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CompilerId\VS-6.dsp.in\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeFindBinUtils.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeClDeps.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeSystemSpecificInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeGenericSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\WindowsPaths.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC-C.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Templates\CMakeVisualStudio6Configurations.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeRCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeRCInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCommonLanguageInclude.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCompilerCommon.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerABI.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeParseImplicitLinkInfo.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompilerABI.c\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC-CXX.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCommonLanguageInclude.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCompilerCommon.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerABI.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeParseImplicitLinkInfo.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompilerABI.cpp\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCXXCompiler.cmake\
	E:\ecef\src\msvcpch.cmake\
	E:\ecef\src\CMakeLists.txt
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Custom Rule E:/ecef/src/CMakeLists.txt

ecef_static.dsp.cmake :  "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\bin\cmake.exe -HE:/ecef/src -BE:/ecef/build\
	if errorlevel 1 goto :VCReportError

# End Custom Build

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"
USERDEP__HACK=\
	E:\ecef\src\CMakeLists.txt\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Templates\CMakeVisualStudio6Configurations.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeSystem.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerId.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CompilerId\VS-6.dsp.in\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeFindBinUtils.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeClDeps.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-CXX.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerId.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CompilerId\VS-6.dsp.in\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeFindBinUtils.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeClDeps.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeSystemSpecificInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeGenericSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\WindowsPaths.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC-C.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Templates\CMakeVisualStudio6Configurations.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeRCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeRCInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCommonLanguageInclude.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCompilerCommon.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerABI.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeParseImplicitLinkInfo.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompilerABI.c\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC-CXX.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCommonLanguageInclude.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCompilerCommon.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerABI.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeParseImplicitLinkInfo.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompilerABI.cpp\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCXXCompiler.cmake\
	E:\ecef\src\msvcpch.cmake\
	E:\ecef\src\CMakeLists.txt
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Custom Rule E:/ecef/src/CMakeLists.txt

ecef_static.dsp.cmake :  "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\bin\cmake.exe -HE:/ecef/src -BE:/ecef/build\
	if errorlevel 1 goto :VCReportError

# End Custom Build

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"
USERDEP__HACK=\
	E:\ecef\src\CMakeLists.txt\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Templates\CMakeVisualStudio6Configurations.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeSystem.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerId.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CompilerId\VS-6.dsp.in\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeFindBinUtils.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeClDeps.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-CXX.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerId.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CompilerId\VS-6.dsp.in\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeFindBinUtils.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeClDeps.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeSystemSpecificInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeGenericSystem.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\WindowsPaths.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC-C.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Templates\CMakeVisualStudio6Configurations.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeRCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeRCInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestRCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCommonLanguageInclude.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCompilerCommon.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerABI.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeParseImplicitLinkInfo.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompilerABI.c\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXInformation.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC-CXX.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\Platform\Windows-MSVC.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCommonLanguageInclude.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCXXCompiler.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeTestCompilerCommon.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeDetermineCompilerABI.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeParseImplicitLinkInfo.cmake\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompilerABI.cpp\
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\share\cmake-3.0\Modules\CMakeCXXCompiler.cmake.in\
	E:\ecef\build\CMakeFiles\3.0.2\CMakeCXXCompiler.cmake\
	E:\ecef\src\msvcpch.cmake\
	E:\ecef\src\CMakeLists.txt
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Custom Rule E:/ecef/src/CMakeLists.txt

ecef_static.dsp.cmake :  "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	E:\ecef\vc98\cmake\cmake-3.0.2-win32-x86\bin\cmake.exe -HE:/ecef/src -BE:/ecef/build\
	if errorlevel 1 goto :VCReportError

# End Custom Build

!ENDIF

# End Source File
# Begin Group "Source Files"
# PROP Default_Filter ""
# Begin Source File

SOURCE=E:\ecef\src\ecef.def

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\ecef.rc

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\ecef.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLChromium.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLMain.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyActiveBrowserCallback.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyAuthCallback.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyBase.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyBrowser.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyBrowserSettings.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyCollection.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyCommandLine.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyContextMenuParams.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyCookie.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyCookieManager.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyDictionaryValue.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyDOMDocument.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyDOMNode.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyDownloadItem.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyExtension.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyFileDialogCallback.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyFrame.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyGetExtensionResourceCallback.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyJSDialogCallback.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyListValue.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyMenuModel.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyPostDataElement.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyQueryCallback.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyRequest.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyResponse.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyResponseFilter.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyRunContextMenuCallback.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyServer.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxySettings.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyURLRequest.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyValue.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyWaitableEvent.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyWebSocket.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\EPLProxyWindowInfo.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\stdafx.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP /Ycstdafx.h /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP /Ycstdafx.h /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP /Ycstdafx.h /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP /Ycstdafx.h /TP 

!ENDIF

# End Source File
# Begin Source File

SOURCE=E:\ecef\src\untshare.cpp

!IF  "$(CFG)" == "ecef - Win32 Release"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 Debug"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 MinSizeRel"

# ADD CPP  /TP 

!ELSEIF  "$(CFG)" == "ecef - Win32 RelWithDebInfo"

# ADD CPP  /TP 

!ENDIF

# End Source File
# End Group
# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
