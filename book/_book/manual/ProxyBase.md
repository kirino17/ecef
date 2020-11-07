# 静态方法
###### 适用于全局的静态函数集合。

| `Quick Links` |
|:----|
|<a href="#Initialize"  style="color:rgb(128,0,0)">进程初始化</a> , <a href="#Base64Encode"  style="color:rgb(128,0,0)">BASE64编码</a> , <a href="#Base64Decode"  style="color:rgb(128,0,0)">BASE64解码</a> , <a href="#UriEncode"  style="color:rgb(128,0,0)">URI编码</a> , <a href="#UriDecode"  style="color:rgb(128,0,0)">URI解码</a> , <a href="#Utf8ToBytes"  style="color:rgb(128,0,0)">UTF8解码</a> , <a href="#BytesToUtf8"  style="color:rgb(128,0,0)">UTF8编码</a> , <a href="#CreateBrowserSettings"  style="color:rgb(128,0,0)">创建浏览器设置</a> , <a href="#CreateCommandLine"  style="color:rgb(128,0,0)">创建命令行</a> , <a href="#GetGlobalCommandLine"  style="color:rgb(128,0,0)">取全局命令行</a> , <a href="#GetGlobalCookieManager"  style="color:rgb(128,0,0)">取全局会话凭证管理器</a> , <a href="#CreateDictionartyValue"  style="color:rgb(128,0,0)">创建字典值</a> , <a href="#CreateListValue"  style="color:rgb(128,0,0)">创建列表值</a> , <a href="#CreatePostDataElement"  style="color:rgb(128,0,0)">创建提交元素</a> , <a href="#CreatePostDataElementWithFile"  style="color:rgb(128,0,0)">创建文件提交元素</a> , <a href="#CreatePostDataElementWithData"  style="color:rgb(128,0,0)">创建字节集提交元素</a> , <a href="#CreateRequest"  style="color:rgb(128,0,0)">创建请求</a> , <a href="#CreateResponse"  style="color:rgb(128,0,0)">创建响应</a> , <a href="#CreateSetting"  style="color:rgb(128,0,0)">创建初始化设置</a> , <a href="#CreateValue"  style="color:rgb(128,0,0)">创建通用值</a> , <a href="#CreateWindowInfo"  style="color:rgb(128,0,0)">创建窗口设置</a> , <a href="#CreateAsChildWindow"  style="color:rgb(128,0,0)">创建子窗口设置</a> , <a href="#CreateAsPopupWindow"  style="color:rgb(128,0,0)">创建弹出窗口设置</a> , <a href="#SendURLRequest"  style="color:rgb(128,0,0)">发送URL请求</a> , <a href="#CreateServer"  style="color:rgb(128,0,0)">创建服务器</a> , <a href="#CreateWebSocket"  style="color:rgb(128,0,0)">创建网页套接字</a> , <a href="#CreateWaitableEvent"  style="color:rgb(128,0,0)">创建等待事件</a> , <a href="#Awaking"  style="color:rgb(128,0,0)">等待唤醒</a> , <a href="#TimedAwaking"  style="color:rgb(128,0,0)">等待唤醒2</a> , <a href="#CreateMenu"  style="color:rgb(128,0,0)">创建菜单</a> , <a href="#CreateCollection"  style="color:rgb(128,0,0)">创建网页驱动器</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="Initialize">进程初始化</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数应该在程序启动位置调用, 且应该于浏览器进程中执行, 执行此函数以初始化Chromium浏览器进程。初始化成功返回真, 失败返回假。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxySettings.md" style ="color: blue">水星初始化设置</a> 初始化设置 <span style="color: rgb(0, 128, 0)">初始化设置</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 保留 <span style="color: rgb(0, 128, 0)">保留</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Base64Encode">BASE64编码</span> |
|:----|
| <span style="color:rgb(0,128,0)">将字节集数据编码为Base64字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">字节集型</span> 待编码的数据 <span style="color: rgb(0, 128, 0)">待编码的数据</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 数据长度 <span style="color: rgb(0, 128, 0)">数据长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="Base64Decode">BASE64解码</span> |
|:----|
| <span style="color:rgb(0,128,0)">将Base64字符串解码为字节集数据<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 编码字符串 <span style="color: rgb(0, 128, 0)">编码字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">字节集型</span> |


