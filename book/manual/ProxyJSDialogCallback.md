# 水星脚本对话框
###### 脚本对话框回调接口, 用于Javascript对话框请求的执行返回。

| `Quick Links` |
|:----|
|<a href="#Continue"  style="color:rgb(128,0,0)">回复</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="Continue">回复</span> |
|:----|
| <span style="color:rgb(0,128,0)">向Javascript对话框回复对话框选择命令。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> OK <span style="color: rgb(0, 128, 0)">OK</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 输入文本 <span style="color: rgb(0, 128, 0)">输入文本</span> | 
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
