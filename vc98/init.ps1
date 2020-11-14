$installFolder          = (Split-Path -Parent $MyInvocation.MyCommand.Definition) + "\"
$downloadFolder         = $installFolder + "update\"
##############################################################################

# vc60-toolset configuration
$vc60ToolsetUri         = "https://github.com/kirino17/vc60/releases/download/6.02/vc60env.zip"
$vc60Folder             = $installFolder + "vc60\"
$vc60DownloadFile       = $downloadFolder + "vc60.zip"
$vc60ExecutableFolder   = $vc60Folder + "Common\MSDev98\Bin\"
$vc60VC98Folder         = $vc60Folder + "VC98\Bin\"

#############################################################################
# cmake configuration
$cmakeUri               = "https://github.com/Kitware/CMake/releases/download/v3.0.2/cmake-3.0.2-win32-x86.zip"  #version 3.0.2
$cmakeFolder            = $installFolder + "cmake\"
$cmakeDownloadFile      = $downloadFolder + "cmake302.zip"
$camkeExecutableFolder  = $cmakeFolder

#############################################################################
#############################################################################
$scriptCode = @"
    using System;
    using System.IO;

    public class Program {
        public static void Makefile(string readFilename, string writeFilename, string sourceName, string projectName, string targetName, string vcFolder){
            string output = "";
            try {
                using (StreamReader reader = new StreamReader(readFilename)){
                    string context = reader.ReadToEnd();
                    output = string.Format(context, 
                        vcFolder + `"Common`",
                        vcFolder + `"Common\\MSDev98`",
                        vcFolder + `"VC98`",
                        sourceName,
                        projectName,
                        targetName
                    );
                }
            }
            catch(Exception e){
                Console.Write(e.Message);
            }

            if(output.Length > 0){
                try{
                    using (StreamWriter writer = new StreamWriter(writeFilename)){
                        writer.Write(output);
                        writer.Flush();
                        writer.Close();
                    }
                }
                catch(Exception e){
                    Console.Write(e.Message);
                }
            }
        }
    }
"@



#############################################################################
function fetch {
    param (
        $Uri,
        $WriteToLocation
    )
    Write-Host ("fetching archive the " + $Uri + " ...")
    Invoke-WebRequest -Uri $Uri -OutFile $WriteToLocation
    Write-Host ("saved to " + $WriteToLocation)
    Write-Host "fetch finished!"

}
function installVC60 {
    do {
        # 编译环境完整性检�?
        if(!((Test-Path $vc60ExecutableFolder) -and (Test-Path ($vc60ExecutableFolder + "MSDEV.EXE")))) {
            break
        }

        if(!((Test-Path $vc60VC98Folder) -and (Test-Path ($vc60VC98Folder + "CL.EXE")) -and (Test-Path ($vc60VC98Folder + "LINK.EXE")))){
            break
        }

        return

    } while (0)

    if(!(Test-Path $vc60Folder)){
        New-Item -ItemType Directory -Force -Path $vc60Folder
    }
    else {
        Remove-Item ($vc60Folder + "*") -Recurse
    }

    Write-Host ("installing vc60 toolset: " + $vc60DownloadFile + " ...")
    if(!(Test-Path $vc60DownloadFile)){
        New-Item -ItemType Directory -Force -Path $downloadFolder
        fetch -Uri $vc60ToolsetUri -WriteToLocation $vc60DownloadFile
    }
    Write-Host "expand archive ..."
    Expand-Archive -Path $vc60DownloadFile -DestinationPath $vc60Folder
    Write-Host "install finished!"
}

function installCmake {
    $camkeBinFolder = $cmakeFolder

    if(!(Test-Path $cmakeFolder)){
        New-Item -ItemType Directory -Force -Path $cmakeFolder
    }

    Get-ChildItem $cmakeFolder | ForEach-Object -Process {
        if(($_.Attributes -eq "Directory")){
            $camkeBinFolder += $_.Name
        }
    }
    $camkeBinFolder += "\bin\"

    if($Env:Path.IndexOf($camkeBinFolder) -eq -1){
        $Env:Path = ($camkeBinFolder+";"+$Env:Path)
    }

    $Script:camkeExecutableFolder = $camkeBinFolder

    do{

        if(!(Test-Path ($camkeBinFolder + "cmake.exe"))){
            break
        }

        return

    }while(0)


    if(!(Test-Path $cmakeFolder)){
        New-Item -ItemType Directory -Force -Path $cmakeFolder
    }
    else {
        Remove-Item ($cmakeFolder + "*") -Recurse
    }

    Write-Host ("installing cmake 3.0.2 : " + $cmakeDownloadFile + " ...")
    if(!(Test-Path $cmakeDownloadFile)){
        New-Item -ItemType Directory -Force -Path $downloadFolder
        fetch -Uri $cmakeUri -WriteToLocation $cmakeDownloadFile
        Write-Host "expand archive ..."
    }
    Expand-Archive -Path $cmakeDownloadFile -DestinationPath $cmakeFolder

    $camkeBinFolder = $cmakeFolder
    Get-ChildItem $cmakeFolder | ForEach-Object -Process {
        if(($_.Attributes -eq "Directory")){
            $camkeBinFolder += $_.Name
        }
    }
    $camkeBinFolder += "\bin\"
    if($Env:Path.IndexOf($camkeBinFolder) -eq -1){
        $Env:Path = ($camkeBinFolder+";"+$Env:Path)
    }

    $Script:camkeExecutableFolder = $cmakeFolder

    Write-Host "install finished!"
}

############################################################################
############################################################################
############################################################################

installVC60
installCmake

function make {
    param (
        $Project,
        $Target,
        $SourceDir,
        $OutputDir
    )

    #此处删除该项注册表的作用为使编译器使用环境变量提供的构建环境, 不会出现安全问题�?
    Remove-Item -Path 'HKCU:\Software\Microsoft\DevStudio\6.0\Build System\Components\Platforms\Win32 (x86)\Directories'

    Set-Location -Path $OutputDir
    Add-Type -TypeDefinition $scriptCode -Language CSharp
    [Program]::Makefile(
        ($installFolder + "VCVARS32.BAT"), 
        ($OutputDir + "\AUTOMATE.BAT"), 
        $SourceDir,
        $Project,
        $Target,
        $vc60Folder
    )

    Start-Process -FilePath ".\AUTOMATE.BAT" -NoNewWindow -Wait
}

if($args.Count -ge 4){
    make -Project $args[0] -Target $args[1] -SourceDir $args[2] -OutputDir $args[3]
}






