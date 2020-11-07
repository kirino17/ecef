# 水星浏览器
###### 用于代表浏览器的类。在浏览器进程中可以在任何线程上调用此类方法, 除非注释中另有说明。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#GetWindowHandle"  style="color:rgb(128,0,0)">取窗口句柄</a> , <a href="#CanGoBack"  style="color:rgb(128,0,0)">可否回退</a> , <a href="#GoBack"  style="color:rgb(128,0,0)">回退</a> , <a href="#CanGoForward"  style="color:rgb(128,0,0)">可否前进</a> , <a href="#GoForward"  style="color:rgb(128,0,0)">前进</a> , <a href="#IsLoading"  style="color:rgb(128,0,0)">是否正在加载</a> , <a href="#Reload"  style="color:rgb(128,0,0)">重新加载</a> , <a href="#ReloadIgnoreCache"  style="color:rgb(128,0,0)">重新加载忽略缓存</a> , <a href="#StopLoad"  style="color:rgb(128,0,0)">停止加载</a> , <a href="#GetIdentifier"  style="color:rgb(128,0,0)">取标识符</a> , <a href="#IsPopup"  style="color:rgb(128,0,0)">是否为弹出式窗口</a> , <a href="#HasDocument"  style="color:rgb(128,0,0)">是否已加载文档</a> , <a href="#GetMainFrame"  style="color:rgb(128,0,0)">取主框架</a> , <a href="#GetFocusedFrame"  style="color:rgb(128,0,0)">取焦点框架</a> , <a href="#GetFrame"  style="color:rgb(128,0,0)">从名称取框架</a> , <a href="#GetFrameWithIdentity"  style="color:rgb(128,0,0)">从标识符取框架</a> , <a href="#GetFrameCount"  style="color:rgb(128,0,0)">取框架数量</a> , <a href="#GetFrameNames"  style="color:rgb(128,0,0)">取所有框架名称</a> , <a href="#GetFrameIdentifiers"  style="color:rgb(128,0,0)">取所有框架标识符</a> , <a href="#GetFrames"  style="color:rgb(128,0,0)">取所有框架</a> , <a href="#CloseBrowser"  style="color:rgb(128,0,0)">关闭浏览器</a> , <a href="#SetFocus"  style="color:rgb(128,0,0)">置焦点</a> , <a href="#GetOpenerWindowHandle"  style="color:rgb(128,0,0)">取所有者窗口句柄</a> , <a href="#GetZoomLevel"  style="color:rgb(128,0,0)">取缩放比例</a> , <a href="#SetZoomLevel"  style="color:rgb(128,0,0)">置缩放比例</a> , <a href="#StartDownload"  style="color:rgb(128,0,0)">启动下载</a> , <a href="#Print"  style="color:rgb(128,0,0)">打印页面</a> , <a href="#SendKeyDownEvent"  style="color:rgb(128,0,0)">按下某键</a> , <a href="#SendKeyUpEvent"  style="color:rgb(128,0,0)">弹起某键</a> , <a href="#SendKeyPressEvent"  style="color:rgb(128,0,0)">某键输入</a> , <a href="#SendCharEvent"  style="color:rgb(128,0,0)">字符输入</a> , <a href="#SendCharArrayEvent"  style="color:rgb(128,0,0)">字符串输入</a> , <a href="#SendMouseClickEvent"  style="color:rgb(128,0,0)">鼠标点击</a> , <a href="#SendMouseMoveEvent"  style="color:rgb(128,0,0)">鼠标移动</a> , <a href="#SendMouseWheelEvent"  style="color:rgb(128,0,0)">鼠标滚轮滑动</a> , <a href="#SendTouchEvent"  style="color:rgb(128,0,0)">触摸</a> , <a href="#SendFocusEvent"  style="color:rgb(128,0,0)">置焦点事件</a> , <a href="#SendCaptureLostEvent"  style="color:rgb(128,0,0)">置捕获丢失事件</a> , <a href="#NotifyMoveOrResizeStarted"  style="color:rgb(128,0,0)">通知位置尺寸已改变</a> , <a href="#SetAudioMuted"  style="color:rgb(128,0,0)">置静音模式</a> , <a href="#IsAudioMuted"  style="color:rgb(128,0,0)">是否为静音模式</a> , <a href="#ShowDevTools"  style="color:rgb(128,0,0)">打开开发者工具</a> , <a href="#CloseDevTools"  style="color:rgb(128,0,0)">关闭开发者工具</a> , <a href="#HasDevTools"  style="color:rgb(128,0,0)">是否已打开开发者工具</a> , <a href="#GetCookieManager"  style="color:rgb(128,0,0)">取会话管理器</a> , <a href="#AddFirstScriptOnNewDocument"  style="color:rgb(128,0,0)">置优先执行脚本</a> , <a href="#SetUserAgentOverride"  style="color:rgb(128,0,0)">置用户代理标识</a> , <a href="#SetTouchEventEmulationEnabled"  style="color:rgb(128,0,0)">启用触摸事件模拟</a> , <a href="#SetGeolocationOverride"  style="color:rgb(128,0,0)">置地理位置</a> , <a href="#SetEmulatedMedia"  style="color:rgb(128,0,0)">启用多媒体模拟</a> , <a href="#ClearMediaFeatureOverrides"  style="color:rgb(128,0,0)">清除多媒体模拟功能</a> , <a href="#EnableDeviceEmulation"  style="color:rgb(128,0,0)">启用设备仿真模拟</a> , <a href="#DisableDeviceEmulation"  style="color:rgb(128,0,0)">关闭设备仿真模拟</a> , <a href="#SetEmitTouchEventsForMouse"  style="color:rgb(128,0,0)">启用触摸模拟传感器</a> , <a href="#LoadExtension"  style="color:rgb(128,0,0)">载入扩展程序</a> , <a href="#DidLoadExtension"  style="color:rgb(128,0,0)">从标识符载入扩展程序</a> , <a href="#HasExtension"  style="color:rgb(128,0,0)">是否存在扩展程序</a> , <a href="#GetExtensions"  style="color:rgb(128,0,0)">取所有扩展程序标识符</a> , <a href="#GetExtension"  style="color:rgb(128,0,0)">取扩展程序</a> , <a href="#IsBackgroundHost"  style="color:rgb(128,0,0)">是否为扩展程序浏览器</a> , <a href="#GetUserData"  style="color:rgb(128,0,0)">取用户数据</a> , <a href="#HasPreference"  style="color:rgb(128,0,0)">是否存在首选项</a> , <a href="#GetPreference"  style="color:rgb(128,0,0)">取首选项</a> , <a href="#GetAllPreferences"  style="color:rgb(128,0,0)">取所有首选项</a> , <a href="#CanSetPreference"  style="color:rgb(128,0,0)">可否设置首选项</a> , <a href="#SetPreference"  style="color:rgb(128,0,0)">置首选项值</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetWindowHandle">取窗口句柄</span> |
|:----|
| <span style="color:rgb(0,128,0)">取浏览器窗口句柄。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="CanGoBack">可否回退</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果当前浏览器可回退至上一浏览页面返回真, 否则返回假。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GoBack">回退</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置浏览器回退到上一浏览页面。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="CanGoForward">可否前进</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果当前浏览器可前进至下一浏览页面返回真, 否则返回假<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GoForward">前进</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置浏览器前进至下一浏览页面。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="IsLoading">是否正在加载</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果当前浏览器正在加载中返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Reload">重新加载</span> |
|:----|
| <span style="color:rgb(0,128,0)">重新加载此页面。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ReloadIgnoreCache">重新加载忽略缓存</span> |
|:----|
| <span style="color:rgb(0,128,0)">重新加载此页面, 不从缓冲中读取。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="StopLoad">停止加载</span> |
|:----|
| <span style="color:rgb(0,128,0)">停止加载页面。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetIdentifier">取标识符</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此浏览器的标识符<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="IsPopup">是否为弹出式窗口</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果当前浏览器为弹出式窗口返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="HasDocument">是否已加载文档</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果文档已加载到浏览器中返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetMainFrame">取主框架</span> |
|:----|
| <span style="color:rgb(0,128,0)">取第一个加载的(Top-Level)框架。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> |


