# Microsoft Developer Studio Project File - Name="CompilerIdCXX" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=CompilerIdCXX - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "CompilerIdCXX.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "CompilerIdCXX.mak" CFG="CompilerIdCXX - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "CompilerIdCXX - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /c
LINK32=link.exe
# ADD LINK32 /nologo /version:0.0 /subsystem:console /machine:x86 /out:"CompilerIdCXX.exe" /IGNORE:4089
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=for %%i in (cl.exe) do @echo CMAKE_CXX_COMPILER=%%~$PATH:i
# End Special Build Tool
# Begin Target

# Name "CompilerIdCXX - Win32 Debug"
# Begin Group "Source Files"

# Begin Source File

SOURCE="CMakeCXXCompilerId.cpp"
# End Source File
# End Group
# End Target
# End Project
