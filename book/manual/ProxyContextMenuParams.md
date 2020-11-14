# 水星菜单信息
###### 与菜单相关的上下文信息。

| `Quick Links` |
|:----|
|<a href="#GetXCoord"  style="color:rgb(128,0,0)">取坐标X</a> , <a href="#GetYCoord"  style="color:rgb(128,0,0)">取坐标Y</a> , <a href="#GetTypeFlags"  style="color:rgb(128,0,0)">取菜单类型</a> , <a href="#GetLinkUrl"  style="color:rgb(128,0,0)">取URL</a> , <a href="#GetUnfilteredLinkUrl"  style="color:rgb(128,0,0)">取原始URL</a> , <a href="#GetSourceUrl"  style="color:rgb(128,0,0)">取源URL</a> , <a href="#HasImageContents"  style="color:rgb(128,0,0)">是否为图像</a> , <a href="#GetTitleText"  style="color:rgb(128,0,0)">取标题文本</a> , <a href="#GetPageUrl"  style="color:rgb(128,0,0)">取页URL</a> , <a href="#GetFrameUrl"  style="color:rgb(128,0,0)">取框架URL</a> , <a href="#GetFrameCharset"  style="color:rgb(128,0,0)">取框架字符集</a> , <a href="#GetMediaType"  style="color:rgb(128,0,0)">取多媒体类型</a> , <a href="#GetMediaStateFlags"  style="color:rgb(128,0,0)">取多媒体状态</a> , <a href="#GetSelectionText"  style="color:rgb(128,0,0)">取选区文本</a> , <a href="#GetMisspelledWord"  style="color:rgb(128,0,0)">取拼写错误单词</a> , <a href="#GetDictionarySuggestions"  style="color:rgb(128,0,0)">取建议拼写单词</a> , <a href="#IsEditable"  style="color:rgb(128,0,0)">是否可编辑</a> , <a href="#IsSpellCheckEnabled"  style="color:rgb(128,0,0)">是否启用拼写检查</a> , <a href="#GetEditStateFlags"  style="color:rgb(128,0,0)">取编辑状态</a> , <a href="#IsCustomMenu"  style="color:rgb(128,0,0)">是否为自定义菜单</a> , <a href="#IsPepperMenu"  style="color:rgb(128,0,0)">是否为插件菜单</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="GetXCoord">取坐标X</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回鼠标的X坐标。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetYCoord">取坐标Y</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回鼠标的Y坐标。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetTypeFlags">取菜单类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回菜单的类型。定义值为枚举常量: #菜单类型.* 。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetLinkUrl">取URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">取链接URL<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetUnfilteredLinkUrl">取原始URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">取链接原始URL<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetSourceUrl">取源URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">取链接源URL<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="HasImageContents">是否为图像</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果在图像内容上调用了菜单返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetTitleText">取标题文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回标题文本或者alt文本。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetPageUrl">取页URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetFrameUrl">取框架URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetFrameCharset">取框架字符集</span> |
|:----|
| <span style="color:rgb(0,128,0)">charset<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetMediaType">取多媒体类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">定义值为枚举常量: #多媒体类型.* 。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetMediaStateFlags">取多媒体状态</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetSelectionText">取选区文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetMisspelledWord">取拼写错误单词</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetDictionarySuggestions">取建议拼写单词</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型变量</span> |


| <span style="color:rgb(128,0,0)" id="IsEditable">是否可编辑</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsSpellCheckEnabled">是否启用拼写检查</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetEditStateFlags">取编辑状态</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="IsCustomMenu">是否为自定义菜单</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsPepperMenu">是否为插件菜单</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


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