| <span style="color:rgb(128,0,0)" id="UriEncode">URI编码</span> |
|:----|
| <span style="color:rgb(0,128,0)">对指定的字符串执行URI字符转义。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 转义的字符串 <span style="color: rgb(0, 128, 0)">转义的字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 空格转义为加号 <span style="color: rgb(0, 128, 0)">空格转义为加号</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="UriDecode">URI解码</span> |
|:----|
| <span style="color:rgb(0,128,0)">还原指定字符串中的URI转义字符。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 待解码的字符串 <span style="color: rgb(0, 128, 0)">待解码的字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 转换到UTF8 <span style="color: rgb(0, 128, 0)">转换到UTF8</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 转义规则 <span style="color: rgb(0, 128, 0)">转义规则</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="Utf8ToBytes">UTF8解码</span> |
|:----|
| <span style="color:rgb(0,128,0)">将UTF-8编码字符串解码为多字节编码字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">字节集型</span> 待解码的字符串 <span style="color: rgb(0, 128, 0)">待解码的字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 字节长度 <span style="color: rgb(0, 128, 0)">字节长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="BytesToUtf8">UTF8编码</span> |
|:----|
| <span style="color:rgb(0,128,0)">将多字节编码字符串编码为UTF-8编码字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 待编码的字符串 <span style="color: rgb(0, 128, 0)">待编码的字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">字节集型</span> |


| <span style="color:rgb(128,0,0)" id="CreateBrowserSettings">创建浏览器设置</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的浏览器设置类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyBrowserSettings.md" style ="color: blue">水星浏览器设置</a> |


| <span style="color:rgb(128,0,0)" id="CreateCommandLine">创建命令行</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的命令行类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCommandLine.md" style ="color: blue">水星命令行</a> |


| <span style="color:rgb(128,0,0)" id="GetGlobalCommandLine">取全局命令行</span> |
|:----|
| <span style="color:rgb(0,128,0)">从全局获取命令行类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCommandLine.md" style ="color: blue">水星命令行</a> |


| <span style="color:rgb(128,0,0)" id="GetGlobalCookieManager">取全局会话凭证管理器</span> |
|:----|
| <span style="color:rgb(0,128,0)">从全局获取会话凭证管理器类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCookieManager.md" style ="color: blue">水星会话管理器</a> |


| <span style="color:rgb(128,0,0)" id="CreateDictionartyValue">创建字典值</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的字典类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> |


| <span style="color:rgb(128,0,0)" id="CreateListValue">创建列表值</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的列表类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 初始化值 <span style="color: rgb(0, 128, 0)">初始化值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyListValue.md" style ="color: blue">水星列表型</a> |


| <span style="color:rgb(128,0,0)" id="CreatePostDataElement">创建提交元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个空的提交数据元素(Post Data Element)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyPostDataElement.md" style ="color: blue">水星提交元素</a> |


| <span style="color:rgb(128,0,0)" id="CreatePostDataElementWithFile">创建文件提交元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个代表文件的提交数据元素(Post Data Element)。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 文件名 <span style="color: rgb(0, 128, 0)">文件名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyPostDataElement.md" style ="color: blue">水星提交元素</a> |


| <span style="color:rgb(128,0,0)" id="CreatePostDataElementWithData">创建字节集提交元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个代表字节集的提交数据元素(Post Data Element)。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 字节集数据 <span style="color: rgb(0, 128, 0)">字节集数据</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyPostDataElement.md" style ="color: blue">水星提交元素</a> |


| <span style="color:rgb(128,0,0)" id="CreateRequest">创建请求</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的请求类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 方法 <span style="color: rgb(0, 128, 0)">方法</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 来源地址 <span style="color: rgb(0, 128, 0)">来源地址</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标头字符串 <span style="color: rgb(0, 128, 0)">标头字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyPostDataElement.md" style ="color: blue">水星提交元素</a> 提交数据 <span style="color: rgb(0, 128, 0)">提交数据</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> |


| <span style="color:rgb(128,0,0)" id="CreateResponse">创建响应</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的响应类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyResponse.md" style ="color: blue">水星响应</a> |


