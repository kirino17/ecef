# 水星脚本查询回调
###### 与单个挂起的Javascript异步查询关联的回调。执行 \"成功\" 或 \"失败\" 方法将异步响应发送到关联的Javascript处理程序。在不首先执行其中一共回调方法的情况下, 销毁与未取消查询相关联的回调对象时会报告运行时错误。

| `Quick Links` |
|:----|
|<a href="#Success"  style="color:rgb(128,0,0)">成功</a> , <a href="#Failure"  style="color:rgb(128,0,0)">失败</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="Success">成功</span> |
|:----|
| <span style="color:rgb(0,128,0)">通知关联的Javascript onSuccess回调, 以成功完成查询, 参数 | 响应 | 提供了查询结果。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 响应 <span style="color: rgb(0, 128, 0)">响应</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Failure">失败</span> |
|:----|
| <span style="color:rgb(0,128,0)">通知关联的Javascript onFailure 回调, 查询已失败, 参数 |错误代码| , | 错误信息 | 提供了查询失败的原因。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 错误代码 <span style="color: rgb(0, 128, 0)">错误代码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 错误信息 <span style="color: rgb(0, 128, 0)">错误信息</span> | 
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
