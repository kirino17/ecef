# 水星提交元素
###### 用于表示 Web 请求提交数据(PostData)中的单个元素的的类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#IsReadOnly"  style="color:rgb(128,0,0)">是否只读</a> , <a href="#SetToEmpty"  style="color:rgb(128,0,0)">置空元素</a> , <a href="#SetToFile"  style="color:rgb(128,0,0)">置文件</a> , <a href="#SetToBytes"  style="color:rgb(128,0,0)">置字节集</a> , <a href="#GetType"  style="color:rgb(128,0,0)">取元素类型</a> , <a href="#GetFile"  style="color:rgb(128,0,0)">取文件名</a> , <a href="#GetBytesCount"  style="color:rgb(128,0,0)">取字节长度</a> , <a href="#GetBytes"  style="color:rgb(128,0,0)">取字节集</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsReadOnly">是否只读</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果对象是只读的返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetToEmpty">置空元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">从提交数据元素中删除所有数据<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetToFile">置文件</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此提交数据元素代表为一个文件。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 文件名 <span style="color: rgb(0, 128, 0)">文件名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetToBytes">置字节集</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此提交数据元素代表为一串字节流。传入的字节流会被复制。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 字节长度 <span style="color: rgb(0, 128, 0)">字节长度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 字节数据 <span style="color: rgb(0, 128, 0)">字节数据</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetType">取元素类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此提交数据元素的类型。定义值为枚举常量： #提交元素类型.* 。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetFile">取文件名</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此提交元素代表的文件名。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetBytesCount">取字节长度</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此提交元素代表的字节流长度。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetBytes">取字节集</span> |
|:----|
| <span style="color:rgb(0,128,0)">读取|读取长度|个字节流数据写入到字节流缓冲区, 返回值为实际写入的字节数。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">字节集型</span> |


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
