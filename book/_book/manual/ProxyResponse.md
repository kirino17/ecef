# 水星响应
###### 用于表示 Web 响应的类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#IsReadOnly"  style="color:rgb(128,0,0)">是否为只读</a> , <a href="#GetError"  style="color:rgb(128,0,0)">取会话错误</a> , <a href="#SetError"  style="color:rgb(128,0,0)">置会话错误</a> , <a href="#GetStatus"  style="color:rgb(128,0,0)">取状态代码</a> , <a href="#SetStatus"  style="color:rgb(128,0,0)">置状态代码</a> , <a href="#GetStatusText"  style="color:rgb(128,0,0)">取状态文本</a> , <a href="#SetStatusText"  style="color:rgb(128,0,0)">置状态文本</a> , <a href="#GetMimeType"  style="color:rgb(128,0,0)">取MIME类型</a> , <a href="#SetMimeType"  style="color:rgb(128,0,0)">置MIME类型</a> , <a href="#GetCharset"  style="color:rgb(128,0,0)">取字符集</a> , <a href="#SetCharset"  style="color:rgb(128,0,0)">置响应字符集</a> , <a href="#GetHeaderByName"  style="color:rgb(128,0,0)">取标头</a> , <a href="#SetHeaderByName"  style="color:rgb(128,0,0)">置标头</a> , <a href="#GetHeaderMap"  style="color:rgb(128,0,0)">取标头列表</a> , <a href="#SetHeaderMap"  style="color:rgb(128,0,0)">置标头列表</a> , <a href="#GetURL"  style="color:rgb(128,0,0)">取URL</a> , <a href="#SetURL"  style="color:rgb(128,0,0)">置URL</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsReadOnly">是否为只读</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetError">取会话错误</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SetError">置会话错误</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 错误代码 <span style="color: rgb(0, 128, 0)">错误代码</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetStatus">取状态代码</span> |
|:----|
| <span style="color:rgb(0,128,0)">取响应状态码<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SetStatus">置状态代码</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置响应状态码<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 状态码 <span style="color: rgb(0, 128, 0)">状态码</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetStatusText">取状态文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">取响应状态文本<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetStatusText">置状态文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置响应状态文本<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 状态文本 <span style="color: rgb(0, 128, 0)">状态文本</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetMimeType">取MIME类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取响应MIME类型。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetMimeType">置MIME类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置响应MIME类型<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> MIME类型 <span style="color: rgb(0, 128, 0)">MIME类型</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetCharset">取字符集</span> |
|:----|
| <span style="color:rgb(0,128,0)">取响应字符集<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetCharset">置响应字符集</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 字符集 <span style="color: rgb(0, 128, 0)">字符集</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetHeaderByName">取标头</span> |
|:----|
| <span style="color:rgb(0,128,0)">取指定HTTP标头值<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标头名称 <span style="color: rgb(0, 128, 0)">标头名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetHeaderByName">置标头</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置指定HTTP标头值<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标头名称 <span style="color: rgb(0, 128, 0)">标头名称</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 覆盖写入 <span style="color: rgb(0, 128, 0)">覆盖写入</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetHeaderMap">取标头列表</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该会话响应的HTTP标头列表<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型变量</span> |


| <span style="color:rgb(128,0,0)" id="SetHeaderMap">置标头列表</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置该会话响应的HTTP标头列表。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标头列表字符串 <span style="color: rgb(0, 128, 0)">标头列表字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetURL">取URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该会话响应的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetURL">置URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置该会话响应的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
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