| <span style="color:rgb(128,0,0)" id="GetFocusedFrame">取焦点框架</span> |
|:----|
| <span style="color:rgb(0,128,0)">取当前拥有焦点的框架。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> |


| <span style="color:rgb(128,0,0)" id="GetFrame">从名称取框架</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用名称检索浏览器中的指定框架, 检索成功返回对象实例, 检索失败返回空对象, 可调用IsValid() 函数检查对象有效性。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 框架名称 <span style="color: rgb(0, 128, 0)">框架名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> |


| <span style="color:rgb(128,0,0)" id="GetFrameWithIdentity">从标识符取框架</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用标识符检索浏览器中的指定框架, 检索成功返回对象实例, 检索失败返回空对象, 可调用IsValid() 函数检查对象有效性。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">长整数型</span> 标识符 <span style="color: rgb(0, 128, 0)">标识符</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> |


| <span style="color:rgb(128,0,0)" id="GetFrameCount">取框架数量</span> |
|:----|
| <span style="color:rgb(0,128,0)">取浏览器中已加载的框架数量。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetFrameNames">取所有框架名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">取浏览器中所有已加载框架的名称。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型变量</span> |


| <span style="color:rgb(128,0,0)" id="GetFrameIdentifiers">取所有框架标识符</span> |
|:----|
| <span style="color:rgb(0,128,0)">取浏览器中所有已加载框架的标识符。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetFrames">取所有框架</span> |
|:----|
| <span style="color:rgb(0,128,0)">取浏览器中所有已加载的框架。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> |


