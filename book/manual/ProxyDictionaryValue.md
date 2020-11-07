# 水星字典型
###### 表示字典值(DictionaryValue)的类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#IsOwned"  style="color:rgb(128,0,0)">是否拥有</a> , <a href="#IsReadOnly"  style="color:rgb(128,0,0)">是否只读</a> , <a href="#IsSame"  style="color:rgb(128,0,0)">是否相同</a> , <a href="#IsEqual"  style="color:rgb(128,0,0)">是否相等</a> , <a href="#Copy"  style="color:rgb(128,0,0)">创建副本</a> , <a href="#GetSize"  style="color:rgb(128,0,0)">取大小</a> , <a href="#Clear"  style="color:rgb(128,0,0)">清空</a> , <a href="#HasKey"  style="color:rgb(128,0,0)">可有键</a> , <a href="#GetKeys"  style="color:rgb(128,0,0)">取所有键</a> , <a href="#Remove"  style="color:rgb(128,0,0)">移除键</a> , <a href="#GetType"  style="color:rgb(128,0,0)">取类型</a> , <a href="#GetValue"  style="color:rgb(128,0,0)">取通用型</a> , <a href="#GetBool"  style="color:rgb(128,0,0)">取逻辑型</a> , <a href="#GetInt"  style="color:rgb(128,0,0)">取整数型</a> , <a href="#GetDouble"  style="color:rgb(128,0,0)">取双精度小数型</a> , <a href="#GetString"  style="color:rgb(128,0,0)">取文本型</a> , <a href="#GetBinary"  style="color:rgb(128,0,0)">取字节集型</a> , <a href="#GetDictionary"  style="color:rgb(128,0,0)">取字典型</a> , <a href="#GetList"  style="color:rgb(128,0,0)">取列表型</a> , <a href="#SetValue"  style="color:rgb(128,0,0)">置通用型</a> , <a href="#SetNull"  style="color:rgb(128,0,0)">置为空</a> , <a href="#SetBool"  style="color:rgb(128,0,0)">置逻辑型</a> , <a href="#SetInt"  style="color:rgb(128,0,0)">置整数型</a> , <a href="#SetDouble"  style="color:rgb(128,0,0)">置双精度小数型</a> , <a href="#SetString"  style="color:rgb(128,0,0)">置文本型</a> , <a href="#SetBinary"  style="color:rgb(128,0,0)">置字节集型</a> , <a href="#SetDictionary"  style="color:rgb(128,0,0)">置字典型</a> , <a href="#SetList"  style="color:rgb(128,0,0)">置列表型</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsOwned">是否拥有</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果基础数据由另一个对象拥有，则返回true。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsReadOnly">是否只读</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果对象是只读的返回真<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsSame">是否相同</span> |
|:----|
| <span style="color:rgb(0,128,0)">比较两个对象是否相同。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> 比较对象 <span style="color: rgb(0, 128, 0)">比较对象</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsEqual">是否相等</span> |
|:----|
| <span style="color:rgb(0,128,0)">比较两个对象是否为同一个。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> 比较对象 <span style="color: rgb(0, 128, 0)">比较对象</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Copy">创建副本</span> |
|:----|
| <span style="color:rgb(0,128,0)">为此对象创建一个新副本。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 是否清空 <span style="color: rgb(0, 128, 0)">是否清空</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> |


| <span style="color:rgb(128,0,0)" id="GetSize">取大小</span> |
|:----|
| <span style="color:rgb(0,128,0)">取已存储类型大小<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="Clear">清空</span> |
|:----|
| <span style="color:rgb(0,128,0)">清空类型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="HasKey">可有键</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果指定的键名存在返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetKeys">取所有键</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回以Key字符串列表。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型变量</span> |


| <span style="color:rgb(128,0,0)" id="Remove">移除键</span> |
|:----|
| <span style="color:rgb(0,128,0)">删除指定的键值项<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetType">取类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取该对象中存储的基础数据值类型, 有关定义在枚举常量: #值类型.* 中。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetValue">取通用型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取通用型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyValue.md" style ="color: blue">水星通用型</a> |


| <span style="color:rgb(128,0,0)" id="GetBool">取逻辑型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取逻辑型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetInt">取整数型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取整数型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetDouble">取双精度小数型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取双精度小数型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">双精度小数型</span> |


| <span style="color:rgb(128,0,0)" id="GetString">取文本型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取文本型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetBinary">取字节集型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取字节集型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">字节集型</span> |


| <span style="color:rgb(128,0,0)" id="GetDictionary">取字典型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取字典型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> |


| <span style="color:rgb(128,0,0)" id="GetList">取列表型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取列表型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyListValue.md" style ="color: blue">水星列表型</a> |


| <span style="color:rgb(128,0,0)" id="SetValue">置通用型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置通用型数据<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyValue.md" style ="color: blue">水星通用型</a> 类型值 <span style="color: rgb(0, 128, 0)">类型值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetNull">置为空</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置为空类型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetBool">置逻辑型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置为逻辑型数据<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 类型值 <span style="color: rgb(0, 128, 0)">类型值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetInt">置整数型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置为整数型数据<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 类型值 <span style="color: rgb(0, 128, 0)">类型值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetDouble">置双精度小数型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置双精度小数型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">双精度小数型</span> 类型值 <span style="color: rgb(0, 128, 0)">类型值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetString">置文本型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置为文本型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 类型值 <span style="color: rgb(0, 128, 0)">类型值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetBinary">置字节集型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置为字节集类型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">字节集型</span> 类型值 <span style="color: rgb(0, 128, 0)">类型值</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 长度 <span style="color: rgb(0, 128, 0)">长度</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetDictionary">置字典型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置字典型数据。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyDictionaryValue.md" style ="color: blue">水星字典型</a> 类型值 <span style="color: rgb(0, 128, 0)">类型值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetList">置列表型</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置为列表型数据<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 键名 <span style="color: rgb(0, 128, 0)">键名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyListValue.md" style ="color: blue">水星列表型</a> 类型值 <span style="color: rgb(0, 128, 0)">类型值</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


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
