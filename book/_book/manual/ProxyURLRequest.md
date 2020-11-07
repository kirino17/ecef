# 水星URL请求
###### 表示HTTP请求的类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#GetRequest"  style="color:rgb(128,0,0)">取请求</a> , <a href="#GetResponse"  style="color:rgb(128,0,0)">取响应</a> , <a href="#GetRequestStatus"  style="color:rgb(128,0,0)">取请求状态</a> , <a href="#GetRequestError"  style="color:rgb(128,0,0)">取错误代码</a> , <a href="#ResponseWasCached"  style="color:rgb(128,0,0)">是否从缓存加载</a> , <a href="#GetResponseDataBytes"  style="color:rgb(128,0,0)">取响应数据长度</a> , <a href="#GetResponseData"  style="color:rgb(128,0,0)">取响应数据</a> , <a href="#GetCookieManager"  style="color:rgb(128,0,0)">取会话管理器</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetRequest">取请求</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取发出的HTTP请求。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> |


| <span style="color:rgb(128,0,0)" id="GetResponse">取响应</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取收到的HTTP响应。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyResponse.md" style ="color: blue">水星响应</a> |


| <span style="color:rgb(128,0,0)" id="GetRequestStatus">取请求状态</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取本次请求的执行状态。定义值为枚举常量: #请求状态.* 。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetRequestError">取错误代码</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取执行请求失败时的错误代码。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="ResponseWasCached">是否从缓存加载</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果响应数据是从缓存提供的返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetResponseDataBytes">取响应数据长度</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取响应数据字节长度。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetResponseData">取响应数据</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取接收到的响应数据   <span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">字节集型</span> |


| <span style="color:rgb(128,0,0)" id="GetCookieManager">取会话管理器</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取本请求使用的会话凭证(Cookie)管理器。 未设置隐身模式时本请求共享使用全局的会话凭证管理器。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCookieManager.md" style ="color: blue">水星会话管理器</a> |


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
