# 水星网页驱动器
###### 用作一次浏览器自动化测试过程表达。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#CreateBrowser"  style="color:rgb(128,0,0)">创建浏览器</a> , <a href="#CloseBrowser"  style="color:rgb(128,0,0)">关闭浏览器</a> , <a href="#GetBrowserCount"  style="color:rgb(128,0,0)">取浏览器数量</a> , <a href="#GetBrowser"  style="color:rgb(128,0,0)">取浏览器索引</a> , <a href="#GetAllBrowser"  style="color:rgb(128,0,0)">取所有浏览器</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="CreateBrowser">创建浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个新的浏览器窗口, 创建成功返回新的窗口对象, 失败返回空, 可使用 IsValid 函数检查返回有效性。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowserSettings.md" style ="color: blue">水星浏览器设置</a> 浏览器设置 <span style="color: rgb(0, 128, 0)">浏览器设置</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> |


| <span style="color:rgb(128,0,0)" id="CloseBrowser">关闭浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">向指定的浏览器发送关闭请求。发送此请求后JavaScript的\"onbeforeunload\"事件将被触发。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> 浏览器 <span style="color: rgb(0, 128, 0)">浏览器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetBrowserCount">取浏览器数量</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回当前采集上下文中的浏览器窗口数量。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetBrowser">取浏览器索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用索引在当前采集器上下文中查询浏览器, 索引从0开始, 成功返回浏览器对象, 失败返回空对象。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 索引 <span style="color: rgb(0, 128, 0)">索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> |


| <span style="color:rgb(128,0,0)" id="GetAllBrowser">取所有浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取当前采集器上下文中所有的浏览器。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> |


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