| <span style="color:rgb(128,0,0)" id="CloseBrowser">关闭浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">向此实例中的浏览器发送关闭请求。发送此请求后JavaScript的\"onbeforeunload\"事件将被触发。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 强制关闭 <span style="color: rgb(0, 128, 0)">强制关闭</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetFocus">置焦点</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置浏览器是否索取焦点。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 焦点 <span style="color: rgb(0, 128, 0)">焦点</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetOpenerWindowHandle">取所有者窗口句柄</span> |
|:----|
| <span style="color:rgb(0,128,0)">取创建此浏览器窗口的窗口句柄。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetZoomLevel">取缩放比例</span> |
|:----|
| <span style="color:rgb(0,128,0)">浏览器当前浏览器页面缩放比例。默认值为: 0.0f<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">双精度小数型</span> |


| <span style="color:rgb(128,0,0)" id="SetZoomLevel">置缩放比例</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置当前浏览器页面缩放比例, 设置为0.0f时重置缩放比例。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">双精度小数型</span> 缩放比例 <span style="color: rgb(0, 128, 0)">缩放比例</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="StartDownload">启动下载</span> |
|:----|
| <span style="color:rgb(0,128,0)">下载指定URL资源。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Print">打印页面</span> |
|:----|
| <span style="color:rgb(0,128,0)">打印当前页面。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendKeyDownEvent">按下某键</span> |
|:----|
| <span style="color:rgb(0,128,0)">向浏览器发送一次键盘输入事件表示某个按键已被按下。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 键代码 <span style="color: rgb(0, 128, 0)">键代码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否为系统键 <span style="color: rgb(0, 128, 0)">是否为系统键</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendKeyUpEvent">弹起某键</span> |
|:----|
| <span style="color:rgb(0,128,0)">向浏览器发送一次键盘输入事件表示某个按键已弹起。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 键代码 <span style="color: rgb(0, 128, 0)">键代码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否为系统键 <span style="color: rgb(0, 128, 0)">是否为系统键</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendKeyPressEvent">某键输入</span> |
|:----|
| <span style="color:rgb(0,128,0)">向浏览器发送一次键盘输入事件包含某个按键的按下以及弹起过程。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 键代码 <span style="color: rgb(0, 128, 0)">键代码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否为系统键 <span style="color: rgb(0, 128, 0)">是否为系统键</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 持续时间 <span style="color: rgb(0, 128, 0)">持续时间</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendCharEvent">字符输入</span> |
|:----|
| <span style="color:rgb(0,128,0)">向浏览器发送一次键盘输入事件表示某个字符已被输入。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">字节型</span> 字符 <span style="color: rgb(0, 128, 0)">字符</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendCharArrayEvent">字符串输入</span> |
|:----|
| <span style="color:rgb(0,128,0)">向浏览器发送一次键盘输入事件包含一个字符数组的输入信息。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 字符数组 <span style="color: rgb(0, 128, 0)">字符数组</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 间隔时间 <span style="color: rgb(0, 128, 0)">间隔时间</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendMouseClickEvent">鼠标点击</span> |
|:----|
| <span style="color:rgb(0,128,0)">向当前浏览器发送鼠标点击事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始位置X <span style="color: rgb(0, 128, 0)">起始位置X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始位置Y <span style="color: rgb(0, 128, 0)">起始位置Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 点击类型 <span style="color: rgb(0, 128, 0)">点击类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否弹起 <span style="color: rgb(0, 128, 0)">是否弹起</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 点击次数 <span style="color: rgb(0, 128, 0)">点击次数</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendMouseMoveEvent">鼠标移动</span> |
|:----|
| <span style="color:rgb(0,128,0)">向当前浏览器发送鼠标移动事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始位置X <span style="color: rgb(0, 128, 0)">起始位置X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始位置Y <span style="color: rgb(0, 128, 0)">起始位置Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否离开 <span style="color: rgb(0, 128, 0)">是否离开</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendMouseWheelEvent">鼠标滚轮滑动</span> |
|:----|
| <span style="color:rgb(0,128,0)">向当前浏览器发送鼠标滚轮事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始位置X <span style="color: rgb(0, 128, 0)">起始位置X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始位置Y <span style="color: rgb(0, 128, 0)">起始位置Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 增量X <span style="color: rgb(0, 128, 0)">增量X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 增量Y <span style="color: rgb(0, 128, 0)">增量Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendTouchEvent">触摸</span> |
|:----|
| <span style="color:rgb(0,128,0)">向当前浏览器发送触摸事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 标识符 <span style="color: rgb(0, 128, 0)">标识符</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 触点位置X <span style="color: rgb(0, 128, 0)">触点位置X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 触点位置Y <span style="color: rgb(0, 128, 0)">触点位置Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 半径X <span style="color: rgb(0, 128, 0)">半径X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 半径Y <span style="color: rgb(0, 128, 0)">半径Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 旋转角度 <span style="color: rgb(0, 128, 0)">旋转角度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 输入压力 <span style="color: rgb(0, 128, 0)">输入压力</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 触点状态 <span style="color: rgb(0, 128, 0)">触点状态</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 指针类型 <span style="color: rgb(0, 128, 0)">指针类型</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendFocusEvent">置焦点事件</span> |
|:----|
| <span style="color:rgb(0,128,0)">向当前浏览器发送焦点事件<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 焦点 <span style="color: rgb(0, 128, 0)">焦点</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SendCaptureLostEvent">置捕获丢失事件</span> |
|:----|
| <span style="color:rgb(0,128,0)">向浏览器发送捕获丢失事件。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="NotifyMoveOrResizeStarted">通知位置尺寸已改变</span> |
|:----|
| <span style="color:rgb(0,128,0)">通知浏览器窗口位置以及尺寸已变更。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetAudioMuted">置静音模式</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置当前浏览器是否启用静音模式。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 静音 <span style="color: rgb(0, 128, 0)">静音</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="IsAudioMuted">是否为静音模式</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果当前浏览器已设置为静音模式返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="ShowDevTools">打开开发者工具</span> |
|:----|
| <span style="color:rgb(0,128,0)">在此浏览器中运行开发者工具。成功返回开发者工具所在浏览器窗口句柄。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 审查坐标X <span style="color: rgb(0, 128, 0)">审查坐标X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 审查坐标Y <span style="color: rgb(0, 128, 0)">审查坐标Y</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="CloseDevTools">关闭开发者工具</span> |
|:----|
| <span style="color:rgb(0,128,0)">关闭运行的开发者工具。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="HasDevTools">是否已打开开发者工具</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此浏览器已有开发者工具在运行返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetCookieManager">取会话管理器</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取本浏览器使用的会话凭证(Cookie)管理器。 未设置隐身模式时浏览器共享使用全局的会话凭证管理器。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCookieManager.md" style ="color: blue">水星会话管理器</a> |


