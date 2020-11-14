# 水星网页套接字
###### 表示一个Websocket连接的类。

| `Quick Links` |
|:----|
|<a href="#SetProxy"  style="color:rgb(128,0,0)">置代理</a> , <a href="#SetUserAgent"  style="color:rgb(128,0,0)">置用户代理标识</a> , <a href="#SetHeaderByName"  style="color:rgb(128,0,0)">置标头</a> , <a href="#AddSubProtocol"  style="color:rgb(128,0,0)">置子协议</a> , <a href="#Connect"  style="color:rgb(128,0,0)">连接</a> , <a href="#Send"  style="color:rgb(128,0,0)">发送</a> , <a href="#Close"  style="color:rgb(128,0,0)">关闭</a> , <a href="#IsConnected"  style="color:rgb(128,0,0)">连接是否有效</a> , <a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="SetProxy">置代理</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置代理服务器。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 服务器信息 <span style="color: rgb(0, 128, 0)">服务器信息</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetUserAgent">置用户代理标识</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置用户代理标识(user-agent)字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 用户代理标识 <span style="color: rgb(0, 128, 0)">用户代理标识</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetHeaderByName">置标头</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置HTTP标头信息。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 名称 <span style="color: rgb(0, 128, 0)">名称</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="AddSubProtocol">置子协议</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置websocket子协议(sub-protocol)。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 协议名 <span style="color: rgb(0, 128, 0)">协议名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Connect">连接</span> |
|:----|
| <span style="color:rgb(0,128,0)">连接到websocket-server。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 地址 <span style="color: rgb(0, 128, 0)">地址</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Send">发送</span> |
|:----|
| <span style="color:rgb(0,128,0)">发送数据流到服务器。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 流类型 <span style="color: rgb(0, 128, 0)">流类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 流数据 <span style="color: rgb(0, 128, 0)">流数据</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 流长度 <span style="color: rgb(0, 128, 0)">流长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Close">关闭</span> |
|:----|
| <span style="color:rgb(0,128,0)">关闭与websocket-server的连接。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="IsConnected">连接是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果连接没有被断开返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
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
