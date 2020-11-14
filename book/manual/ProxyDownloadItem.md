# 水星下载项
###### 用于表示下载项目的类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#IsInProgress"  style="color:rgb(128,0,0)">是否正在下载</a> , <a href="#IsComplete"  style="color:rgb(128,0,0)">是否已完成</a> , <a href="#IsCanceled"  style="color:rgb(128,0,0)">是否已取消</a> , <a href="#GetCurrentSpeed"  style="color:rgb(128,0,0)">取下载速度</a> , <a href="#GetPercentComplete"  style="color:rgb(128,0,0)">取下载百分比</a> , <a href="#GetTotalBytes"  style="color:rgb(128,0,0)">取字节总数</a> , <a href="#GetReceivedBytes"  style="color:rgb(128,0,0)">取已接收字节数</a> , <a href="#GetStartTime"  style="color:rgb(128,0,0)">取开始时间</a> , <a href="#GetEndTime"  style="color:rgb(128,0,0)">取结束时间</a> , <a href="#GetFullPath"  style="color:rgb(128,0,0)">取文件路径</a> , <a href="#GetId"  style="color:rgb(128,0,0)">取ID</a> , <a href="#GetURL"  style="color:rgb(128,0,0)">取URL</a> , <a href="#GetOriginalUrl"  style="color:rgb(128,0,0)">取原始URL</a> , <a href="#GetSuggestedFileName"  style="color:rgb(128,0,0)">取建议名称</a> , <a href="#GetContentDisposition"  style="color:rgb(128,0,0)">取内容处置</a> , <a href="#GetMimeType"  style="color:rgb(128,0,0)">取MIME类型</a> , <a href="#SaveTo"  style="color:rgb(128,0,0)">保存到</a> , <a href="#CancelDownload"  style="color:rgb(128,0,0)">取消下载</a> , <a href="#PauseDownload"  style="color:rgb(128,0,0)">暂停下载</a> , <a href="#ResumeDownload"  style="color:rgb(128,0,0)">恢复下载</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsInProgress">是否正在下载</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果下载正在进行返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsComplete">是否已完成</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果下载已完成返回真<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsCanceled">是否已取消</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果下载被取消或中断返回真<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetCurrentSpeed">取下载速度</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回以字节(Bytes)/每秒为单位的简单速度估算值。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">长整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetPercentComplete">取下载百分比</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回已下载完成的大致百分比, 如果接收的总大小未知则会返回-1。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetTotalBytes">取字节总数</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回字节总数<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">长整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetReceivedBytes">取已接收字节数</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回接收到的字节数<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">长整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetStartTime">取开始时间</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回下载开始的时间。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">双精度小数型</span> |


| <span style="color:rgb(128,0,0)" id="GetEndTime">取结束时间</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回下载结束的时间。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">双精度小数型</span> |


| <span style="color:rgb(128,0,0)" id="GetFullPath">取文件路径</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回该下载文件的完整路径。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetId">取ID</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此下载文件的唯一标识符。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetURL">取URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此下载文件的URL<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetOriginalUrl">取原始URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此下载文件的原始URL。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetSuggestedFileName">取建议名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此下载文件的建议名称。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetContentDisposition">取内容处置</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此文件的内容处置<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetMimeType">取MIME类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此文件的MIME类型。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SaveTo">保存到</span> |
|:----|
| <span style="color:rgb(0,128,0)">提供文件的保存路径或者弹出对话框供用户选择。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 保存路径 <span style="color: rgb(0, 128, 0)">保存路径</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 显示对话框 <span style="color: rgb(0, 128, 0)">显示对话框</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="CancelDownload">取消下载</span> |
|:----|
| <span style="color:rgb(0,128,0)">取消此文件的下载。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="PauseDownload">暂停下载</span> |
|:----|
| <span style="color:rgb(0,128,0)">暂停此文件的下载。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ResumeDownload">恢复下载</span> |
|:----|
| <span style="color:rgb(0,128,0)">恢复此文件的下载<span> |
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
