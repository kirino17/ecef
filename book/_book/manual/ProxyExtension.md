# 水星扩展程序
###### 用于管理 chrome extension 扩展应用程序的类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#GetIdentifier"  style="color:rgb(128,0,0)">取标识符</a> , <a href="#GetPath"  style="color:rgb(128,0,0)">取路径</a> , <a href="#GetManifest"  style="color:rgb(128,0,0)">取清单列表</a> , <a href="#IsSame"  style="color:rgb(128,0,0)">是否相同</a> , <a href="#IsLoaded"  style="color:rgb(128,0,0)">是否已载入</a> , <a href="#Unload"  style="color:rgb(128,0,0)">卸载</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetIdentifier">取标识符</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回唯一的扩展程序标识符(ID), 这是根据扩展公共密钥(如果有)或扩展路径来计算的。有关详细信息, 请参见: https://developer.chrome.com/extensions/manifest/key<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetPath">取路径</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回磁盘上扩展程序所在目录的绝对路径。如果载入扩展程序时使用的是相对路径, 则此值将返回带有PK_DIR_RESOURCES前缀的路径字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetManifest">取清单列表</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回扩展程序的清单内容。有关详细信息, 请参见: https://developer.chrome.com/extensions/manifest<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> |


| <span style="color:rgb(128,0,0)" id="IsSame">是否相同</span> |
|:----|
| <span style="color:rgb(0,128,0)">比较两个对象是否相同。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> 比较对象 <span style="color: rgb(0, 128, 0)">比较对象</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsLoaded">是否已载入</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果当前已加载此扩展程序返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Unload">卸载</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此扩展程序非系统扩展程序则卸载此扩展程序。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


----------------------

<link rel="stylesheet" href="../gitalk.min.css">
<script src="../gitalk.min.js"></script>
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
