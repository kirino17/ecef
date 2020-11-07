# 水星铬浏览框
###### 水星铬浏览框是浏览器的父窗口控件类, 除了提供了一个默认的父窗口实现外,它还负责浏览器的事件调度分发, 提供创建、销毁、查询等功能函数。

| `Quick Links` |
|:----|
|<a href="#CreateBrowser"  style="color:rgb(128,0,0)">创建浏览器</a> , <a href="#CloseBrowser"  style="color:rgb(128,0,0)">关闭浏览器</a> , <a href="#SetForeground"  style="color:rgb(128,0,0)">置前台窗口</a> , <a href="#GetBrowserCount"  style="color:rgb(128,0,0)">取浏览器数量</a> , <a href="#GetBrowserWithHandle"  style="color:rgb(128,0,0)">取浏览器</a> , <a href="#GetBrowserWithIndex"  style="color:rgb(128,0,0)">取浏览器索引</a> , <a href="#GetIndex"  style="color:rgb(128,0,0)">取索引</a> , <a href="#GetSameOriginBrowser"  style="color:rgb(128,0,0)">取同源浏览器</a> , <a href="#OnBeforeCommandLineProcessing"  style="color:rgb(128,0,0)">进程即将初始化</a> , <a href="#OnContextInitialized"  style="color:rgb(128,0,0)">进程初始化完毕</a> , <a href="#OnBeforeChildProcessLaunch"  style="color:rgb(128,0,0)">子进程即将启动</a> , <a href="#OnRenderProcessThreadCreated"  style="color:rgb(128,0,0)">渲染进程线程已创建</a> , <a href="#OnBeforePopup"  style="color:rgb(128,0,0)">浏览器将要打开</a> , <a href="#OnAfterCreated"  style="color:rgb(128,0,0)">浏览器创建完毕</a> , <a href="#OnBeforeClose"  style="color:rgb(128,0,0)">浏览器即将销毁</a> , <a href="#DoClose"  style="color:rgb(128,0,0)">浏览器将要关闭</a> , <a href="#OnLoadingStateChange"  style="color:rgb(128,0,0)">浏览器加载状态已改变</a> , <a href="#OnLoadStart"  style="color:rgb(128,0,0)">浏览器开始加载</a> , <a href="#OnLoadEnd"  style="color:rgb(128,0,0)">浏览器加载完毕</a> , <a href="#OnLoadError"  style="color:rgb(128,0,0)">浏览器加载失败</a> , <a href="#OnBeforeContextMenu"  style="color:rgb(128,0,0)">浏览器菜单即将打开</a> , <a href="#RunContextMenu"  style="color:rgb(128,0,0)">浏览器显示自定义菜单</a> , <a href="#OnContextMenuCommand"  style="color:rgb(128,0,0)">浏览器菜单项被选择</a> , <a href="#OnContextMenuDismissed"  style="color:rgb(128,0,0)">浏览器菜单即将关闭</a> , <a href="#OnAddressChange"  style="color:rgb(128,0,0)">浏览器地址已改变</a> , <a href="#OnTitleChange"  style="color:rgb(128,0,0)">浏览器标题已改变</a> , <a href="#OnTooltip"  style="color:rgb(128,0,0)">浏览器显示工具提示</a> , <a href="#OnStatusMessage"  style="color:rgb(128,0,0)">浏览器状态消息</a> , <a href="#OnConsoleMessage"  style="color:rgb(128,0,0)">浏览器控制台消息</a> , <a href="#OnLoadingProgressChange"  style="color:rgb(128,0,0)">浏览器加载进度已更新</a> , <a href="#OnFullscreenModeChange"  style="color:rgb(128,0,0)">浏览器全屏模式已改变</a> , <a href="#OnJSDialog"  style="color:rgb(128,0,0)">浏览器脚本对话框将要打开</a> , <a href="#OnBeforeUnloadDialog"  style="color:rgb(128,0,0)">浏览器对话框页面刷新询问</a> , <a href="#OnResetDialogState"  style="color:rgb(128,0,0)">浏览器重置对话框状态</a> , <a href="#OnDialogClosed"  style="color:rgb(128,0,0)">浏览器对话框关闭</a> , <a href="#GetAuthCredentials"  style="color:rgb(128,0,0)">浏览器请求用户身份验证</a> , <a href="#OnBeforeBrowse"  style="color:rgb(128,0,0)">浏览器将要导航</a> , <a href="#OnBeforeResourceLoad"  style="color:rgb(128,0,0)">浏览器将要加载资源</a> , <a href="#OnResourceRedirect"  style="color:rgb(128,0,0)">浏览器资源重定向</a> , <a href="#OnResourceResponse"  style="color:rgb(128,0,0)">浏览器资源请求收到响应</a> , <a href="#OnResourceResponseFilter"  style="color:rgb(128,0,0)">浏览器资源过滤器</a> , <a href="#OnResourceLoadComplete"  style="color:rgb(128,0,0)">浏览器资源加载完毕</a> , <a href="#OnFileDialog"  style="color:rgb(128,0,0)">浏览器将要打开文件对话框</a> , <a href="#OnBeforeDownload"  style="color:rgb(128,0,0)">浏览器即将下载</a> , <a href="#OnDownloadUpdated"  style="color:rgb(128,0,0)">浏览器下载进度已更新</a> , <a href="#OnResourceFilter"  style="color:rgb(128,0,0)">浏览器资源过滤器已就绪</a> , <a href="#OnServerCreated"  style="color:rgb(128,0,0)">服务器启动就绪</a> , <a href="#OnServerDestroyed"  style="color:rgb(128,0,0)">服务器停止运行</a> , <a href="#OnClientConnected"  style="color:rgb(128,0,0)">服务器客户进入</a> , <a href="#OnClientDisconnected"  style="color:rgb(128,0,0)">服务器客户离开</a> , <a href="#OnHttpRequest"  style="color:rgb(128,0,0)">服务器收到请求</a> , <a href="#OnWebSocketRequest"  style="color:rgb(128,0,0)">服务器收到套接字请求</a> , <a href="#OnWebSocketConnected"  style="color:rgb(128,0,0)">服务器套接字已连接</a> , <a href="#OnWebSocketMessage"  style="color:rgb(128,0,0)">服务器收到套接字消息</a> , <a href="#OnWebSocketClientConnected"  style="color:rgb(128,0,0)">网页套接字连接成功</a> , <a href="#OnWebSocketClientClosed"  style="color:rgb(128,0,0)">网页套接字连接断开</a> , <a href="#OnWebSocketClientMessage"  style="color:rgb(128,0,0)">网页套接字数据到达</a> , <a href="#OnWebSocketClientError"  style="color:rgb(128,0,0)">网页套接字连接错误</a> , <a href="#OnExtensionLoadFailed"  style="color:rgb(128,0,0)">扩展程序载入失败</a> , <a href="#OnExtensionLoaded"  style="color:rgb(128,0,0)">扩展程序载入完毕</a> , <a href="#OnExtensionUnloaded"  style="color:rgb(128,0,0)">扩展程序已卸载</a> , <a href="#OnBeforeBackgroundBrowser"  style="color:rgb(128,0,0)">扩展程序托管脚本</a> , <a href="#OnBeforeBrowser"  style="color:rgb(128,0,0)">扩展程序将要打开</a> , <a href="#CanAccessBrowser"  style="color:rgb(128,0,0)">扩展程序关联浏览器</a> , <a href="#GetActiveBrowser"  style="color:rgb(128,0,0)">扩展程序取活动浏览器</a> , <a href="#GetExtensionResource"  style="color:rgb(128,0,0)">扩展程序获取资源事件</a> , <a href="#OnQuery"  style="color:rgb(128,0,0)">脚本收到查询</a> , <a href="#OnQueryCanceled"  style="color:rgb(128,0,0)">脚本查询已取消</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="CreateBrowser">创建浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个新的浏览器窗口, 创建成功返回新的窗口对象, 失败返回空, 可使用 IsValid 函数检查返回有效性。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWindowInfo.md" style ="color: blue">水星窗口设置</a> 窗口设置 <span style="color: rgb(0, 128, 0)">窗口设置</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowserSettings.md" style ="color: blue">水星浏览器设置</a> 浏览器设置 <span style="color: rgb(0, 128, 0)">浏览器设置</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 隐身模式 <span style="color: rgb(0, 128, 0)">隐身模式</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="CloseBrowser">关闭浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">向指定的浏览器发送关闭请求。发送此请求后JavaScript的\"onbeforeunload\"事件将被触发。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 待关闭的浏览器 <span style="color: rgb(0, 128, 0)">待关闭的浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 强制关闭 <span style="color: rgb(0, 128, 0)">强制关闭</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetForeground">置前台窗口</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置显示指定的浏览器窗口。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 浏览器父窗口 <span style="color: rgb(0, 128, 0)">浏览器父窗口</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器窗口 <span style="color: rgb(0, 128, 0)">浏览器窗口</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetBrowserCount">取浏览器数量</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回当前进程中的浏览器窗口数量。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetBrowserWithHandle">取浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用窗口句柄取进程中的指定浏览器窗口, 成功返回窗口对象, 失败返回空, 可使用 IsValid 函数检查返回有效性。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 窗口句柄 <span style="color: rgb(0, 128, 0)">窗口句柄</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> |


