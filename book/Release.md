# 发布程序
在发布程序使应将以下文件打包至您的安装文件中:
```bash
    #支持库资源
    aquarius2.dll
    spare-proc.exe

    #CEF二进制资源
    /swiftshader
    /locales
    chrome_elf.dll
    cef.pak
    cef_100_percent.pak
    cef_200_percent.pak
    cef_extensions.pak
    devtools_resources.pak
    icudtl.dat
    d3dcompiler_47.dll
    libcef.dll
    libEGL.dll
    libGLESv2.dll
    snapshot_blob.bin
    v8_context_snapshot.bin

```
> 关于文件的说明与可裁剪性参见章节[精简支持库](FileExplainAndCulling.md) 。

# 导出资源
```
发布程序时可以在易语言环境中选择: "工具->[水星]导出安装资源" 菜单
提取支持库运行所需资源到你的程序发布目录中
```
![导出安装资源](\image\Release-01.png)


------------------------

<link rel="stylesheet" href="gitalk.min.css">
<script src="gitalk.min.js"></script>
<div id="gitalk-container"></div>
<script>
    var gitalk = new Gitalk({
        clientID: 'd17d49be2e680b77a84d',
        clientSecret:'9364cb456dda6401cb71d65092489e75c9f11872',
        repo: 'ecef_comment',
        owner: 'kirino17',
        admin: ['kirino17'],
        id: location.pathname
    });
    gitalk.render('gitalk-container');
</script>