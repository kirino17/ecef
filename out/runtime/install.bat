copy .\Release\ecef.fne ..\lib /y
copy .\aquarius2.dll ..\lib /y
copy .\Release\ecef_static.lib ..\static_lib\ /y
copy .\aquarius2.lib ..\static_lib\ /y
md ..\lib\ecef
md ..\lib\ecef\samples
xcopy .\Release\samples ..\lib\ecef\samples /e /c /f /y


