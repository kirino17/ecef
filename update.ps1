$OUT            = ".\out\"
$BUILD          = ".\build\"


$VC60_INSTALL   = ".\vc98\"
$VC60_GIT       = "https://github.com/kirino17/vc60"

$CEF_RUNTIME_INSTALL    = ($OUT + "runtime\")
$CEF_RUNTIME_DOWNLOAD   = "https://github.com/kirino17/ecef/releases/download/run80_3987/cef_80.1.16_win32_release.zip"

$CEF_SOURCE_INSTALL     = ".\cef\"
$CEF_SOURCE_DOWNLOAD    = "https://github.com/kirino17/ecef/releases/download/lib80_3987/cef_80.1.16_lib_release.zip"

#######################################################################
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

if (!(Test-Path $OUT)){
    New-Item -ItemType Directory -Force -Path $OUT
}

if (!(Test-Path $BUILD)){
    New-Item -ItemType Directory -Force -Path $BUILD
}

if (!(Test-Path $VC60_INSTALL)){
    New-Item -ItemType Directory -Force -Path $VC60_INSTALL
}

if (!(Test-Path $CEF_RUNTIME_INSTALL)){
    New-Item -ItemType Directory -Force -Path $CEF_RUNTIME_INSTALL
}

if (!(Test-Path $CEF_SOURCE_INSTALL)){
    New-Item -ItemType Directory -Force -Path $CEF_SOURCE_INSTALL
}


Start-Process -FilePath "git" -ArgumentList "clone", $VC60_GIT, $VC60_INSTALL -Wait -NoNewWindow
&($VC60_INSTALL + "init.ps1")


$CEF_TEMP_FILE = ($CEF_RUNTIME_INSTALL + "temp.zip")
fetch -Uri $CEF_RUNTIME_DOWNLOAD -WriteToLocation $CEF_TEMP_FILE

Write-Host "expand archive ..."
Expand-Archive -Path $CEF_TEMP_FILE -DestinationPath $CEF_RUNTIME_INSTALL
Write-Host "install finished!"

Remove-Item -Path $CEF_TEMP_FILE

$CEF_TEMP_FILE = ($CEF_SOURCE_INSTALL + "temp.zip")
fetch -Uri $CEF_SOURCE_DOWNLOAD -WriteToLocation $CEF_TEMP_FILE

Write-Host "expand archive ..."
Expand-Archive -Path $CEF_TEMP_FILE -DestinationPath $CEF_SOURCE_INSTALL
Write-Host "install finished!"

Remove-Item -Path $CEF_TEMP_FILE