| <span style="color:rgb(128,0,0)" id="GetBrowserWithIndex">取浏览器索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用索引查询浏览器, 索引从0开始, 成功返回浏览器对象, 失败返回空对象。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 索引 <span style="color: rgb(0, 128, 0)">索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> |


| <span style="color:rgb(128,0,0)" id="GetIndex">取索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回浏览器的索引编号。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetSameOriginBrowser">取同源浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回与指定浏览器共享会话环境的所有浏览器。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> |



---------------------
`事件函数` <br/>

| <span style="color:rgb(128,0,0)" id="OnBeforeCommandLineProcessing">进程即将初始化</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器进程上下文环境将要初始化时调用此事件。在此事件中浏览器进程提供了一次查看或者修改命令行参数的机会。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 进程类型 <span style="color: rgb(0, 128, 0)">进程类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyCommandLine.md" style ="color: blue">水星命令行</a> 命令行 <span style="color: rgb(0, 128, 0)">命令行</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnContextInitialized">进程初始化完毕</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器进程上下文初始化完毕后调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeChildProcessLaunch">子进程即将启动</span> |
|:----|
| <span style="color:rgb(0,128,0)">在启动子进程前调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyCommandLine.md" style ="color: blue">水星命令行</a> 命令行 <span style="color: rgb(0, 128, 0)">命令行</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnRenderProcessThreadCreated">渲染进程线程已创建</span> |
|:----|
| <span style="color:rgb(0,128,0)">在为新的渲染过程创建主线程后调用此事件。这将提供一次机会用于为渲染过程提供额外的信息。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyListValue.md" style ="color: blue">水星列表型</a> 附加信息 <span style="color: rgb(0, 128, 0)">附加信息</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforePopup">浏览器将要打开</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器即将创建新的窗口前调用此事件, 如果不希望浏览器继续创建该窗口则应在此事件中返回真以促使浏览器取消创建过程, 如未设置返回值则浏览器将会默认继续执行该项操作。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 目标URL <span style="color: rgb(0, 128, 0)">目标URL</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 目标框架名称 <span style="color: rgb(0, 128, 0)">目标框架名称</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 链接的打开方式 <span style="color: rgb(0, 128, 0)">链接的打开方式</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否为手势点击 <span style="color: rgb(0, 128, 0)">是否为手势点击</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWindowInfo.md" style ="color: blue">水星窗口设置</a> 窗口设置 <span style="color: rgb(0, 128, 0)">窗口设置</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowserSettings.md" style ="color: blue">水星浏览器设置</a> 浏览器设置 <span style="color: rgb(0, 128, 0)">浏览器设置</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 是否禁止脚本访问 <span style="color: rgb(0, 128, 0)">是否禁止脚本访问</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnAfterCreated">浏览器创建完毕</span> |
|:----|
| <span style="color:rgb(0,128,0)">在创建新的浏览器后调用此事件, 这个事件是在浏览器创建后的第一个调用的事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeClose">浏览器即将销毁</span> |
|:----|
| <span style="color:rgb(0,128,0)">在浏览器被销毁之前调用此事件, 这个事件返回后浏览器将会释放所有对该对象的引用, 所以请不要在此事件之后尝试对再对该对象执行任何方法, 这个世界是该浏览器对象的最后一个调用事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="DoClose">浏览器将要关闭</span> |
|:----|
| <span style="color:rgb(0,128,0)">对于浏览器的关闭, 其关闭事件来源于它的关闭浏览器方法或是其父窗口接受了用户的关闭请求(用户点击了X按钮)。在此事件中如果不希望浏览器被立即关闭返回真, 以取消关闭请求。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnLoadingStateChange">浏览器加载状态已改变</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器加载状态更改时调用此事件。该事件通常将会被调用两次, 一次由通过用户操作启动, 另一次则由完成或者终止加载触发。该事件将会早于事件\"开始加载\"调用, 并在加载完成或终止时在\"加载完毕\" 或 \"加载失败\"事件之后调用。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否正在加载 <span style="color: rgb(0, 128, 0)">是否正在加载</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 可否回退 <span style="color: rgb(0, 128, 0)">可否回退</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 可否前进 <span style="color: rgb(0, 128, 0)">可否前进</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnLoadStart">浏览器开始加载</span> |
|:----|
| <span style="color:rgb(0,128,0)">在导航请求被提交后将会调用此事件。该事件可能会在所有框架发生导航变更后多次调用。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 导航来源 <span style="color: rgb(0, 128, 0)">导航来源</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnLoadEnd">浏览器加载完毕</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器完成加载框架时调用此事件。如果当前页面中存在多个框架, 则该事件会被多次调用。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 状态码 <span style="color: rgb(0, 128, 0)">状态码</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnLoadError">浏览器加载失败</span> |
|:----|
| <span style="color:rgb(0,128,0)">在浏览器加载页面失败或者执行被取消后调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 错误代码 <span style="color: rgb(0, 128, 0)">错误代码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 错误信息 <span style="color: rgb(0, 128, 0)">错误信息</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 加载失败的URL <span style="color: rgb(0, 128, 0)">加载失败的URL</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeContextMenu">浏览器菜单即将打开</span> |
|:----|
| <span style="color:rgb(0,128,0)">显示上下文菜单前调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyContextMenuParams.md" style ="color: blue">水星菜单信息</a> 菜单信息 <span style="color: rgb(0, 128, 0)">菜单信息</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyMenuModel.md" style ="color: blue">水星菜单</a> 菜单 <span style="color: rgb(0, 128, 0)">菜单</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="RunContextMenu">浏览器显示自定义菜单</span> |
|:----|
| <span style="color:rgb(0,128,0)">显示上下文菜单前调用此事件, 如果需要显示自定义菜单返回真。否则返回假以显示系统默认菜单。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyContextMenuParams.md" style ="color: blue">水星菜单信息</a> 菜单信息 <span style="color: rgb(0, 128, 0)">菜单信息</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyMenuModel.md" style ="color: blue">水星菜单</a> 菜单 <span style="color: rgb(0, 128, 0)">菜单</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRunContextMenuCallback.md" style ="color: blue">水星菜单回调</a> 菜单回调 <span style="color: rgb(0, 128, 0)">菜单回调</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnContextMenuCommand">浏览器菜单项被选择</span> |
|:----|
| <span style="color:rgb(0,128,0)">执行菜单命令时调用此事件。如果菜单命令已处理返回真, 否则返回假交由系统处理。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyContextMenuParams.md" style ="color: blue">水星菜单信息</a> 菜单信息 <span style="color: rgb(0, 128, 0)">菜单信息</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnContextMenuDismissed">浏览器菜单即将关闭</span> |
|:----|
| <span style="color:rgb(0,128,0)">关闭菜单前调用此事件, 无论菜单是否被选择或者取消都将会发生此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnAddressChange">浏览器地址已改变</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器框架地址更改时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 变更地址 <span style="color: rgb(0, 128, 0)">变更地址</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnTitleChange">浏览器标题已改变</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器页面标题变更时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 变更标题 <span style="color: rgb(0, 128, 0)">变更标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnTooltip">浏览器显示工具提示</span> |
|:----|
| <span style="color:rgb(0,128,0)">在浏览器将显示工具提示时调用此事件, 如果需要将该提示信息放在您的自定义提示工具中显示则应当在此事件中返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 提示信息 <span style="color: rgb(0, 128, 0)">提示信息</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnStatusMessage">浏览器状态消息</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器收到状态消息时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 消息内容 <span style="color: rgb(0, 128, 0)">消息内容</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnConsoleMessage">浏览器控制台消息</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器收到控制台消息时调用此事件, 如果希望浏览器停止消息输出到控制台则应当返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 消息等级 <span style="color: rgb(0, 128, 0)">消息等级</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 消息内容 <span style="color: rgb(0, 128, 0)">消息内容</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 消息源 <span style="color: rgb(0, 128, 0)">消息源</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始行 <span style="color: rgb(0, 128, 0)">起始行</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnLoadingProgressChange">浏览器加载进度已更新</span> |
|:----|
| <span style="color:rgb(0,128,0)">当整体页面加载进度更改时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">双精度小数型</span> 进度值 <span style="color: rgb(0, 128, 0)">进度值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnFullscreenModeChange">浏览器全屏模式已改变</span> |
|:----|
| <span style="color:rgb(0,128,0)">网页中的网页内容切换为全屏模式时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 全屏模式 <span style="color: rgb(0, 128, 0)">全屏模式</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnJSDialog">浏览器脚本对话框将要打开</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器接收到Javascript对话框调用时执行此事件。返回假使用系统默认对话框, 返回真使用自定义对话框。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 页面URL <span style="color: rgb(0, 128, 0)">页面URL</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 对话框类型 <span style="color: rgb(0, 128, 0)">对话框类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 消息内容 <span style="color: rgb(0, 128, 0)">消息内容</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 默认值 <span style="color: rgb(0, 128, 0)">默认值</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyJSDialogCallback.md" style ="color: blue">水星脚本对话框</a> 对话框回调 <span style="color: rgb(0, 128, 0)">对话框回调</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 禁止消息 <span style="color: rgb(0, 128, 0)">禁止消息</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeUnloadDialog">浏览器对话框页面刷新询问</span> |
|:----|
| <span style="color:rgb(0,128,0)">弹出一个对话框, 询问用户是否要离开页面，如果希望使用自定义的对话框显示消息内容则应当在此事件中返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 消息内容 <span style="color: rgb(0, 128, 0)">消息内容</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否重新加载 <span style="color: rgb(0, 128, 0)">是否重新加载</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyJSDialogCallback.md" style ="color: blue">水星脚本对话框</a> 对话框回调 <span style="color: rgb(0, 128, 0)">对话框回调</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnResetDialogState">浏览器重置对话框状态</span> |
|:----|
| <span style="color:rgb(0,128,0)">执行此事件以取消所有未决的对话框并重置所有保持的对话框状态。由于诸如页面导航之类的事件而将被调用, 而不管当前是否有任何对话框挂起。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnDialogClosed">浏览器对话框关闭</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器默认对话框被关闭时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetAuthCredentials">浏览器请求用户身份验证</span> |
|:----|
| <span style="color:rgb(0,128,0)">当浏览器需要用户提供认证凭据时调用此事件, 如果希望浏览器继续执行该项请求则应当返回真, 并在此方法中或在后续获得身份验证信息之后调用认证回调接口。返回假立即取消该项请求。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 认证源 <span style="color: rgb(0, 128, 0)">认证源</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否为代理服务器 <span style="color: rgb(0, 128, 0)">是否为代理服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 主机名称 <span style="color: rgb(0, 128, 0)">主机名称</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 端口号 <span style="color: rgb(0, 128, 0)">端口号</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 域 <span style="color: rgb(0, 128, 0)">域</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 认证方案 <span style="color: rgb(0, 128, 0)">认证方案</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyAuthCallback.md" style ="color: blue">水星认证</a> 认证回调 <span style="color: rgb(0, 128, 0)">认证回调</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeBrowse">浏览器将要导航</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器将要导航之前调用此事件。返回真以取消导航, 返回假导航将继续进行。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否为用户手势 <span style="color: rgb(0, 128, 0)">是否为用户手势</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否重定向 <span style="color: rgb(0, 128, 0)">是否重定向</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeResourceLoad">浏览器将要加载资源</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器加载资源之前调用此事件。通过返回枚举常量: #资源请求.* 中定义的值以决定浏览器是否取消或者继续该资源的请求。 <span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="OnResourceRedirect">浏览器资源重定向</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器重定向资源负载时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyResponse.md" style ="color: blue">水星响应</a> 响应 <span style="color: rgb(0, 128, 0)">响应</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 新地址 <span style="color: rgb(0, 128, 0)">新地址</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnResourceResponse">浏览器资源请求收到响应</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器收到资源响应时调用此事件。若要允许资源加载而无需修改则应返回假, 要重定向或重试资源负载, 可以选择修改|请求|参数并返回真, 对请求URL的修改将被视为重定向。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyResponse.md" style ="color: blue">水星响应</a> 响应 <span style="color: rgb(0, 128, 0)">响应</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnResourceResponseFilter">浏览器资源过滤器</span> |
|:----|
| <span style="color:rgb(0,128,0)">提供此事件用以可选化的过滤资源响应内容。如果希望浏览器执行资源过滤器应当在此事件返回真, 并在事件\"浏览器资源过滤器已就绪\"中完成过滤设置, 如果返回假则请求资源将不经过过滤器而直接返回到浏览器。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyResponse.md" style ="color: blue">水星响应</a> 响应 <span style="color: rgb(0, 128, 0)">响应</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnResourceLoadComplete">浏览器资源加载完毕</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器资源加载完成后调用此事件。所有的资源请求都会调用此事件, 包括印Chromium关闭或相关浏览器销毁而终止的请求。如果关联的浏览器被销毁, 则该事件可能在该浏览器的\"即将被销毁\"事件之后到达。对|框架|执行方法\"是否有效\"可以测试这种情况, 并且应注意不要调用\"取浏览器\"方法。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyResponse.md" style ="color: blue">水星响应</a> 响应 <span style="color: rgb(0, 128, 0)">响应</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 状态码 <span style="color: rgb(0, 128, 0)">状态码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">长整数型</span> 接收长度 <span style="color: rgb(0, 128, 0)">接收长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnFileDialog">浏览器将要打开文件对话框</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器运行文件选择对话框时调用此事件, 如果希望使用自定义的文件选择器对话框则应在此事件中返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 打开模式 <span style="color: rgb(0, 128, 0)">打开模式</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 默认文件名 <span style="color: rgb(0, 128, 0)">默认文件名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 过滤器 <span style="color: rgb(0, 128, 0)">过滤器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 选择过滤器 <span style="color: rgb(0, 128, 0)">选择过滤器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFileDialogCallback.md" style ="color: blue">水星文件选择器</a> 对话框回调 <span style="color: rgb(0, 128, 0)">对话框回调</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeDownload">浏览器即将下载</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器在下载开始之前调用此事件。默认请况下所有的下载都将被取消。执行|下载回调|接口可以使浏览器继续下载(如果需要)。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyDownloadItem.md" style ="color: blue">水星下载项</a> 下载项 <span style="color: rgb(0, 128, 0)">下载项</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 建议名称 <span style="color: rgb(0, 128, 0)">建议名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnDownloadUpdated">浏览器下载进度已更新</span> |
|:----|
| <span style="color:rgb(0,128,0)">当下载状态或进度信息已更新时调用此事件。该事件会在\"浏览器即将下载\"事件之后被多次调用。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyDownloadItem.md" style ="color: blue">水星下载项</a> 下载项 <span style="color: rgb(0, 128, 0)">下载项</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnResourceFilter">浏览器资源过滤器已就绪</span> |
|:----|
| <span style="color:rgb(0,128,0)">该事件仅在启用资源过滤器后才会发生, 资源过滤器初始化完毕时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyResponseFilter.md" style ="color: blue">水星资源过滤器</a> 过滤器 <span style="color: rgb(0, 128, 0)">过滤器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnServerCreated">服务器启动就绪</span> |
|:----|
| <span style="color:rgb(0,128,0)">服务器启动就绪时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyServer.md" style ="color: blue">水星服务器</a> 服务器 <span style="color: rgb(0, 128, 0)">服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnServerDestroyed">服务器停止运行</span> |
|:----|
| <span style="color:rgb(0,128,0)">服务器停止运行时调用此事件<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyServer.md" style ="color: blue">水星服务器</a> 服务器 <span style="color: rgb(0, 128, 0)">服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnClientConnected">服务器客户进入</span> |
|:----|
| <span style="color:rgb(0,128,0)">收到客户端连接时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyServer.md" style ="color: blue">水星服务器</a> 服务器 <span style="color: rgb(0, 128, 0)">服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnClientDisconnected">服务器客户离开</span> |
|:----|
| <span style="color:rgb(0,128,0)">客户端与服务器断开连接时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyServer.md" style ="color: blue">水星服务器</a> 服务器 <span style="color: rgb(0, 128, 0)">服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnHttpRequest">服务器收到请求</span> |
|:----|
| <span style="color:rgb(0,128,0)">服务器收到一个HTTP请求时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyServer.md" style ="color: blue">水星服务器</a> 服务器 <span style="color: rgb(0, 128, 0)">服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 客户地址 <span style="color: rgb(0, 128, 0)">客户地址</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnWebSocketRequest">服务器收到套接字请求</span> |
|:----|
| <span style="color:rgb(0,128,0)">服务器收到一个WebSocket请求时调用此事件。返回真允许客户连接套接字(Websocket)连接, 返回假忽略此请求。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyServer.md" style ="color: blue">水星服务器</a> 服务器 <span style="color: rgb(0, 128, 0)">服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 客户地址 <span style="color: rgb(0, 128, 0)">客户地址</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnWebSocketConnected">服务器套接字已连接</span> |
|:----|
| <span style="color:rgb(0,128,0)">接受客户端Websocket连接后调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyServer.md" style ="color: blue">水星服务器</a> 服务器 <span style="color: rgb(0, 128, 0)">服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnWebSocketMessage">服务器收到套接字消息</span> |
|:----|
| <span style="color:rgb(0,128,0)">服务器收到Websocket消息时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyServer.md" style ="color: blue">水星服务器</a> 服务器 <span style="color: rgb(0, 128, 0)">服务器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 客户ID <span style="color: rgb(0, 128, 0)">客户ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 消息内容 <span style="color: rgb(0, 128, 0)">消息内容</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 消息长度 <span style="color: rgb(0, 128, 0)">消息长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnWebSocketClientConnected">网页套接字连接成功</span> |
|:----|
| <span style="color:rgb(0,128,0)">成功连接到服务器时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWebSocket.md" style ="color: blue">水星网页套接字</a> 套接字 <span style="color: rgb(0, 128, 0)">套接字</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnWebSocketClientClosed">网页套接字连接断开</span> |
|:----|
| <span style="color:rgb(0,128,0)">已断开与服务器的连接时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWebSocket.md" style ="color: blue">水星网页套接字</a> 套接字 <span style="color: rgb(0, 128, 0)">套接字</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnWebSocketClientMessage">网页套接字数据到达</span> |
|:----|
| <span style="color:rgb(0,128,0)">接收到服务器数据时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWebSocket.md" style ="color: blue">水星网页套接字</a> 套接字 <span style="color: rgb(0, 128, 0)">套接字</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 流类型 <span style="color: rgb(0, 128, 0)">流类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 流数据 <span style="color: rgb(0, 128, 0)">流数据</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnWebSocketClientError">网页套接字连接错误</span> |
|:----|
| <span style="color:rgb(0,128,0)">网页套接字连接产生错误时调用此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWebSocket.md" style ="color: blue">水星网页套接字</a> 套接字 <span style="color: rgb(0, 128, 0)">套接字</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 错误信息 <span style="color: rgb(0, 128, 0)">错误信息</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnExtensionLoadFailed">扩展程序载入失败</span> |
|:----|
| <span style="color:rgb(0,128,0)">调用函数 水星浏览器.载入扩展程序() 请求失败时执行此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 错误代码 <span style="color: rgb(0, 128, 0)">错误代码</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnExtensionLoaded">扩展程序载入完毕</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果调用函数 水星浏览器.载入扩展程序() 请求成功时执行此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> 扩展程序 <span style="color: rgb(0, 128, 0)">扩展程序</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnExtensionUnloaded">扩展程序已卸载</span> |
|:----|
| <span style="color:rgb(0,128,0)">调用函数 水星扩展程序.卸载() 请求成功时执行此事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> 扩展程序 <span style="color: rgb(0, 128, 0)">扩展程序</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeBackgroundBrowser">扩展程序托管脚本</span> |
|:----|
| <span style="color:rgb(0,128,0)">当扩展程序需要浏览器来托管后台脚本运行时调用此事件。取消后台脚本的加载以及浏览器的创建返回真, 返回假则允许创建浏览器并运行脚本。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> 扩展程序 <span style="color: rgb(0, 128, 0)">扩展程序</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 引用页面URL <span style="color: rgb(0, 128, 0)">引用页面URL</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnBeforeBrowser">扩展程序将要打开</span> |
|:----|
| <span style="color:rgb(0,128,0)">当扩展程序API(例如: chrome.tabs.create)请求创建一个新的浏览器时调用此事件。取消浏览器的创建返回真, 返回假则允许创建此浏览器。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> 扩展程序 <span style="color: rgb(0, 128, 0)">扩展程序</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 活动浏览器 <span style="color: rgb(0, 128, 0)">活动浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 索引 <span style="color: rgb(0, 128, 0)">索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 加载URL <span style="color: rgb(0, 128, 0)">加载URL</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 活动窗口 <span style="color: rgb(0, 128, 0)">活动窗口</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyWindowInfo.md" style ="color: blue">水星窗口设置</a> 窗口设置 <span style="color: rgb(0, 128, 0)">窗口设置</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="CanAccessBrowser">扩展程序关联浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">当tabId与|目标浏览器|关联时调用此事件以指定给接受tabId参数的扩展程序API调用(例如: chrome.tabs.* )。允许扩展程序访问浏览器返回真, 取消访问返回假。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> 扩展程序 <span style="color: rgb(0, 128, 0)">扩展程序</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 隐身模式 <span style="color: rgb(0, 128, 0)">隐身模式</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 目标浏览器 <span style="color: rgb(0, 128, 0)">目标浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetActiveBrowser">扩展程序取活动浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">为未接受tabId参数的扩展API调用指定tabId时调用(例如, chrome.tabs.*)。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> 扩展程序 <span style="color: rgb(0, 128, 0)">扩展程序</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 隐身模式 <span style="color: rgb(0, 128, 0)">隐身模式</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyActiveBrowserCallback.md" style ="color: blue">水星获取活动浏览器回调</a> 获取回调 <span style="color: rgb(0, 128, 0)">获取回调</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetExtensionResource">扩展程序获取资源事件</span> |
|:----|
| <span style="color:rgb(0,128,0)">扩展程序调用此事件从磁盘搜索并加载扩展资源(例如, 如果将文件参数指定为chrome.tabs.executeScript)。要处理资源请求请返回真并执行|资源获取回调|参数方法向扩展程序提交获取结果。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> 扩展程序 <span style="color: rgb(0, 128, 0)">扩展程序</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 资源文件名 <span style="color: rgb(0, 128, 0)">资源文件名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyGetExtensionResourceCallback.md" style ="color: blue">水星扩展程序资源获取回调</a> 资源获取回调 <span style="color: rgb(0, 128, 0)">资源获取回调</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnQuery">脚本收到查询</span> |
|:----|
| <span style="color:rgb(0,128,0)">收到新的 Javascript 查询时执行此事件。返回真表示查询已被处理, 返回假查询将会被传递至其它已注册的处理例程(如果有)。如果没有处理程序从此事件中返回真, 查询将会被取消, 并向Javascript onFailure 回调传递错误代码-1。如果此返回返回真必须执行异步参数回调|查询结果|以返回查询结果。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">长整数型</span> 查询ID <span style="color: rgb(0, 128, 0)">查询ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 持久性 <span style="color: rgb(0, 128, 0)">持久性</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyQueryCallback.md" style ="color: blue">水星脚本查询回调</a> 查询结果 <span style="color: rgb(0, 128, 0)">查询结果</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="OnQueryCanceled">脚本查询已取消</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用 Javascript 取消功能显示的取消了查询或由于浏览器被销毁, 发生导航或Renderer进程终止而隐式取消查询时调用此事件。调用此方法后, 不应在保留与查询关联的回调接口对象, 也不应在执行回调中的任何接口。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> 框架 <span style="color: rgb(0, 128, 0)">框架</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">长整数型</span> 查询ID <span style="color: rgb(0, 128, 0)">查询ID</span> | 
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
