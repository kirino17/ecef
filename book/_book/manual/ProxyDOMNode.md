# 水星网页文档元素
###### 用于表示 DOM 节点的类型。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#GetType"  style="color:rgb(128,0,0)">取类型</a> , <a href="#IsText"  style="color:rgb(128,0,0)">是否为文本</a> , <a href="#IsElement"  style="color:rgb(128,0,0)">是否为元素</a> , <a href="#IsEditable"  style="color:rgb(128,0,0)">是否可编辑</a> , <a href="#IsFormControlElement"  style="color:rgb(128,0,0)">是否为表单元素</a> , <a href="#GetFormControlElementType"  style="color:rgb(128,0,0)">取表单元素类型</a> , <a href="#GetName"  style="color:rgb(128,0,0)">取名称</a> , <a href="#GetValue"  style="color:rgb(128,0,0)">取值</a> , <a href="#SetValue"  style="color:rgb(128,0,0)">置值</a> , <a href="#GetAsMarkup"  style="color:rgb(128,0,0)">取标记文本</a> , <a href="#GetDocument"  style="color:rgb(128,0,0)">取文档对象</a> , <a href="#GetParent"  style="color:rgb(128,0,0)">取父元素</a> , <a href="#GetPreviousSibling"  style="color:rgb(128,0,0)">取上一兄弟元素</a> , <a href="#GetNextSibling"  style="color:rgb(128,0,0)">取下一兄弟元素</a> , <a href="#HasChildren"  style="color:rgb(128,0,0)">是否有子元素</a> , <a href="#GetFirstChild"  style="color:rgb(128,0,0)">取首个子元素</a> , <a href="#GetLastChild"  style="color:rgb(128,0,0)">取最后一个子元素</a> , <a href="#GetElementTagName"  style="color:rgb(128,0,0)">取标签名称</a> , <a href="#HasElementAttributes"  style="color:rgb(128,0,0)">是否有属性</a> , <a href="#HasElementAttribute"  style="color:rgb(128,0,0)">是否存在属性</a> , <a href="#GetElementAttribute"  style="color:rgb(128,0,0)">取属性</a> , <a href="#GetElementAttributes"  style="color:rgb(128,0,0)">取所有属性</a> , <a href="#SetElementAttribute"  style="color:rgb(128,0,0)">置属性</a> , <a href="#GetElementInnerText"  style="color:rgb(128,0,0)">取内部文本</a> , <a href="#GetElementBounds"  style="color:rgb(128,0,0)">取包围框</a> , <a href="#SendEvent"  style="color:rgb(128,0,0)">执行方法</a> , <a href="#QuerySelector"  style="color:rgb(128,0,0)">查询元素</a> , <a href="#QuerySelectorAll"  style="color:rgb(128,0,0)">查询所有元素</a> , <a href="#GetChildCount"  style="color:rgb(128,0,0)">取子元素数量</a> , <a href="#GetSelector"  style="color:rgb(128,0,0)">取选择器</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetType">取类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回文档元素的类型。定义值为枚举常量: #网页文档元素.* 。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="IsText">是否为文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此文档元素为文本返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsElement">是否为元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此元素为文档元素返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsEditable">是否可编辑</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此元素允许更改返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsFormControlElement">是否为表单元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此元素为表单控件元素返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetFormControlElementType">取表单元素类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此表单元素的类型。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetName">取名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此文档元素的名称(name)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetValue">取值</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此文档元素的值(value)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetValue">置值</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置此文档元素的值(value).<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 值 <span style="color: rgb(0, 128, 0)">值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetAsMarkup">取标记文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取此元素的标记文本(HTML)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetDocument">取文档对象</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回与此元素关联的文档对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMDocument.md" style ="color: blue">水星网页文档对象</a> |


| <span style="color:rgb(128,0,0)" id="GetParent">取父元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素的父元素对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="GetPreviousSibling">取上一兄弟元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素的上一个兄弟元素(previous sibling)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="GetNextSibling">取下一兄弟元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素的下一个兄弟元素(next sibling)。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="HasChildren">是否有子元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此元素具有子元素对象返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetFirstChild">取首个子元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素的第一个子元素对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="GetLastChild">取最后一个子元素</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素的最后一个子元素对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMNode.md" style ="color: blue">水星网页文档元素</a> |


| <span style="color:rgb(128,0,0)" id="GetElementTagName">取标签名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素的标签名称(tag)。此方法仅对元素类型对象有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="HasElementAttributes">是否有属性</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此元素具有属性(attributes)返回真。此方法仅对元素类型对象有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="HasElementAttribute">是否存在属性</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此元素具有符合指定名称的属性返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 属性名称 <span style="color: rgb(0, 128, 0)">属性名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetElementAttribute">取属性</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素中符合指定名称的属性值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 属性名称 <span style="color: rgb(0, 128, 0)">属性名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetElementAttributes">取所有属性</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素中的所有属性。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> |


| <span style="color:rgb(128,0,0)" id="SetElementAttribute">置属性</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置指定属性到元素中。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 属性名称 <span style="color: rgb(0, 128, 0)">属性名称</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 属性值 <span style="color: rgb(0, 128, 0)">属性值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetElementInnerText">取内部文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素的内部(inner)文本。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetElementBounds">取包围框</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此元素的包围框(bounding box)边界。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SendEvent">执行方法</span> |
|:----|
| <span style="color:rgb(0,128,0)">执行元素方法。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 方法名 <span style="color: rgb(0, 128, 0)">方法名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 参数 <span style="color: rgb(0, 128, 0)">参数</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


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


| <span style="color:rgb(128,0,0)" id="GetChildCount">取子元素数量</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此文档元素拥有的子元素数量。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetSelector">取选择器</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此文档元素的CSS选择器字符串。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


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
