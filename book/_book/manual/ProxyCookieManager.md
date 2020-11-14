# 水星会话管理器
###### 用于管理 cookie 的类。除非另有说明, 否则可以在任何线程上调用此类的方法。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#VisitAllCookies"  style="color:rgb(128,0,0)">取所有会话凭证</a> , <a href="#VisitUrlCookies"  style="color:rgb(128,0,0)">取指定会话凭证</a> , <a href="#SetCookie"  style="color:rgb(128,0,0)">置会话凭证</a> , <a href="#DeleteCookies"  style="color:rgb(128,0,0)">删除会话凭证</a> , <a href="#FlushStore"  style="color:rgb(128,0,0)">刷新到存储</a> , <a href="#ExtractToString"  style="color:rgb(128,0,0)">保存到文本</a> , <a href="#ReduceFromString"  style="color:rgb(128,0,0)">从文本还原</a> , <a href="#ExtractToHTTP"  style="color:rgb(128,0,0)">保存为HTTP格式</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="VisitAllCookies">取所有会话凭证</span> |
|:----|
| <span style="color:rgb(0,128,0)">访问所有cookies。 返回的cookie由事件\"OnCookieVisitor\"传递, cookie的传递顺序根据最长路径来选择, 在然后是最早的创建日期。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCookie.md" style ="color: blue">水星会话凭证</a> |


| <span style="color:rgb(128,0,0)" id="VisitUrlCookies">取指定会话凭证</span> |
|:----|
| <span style="color:rgb(0,128,0)">访问指定url下的所有cookies。返回的cookie由事件\"OnCookieVisitor\"传递, cookie的传递顺序根据最长路径来选择, 在然后是最早的创建日期。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> includeHttpOnly <span style="color: rgb(0, 128, 0)">includeHttpOnly</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCookie.md" style ="color: blue">水星会话凭证</a> |


| <span style="color:rgb(128,0,0)" id="SetCookie">置会话凭证</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置一个具有有效URL和cookie属性的cookie。设置的cookie属性应该使用标准的格式输入, 在此函数中将会检查cookie中是否存在非法字符(例如: \";\"是不允许出现在cookie.value中的),如果出现了这样的字符此函数将不会设置此cookie属性并返回失败。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> domain <span style="color: rgb(0, 128, 0)">domain</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> name <span style="color: rgb(0, 128, 0)">name</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> value <span style="color: rgb(0, 128, 0)">value</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="DeleteCookies">删除会话凭证</span> |
|:----|
| <span style="color:rgb(0,128,0)">删除与指定参数匹配的cookie。如果指定了 |url| 和 |cookie_name| 那么将仅删除与其相符的cookie。如果仅指定|url|所有与其相符的cookie都将删除(但不包括域cookie)。如果|url|为空则将删除所有主机和域的cookies。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 凭证名称 <span style="color: rgb(0, 128, 0)">凭证名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="FlushStore">刷新到存储</span> |
|:----|
| <span style="color:rgb(0,128,0)">将在内存中的存储数据(如果有的话)写入到磁盘上。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="ExtractToString">保存到文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">将当前cookie管理器的所有数据保存到文本字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="ReduceFromString">从文本还原</span> |
|:----|
| <span style="color:rgb(0,128,0)">从文本字符串中还原所有cookie数据到管理器。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> cookie数据 <span style="color: rgb(0, 128, 0)">cookie数据</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ExtractToHTTP">保存为HTTP格式</span> |
|:----|
| <span style="color:rgb(0,128,0)">将当前cookie管理器中的指定数据以HTTP会话请求所用的格式保存到文本字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


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
