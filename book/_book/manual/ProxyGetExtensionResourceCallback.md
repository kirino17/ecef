# 水星扩展程序资源获取回调
###### 用于扩展程序获取资源事件的异步延续回调接口, 使用此接口回复扩展程序资源获取请求。

| `Quick Links` |
|:----|
|<a href="#ContinueWithData"  style="color:rgb(128,0,0)">允许获取提供字节集</a> , <a href="#ContinueWithFile"  style="color:rgb(128,0,0)">允许获取提供文件</a> , <a href="#Cancel"  style="color:rgb(128,0,0)">取消获取</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="ContinueWithData">允许获取提供字节集</span> |
|:----|
| <span style="color:rgb(0,128,0)">允许扩展程序获取此资源, 并为扩展程序提供此资源的字节集数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">字节集型</span> 资源内容 <span style="color: rgb(0, 128, 0)">资源内容</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 资源长度 <span style="color: rgb(0, 128, 0)">资源长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ContinueWithFile">允许获取提供文件</span> |
|:----|
| <span style="color:rgb(0,128,0)">允许扩展程序获取此资源, 并为扩展程序提供此资源的文件数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 文件名 <span style="color: rgb(0, 128, 0)">文件名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Cancel">取消获取</span> |
|:----|
| <span style="color:rgb(0,128,0)">取消扩展程序的资源获取请求。<span> |
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
