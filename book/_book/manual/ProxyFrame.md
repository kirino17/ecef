# 水星框架
###### 用于在浏览器窗口中表示框架的类。在浏览器进程中使用时, 可以在任何线程上调用此类中的方法。除非注释另有说明。

| `Quick Links` |
|:----|
|<a href="#IsValid"  style="color:rgb(128,0,0)">是否有效</a> , <a href="#Undo"  style="color:rgb(128,0,0)">撤销</a> , <a href="#Redo"  style="color:rgb(128,0,0)">重做</a> , <a href="#Cut"  style="color:rgb(128,0,0)">剪切</a> , <a href="#Copy"  style="color:rgb(128,0,0)">复制</a> , <a href="#Paste"  style="color:rgb(128,0,0)">粘贴</a> , <a href="#Delete"  style="color:rgb(128,0,0)">删除</a> , <a href="#SelectAll"  style="color:rgb(128,0,0)">全选</a> , <a href="#ViewSource"  style="color:rgb(128,0,0)">源码视图</a> , <a href="#GetSource"  style="color:rgb(128,0,0)">取页面源码</a> , <a href="#GetText"  style="color:rgb(128,0,0)">取页面文本</a> , <a href="#LoadURL"  style="color:rgb(128,0,0)">加载URL</a> , <a href="#LoadRequest"  style="color:rgb(128,0,0)">加载请求</a> , <a href="#ExecuteJavaScript"  style="color:rgb(128,0,0)">执行脚本</a> , <a href="#ExecuteJavaScriptEx"  style="color:rgb(128,0,0)">执行脚本2</a> , <a href="#IsMain"  style="color:rgb(128,0,0)">是否为主框架</a> , <a href="#IsFocused"  style="color:rgb(128,0,0)">是否拥有焦点</a> , <a href="#GetName"  style="color:rgb(128,0,0)">取名称</a> , <a href="#GetParent"  style="color:rgb(128,0,0)">取父框架</a> , <a href="#GetURL"  style="color:rgb(128,0,0)">取URL</a> , <a href="#GetBrowser"  style="color:rgb(128,0,0)">取浏览器</a> , <a href="#GetIdentifier"  style="color:rgb(128,0,0)">取标识符</a> , <a href="#CreateURLRequest"  style="color:rgb(128,0,0)">发送URL请求</a> , <a href="#VisitDOM"  style="color:rgb(128,0,0)">取文档对象</a> , <a href="#SynthesizePinchGesture"  style="color:rgb(128,0,0)">合成捏合手势</a> , <a href="#SynthesizeScrollGesture"  style="color:rgb(128,0,0)">合成滑动手势</a> , <a href="#SynthesizeTapGesture"  style="color:rgb(128,0,0)">合成轻击手势</a> , <a href="#SynthesizeDragGesture"  style="color:rgb(128,0,0)">合成拖动手势</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsValid">是否有效</span> |
|:----|
| <span style="color:rgb(0,128,0)">此函数检查本类中的对象实例是否有效。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Undo">撤销</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Redo">重做</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Cut">剪切</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Copy">复制</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Paste">粘贴</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="Delete">删除</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SelectAll">全选</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ViewSource">源码视图</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="GetSource">取页面源码</span> |
|:----|
| <span style="color:rgb(0,128,0)">取此框架中的页面HTML源代码, 注意: 此函数禁止在事件中调用。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetText">取页面文本</span> |
|:----|
| <span style="color:rgb(0,128,0)">取此框架中的页面文本, 注意: 此函数禁止在事件中调用。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="LoadURL">加载URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">在此框架中加载指定的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> url <span style="color: rgb(0, 128, 0)">url</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="LoadRequest">加载请求</span> |
|:----|
| <span style="color:rgb(0,128,0)">在此框架中加载一个新的请求。在执行此方法前需要至少执行过一次加载URL函数。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ExecuteJavaScript">执行脚本</span> |
|:----|
| <span style="color:rgb(0,128,0)">在此框架值执行指定的Javascript脚本代码。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 脚本代码 <span style="color: rgb(0, 128, 0)">脚本代码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 脚本别名 <span style="color: rgb(0, 128, 0)">脚本别名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始行 <span style="color: rgb(0, 128, 0)">起始行</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="ExecuteJavaScriptEx">执行脚本2</span> |
|:----|
| <span style="color:rgb(0,128,0)">在此框架中执行指定的javacript脚本代码。执行成功返回计算结果, 执行失败返回空对象, 可调用IsValid() 函数检查对象有效性。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 脚本代码 <span style="color: rgb(0, 128, 0)">脚本代码</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 脚本别名 <span style="color: rgb(0, 128, 0)">脚本别名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 起始行 <span style="color: rgb(0, 128, 0)">起始行</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型变量</span> 异常信息 <span style="color: rgb(0, 128, 0)">异常信息</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyValue.md" style ="color: blue">水星通用型</a> |


