# 水星浏览器

### 介绍
水星浏览器创建于2016年, 是一个易语言项目, 项目目标是追踪 Google Chromium 嵌入式分支CEF以及前沿WEB自动化测试技术以在此之上构建易语言的 Chromium 嵌入式实现满足易语言开发环境对现代化浏览器功能的需求支持。 水星浏览器的典型应用场景包括:

* 作为一个兼容HTML5的浏览器控件嵌入到应用程序中。
* 创建一个轻量化的壳浏览器用于托管Web技术开发的应用程序。
* 使用浏览器进行自动化的WEB内容测试。

### 开发手册

[http://www.itwitch.cc/ecef/](http://www.itwitch.cc/ecef/)

### 编译
编译支持库需要准备:
* Visual Studio 2015 或者更高版本。
* Windows 10 SDK 18362.0
* Visual Studio Code

项目: src/aquarius2 为实现易语言调用CEF所需要的胶水代码工程。已进行自动化配置可使用Visual Studio打开.sln 项目方案进行编译。 <br/>
项目: src/TestRenderer 为多进程模式下用于挂载浏览器进程的壳程序工程, 壳程序提供了执行Javascript脚本, DOM访问, 以及一些其它功能性方法。已进行自动化配置可使用Visual Studio打开.sln 项目方案进行编译。 <br/>
项目: src/ 为支持库工程代码, 项目方案使用Visual Studio Code构建, 在项目根文件夹下打开Visual Studio Code运行生成任务即可编译支持库。<br/>

### 安装

选择所需版本安装程序下载到本地磁盘上，双击执行安装向导程序。如果本机已装有支持库, 需要先执行支持库卸载操作后再进行安装。
> 装有2.0测试版本的电脑需要在系统环境变量"Path"中将测试版本运行时目录删除。

安装须知, 执行安装程序时应选择将支持库安装到易语言客户端目录下,如:
![安装位置](https://github.com/kirino17/ecef/raw/master/image/Install-02.png)

并在安装完成时勾选"启用水星浏览器支持库"以安装支持库文件到易语言中。
![安装支持库文件](https://github.com/kirino17/ecef/raw/master/image/Install-03.png)


### 授权
水星浏览器浏览器使用 BSD-3-Clause 开源协议免费授权, 欢迎下载使用。


### 发布
发布使用水星浏览器的应用程序应将以下文件打包至你的安装资源包中:
```hash
    #支持库资源

    aquarius2.dll
    spare-proc.exe

    #CEF 资源

    /swiftshader
    /locales
    chrome_elf.dll
    cef.pak
    cef_100_percent.pak
    cef_200_percent.pak
    cef_extensions.pak
    devtools_resources.pak
    icudtl.dat
    d3dcompiler_47.dll
    libcef.dll
    libEGL.dll
    libGLESv2.dll
    snapshot_blob.bin
    v8_context_snapshot.bin

```

可以通过支持库快捷命令 "工具"->"水星 发布应用程序" 一次性将这些文件复制到你的安装资源文件夹中:
![发布应用程序](https://github.com/kirino17/ecef/raw/master/image/Release-01.png)



### 开始

#### 创建应用程序
创建使用水星浏览器的应用程序没有什么特别的, 从启动窗口或者从启动子程序开始应用程序并执行第一个浏览器方法:
<br/><br/>
![初始化设置](https://github.com/kirino17/ecef/raw/master/image/readme-02.png)
<br/><br/>

类型 [水星初始化设置](\manual\ProxySettings.md) 提供了浏览器的初始化参数设置, 执行方法 <a href="ProxyBase.md#Initialize" style="color:rgb(128,0,0)">进程初始化</a> 初始化浏览器, 缺省参数浏览器将使用默认设置。
<br/><br/>
![缺省初始化](https://github.com/kirino17/ecef/raw/master/image/readme-66.png)
<br/>

一些常用到的初始化配置项如下:
* `全局缓存目录` 设置磁盘上用于存放缓存数据的位置。如果此项为空, 某些功能将使用内存缓存, 多数功能将使用临时的磁盘缓存。 形如本地存储的HTML5数据库只能在设置了缓存路径后才能跨 session 存储。
* `语言环境` 此设置项将传递给Blink。如果此项为空, 将使用默认值"en-US"。此项额可以通过命令行参数 `--lang` 设置。
* `用户数据目录` 设置用户数据存储(例如拼写检查字段文件)位置。此值作为所有浏览器创建时使用的缺省值, 如非特别指定, 所有的浏览器都将会共享此设置。保持为空时则默认不会将数据存储到磁盘上。
* `用户代理标识` 设置此值作为: User-Agent HTTP 标头的返回值。
* `保持用户首选项` 设置此值, 用户首选项数据将使用JSON文件保留到缓存目录中。
* `保持会话cookies`  设置此值, 在全局cookies管理器中保留会话cookies(它们将没有有效期)。
* `接收语言字符串` 设置全局的HTTP接收语言字符串,以逗号分隔的语言代码字符串数组,不可以使用空格, 这些字符串值将在"Accept-Language" HTTP标头中使用。

#### 浏览器组件
将 [水星铬浏览框](\manual\ProxyClient.md) 拖入设计窗口中以创建浏览器组件。
<br/><br/>
![浏览器组件](https://github.com/kirino17/ecef/raw/master/image/readme-67.png)
<br/><br/>

水星铬浏览框是浏览器的父窗口组件, 除了提供一共浏览器窗口管理能力外, 它还复制浏览器的事件分发与生命周期管理。


#### 命令行
执行 <a href="ProxyBase.md#Initialize" style="color:rgb(128,0,0)">进程初始化</a> 方法后第一个事件 `进程即将初始化` 将会触发。
<br/><br/>
![水星铬浏览框.进程即将初始化](https://github.com/kirino17/ecef/raw/master/image/readme-01.png)
<br/>
水星浏览器中的许多特性可以使用命令行参数进行配置。 这些参数参数采用 `--some-argument[-optional-param]` 的形式设置。 如果像将指定的命令行参数传入浏览器, 则应该在此事件中进行。<br/>
参数 `命令行` 类型对象提供了修改、设置命令行的能力。

##### 加载flash
加载 flash 播放器插件

```
加载 flash 播放插件
```bash
    --ppapi-flash-version = <flash插件版本>
    --ppapi-flash-path = <flash插件路径>
如:
    --ppapi-flash-version = "29.0.0.140" --ppapi-flash-path="d:\flash\pepflashplayer32_29_0_0_140.dll"
```
<br/>
![flash播放器插件](https://github.com/kirino17/ecef/raw/master/image/readme-68.png)
<br/><br/>

##### 加载ppapi

水星浏览器支持 `PPAPI` 插件, 使用命令行参数 `--register-pepper-plugins=...` 加载, 最大允许加载数量为 64 个。
```bash
参数格式:
    --register-pepper-plugins = <plugin-entry> + *( LWS + "," + LWS + <plugin-entry> )

    <plugin-entry> = <file-path> + [ "#" + <name> + ["#" + <description> + ["#" + <version>
        ]]] + *1( LWS + ";" + LWS + <mime-type-data> )

    <mime-type-data> = <mime-type> + [ LWS + "#" + LWS + <extension> ]

格式说明:
    --register-pepper-plugins = <插件入口(一般为DLL文件名)> + 可选的( [#插件名称 [#插件描述 [
        #插件版本] ] ] );MIME类型 + 可选的[#扩展信息]

    如需加载多个插件使用","分隔。

完整例子:
    --register-pepper-plugins = "d:\my\plugins\my-plugins.dll#插件的名字#插件的描述信息#插件版本;
    application/x-ppapi-test-xxxx#插件扩展信息,d:\my\plugins\my-plugins2.dll#第二个插件#第二个插件
    的描述信息#第二个插件的版本;application/x-ppapi-test-xxxx#第二个插件的扩展信息,..."
```
<br/>
![ppapi插件](https://github.com/kirino17/ecef/raw/master/image/readme-69.png)
<br/><br/>

#### 浏览器生命周期
##### 创建
浏览器生命周期从执行 水星铬浏览框<a href="ProxyClient.md#CreateBrowser" style="color:rgb(128,0,0)">.创建浏览器()</a> 开始。可以在 <a href="ProxyClient.md#Initialize" style="color:rgb(128)">进程初始化完毕</a> 事件或者在这个事件之后的任意方便的位置添加创建代码。
<br/><br/>
![创建浏览器](https://github.com/kirino17/ecef/raw/master/image/readme-70.png)
<br/><br/>
浏览器创建完成后事件 `浏览器创建完毕` 将会被触发。宿主程序可以在这个事件中获取并保存浏览器对象的引用。
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-13.png)
<br/><br/>

##### 打开
如果用户在浏览器内点击了具有"target=_blank"的链接将将会触发 `浏览器将要打开` 事件。
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-71.png)
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-72.png)
<br/>

##### 关闭
关闭浏览器使用 水星铬浏览框<a href="ProxyClient.md#CloseBrowser" style="color:rgb(128,0,0)">.关闭浏览器()</a> 方法。 关闭浏览器后 `浏览器将要关闭` 和 `浏览器即将销毁` 事件会依次触发。

#### 水星浏览器 和 水星框架
水星浏览器和水星框架对象被用来发送命令给浏览器以及在事件中获取状态信息。 每个水星浏览器对象都包含一个主框架对象, 主框架对象代表页面的顶层 `iframe` ; 同时每个浏览器对象可以包含零个或多个的子框架对象, 分别代表不同的子 `iframe` 。例如, 一个浏览器加载了两个 `iframe` ,则该浏览器对象拥有三个框架对象(顶层 `iframe` 和 两个子 `iframe` )。
下面的代码在浏览器的主 `iframe` 中加载一个URL:
```c++
    浏览器.取主框架().加载URL( some_url );
```

下面的代码执行浏览器的回退操作:
```c++
    浏览器.回退();
```

下面的代码从主 `iframe` 中获取HTML内容:
```c++
    页面HTML = 浏览器.取主框架().取页面源码();
```

浏览器窗口的原生句柄可以用下面的代码获取:
```
    窗口句柄 = 浏览器.取窗口句柄();
```
其它方法请参考支持函数相关的文档或者水星浏览器类型的使用说明。


#### 代理方案
水星浏览器使用类似 Google Chrome 一样的的方式, 通过命令行参数传递代理设置。
```bash
    
    ---proxy-server=host:port
    指定用于请求的 HTTP/SOCKS4/SOCKS5 代理服务器。
        
    个人代理服务器使用以下格式:

    [<proxy-scheme>://]<proxy-host>[:proxy-port]

    其中<proxy-scheme>是代理服务器的协议, 并且是以下之一:

    "https" , "socks" , "socks4" , "socks5".

    如果省略 <proxy-scheme> , 则默认为: "http" 。 另请注意, "socks" 等同于 
    "socks5"
    
    一些例子:

    --proxy-server="foopy:99"
    使用HTTP代理"foopy:99"加载所有URL。

    --proxy-server="socks://foobar:1080"
    使用SOCKS v5代理"foobar:1080"加载所有URL。

    --proxy-server="socks4://foobar:1080"
    使用SOCKS v4代理"foobar:1080"加载所有URL。

    --proxy-server="socks5://foobar:66"
    使用SOCKS v5代理"foobar:66"加载所有URL。

    还可以通过添加前缀为不同的URL类型指定单独的代理服务器， 带有URL说明符的代理服务器:

    --proxy-server="https=proxy1:80;http=socks4://baz:1080"

    使用HTTP代理"proxy1:80"加载 https://* , 使用SOCKS v4代理"baz:1080"加载所有 http://* 。

    --no-proxy-server
    禁用代理服务器

    --proxy-auto-detect
    自动检测代理配置

    --proxy-pac-url=URL
    指定代理自动配置URL

```
如果代理请求授权,事件 `浏览器请求用户身份验证` 会被调用。 如果 `是否为代理服务器` 参数为真, 则需要使用`认证回调`参数返回用户名和密码。
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-20.png)
<br/><br/>
网络内容加载可能会因为代理而有延迟。为了更好的用户体验, 可以考虑让你的应用程序先显示一个闪屏, 等内容加载好了再通过meta refresh显示真实网页。可以指定`--no-proxy-server`禁用代理并做相关测试。代理延迟也可以通过Chrome浏览器重现, 方式是使用命令行参数 `--chrome-url=....`

#### 脚本
运行Javascript脚本通过 `水星框架` 支持。执行没有返回值的Javascript表达式使用方法 水星框架<a href="ProxyFrame.md#ExecuteJavaScript" style="color:rgb(128,0,0)">.执行脚本()</a> , 具有返回值的Javascript表达式则应当使用方法 水星框架<a href="ProxyFrame.md#ExecuteJavaScript2" style="color:rgb(128,0,0)">.执行脚本2()</a> 。<br/>
运行没有返回值的Javascript表达式:
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-21.png)
<br/><br/>

运行具有返回值的Javascript表达式:
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-22.png)
<br/><br/>

##### 下载(Download)
当浏览器产生下载请求时( 可能是调用了方法 水星浏览器<a href="ProxyBrowser.md#StartDownload" style="color:rgb(128,0,0)">.启动下载</a> 或是 用户点击了资源URL ) 回调事件 <a href="ProxyClient.md#OnBeforeDownload" style="color:blue">浏览器即将下载</a> 将会被触发。执行参数回调 `下载项.保存到()` 方法允许下载资源并提供资源存储位置, 如果不希望浏览器下载此资源则忽略此下载请求。
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-23.png)
<br/><br/>
如果下载请求被允许浏览器将会每隔一秒调用一次事件回调 `浏览器下载进度已更新` 以告知当前资源的下载状态。通过参数回调方法 `下载项.取消下载()` , `下载项.暂停下载()` , `下载项.恢复下载()` 提供资源下载管理。
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-24.png)
<br/><br/>

##### 上下文菜单(Context Menu)
上下文菜单请求产生时由事件 `菜单即将打开` 传递, 如果希望实现自定义菜单则应该实现事件 `显示自定义菜单` 。参数类型 水星菜单信息 提供了菜单上下文信息这包括请求来源的框架信息以及期望创建的菜单类型等等。水星菜单 类型对象提供了一组菜单功能实现, 详细信息见类型说明。
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-25.png)
<br/><br/>
如果希望使用自定义菜单则应实现 `显示自定义菜单` 事件
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-26.png)
<br/><br/>

##### DOM
水星浏览器提供HTML页面DOM结构查询支持。DOM结构的访问操作被包装在 水星网页文档对象 和 水星网页文档元素 类型中, 并由 水星框架<a href="ProxyFrame.md#VisitDOM" style="color:rgb(128,0,0)">.取文档对象()</a> 方法提供DOM结构访问入口。 
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-27.png)
<br/><br/>
水星浏览器除支持标准的DOM结构遍外还提供了一种更加简便的DOM结构访问方法, CSS 选择器。可以使用的选择器如下:<br/>

| 选择器 | 例子 | 例子描述 |
|:---|:---|:---|
| [.class](https://www.w3school.com.cn/cssref/selector_class.asp) | [.intro](https://www.w3school.com.cn/cssref/selector_class.asp) | 选择 class="intro" 的所有元素 |
| [.#id](https://www.w3school.com.cn/cssref/selector_id.asp) | [#id="firstname"](https://www.w3school.com.cn/cssref/selector_id.asp) | 选择 id="firstname" 的所有元素 |
| [*](https://www.w3school.com.cn/cssref/selector_all.asp) | [*](https://www.w3school.com.cn/cssref/selector_all.asp) | 选择所有元素。 |
| [element](https://www.w3school.com.cn/cssref/selector_element.asp) | [p](https://www.w3school.com.cn/cssref/selector_element.asp) | 选择所有 &lt;p&gt; 元素 |
| [element,element](https://www.w3school.com.cn/cssref/selector_element_comma.asp) | [div,p](https://www.w3school.com.cn/cssref/selector_element_comma.asp) | 选择所有 &lt;div&gt; 元素和所有 &lt;p&gt; 元素。 |
| [element element](https://www.w3school.com.cn/cssref/selector_element_element.asp) | [div p](https://www.w3school.com.cn/cssref/selector_element_element.asp) | 选择 &lt;div&gt; 元素内部的所有 &lt;p&gt; 元素。 |
| [element>element](https://www.w3school.com.cn/cssref/selector_element_gt.asp) | [div>p](https://www.w3school.com.cn/cssref/selector_element_gt.asp) | 选择父元素为 &lt;div&gt; 元素的所有 &lt;p&gt; 元素。 |
| [element+element](https://www.w3school.com.cn/cssref/selector_element_plus.asp) | [div+p](https://www.w3school.com.cn/cssref/selector_element_plus.asp) | 选择紧接在 &lt;div&gt; 元素之后的所有 &lt;p&gt; 元素。 |
| [element1~element2](https://www.w3school.com.cn/cssref/selector_gen_sibling.asp) | [p~ul](https://www.w3school.com.cn/cssref/selector_gen_sibling.asp) | 选择前面由 &lt;p&gt; 元素的每个 &lt;ul&gt; 元素。 |
| [[attribute]](https://www.w3school.com.cn/cssref/selector_attribute.asp) | [target](https://www.w3school.com.cn/cssref/selector_attribute.asp) | 选择带有 target 属性的所有元素。|
| [[attribute=value]](https://www.w3school.com.cn/cssref/selector_attribute_value.asp) | [target=_blank](https://www.w3school.com.cn/cssref/selector_attribute_value.asp) | 选择 target="_blank"的所有元素。|
| [[attribute~=value]](https://www.w3school.com.cn/cssref/selector_attribute_value_contain.asp) | [title~=flower](https://www.w3school.com.cn/cssref/selector_attribute_value_contain.asp) | 选择 title 元素保护单词 "flower" 的所有元素。|
| [[attribute~=value]](https://www.w3school.com.cn/cssref/selector_attribute_value_start.asp) | [lang&brvbar;=en](https://www.w3school.com.cn/cssref/selector_attribute_value_start.asp) | 选择 lang 属性值以 "en" 开头的所有元素。|
| [[attribute^=value]](https://www.w3school.com.cn/cssref/selector_attr_begin.asp) | [a[src^="https"]](https://www.w3school.com.cn/cssref/selector_attr_begin.asp) | 选择 src 属性值以 "https" 开头的每个&lt;a&gt;元素。|
| [[attribute$=value]](https://www.w3school.com.cn/cssref/selector_attr_end.asp) | [a[src^=".pdf"]](https://www.w3school.com.cn/cssref/selector_attr_end.asp) | 选择 src 属性值以 ".pdf" 结尾的每个&lt;a&gt;元素。|
| [[attribute*=value]](https://www.w3school.com.cn/cssref/selector_attr_contain.asp) | [a[src*="abc"]](https://www.w3school.com.cn/cssref/selector_attr_contain.asp) | 选择 src 属性值中 "abc" 子串的每个&lt;a&gt;元素。|
| [:first-child](https://www.w3school.com.cn/cssref/selector_first-child.asp) | [p:first-child](https://www.w3school.com.cn/cssref/selector_first-child.asp) | 选择属于父元素的第一个子元素的每个 &lt;p&gt; 元素。|
| [:only-child](https://www.w3school.com.cn/cssref/selector_only-child.asp) | [p:only-child](https://www.w3school.com.cn/cssref/selector_only-child.asp) | 选择属于其父元素的唯一子元素的每个 &lt;p&gt; 元素。|
| [:nth-child(n)](https://www.w3school.com.cn/cssref/selector_nth-child.asp) | [p:nth-child(2)](https://www.w3school.com.cn/cssref/selector_nth-child.asp) | 选择属于其父元素的第二个子元素的每个 &lt;p&gt; 元素。|
| [:nth-last-child(n)](https://www.w3school.com.cn/cssref/selector_nth-last-child.asp) | [p:nth-last-child(2)](https://www.w3school.com.cn/cssref/selector_nth-last-child.asp) | 同上, 从最后一个子元素开始计数。|
| [:last-child](https://www.w3school.com.cn/cssref/selector_last-child.asp) | [p:last-child](https://www.w3school.com.cn/cssref/selector_last-child.asp) | 选择始于其父元素最后一个子元素的每个 &lt;p&gt; 元素。|
| [:first-of-type](https://www.w3school.com.cn/cssref/selector_first-of-type.asp) | [p:first-of-type](https://www.w3school.com.cn/cssref/selector_first-of-type.asp) | 选择属于其父元素的首个 &lt;p&gt; 元素的每个 &lt;p&gt; 元素。|
| [:only-of-type](https://www.w3school.com.cn/cssref/selector_only-of-type.asp) | [p:only-of-type](https://www.w3school.com.cn/cssref/selector_only-of-type.asp) | 选择属于其父元素唯一的 &lt;p&gt; 元素的每个 &lt;p&gt; 元素。|
| [:nth-of-type](https://www.w3school.com.cn/cssref/selector_nth-of-type.asp) | [p:nth-of-type(2)](https://www.w3school.com.cn/cssref/selector_nth-of-type.asp) | 选择属于其父元素的第二个 &lt;p&gt; 元素的每个 &lt;p&gt; 元素。|
| [:nth-last-of-type](https://www.w3school.com.cn/cssref/selector_nth-last-of-type.asp) | [p:nth-last-of-type(2)](https://www.w3school.com.cn/cssref/selector_nth-last-of-type.asp) | 同上, 但是从最后一个子元素开始计数。|
| [:last-of-type](https://www.w3school.com.cn/cssref/selector_last-of-type.asp) | [p:last-of-type](https://www.w3school.com.cn/cssref/selector_last-of-type.asp) | 选择属于其父元素的最后一个 &lt;p&gt; 元素的每个 &lt;p&gt; 元素。|

一些例子:
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-28.png)
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-29.png)
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-30.png)
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-31.png)
<br/><br/>

##### 隐身模式
水星浏览器支持隐身模式访问, 隐身模式为不同浏览器对象间不共享同一个缓存设置和cookies存储, 并且浏览器缓存数据(除临时文件外)仅会保留在内存中, 不会写出到磁盘上, 也不会从磁盘中装载。隐身模式的使用非常的简单, 因为它只是一个开关参数, 在创建浏览器时提供。
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-64.png)
<br/><br/>
隐身模式下所有的浏览器彼此隔离使用单独的缓存设置和cookies存储, 但是有例外情况, 如果一个浏览器是由另一个浏览器创建的则它们彼此共享一个缓存设置和cookis存储, 何为浏览器创建的浏览器呢? 比方说有 浏览器A 和 浏览器B , 浏览器A 是通过 水星铬浏览框<a href="ProxyClient.md#CreateBrowser" style="color:blue">.创建浏览器()</a> 函数创建的并使用了隐身模式, 而浏览器B则是由用户在浏览器A中点击连接后产生的浏览器, 则 浏览器B 共享 浏览器A 的缓存设置与cookies存储, 它们是同源的!
如果希望获得某个浏览器的其它同源浏览器可使用方法 水星铬浏览框<a href="ProxyClient.md#GetSameOriginBrowser" style="color:blue">.取同源浏览器()</a> 获得。
<br/><br/>
![水星铬浏览框.浏览器将要加载资源](https://github.com/kirino17/ecef/raw/master/image/readme-65.png)
<br/><br/>

##### 偏好/首选项(Preference)
水星浏览器和 Google Chrome 一样支持偏好/首选项(Prefence)设置。如果你希望配置一些默认的偏好设置到浏览器中可以使用下面这些方法:
水星浏览器<a href="ProxyBrowser.md#CanSetPreference" style="color:blue">.可否设置首选项()</a> 、 水星浏览器<a href="ProxyBrowser.md#SetPreference" style="color:blue">.置首选项值()</a> 。设置偏好/首选项后当用户首次打开浏览器时, 将应用这些首选项。下面是一些可能受支持的首选项:

| 名称 | 描述 |
|:---|:--|
| disable_screenshots | 禁用屏幕快照加速器和扩展程序API |
| profile.ephemeral_mode | 如果设置为true, 则在临时模式下创建配置文件, 并且不存储其配置文件, 仅会在内存中使用 |
| intl.charset_default | 设置网页中使用的默认字符编码, 缺少MIME字符集规范时 |
| intl.accept_languages | 创建HTTP时用于Accept-Languages HTTP标头的值 |
| intl.static_encodings | 显示用于不同语言环境的编码列表的值,语言环境它是从响应的字符串资源(即存储在资源包中的不可翻译部分) |
| settings.labs.mediaplayer | 开启媒体播放器的逻辑值选项 |
| settings.use_shared_proxies | 逻辑值选项, 用于控制是否从共享网络中获取代理设置 |
| plugins.migrated_to_pepper_flash | Pepper Flash已禁用, 如果希望在浏览器中重新使用, 则启用此首选项 |
| plugins.allow_outdated | 逻辑值选项, 指示是否允许使用过时的插件|
| plugins.always_authorize | 逻辑值选项, 指示是否始终允许插件获取授权 |
| profile.default_zoom_level | 默认的缩放级别 |
| geolocation.enabled | 逻辑值选项, 是否启用地理位置信息 |
| disable_3d_apis | 禁用3D API(WebGL, Pepper 3D) |
| profile.default_content_settings | 适用于默认情况下的内容设置 |
| enable_referrers | 是否启用发送来源(referrer)地址 |
| enable_do_not_track | 是否发送DNT标头 |
| gl_vendor_string | GL_VENDOR字符串 |
| gl_renderer_string | GL_RENDERER字符串 |
| gl_version_string | GL_VERSION字符串 |
| fullscreen.allowed | 确定用户是否可以进入全屏模式 |
| extensions.disabled | 是否启用扩展程序 |
| devtools.port_forwarding_enabled | 逻辑值选项, 指示是否应打启用端口转发 |
| devtools.port_forwarding_default_set | 逻辑值选项, 指示是否已设置默认端口转发配置 |
| devtools.port_forwarding_config | 用于端口转发的port->location字典对 |
| devtools.remote_enabled | 指示是否启用远程开发工具调试 |
| auth.allow_cross_origin_prompt | 逻辑值选项, 指示是否允许跨域子内容请求 |
| device_status.location | 设备位置报告 |
| browser.disk_cache_dir | 指示磁盘缓存存储位置的字符串 |

关于 profile.default_content_settings 默认内容设置选项有以下可选设置项:
* profile.managed_default_content_settings.ads
* profile.managed_default_content_settings.cookies
* profile.managed_default_content_settings.geolocation
* profile.managed_default_content_settings.images
* profile.managed_default_content_settings.insecure_content
* profile.managed_default_content_settings.javascript
* profile.managed_default_content_settings.notifications
* profile.managed_default_content_settings.media_stream
* profile.managed_default_content_settings.plugins
* profile.managed_default_content_settings.popups
* profile.managed_default_content_settings.sensors
* profile.managed_default_content_settings.web_bluetooth_guard
* profile.managed_default_content_settings.web_usb_guard
* profile.managed_default_content_settings.file_system_read_guard
* profile.managed_default_content_settings.file_system_write_guard
* profile.managed_default_content_settings.legacy_cookie_access
* profile.managed_default_content_settings.serial_guard
* profile.managed_default_content_settings.insecure_private_network

用于托管内容存储的模式设置:
* profile.managed_auto_select_certificate_for_urls
* profile.managed_cookies_allowed_for_urls
* profile.managed_cookies_blocked_for_urls
* profile.managed_cookies_sessiononly_for_urls
* profile.managed_images_allowed_for_urls
* profile.managed_images_blocked_for_urls
* profile.managed_insecure_content_allowed_for_urls
* profile.managed_insecure_content_blocked_for_urls
* profile.managed_javascript_allowed_for_urls
* profile.managed_javascript_blocked_for_urls
* profile.managed_notifications_allowed_for_urls
* profile.managed_notifications_blocked_for_urls
* profile.managed_plugins_allowed_for_urls
* profile.managed_plugins_blocked_for_urls
* profile.managed_popups_allowed_for_urls
* profile.managed_popups_blocked_for_urls
* profile.managed_sensors_allowed_for_urls
* profile.managed_sensors_blocked_for_urls
* profile.managed_web_usb_allow_devices_for_urls
* profile.managed_web_usb_ask_for_urls
* profile.managed_web_usb_blocked_for_urls
* profile.managed_file_system_read_ask_for_urls
* profile.managed_file_system_read_blocked_for_urls
* profile.managed_file_system_write_ask_for_urls
* profile.managed_file_system_write_blocked_for_urls
* profile.managed_legacy_cookie_access_allowed_for_domains
* profile.managed_serial_ask_for_urls
* profile.managed_serial_blocked_for_urls
* profile.managed_insecure_private_network_allowed_for_urls


更多首选项设置可参考: [https://src.chromium.org/viewvc/chrome/trunk/src/chrome/common/pref_names.cc?view=markup](https://src.chromium.org/viewvc/chrome/trunk/src/chrome/common/pref_names.cc?view=markup)

-----------------------

更多功能演示和使用介绍参考支持库测试例程。

-----------------------


<script type="text/javascript">document.write(unescape("%3Cspan id='cnzz_stat_icon_1279411688'%3E%3C/span%3E%3Cscript src='https://s9.cnzz.com/z_stat.php%3Fid%3D1279411688%26show%3Dpic' type='text/javascript'%3E%3C/script%3E"));</script>
