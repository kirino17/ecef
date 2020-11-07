# 水星窗口设置
###### 为浏览器提供窗口设置信息,它告诉浏览器该创建怎样的窗口。比如让浏览器呈现在某个窗口中作为它的子控件抑或是让它在独立的顶层窗口中( 调用 **.设置为弹出窗口** 函数 )运行。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#SetAsChild"  style="color:rgb(128,0,0)">置为子窗口</a> , <a href="#SetAsPopup"  style="color:rgb(128,0,0)">置为弹出窗口</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetAsChild">置为子窗口</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置浏览器在某窗口中显示。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 父窗口 <span style="color: rgb(0, 128, 0)">父窗口</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 横向位置 <span style="color: rgb(0, 128, 0)">横向位置</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 纵向位置 <span style="color: rgb(0, 128, 0)">纵向位置</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 宽度 <span style="color: rgb(0, 128, 0)">宽度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 高度 <span style="color: rgb(0, 128, 0)">高度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetAsPopup">置为弹出窗口</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置浏览器在独立的窗口中显示。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 父窗口 <span style="color: rgb(0, 128, 0)">父窗口</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 窗口标题 <span style="color: rgb(0, 128, 0)">窗口标题</span> | 
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