| <span style="color:rgb(128,0,0)" id="AddFirstScriptOnNewDocument">置优先执行脚本</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置浏览器DOM结构加载后第一个执行的脚本。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 脚本代码 <span style="color: rgb(0, 128, 0)">脚本代码</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetUserAgentOverride">置用户代理标识</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用新的用户代理标识以覆盖默认值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 用户代理标识 <span style="color: rgb(0, 128, 0)">用户代理标识</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 应用程序版本 <span style="color: rgb(0, 128, 0)">应用程序版本</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetTouchEventEmulationEnabled">启用触摸事件模拟</span> |
|:----|
| <span style="color:rgb(0,128,0)">在不支持的平台上启用触摸事件模拟。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 启用 <span style="color: rgb(0, 128, 0)">启用</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 最大触点数 <span style="color: rgb(0, 128, 0)">最大触点数</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetGeolocationOverride">置地理位置</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置地理位置信息。所有的参数都不可以省略。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 纬度 <span style="color: rgb(0, 128, 0)">纬度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 经度 <span style="color: rgb(0, 128, 0)">经度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 精度 <span style="color: rgb(0, 128, 0)">精度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetEmulatedMedia">启用多媒体模拟</span> |
|:----|
| <span style="color:rgb(0,128,0)">模拟CSS媒体查询的给定媒体类型或媒体功能。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 媒体类型 <span style="color: rgb(0, 128, 0)">媒体类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> 功能 <span style="color: rgb(0, 128, 0)">功能</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ClearMediaFeatureOverrides">清除多媒体模拟功能</span> |
|:----|
| <span style="color:rgb(0,128,0)">清除模拟的多媒体功能。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="EnableDeviceEmulation">启用设备仿真模拟</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用指定的参数进行设备仿真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> 仿真参数 <span style="color: rgb(0, 128, 0)">仿真参数</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="DisableDeviceEmulation">关闭设备仿真模拟</span> |
|:----|
| <span style="color:rgb(0,128,0)">关闭指定参数的设备仿真模拟<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetEmitTouchEventsForMouse">启用触摸模拟传感器</span> |
|:----|
| <span style="color:rgb(0,128,0)">启用触摸模拟传感器, 开启后所有的鼠标事件将会转换为触摸事件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 启用 <span style="color: rgb(0, 128, 0)">启用</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 配置参数 <span style="color: rgb(0, 128, 0)">配置参数</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="LoadExtension">载入扩展程序</span> |
|:----|
| <span style="color:rgb(0,128,0)">加载 chrome extension 扩展程序。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 加载目录 <span style="color: rgb(0, 128, 0)">加载目录</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> 清单内容 <span style="color: rgb(0, 128, 0)">清单内容</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="DidLoadExtension">从标识符载入扩展程序</span> |
|:----|
| <span style="color:rgb(0,128,0)">加载 chrome extension 扩展程序。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 扩展程序标识符 <span style="color: rgb(0, 128, 0)">扩展程序标识符</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="HasExtension">是否存在扩展程序</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果在此浏览器上下文中存在目标扩展程序返回真<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 扩展程序标识符 <span style="color: rgb(0, 128, 0)">扩展程序标识符</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetExtensions">取所有扩展程序标识符</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此浏览器上下文中所有存在的扩展程序标识符。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型变量</span> |


