# 数据类型
| 类型名称 | 类型说明 | 方法 |
|:--|:----|:--|
| 水星铬浏览框 | 水星铬浏览框是浏览器的父窗口控件类, 除了提供了一个默认的父窗口实现外,它还负责浏览器的事件调度分发, 提供创建、销毁、查询等功能函数。 | [Goto](/manual/ProxyClient.md) |
| 水星获取活动浏览器回调 | 用于扩展程序事件扩展程序取活动浏览器。向扩展程序返回当前应用程序中的活动浏览器对象。 | [Goto](/manual/ProxyActiveBrowserCallback.md) |
| 水星认证 | 提供用户身份验证数据的回调接口。 | [Goto](/manual/ProxyAuthCallback.md) |
| 静态方法 | 适用于全局的静态函数集合。 | [Goto](/manual/ProxyBase.md) |
| 水星浏览器 | 用于代表浏览器的类。在浏览器进程中可以在任何线程上调用此类方法, 除非注释中另有说明。 | [Goto](/manual/ProxyBrowser.md) |
| 水星浏览器设置 | 提供浏览器初始化设置。 | [Goto](/manual/ProxyBrowserSettings.md) |
| 水星网页驱动器 | 用作一次浏览器自动化测试过程表达。 | [Goto](/manual/ProxyCollection.md) |
| 水星命令行 | 用于创建和解析命令行参数的类。在windows中带有\"--\" 或 \"-\" 以及 \"/\" 前缀的参数被视为命令行开关。开关将始终在任何没有开关前缀的参数之前。 开关可以选择使用\"=\"分隔符指定一个值(例如: \"--switch=value\")。参数\"-\" 将终止所有后续标记的开关解析, 无论前缀如何, 都将被解释为非开关参数。开关名称不区分大小写。可以在调用\"进程初始化\" 之前使用此类。 | [Goto](/manual/ProxyCommandLine.md) |
| 水星菜单信息 | 与菜单相关的上下文信息。 | [Goto](/manual/ProxyContextMenuParams.md) |
| 水星会话凭证 | cookie 信息 | [Goto](/manual/ProxyCookie.md) |
| 水星会话管理器 | 用于管理 cookie 的类。除非另有说明, 否则可以在任何线程上调用此类的方法。 | [Goto](/manual/ProxyCookieManager.md) |
| 水星字典型 | 表示字典值(DictionaryValue)的类。 | [Goto](/manual/ProxyDictionaryValue.md) |
| 水星网页文档对象 | 表示DOM文档的类型。 | [Goto](/manual/ProxyDOMDocument.md) |
| 水星网页文档元素 | 用于表示 DOM 节点的类型。 | [Goto](/manual/ProxyDOMNode.md) |
| 水星下载项 | 用于表示下载项目的类。 | [Goto](/manual/ProxyDownloadItem.md) |
| 水星扩展程序 | 用于管理 chrome extension 扩展应用程序的类。 | [Goto](/manual/ProxyExtension.md) |
| 水星文件选择器 | 文件对话框回调接口, 如使用自定义文件对话框, 则使用该回调接口返回文件选择结果。 | [Goto](/manual/ProxyFileDialogCallback.md) |
| 水星框架 | 用于在浏览器窗口中表示框架的类。在浏览器进程中使用时, 可以在任何线程上调用此类中的方法。除非注释另有说明。 | [Goto](/manual/ProxyFrame.md) |
| 水星扩展程序资源获取回调 | 用于扩展程序获取资源事件的异步延续回调接口, 使用此接口回复扩展程序资源获取请求。 | [Goto](/manual/ProxyGetExtensionResourceCallback.md) |
| 水星脚本对话框 | 脚本对话框回调接口, 用于Javascript对话框请求的执行返回。 | [Goto](/manual/ProxyJSDialogCallback.md) |
| 水星列表型 | 表示列表值(ListValue)的类。 | [Goto](/manual/ProxyListValue.md) |
| 水星菜单 | 上下文菜单 | [Goto](/manual/ProxyMenuModel.md) |
| 水星提交元素 | 用于表示 Web 请求提交数据(PostData)中的单个元素的的类。 | [Goto](/manual/ProxyPostDataElement.md) |
| 水星脚本查询回调 | 与单个挂起的Javascript异步查询关联的回调。执行 \"成功\" 或 \"失败\" 方法将异步响应发送到关联的Javascript处理程序。在不首先执行其中一共回调方法的情况下, 销毁与未取消查询相关联的回调对象时会报告运行时错误。 | [Goto](/manual/ProxyQueryCallback.md) |
| 水星请求 | 用于表示 Web 请求的类。 | [Goto](/manual/ProxyRequest.md) |
| 水星响应 | 用于表示 Web 响应的类。 | [Goto](/manual/ProxyResponse.md) |
| 水星资源过滤器 | 用于提供资源可选化配置的类。 | [Goto](/manual/ProxyResponseFilter.md) |
| 水星菜单回调 | 自定义菜单命令回调 | [Goto](/manual/ProxyRunContextMenuCallback.md) |
| 水星服务器 | 表示支持HTTP/Websocket-Server端的类。服务器容量有限, 并且只能处理少量的同时连接。 | [Goto](/manual/ProxyServer.md) |
| 水星初始化设置 | 提供浏览器进程的初始化设置。这些设置用于配置Chromium全局运行参数, 设置为0或空时保持为建议的默认值, 这些设置也使用命令行开关(command-switch)进行配置。 | [Goto](/manual/ProxySettings.md) |
| 水星URL请求 | 表示HTTP请求的类。 | [Goto](/manual/ProxyURLRequest.md) |
| 水星通用型 | 包装基础数据类型数值的类, 复杂类型如(列表型, 字典型)。将只包含对其的引用,但不属于此对象。 | [Goto](/manual/ProxyValue.md) |
| 水星等待事件 | 等待事件通常用于线程同步, 它允许一个线程等待另一个线程完成某些事件后在继续工作。 | [Goto](/manual/ProxyWaitableEvent.md) |
| 水星网页套接字 | 表示一个Websocket连接的类。 | [Goto](/manual/ProxyWebSocket.md) |
| 水星窗口设置 | 为浏览器提供窗口设置信息,它告诉浏览器该创建怎样的窗口。比如让浏览器呈现在某个窗口中作为它的子控件抑或是让它在独立的顶层窗口中( 调用 **.设置为弹出窗口** 函数 )运行。 | [Goto](/manual/ProxyWindowInfo.md) |
