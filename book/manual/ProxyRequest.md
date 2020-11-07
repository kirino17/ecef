# 水星请求
###### 用于表示 Web 请求的类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#IsReadOnly"  style="color:rgb(128,0,0)">是否为只读</a> , <a href="#GetURL"  style="color:rgb(128,0,0)">取URL</a> , <a href="#SetURL"  style="color:rgb(128,0,0)">置URL</a> , <a href="#GetMethod"  style="color:rgb(128,0,0)">取方法</a> , <a href="#SetMethod"  style="color:rgb(128,0,0)">置方法</a> , <a href="#SetReferrer"  style="color:rgb(128,0,0)">置来源</a> , <a href="#GetReferrerURL"  style="color:rgb(128,0,0)">取来源</a> , <a href="#GetReferrerPolicy"  style="color:rgb(128,0,0)">取来源策略</a> , <a href="#GetPostDataElementCount"  style="color:rgb(128,0,0)">取提交元素数量</a> , <a href="#GetPostDataElements"  style="color:rgb(128,0,0)">取所有提交元素</a> , <a href="#AddPostDataElement"  style="color:rgb(128,0,0)">添加提交元素</a> , <a href="#RemovePostDataElement"  style="color:rgb(128,0,0)">移除提交元素</a> , <a href="#ClearPostDataElements"  style="color:rgb(128,0,0)">清除提交元素</a> , <a href="#GetHeaderMap"  style="color:rgb(128,0,0)">取标头列表</a> , <a href="#SetHeaderMap"  style="color:rgb(128,0,0)">置标头列表</a> , <a href="#GetHeaderByName"  style="color:rgb(128,0,0)">取标头</a> , <a href="#SetHeaderByName"  style="color:rgb(128,0,0)">置标头</a> , <a href="#GetResourceType"  style="color:rgb(128,0,0)">取资源类型</a> , <a href="#GetIdentifier"  style="color:rgb(128,0,0)">取标识符</a> , <a href="#GetFlags"  style="color:rgb(128,0,0)">取标志值</a> , <a href="#SetFlags"  style="color:rgb(128,0,0)">置标志值</a> , <a href="#GetFirstPartyForCookies"  style="color:rgb(128,0,0)">取首要关联URL</a> , <a href="#SetFirstPartyForCookies"  style="color:rgb(128,0,0)">置首要关联URL</a> , <a href="#GetTransitionType"  style="color:rgb(128,0,0)">取传输类型</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsReadOnly">是否为只读</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果当前对象禁止改写返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetURL">取URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该请求的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetURL">置URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置该请求的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetMethod">取方法</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该请求的请求方法。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetMethod">置方法</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置该请求的请求方法。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 请求方法 <span style="color: rgb(0, 128, 0)">请求方法</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SetReferrer">置来源</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置该请求的来源(Referrer)地址。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 请求来源 <span style="color: rgb(0, 128, 0)">请求来源</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 来源设置策略 <span style="color: rgb(0, 128, 0)">来源设置策略</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetReferrerURL">取来源</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该请求的来源(Referrer)地址。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetReferrerPolicy">取来源策略</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该请求的来源策略(ReferrerPolicy)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetPostDataElementCount">取提交元素数量</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回请求包含的提交元素(Post Data Element)数量。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetPostDataElements">取所有提交元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回请求包含的所有提交元素(Post Data Element)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyPostDataElement.md" style ="color: blue">水星提交元素</a> |


| <span style="color:rgb(128,0,0)" id="AddPostDataElement">添加提交元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">添加一个提交元素(Post Data Element)到请求中。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyPostDataElement.md" style ="color: blue">水星提交元素</a> 提交元素 <span style="color: rgb(0, 128, 0)">提交元素</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="RemovePostDataElement">移除提交元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">从请求中移除一个提交元素(Post Data Element)。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyPostDataElement.md" style ="color: blue">水星提交元素</a> 提交元素 <span style="color: rgb(0, 128, 0)">提交元素</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ClearPostDataElements">清除提交元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">将请求体中的所有提交元素(Post Data Element)清除。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetHeaderMap">取标头列表</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该请求的HTTP标头列表。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型变量</span> |


| <span style="color:rgb(128,0,0)" id="SetHeaderMap">置标头列表</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置该请求的HTTP标头。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标头列表 <span style="color: rgb(0, 128, 0)">标头列表</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetHeaderByName">取标头</span> |
|:----|
| <span style="color:rgb(0,128,0)">取指定HTTP标头值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标头名称 <span style="color: rgb(0, 128, 0)">标头名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetHeaderByName">置标头</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置指定HTTP标头值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标头名称 <span style="color: rgb(0, 128, 0)">标头名称</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否覆盖 <span style="color: rgb(0, 128, 0)">是否覆盖</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetResourceType">取资源类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取请求资源类型, 返回值为枚举常量: #资源类型.*<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetIdentifier">取标识符</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此请求的标识符。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">长整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetFlags">取标志值</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取与 URL请求结合使用的标志参数。 定义值为枚举常量: #请求标志.* 。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SetFlags">置标志值</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置与 URL请求结合使用的标志参数。 定义值为枚举常量: #请求标志.* , 多个标志值可用使用位或相加。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 标志值 <span style="color: rgb(0, 128, 0)">标志值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetFirstPartyForCookies">取首要关联URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取与 URL请求结合使用的cookie的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetFirstPartyForCookies">置首要关联URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置与 URL请求结合使用的cookie的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetTransitionType">取传输类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取请求的传输类型。有一共源值和0个活多个限定符组成。参见枚举常量: #请求传输类型.* 。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


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
