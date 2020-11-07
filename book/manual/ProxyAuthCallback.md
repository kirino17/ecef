# 水星认证
###### 提供用户身份验证数据的回调接口。

| `Quick Links` |
|:----|
|<a href="#Continue"  style="color:rgb(128,0,0)">提交</a> , <a href="#Cancel"  style="color:rgb(128,0,0)">取消</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="Continue">提交</span> |
|:----|
| <span style="color:rgb(0,128,0)">提交用户身份认证信息<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 用户名 <span style="color: rgb(0, 128, 0)">用户名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 密码 <span style="color: rgb(0, 128, 0)">密码</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Cancel">取消</span> |
|:----|
| <span style="color:rgb(0,128,0)">取消<span> |
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
