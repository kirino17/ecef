$OUT            = ".\out\"
$CEF_RUNTIME_INSTALL    = ($OUT + "runtime\")
$CEF_RUNTIME_DOWNLOAD   = "https://github.com/kirino17/ecef/releases/download/run80_3987/cef_80.1.16_win32_release.zip"

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

# 下载cef
if ( !(Test-Path ($CEF_RUNTIME_INSTALL+"libcef.dll"))){
    $CEF_TEMP_FILE = ($CEF_RUNTIME_INSTALL + "temp.zip")
    fetch -Uri $CEF_RUNTIME_DOWNLOAD -WriteToLocation $CEF_TEMP_FILE

    Write-Host "expand archive ..."
    Expand-Archive -Path $CEF_TEMP_FILE -DestinationPath $CEF_RUNTIME_INSTALL
    Write-Host "install finished!"

    Remove-Item -Path $CEF_TEMP_FILE
}

#检查安装路径是否已加入系统环境变量
$scriptFolder = (Split-Path -Parent $MyInvocation.MyCommand.Definition) + "\"
if( $Env:Path.IndexOf($scriptFolder) -eq -1){
    [System.Environment]::SetEnvironmentVariable("Path", ($Env:Path + ";"+$scriptFolder + "out\runtime"),"Machine")
}

#安装支持库
$EPLInstallDir = Get-Item -Path HKCU:\Software\FlySky\E\Install\
$InstallDir = $EPLInstallDir.GetValue("Path")
Remove-Item -Path ($InstallDir+"ecef.fne")
Remove-Item -Path ($InstallDir+"..\static_lib\ecef_static.lib")
Remove-Item -Path ($InstallDir+"..\static_lib\aquarius2.lib")
Copy-Item -Path ".\out\Release\ecef.fne" -Destination ($InstallDir+"ecef.fne")
Copy-Item -Path ".\out\Release\ecef_static.lib" -Destination ($InstallDir+"..\static_lib\ecef_static.lib")
Copy-Item -Path ".\out\Release\aquarius2.lib" -Destination ($InstallDir+"..\static_lib\aquarius2.lib")

Write-Host "install finished!"
