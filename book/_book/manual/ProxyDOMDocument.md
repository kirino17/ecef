# 水星网页文档对象
###### 表示DOM文档的类型。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#GetType"  style="color:rgb(128,0,0)">取文档类型</a> , <a href="#GetDocument"  style="color:rgb(128,0,0)">取根元素</a> , <a href="#GetBody"  style="color:rgb(128,0,0)">取BODY元素</a> , <a href="#GetHead"  style="color:rgb(128,0,0)">取HEAD元素</a> , <a href="#GetTitle"  style="color:rgb(128,0,0)">取文档标题</a> , <a href="#GetElementById"  style="color:rgb(128,0,0)">从标识符取元素</a> , <a href="#GetFocusedNode"  style="color:rgb(128,0,0)">取焦点元素</a> , <a href="#HasSelection"  style="color:rgb(128,0,0)">是否有选区</a> , <a href="#GetSelectionStartOffset"  style="color:rgb(128,0,0)">取选区起始位置</a> , <a href="#GetSelectionEndOffset"  style="color:rgb(128,0,0)">取选区结束位置</a> , <a href="#GetSelectionAsMarkup"  style="color:rgb(128,0,0)">取选区标记文本</a> , <a href="#GetSelectionAsText"  style="color:rgb(128,0,0)">取选区文本</a> , <a href="#GetBaseURL"  style="color:rgb(128,0,0)">取根URL</a> , <a href="#GetCompleteURL"  style="color:rgb(128,0,0)">取完整URL</a> , <a href="#QuerySelector"  style="color:rgb(128,0,0)">查询元素</a> , <a href="#QuerySelectorAll"  style="color:rgb(128,0,0)">查询所有元素</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetType">取文档类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此网页文档的类型。定义值为枚举常量: #网页文档类型.* 。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetDocument">取根元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回最上层的文档元素(root document node)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="GetBody">取BODY元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回 Body 节点文档元素。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="GetHead">取HEAD元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回 Head 节点文档元素。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="GetTitle">取文档标题</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回文档标题。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetElementById">从标识符取元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回与符合指定标识符(ID)的文档元素。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标识符 <span style="color: rgb(0, 128, 0)">标识符</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="GetFocusedNode">取焦点元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回当前焦点所在文档元素。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="HasSelection">是否有选区</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果文档中存在选择区域返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetSelectionStartOffset">取选区起始位置</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回文档选择区的起始位置。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetSelectionEndOffset">取选区结束位置</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回文档选择区结束位置。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetSelectionAsMarkup">取选区标记文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回文档选择区域中的标记文本(HTML)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetSelectionAsText">取选区文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回文档选择区域中的文本内容。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetBaseURL">取根URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回文档的起始URL。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetCompleteURL">取完整URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">根据文档的起始URL和指定的URL返回完整的URL地址。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 分段URL <span style="color: rgb(0, 128, 0)">分段URL</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="QuerySelector">查询元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">查找并返回符合指定选择器索引的文档元素。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 选择器 <span style="color: rgb(0, 128, 0)">选择器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="QuerySelectorAll">查询所有元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">查找并返回所有符合指定选择器索引的文档元素。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 选择器 <span style="color: rgb(0, 128, 0)">选择器</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


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
