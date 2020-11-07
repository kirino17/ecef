# 文件说明与可裁剪性
一个完整的水星浏览器发布资源如下:
```bash
    /swiftshader
    /locales
    aquarius2.dll
    cef.pak
    cef_100_percent.pak
    cef_200_percent.pak
    cef_extensions.pak
    chrome_elf.dll
    d3dcompiler_47.dll
    devtools_resources.pak
    libcef.dll
    libEGL.dll
    libGLESv2.dll
    icudtl.dat
    snapshot_blob.bin
    spare-proc.exe
    v8_context_snapshot.bin
```
不可裁剪资源:<br/>

`libcef.dll`<br/>
CEF 核心动态库文件<br/>

`chrome_elf.dll`<br/>
用于报告崩溃信息的动态库文件<br/>

`icudlt.dat`<br/>
Unicode支持数据<br/>

`snapshot_blob.bin`<br/>
`v8_context_snapshot.bin` <br/>
V8 快照数据<br/>

`locales/`<br/>
Unicode支持数据<br/>

`aquarius2.dll/`<br/>
支持库CEF适配接口动态链接库文件<br/>

`spare-proc.exe/`<br/>
支持库多进程模式下提供的默认子进程程序实现<br/>

--------------------------
可裁剪资源( 如果以下这些资源文件丢失,将不会影响到CEF的运行, 但与此相关的所有功能可能会损坏或者无法使用 ):<br/>

`*本地化资源`<br/>
可以使用以下命令完全禁用区域设置文件的加载, `CefSettings.pack_loading_disabled`(对应支持库命令为: `Chromium进程设置.设置禁止加载资源`)。<br/>

`*locales/`<br/>
包含CEF, Chromium和Blink使用的本地化资源的目录。每一个个`.pak`文件代表一种语言环境, CEF将根据CefSettings.locale的值从此目录中加载( 对应支持库命令为: `Chromium进程设置.设置语言环境` )。如果没有设置该值,将使用默认的语言环境"en-US"。没有这些文件所有的Web组件可能显示不正确。<br/>

`*其它资源`<br/>
可以使用以下命令完全禁用打包文件的加载, `CefSettings.pack_loading_disabled`(对应支持库命令为: `Chromium进程设置.设置禁止加载资源`)。<br/>

`*cef.pak`<br/>
`*cef_100_percent.pak`<br/>
`*cef_200_percent.pak`<br/>
这些文件包含CEF, Chromium和Blink使用的非本地化资源。没有这些文件, 所有的Web组件可能无法正确显示。<br/>

`*cef_extensions.pak`<br/>
此文件包含加载扩展所需的非本地化资源。传递`--disable-extensions`命令行标志可以禁用此功能文件。如果扩展系统缺少此文件则组件(例如: PDF viewer)将无法运作。<br/>

`*devtools_resources.pak`<br/>
此文件包含Chrome开发者工具所需要的非本地化资源。没有该文件,Chrome开发者工具将无法运行。<br/>

`*角度和Direct3D支持`<br/>
`*d3dcompiler_47.dll` (Windows Vista 和 更高的版本需要)<br/>
`*libEGL.dll`<br/>
`*libGLESv2.dll`<br/>
没有这些文件, 将无法加速HTML5、2D画布, 3D CSS和WebGL等内容的运行。<br/>

`*SwitfShader支持`<br/>
`*switfshader/libEGL.dll`<br/>
`*switfshader/libGLESv2.dll`<br/>
如果没有这些文件,则当GPU不可用时, WebGL将无法在纯软件模式下运行。

------------------------

<link rel="stylesheet" href="gitalk.min.css">
<script src="gitalk.min.js"></script>
<div id="gitalk-containerfileexpandcul"></div>
<script>
    var gitalk = new Gitalk({
        clientID: 'd17d49be2e680b77a84d',
        clientSecret:'9364cb456dda6401cb71d65092489e75c9f11872',
        repo: 'ecef_comment',
        owner: 'kirino17',
        admin: ['kirino17'],
        id: location.pathname
    });
    gitalk.render('gitalk-containerfileexpandcul');
</script>
