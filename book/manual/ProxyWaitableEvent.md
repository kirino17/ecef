# 水星等待事件
###### 等待事件通常用于线程同步, 它允许一个线程等待另一个线程完成某些事件后在继续工作。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#Reset"  style="color:rgb(128,0,0)">重置</a> , <a href="#Signal"  style="color:rgb(128,0,0)">置信号</a> , <a href="#IsSignaled"  style="color:rgb(128,0,0)">是否有信号</a> , <a href="#Wait"  style="color:rgb(128,0,0)">等待唤醒</a> , <a href="#TimedWait"  style="color:rgb(128,0,0)">等待唤醒2</a> , <a href="#SetUserData"  style="color:rgb(128,0,0)">置附加数据</a> , <a href="#GetUserData"  style="color:rgb(128,0,0)">取附加数据</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Reset">重置</span> |
|:----|
| <span style="color:rgb(0,128,0)">将事件置为未授信状态。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Signal">置信号</span> |
|:----|
| <span style="color:rgb(0,128,0)">将事件置为授信状态。任何等待此事件的线程都将被唤醒。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="IsSignaled">是否有信号</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果事件处于授信状态返回真, 否则返回假。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Wait">等待唤醒</span> |
|:----|
| <span style="color:rgb(0,128,0)">挂起一个等待事件直到被置为有信号状态。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="TimedWait">等待唤醒2</span> |
|:----|
| <span style="color:rgb(0,128,0)">挂起一个等待事件直到被置为有信号状态或者超过时间。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">长整数型</span> 超时时间 <span style="color: rgb(0, 128, 0)">超时时间</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetUserData">置附加数据</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置附加到此事件上的用户数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyValue.md" style ="color: blue">水星通用型</a> 附加数据 <span style="color: rgb(0, 128, 0)">附加数据</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetUserData">取附加数据</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取附加到此事件上的用户数据。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyValue.md" style ="color: blue">水星通用型</a> |


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