| <span style="color:rgb(128,0,0)" id="IsMain">是否为主框架</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此框架为首要框架(Top-Level)返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsFocused">是否拥有焦点</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此框架拥有焦点返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetName">取名称</span> |
|:----|
| <span style="color:rgb(0,128,0)">取此框架的名称。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetParent">取父框架</span> |
|:----|
| <span style="color:rgb(0,128,0)">取此框架的父框架, 如果此框架没有父框架将返回空对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyFrame.md" style ="color: blue">水星框架</a> |


| <span style="color:rgb(128,0,0)" id="GetURL">取URL</span> |
|:----|
| <span style="color:rgb(0,128,0)">取此框架中加载的URL。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetBrowser">取浏览器</span> |
|:----|
| <span style="color:rgb(0,128,0)">取此框架所属的浏览器。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyBrowser.md" style ="color: blue">水星浏览器</a> |


| <span style="color:rgb(128,0,0)" id="GetIdentifier">取标识符</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此框架的标识符<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">长整数型</span> |


| <span style="color:rgb(128,0,0)" id="CreateURLRequest">发送URL请求</span> |
|:----|
| <span style="color:rgb(0,128,0)">使用本框架作为会话源发送一个HTTP请求。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <a href="ProxyRequest.md" style ="color: blue">水星请求</a> 请求 <span style="color: rgb(0, 128, 0)">请求</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 认证用户名 <span style="color: rgb(0, 128, 0)">认证用户名</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 认证密码 <span style="color: rgb(0, 128, 0)">认证密码</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyURLRequest.md" style ="color: blue">水星URL请求</a> |


| <span style="color:rgb(128,0,0)" id="VisitDOM">取文档对象</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此框架内的文档对象。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyDOMDocument.md" style ="color: blue">水星网页文档对象</a> |


| <span style="color:rgb(128,0,0)" id="SynthesizePinchGesture">合成捏合手势</span> |
|:----|
| <span style="color:rgb(0,128,0)">通过发出适当的触摸事件, 以在一段时间内合成捏合手势。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 开始位置X <span style="color: rgb(0, 128, 0)">开始位置X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 开始位置Y <span style="color: rgb(0, 128, 0)">开始位置Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 缩放因子 <span style="color: rgb(0, 128, 0)">缩放因子</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 相对速度 <span style="color: rgb(0, 128, 0)">相对速度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 输出源 <span style="color: rgb(0, 128, 0)">输出源</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SynthesizeScrollGesture">合成滑动手势</span> |
|:----|
| <span style="color:rgb(0,128,0)">通过发出适当的触摸事件, 以在一段时间内合成滑动手势。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 开始位置X <span style="color: rgb(0, 128, 0)">开始位置X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 开始位置Y <span style="color: rgb(0, 128, 0)">开始位置Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 滑动距离X <span style="color: rgb(0, 128, 0)">滑动距离X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 滑动距离Y <span style="color: rgb(0, 128, 0)">滑动距离Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 增量距离X <span style="color: rgb(0, 128, 0)">增量距离X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 增量距离Y <span style="color: rgb(0, 128, 0)">增量距离Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 缩放因子 <span style="color: rgb(0, 128, 0)">缩放因子</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 防止逃逸 <span style="color: rgb(0, 128, 0)">防止逃逸</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 滑动速度 <span style="color: rgb(0, 128, 0)">滑动速度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 输出源 <span style="color: rgb(0, 128, 0)">输出源</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SynthesizeTapGesture">合成轻击手势</span> |
|:----|
| <span style="color:rgb(0,128,0)">通过发出适当的触摸事件, 以在一段时间内合成轻击手势。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 开始位置X <span style="color: rgb(0, 128, 0)">开始位置X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 开始位置Y <span style="color: rgb(0, 128, 0)">开始位置Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 缩放因子 <span style="color: rgb(0, 128, 0)">缩放因子</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 持续时间 <span style="color: rgb(0, 128, 0)">持续时间</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 轻击次数 <span style="color: rgb(0, 128, 0)">轻击次数</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 输出源 <span style="color: rgb(0, 128, 0)">输出源</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">无返回值</span> |


| <span style="color:rgb(128,0,0)" id="SynthesizeDragGesture">合成拖动手势</span> |
|:----|
| <span style="color:rgb(0,128,0)">通过发出适当的触摸事件, 以在一段时间内合成拖动手势。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 开始位置X <span style="color: rgb(0, 128, 0)">开始位置X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 开始位置Y <span style="color: rgb(0, 128, 0)">开始位置Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 拖动距离X <span style="color: rgb(0, 128, 0)">拖动距离X</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 拖动距离Y <span style="color: rgb(0, 128, 0)">拖动距离Y</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">小数型</span> 缩放因子 <span style="color: rgb(0, 128, 0)">缩放因子</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 拖动速度 <span style="color: rgb(0, 128, 0)">拖动速度</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 输出源 <span style="color: rgb(0, 128, 0)">输出源</span> | 
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
