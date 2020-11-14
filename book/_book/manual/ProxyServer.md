# 水星服务器
###### 表示支持HTTP/Websocket-Server端的类。服务器容量有限, 并且只能处理少量的同时连接。

| `Quick Links` |
|:----|
|<a href="#Shutdown"  style="color:rgb(128,0,0)">停止运行</a> , <a href="#IsRunning"  style="color:rgb(128,0,0)">是否正在运行</a> , <a href="#GetAddress"  style="color:rgb(128,0,0)">取地址</a> , <a href="#HasConnection"  style="color:rgb(128,0,0)">是否有连接</a> , <a href="#IsValidConnection"  style="color:rgb(128,0,0)">是否有客户</a> , <a href="#SendHttp200Response"  style="color:rgb(128,0,0)">发送200响应</a> , <a href="#SendHttp404Response"  style="color:rgb(128,0,0)">发送404响应</a> , <a href="#SendHttp500Response"  style="color:rgb(128,0,0)">发送500响应</a> , <a href="#SendHttpResponse"  style="color:rgb(128,0,0)">发送自定义响应</a> , <a href="#SendRawData"  style="color:rgb(128,0,0)">发送原始数据</a> , <a href="#CloseConnection"  style="color:rgb(128,0,0)">关闭连接</a> , <a href="#SendWebSocketMessage"  style="color:rgb(128,0,0)">发送套接字消息</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="Shutdown">停止运行</span> |
|:----|
| <span style="color:rgb(0,128,0)">停止服务器的运行并关闭专用线程。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="IsRunning">是否正在运行</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果服务器当前正在运行并且接受客户接入返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetAddress">取地址</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取服务器地址, 包括端口号。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="HasConnection">是否有连接</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果服务器当前拥有连接返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsValidConnection">是否有客户</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果指定客户连接有效返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SendHttp200Response">发送200响应</span> |
|:----|
| <span style="color:rgb(0,128,0)">发送HTTP 200 \"OK\"响应。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 内容类型 <span style="color: rgb(0, 128, 0)">内容类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 响应内容 <span style="color: rgb(0, 128, 0)">响应内容</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 数据长度 <span style="color: rgb(0, 128, 0)">数据长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendHttp404Response">发送404响应</span> |
|:----|
| <span style="color:rgb(0,128,0)">发送HTTP 404 \"Not Found\"响应。连接将在此后关闭。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendHttp500Response">发送500响应</span> |
|:----|
| <span style="color:rgb(0,128,0)">发送HTTP 500 \"Internal Server Error\"响应。连接将在此后关闭。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 错误信息 <span style="color: rgb(0, 128, 0)">错误信息</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendHttpResponse">发送自定义响应</span> |
|:----|
| <span style="color:rgb(0,128,0)">发送自定义的HTTP响应。在此响应发送后连接将关闭。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 响应状态码 <span style="color: rgb(0, 128, 0)">响应状态码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 内容类型 <span style="color: rgb(0, 128, 0)">内容类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">长整数型</span> 内容长度 <span style="color: rgb(0, 128, 0)">内容长度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 附加标头 <span style="color: rgb(0, 128, 0)">附加标头</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendRawData">发送原始数据</span> |
|:----|
| <span style="color:rgb(0,128,0)">将指定字节流数据发送到客户连接。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 发送数据 <span style="color: rgb(0, 128, 0)">发送数据</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 发送长度 <span style="color: rgb(0, 128, 0)">发送长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="CloseConnection">关闭连接</span> |
|:----|
| <span style="color:rgb(0,128,0)">关闭指定客户连接。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendWebSocketMessage">发送套接字消息</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 发送数据 <span style="color: rgb(0, 128, 0)">发送数据</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 发送长度 <span style="color: rgb(0, 128, 0)">发送长度</span> | 
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