| <span style="color:rgb(128,0,0)" id="CreateSetting">创建初始化设置</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的初始化设置类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxySettings.md" style ="color: blue">水星初始化设置</a> |


| <span style="color:rgb(128,0,0)" id="CreateValue">创建通用值</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的通用类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 初始化值 <span style="color: rgb(0, 128, 0)">初始化值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyValue.md" style ="color: blue">水星通用型</a> |


| <span style="color:rgb(128,0,0)" id="CreateWindowInfo">创建窗口设置</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建并返回一个新的窗口设置类型实例对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyWindowInfo.md" style ="color: blue">水星窗口设置</a> |


| <span style="color:rgb(128,0,0)" id="CreateAsChildWindow">创建子窗口设置</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个窗口设置类型实例, 并将其初始化为子窗口模式。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 父窗口 <span style="color: rgb(0, 128, 0)">父窗口</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> x <span style="color: rgb(0, 128, 0)">x</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> y <span style="color: rgb(0, 128, 0)">y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 宽度 <span style="color: rgb(0, 128, 0)">宽度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 高度 <span style="color: rgb(0, 128, 0)">高度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyWindowInfo.md" style ="color: blue">水星窗口设置</a> |


| <span style="color:rgb(128,0,0)" id="CreateAsPopupWindow">创建弹出窗口设置</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个窗口设置类型实例, 并将其初始化为弹出窗口模式。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 父窗口 <span style="color: rgb(0, 128, 0)">父窗口</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyWindowInfo.md" style ="color: blue">水星窗口设置</a> |


| <span style="color:rgb(128,0,0)" id="SendURLRequest">发送URL请求</span> |
|:----|
| <span style="color:rgb(0,128,0)">发起HTTP请求。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 隐身模式 <span style="color: rgb(0, 128, 0)">隐身模式</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 认证用户名 <span style="color: rgb(0, 128, 0)">认证用户名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 认证密码 <span style="color: rgb(0, 128, 0)">认证密码</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyURLRequest.md" style ="color: blue">水星URL请求</a> |


| <span style="color:rgb(128,0,0)" id="CreateServer">创建服务器</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个新的HTTP服务器。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 监听地址 <span style="color: rgb(0, 128, 0)">监听地址</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 端口号 <span style="color: rgb(0, 128, 0)">端口号</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 连接数 <span style="color: rgb(0, 128, 0)">连接数</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="CreateWebSocket">创建网页套接字</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个新的Websocket套接字。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyWebSocket.md" style ="color: blue">水星网页套接字</a> |


| <span style="color:rgb(128,0,0)" id="CreateWaitableEvent">创建等待事件</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个新的等待事件。 等待事件通常用于线程同步, 它允许一个线程等待另一个线程完成某些事件后在继续工作。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyWaitableEvent.md" style ="color: blue">水星等待事件</a> |


| <span style="color:rgb(128,0,0)" id="Awaking">等待唤醒</span> |
|:----|
| <span style="color:rgb(0,128,0)">挂起一个等待事件直到被置为有信号状态。本方法加入了消息队列的处理不会阻塞UI线程。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWaitableEvent.md" style ="color: blue">水星等待事件</a> 等待事件 <span style="color: rgb(0, 128, 0)">等待事件</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="TimedAwaking">等待唤醒2</span> |
|:----|
| <span style="color:rgb(0,128,0)">挂起一个等待事件直到被置为有信号状态或者超过事时间。本方法加入了消息队列的处理不会阻塞UI线程。返回真表示等待事件已授信, 返回假表示已超过等待时间。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWaitableEvent.md" style ="color: blue">水星等待事件</a> 等待事件 <span style="color: rgb(0, 128, 0)">等待事件</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 超时时间 <span style="color: rgb(0, 128, 0)">超时时间</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="CreateMenu">创建菜单</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个新的菜单。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyMenuModel.md" style ="color: blue">水星菜单</a> |


| <span style="color:rgb(128,0,0)" id="CreateCollection">创建网页驱动器</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个新的网页驱动器。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCollection.md" style ="color: blue">水星网页驱动器</a> |


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
