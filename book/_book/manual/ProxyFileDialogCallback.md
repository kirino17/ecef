# 水星文件选择器
###### 文件对话框回调接口, 如使用自定义文件对话框, 则使用该回调接口返回文件选择结果。

| `Quick Links` |
|:----|
|<a href="#Continue"  style="color:rgb(128,0,0)">选择文件</a> , <a href="#Cancel"  style="color:rgb(128,0,0)">取消</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="Continue">选择文件</span> |
|:----|
| <span style="color:rgb(0,128,0)">提交选择的文件<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 选择器索引 <span style="color: rgb(0, 128, 0)">选择器索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 选择的文件列表 <span style="color: rgb(0, 128, 0)">选择的文件列表</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Cancel">取消</span> |
|:----|
| <span style="color:rgb(0,128,0)">取消文件选择<span> |
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
