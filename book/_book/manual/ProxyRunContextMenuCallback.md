# 水星菜单回调
###### 自定义菜单命令回调

| `Quick Links` |
|:----|
|<a href="#Continue"  style="color:rgb(128,0,0)">执行命令</a> , <a href="#Cancel"  style="color:rgb(128,0,0)">取消</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="Continue">执行命令</span> |
|:----|
| <span style="color:rgb(0,128,0)">执行菜单命令<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 事件标志 <span style="color: rgb(0, 128, 0)">事件标志</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Cancel">取消</span> |
|:----|
| <span style="color:rgb(0,128,0)">取消执行<span> |
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
