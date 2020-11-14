# 水星资源过滤器
###### 用于提供资源可选化配置的类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#GetURL"  style="color:rgb(128,0,0)">取URL</a> , <a href="#GetMimeType"  style="color:rgb(128,0,0)">取MIME类型</a> , <a href="#GetTotalBytes"  style="color:rgb(128,0,0)">取总字节长度</a> , <a href="#GetResource"  style="color:rgb(128,0,0)">取资源</a> , <a href="#SetResource"  style="color:rgb(128,0,0)">置资源</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetURL">取URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该资源的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetMimeType">取MIME类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该资源的Mime类型.<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetTotalBytes">取总字节长度</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该资源所占用的总字节数。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetResource">取资源</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该资源<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">字节集型</span> |


| <span style="color:rgb(128,0,0)" id="SetResource">置资源</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置一个新的资源对资源进行替换<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">字节集型</span> 资源数据 <span style="color: rgb(0, 128, 0)">资源数据</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 资源长度 <span style="color: rgb(0, 128, 0)">资源长度</span> | 
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