| <span style="color:rgb(128,0,0)" id="GetExtension">取扩展程序</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回符合指定标识符的扩展程序对象。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 扩展程序标识符 <span style="color: rgb(0, 128, 0)">扩展程序标识符</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyExtension.md" style ="color: blue">水星扩展程序</a> |


| <span style="color:rgb(128,0,0)" id="IsBackgroundHost">是否为扩展程序浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此浏览器为装载扩展程序的宿主(host)浏览器返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetUserData">取用户数据</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回用于设置与浏览器关联的用户自定义数据信息。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> |


| <span style="color:rgb(128,0,0)" id="HasPreference">是否存在首选项</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果具有符合指定名称的首选项存在则返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 首选项 <span style="color: rgb(0, 128, 0)">首选项</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetPreference">取首选项</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回具有符合指定名称的首选项的值。如果首选项不存在则返回空对象。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 首选项 <span style="color: rgb(0, 128, 0)">首选项</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyValue.md" style ="color: blue">水星通用型</a> |


| <span style="color:rgb(128,0,0)" id="GetAllPreferences">取所有首选项</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回所有首选项信息。返回字典类型数据, 首选项名称为\"key\", 首选项值为\"value\"。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 包含默认首选项 <span style="color: rgb(0, 128, 0)">包含默认首选项</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> |


| <span style="color:rgb(128,0,0)" id="CanSetPreference">可否设置首选项</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果具有指定名称的首选项则返回真, 可以使用 置首选项值 方法进行修改。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 首选项 <span style="color: rgb(0, 128, 0)">首选项</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetPreference">置首选项值</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置符合指定名称的首选项的值。如果设置成功返回真, 否则返回假。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 首选项 <span style="color: rgb(0, 128, 0)">首选项</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyValue.md" style ="color: blue">水星通用型</a> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
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
