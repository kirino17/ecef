# 水星初始化设置
###### 提供浏览器进程的初始化设置。这些设置用于配置Chromium全局运行参数, 设置为0或空时保持为建议的默认值, 这些设置也使用命令行开关(command-switch)进行配置。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#SetCachePath"  style="color:rgb(128,0,0)">全局缓存目录</a> , <a href="#SetUserDataPath"  style="color:rgb(128,0,0)">用户数据目录</a> , <a href="#SetPersistSessionCookies"  style="color:rgb(128,0,0)">保持会话COOKIES</a> , <a href="#SetPersistUserPreferences"  style="color:rgb(128,0,0)">保持用户首选项</a> , <a href="#SetUserAgent"  style="color:rgb(128,0,0)">用户代理标识</a> , <a href="#SetProductVersion"  style="color:rgb(128,0,0)">产品标识</a> , <a href="#SetLocale"  style="color:rgb(128,0,0)">语言环境</a> , <a href="#SetIgnoreCertificateErrors"  style="color:rgb(128,0,0)">忽略SSL证书错误</a> , <a href="#SetAcceptLanguageList"  style="color:rgb(128,0,0)">接收语言字符串</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetCachePath">全局缓存目录</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置浏览器全局缓存目录, 此值作为所有浏览器创建时使用的缺省值, 如非特别指定, 所有的浏览器都将会共享此设置。保持为空时则默认不会将数据存储到磁盘上。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 缓存路径 <span style="color: rgb(0, 128, 0)">缓存路径</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetUserDataPath">用户数据目录</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置用户数据存储(例如拼写检查字段文件)位置。此值作为所有浏览器创建时使用的缺省值, 如非特别指定, 所有的浏览器都将会共享此设置。保持为空时则默认不会将数据存储到磁盘上。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 路径 <span style="color: rgb(0, 128, 0)">路径</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetPersistSessionCookies">保持会话COOKIES</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此值为1, 在全局COOKIE管理器中保留会话COOKIE(它们将没有有效期)。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetPersistUserPreferences">保持用户首选项</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此值为1, 用户首选项数据将使用JSON文件保留到缓存目录中。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetUserAgent">用户代理标识</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此值作为: User-Agent HTTP 标头的返回值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标识字符串 <span style="color: rgb(0, 128, 0)">标识字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetProductVersion">产品标识</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此值作为默认 User-Agent 字符串的产品部分插入的值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 产品标识 <span style="color: rgb(0, 128, 0)">产品标识</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetLocale">语言环境</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置浏览器语言环境字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 语言标识 <span style="color: rgb(0, 128, 0)">语言标识</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetIgnoreCertificateErrors">忽略SSL证书错误</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此值为1, 可忽略于无效SSL证书有关的错误。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetAcceptLanguageList">接收语言字符串</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置全局的HTTP接收语言字符串,以逗号分隔的语言代码字符串数组,不可以使用空格, 这些字符串值将在\"Accept-Language\" HTTP标头中使用。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 语言字符串 <span style="color: rgb(0, 128, 0)">语言字符串</span> | 
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
