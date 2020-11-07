# 水星会话凭证
###### cookie 信息

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#SetName"  style="color:rgb(128,0,0)">置名称</a> , <a href="#GetName"  style="color:rgb(128,0,0)">取名称</a> , <a href="#SetValue"  style="color:rgb(128,0,0)">置值</a> , <a href="#GetValue"  style="color:rgb(128,0,0)">取值</a> , <a href="#SetDomain"  style="color:rgb(128,0,0)">置域</a> , <a href="#GetDomain"  style="color:rgb(128,0,0)">取域</a> , <a href="#SetPath"  style="color:rgb(128,0,0)">置路径</a> , <a href="#GetPath"  style="color:rgb(128,0,0)">取路径</a> , <a href="#SetSecure"  style="color:rgb(128,0,0)">置安全性</a> , <a href="#GetSecure"  style="color:rgb(128,0,0)">取安全性</a> , <a href="#SetHttponly"  style="color:rgb(128,0,0)">置仅限HTTP属性</a> , <a href="#GetHttponly"  style="color:rgb(128,0,0)">取仅限HTTP属性</a> , <a href="#SetCreation"  style="color:rgb(128,0,0)">置创建时间</a> , <a href="#GetCreation"  style="color:rgb(128,0,0)">取创建时间</a> , <a href="#SetLastAccess"  style="color:rgb(128,0,0)">置最后访问时间</a> , <a href="#GetLastAccess"  style="color:rgb(128,0,0)">取最后访问时间</a> , <a href="#SetHasExpires"  style="color:rgb(128,0,0)">置使用有效期</a> , <a href="#GetHasExpires"  style="color:rgb(128,0,0)">取使用有效期</a> , <a href="#SetExpires"  style="color:rgb(128,0,0)">置过期时间</a> , <a href="#GetExpires"  style="color:rgb(128,0,0)">取过期时间</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetName">置名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置 cookie 名称。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> name <span style="color: rgb(0, 128, 0)">name</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetName">取名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">取 cookie 名称。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetValue">置值</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置 cookie 值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetValue">取值</span> |
|:----|
| <span style="color:rgb(0,128,0)">取 cookie 值。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetDomain">置域</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果域值为空, 将创建主机cookie 而不是域cookie。域cookie应该以\".\"开头进行设置。并且对子域可见, 而对主机cookie则不可见。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 域值 <span style="color: rgb(0, 128, 0)">域值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetDomain">取域</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetPath">置路径</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果路径值不为空, 则只有此路径中或路径以下的URL会取cookie值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 路径 <span style="color: rgb(0, 128, 0)">路径</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetPath">取路径</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetSecure">置安全性</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此值为1, 将仅针对HTTPS请求才发送此cookie。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 安全性 <span style="color: rgb(0, 128, 0)">安全性</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetSecure">取安全性</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SetHttponly">置仅限HTTP属性</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此值为1, cookie将仅在HTTP会话中使用。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> httponly <span style="color: rgb(0, 128, 0)">httponly</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetHttponly">取仅限HTTP属性</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SetCreation">置创建时间</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">双精度小数型</span> 创建时间 <span style="color: rgb(0, 128, 0)">创建时间</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetCreation">取创建时间</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">双精度小数型</span> |


| <span style="color:rgb(128,0,0)" id="SetLastAccess">置最后访问时间</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">双精度小数型</span> 最后访问时间 <span style="color: rgb(0, 128, 0)">最后访问时间</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetLastAccess">取最后访问时间</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">双精度小数型</span> |


| <span style="color:rgb(128,0,0)" id="SetHasExpires">置使用有效期</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此值为1, cookie 将具有有效期。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetHasExpires">取使用有效期</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SetExpires">置过期时间</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置 cookie 过期时间。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">双精度小数型</span> 过期时间 <span style="color: rgb(0, 128, 0)">过期时间</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetExpires">取过期时间</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">双精度小数型</span> |


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
