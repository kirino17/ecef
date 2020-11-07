# 水星命令行
###### 用于创建和解析命令行参数的类。在windows中带有\"--\" 或 \"-\" 以及 \"/\" 前缀的参数被视为命令行开关。开关将始终在任何没有开关前缀的参数之前。 开关可以选择使用\"=\"分隔符指定一个值(例如: \"--switch=value\")。参数\"-\" 将终止所有后续标记的开关解析, 无论前缀如何, 都将被解释为非开关参数。开关名称不区分大小写。可以在调用\"进程初始化\" 之前使用此类。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#IsReadOnly"  style="color:rgb(128,0,0)">是否为只读</a> , <a href="#Copy"  style="color:rgb(128,0,0)">复制</a> , <a href="#InitFromString"  style="color:rgb(128,0,0)">从字符串初始化</a> , <a href="#Reset"  style="color:rgb(128,0,0)">重置</a> , <a href="#GetArgv"  style="color:rgb(128,0,0)">取原始命令行</a> , <a href="#GetCommandLineString"  style="color:rgb(128,0,0)">取命令行字符串</a> , <a href="#GetProgram"  style="color:rgb(128,0,0)">取程序名称</a> , <a href="#SetProgram"  style="color:rgb(128,0,0)">置程序名称</a> , <a href="#HasSwitches"  style="color:rgb(128,0,0)">是否有命令行配置项</a> , <a href="#HasSwitch"  style="color:rgb(128,0,0)">是否有指定配置项</a> , <a href="#GetSwitchValue"  style="color:rgb(128,0,0)">取配置项值</a> , <a href="#AppendSwitch"  style="color:rgb(128,0,0)">置配置项开关</a> , <a href="#AppendSwitchWithValue"  style="color:rgb(128,0,0)">置配置项值</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsReadOnly">是否为只读</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此对象项为只读模式返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Copy">复制</span> |
|:----|
| <span style="color:rgb(0,128,0)">创建一个新的命令行对象,该对象为本此对象的副本。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyCommandLine.md" style ="color: blue">水星命令行</a> |


| <span style="color:rgb(128,0,0)" id="InitFromString">从字符串初始化</span> |
|:----|
| <span style="color:rgb(0,128,0)">从字符串初始化命令行对象。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 命令行字符串 <span style="color: rgb(0, 128, 0)">命令行字符串</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Reset">重置</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetArgv">取原始命令行</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型变量</span> |


| <span style="color:rgb(128,0,0)" id="GetCommandLineString">取命令行字符串</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回原始命令行字符串数据。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetProgram">取程序名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回命令行参数中的路径名称。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetProgram">置程序名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置命令行参数中的路径名称。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 程序名称 <span style="color: rgb(0, 128, 0)">程序名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="HasSwitches">是否有命令行配置项</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果命令行中存在配置项返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="HasSwitch">是否有指定配置项</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果命令行中有指定的配置项返回真<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 配置项名称 <span style="color: rgb(0, 128, 0)">配置项名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetSwitchValue">取配置项值</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回指定配置项的值。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 配置项 <span style="color: rgb(0, 128, 0)">配置项</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="AppendSwitch">置配置项开关</span> |
|:----|
| <span style="color:rgb(0,128,0)">追加一个配置项开关到命令行参数中。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 配置项开关名称 <span style="color: rgb(0, 128, 0)">配置项开关名称</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="AppendSwitchWithValue">置配置项值</span> |
|:----|
| <span style="color:rgb(0,128,0)">追加一个配置项值到命令行参数中。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 配置项名称 <span style="color: rgb(0, 128, 0)">配置项名称</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 配置项值 <span style="color: rgb(0, 128, 0)">配置项值</span> | 
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
