# 水星菜单
###### 上下文菜单

| `Quick Links` |
|:----|
|<a href="#IsSubMenu"  style="color:rgb(128,0,0)">是否为子菜单</a> , <a href="#Clear"  style="color:rgb(128,0,0)">清除</a> , <a href="#GetCount"  style="color:rgb(128,0,0)">取菜单项数量</a> , <a href="#AddSeparator"  style="color:rgb(128,0,0)">添加分隔符</a> , <a href="#AddItem"  style="color:rgb(128,0,0)">添加菜单项</a> , <a href="#AddCheckItem"  style="color:rgb(128,0,0)">添加复选菜单项</a> , <a href="#AddRadioItem"  style="color:rgb(128,0,0)">添加单选菜单项</a> , <a href="#AddSubMenu"  style="color:rgb(128,0,0)">添加子菜单项</a> , <a href="#InsertSeparatorAt"  style="color:rgb(128,0,0)">插入分隔符索引</a> , <a href="#InsertItemAt"  style="color:rgb(128,0,0)">插入菜单项索引</a> , <a href="#InsertCheckItemAt"  style="color:rgb(128,0,0)">插入复选菜单项索引</a> , <a href="#InsertRadioItemAt"  style="color:rgb(128,0,0)">插入单选菜单项索引</a> , <a href="#InsertSubMenuAt"  style="color:rgb(128,0,0)">插入子菜单项索引</a> , <a href="#Remove"  style="color:rgb(128,0,0)">移除菜单项</a> , <a href="#RemoveAt"  style="color:rgb(128,0,0)">移除菜单项索引</a> , <a href="#GetIndexOf"  style="color:rgb(128,0,0)">取菜单项索引命令ID</a> , <a href="#GetCommandIdAt"  style="color:rgb(128,0,0)">取菜单项命令ID索引</a> , <a href="#SetCommandIdAt"  style="color:rgb(128,0,0)">置菜单项命令ID索引</a> , <a href="#GetLabel"  style="color:rgb(128,0,0)">取标题</a> , <a href="#GetLabelAt"  style="color:rgb(128,0,0)">取菜单项标题索引</a> , <a href="#SetLabel"  style="color:rgb(128,0,0)">置菜单项标题</a> , <a href="#SetLabelAt"  style="color:rgb(128,0,0)">置菜单项标题索引</a> , <a href="#GetType"  style="color:rgb(128,0,0)">取菜单项类型</a> , <a href="#GetTypeAt"  style="color:rgb(128,0,0)">取菜单项类型索引</a> , <a href="#GetGroupId"  style="color:rgb(128,0,0)">取菜单项分组ID</a> , <a href="#GetGroupIdAt"  style="color:rgb(128,0,0)">取菜单项分组ID索引</a> , <a href="#SetGroupId"  style="color:rgb(128,0,0)">置菜单项分组ID</a> , <a href="#SetGroupIdAt"  style="color:rgb(128,0,0)">置菜单项分组ID索引</a> , <a href="#GetSubMenu"  style="color:rgb(128,0,0)">取子菜单项</a> , <a href="#GetSubMenuAt"  style="color:rgb(128,0,0)">取子菜单项索引</a> , <a href="#IsVisible"  style="color:rgb(128,0,0)">菜单项是否可视</a> , <a href="#IsVisibleAt"  style="color:rgb(128,0,0)">菜单项是否可视索引</a> , <a href="#SetVisible"  style="color:rgb(128,0,0)">置菜单项可视状态</a> , <a href="#SetVisibleAt"  style="color:rgb(128,0,0)">置菜单项可视状态索引</a> , <a href="#IsEnabled"  style="color:rgb(128,0,0)">菜单项是否可用</a> , <a href="#IsEnabledAt"  style="color:rgb(128,0,0)">菜单项是否可用索引</a> , <a href="#SetEnabled"  style="color:rgb(128,0,0)">置菜单项可用状态</a> , <a href="#SetEnabledAt"  style="color:rgb(128,0,0)">置菜单项可用状态索引</a> , <a href="#IsChecked"  style="color:rgb(128,0,0)">菜单项是否被选中</a> , <a href="#IsCheckedAt"  style="color:rgb(128,0,0)">菜单项是否已选中索引</a> , <a href="#SetChecked"  style="color:rgb(128,0,0)">选择菜单项</a> , <a href="#SetCheckedAt"  style="color:rgb(128,0,0)">选择菜单项索引</a> , <a href="#HasAccelerator"  style="color:rgb(128,0,0)">菜单项是否有快捷键</a> , <a href="#HasAcceleratorAt"  style="color:rgb(128,0,0)">菜单项是否有快捷键索引</a> , <a href="#SetAccelerator"  style="color:rgb(128,0,0)">置菜单项快捷键</a> , <a href="#SetAcceleratorAt"  style="color:rgb(128,0,0)">置菜单项快捷键索引</a> , <a href="#RemoveAccelerator"  style="color:rgb(128,0,0)">移除菜单项快捷键</a> , <a href="#RemoveAcceleratorAt"  style="color:rgb(128,0,0)">移除菜单项快捷键索引</a> , <a href="#SetColor"  style="color:rgb(128,0,0)">置菜单项颜色</a> , <a href="#SetColorAt"  style="color:rgb(128,0,0)">置菜单项颜色索引</a> , <a href="#SetFontList"  style="color:rgb(128,0,0)">置菜单项字体列表</a> , <a href="#SetFontListAt"  style="color:rgb(128,0,0)">置菜单项字体列表索引</a> , |

---------------------
 `功能函数` <br/>

| <span style="color:rgb(128,0,0)" id="IsSubMenu">是否为子菜单</span> |
|:----|
| <span style="color:rgb(0,128,0)">如果此菜单对象为子菜单返回真。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="Clear">清除</span> |
|:----|
| <span style="color:rgb(0,128,0)">清除所有菜单项。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetCount">取菜单项数量</span> |
|:----|
| <span style="color:rgb(0,128,0)">返回此菜单的菜单项目数。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="AddSeparator">添加分隔符</span> |
|:----|
| <span style="color:rgb(0,128,0)">在菜单中添加一个分隔符。<span> |
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="AddItem">添加菜单项</span> |
|:----|
| <span style="color:rgb(0,128,0)">添加一个项目到菜单中。<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="AddCheckItem">添加复选菜单项</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="AddRadioItem">添加单选菜单项</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 分组ID <span style="color: rgb(0, 128, 0)">分组ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="AddSubMenu">添加子菜单项</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyMenuModel.md" style ="color: blue">水星菜单</a> |


| <span style="color:rgb(128,0,0)" id="InsertSeparatorAt">插入分隔符索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="InsertItemAt">插入菜单项索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="InsertCheckItemAt">插入复选菜单项索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="InsertRadioItemAt">插入单选菜单项索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 分组ID <span style="color: rgb(0, 128, 0)">分组ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="InsertSubMenuAt">插入子菜单项索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyMenuModel.md" style ="color: blue">水星菜单</a> |


| <span style="color:rgb(128,0,0)" id="Remove">移除菜单项</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="RemoveAt">移除菜单项索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetIndexOf">取菜单项索引命令ID</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetCommandIdAt">取菜单项命令ID索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SetCommandIdAt">置菜单项命令ID索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetLabel">取标题</span> |
|:----|
| <span style="color:rgb(0,128,0)">取菜单项标题<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="GetLabelAt">取菜单项标题索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">取菜单项标题<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">文本型</span> |


| <span style="color:rgb(128,0,0)" id="SetLabel">置菜单项标题</span> |
|:----|
| <span style="color:rgb(0,128,0)">置菜单项标题<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetLabelAt">置菜单项标题索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">置菜单项标题<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 标题 <span style="color: rgb(0, 128, 0)">标题</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetType">取菜单项类型</span> |
|:----|
| <span style="color:rgb(0,128,0)">取菜单项类型<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetTypeAt">取菜单项类型索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">菜单项索引<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetGroupId">取菜单项分组ID</span> |
|:----|
| <span style="color:rgb(0,128,0)">取菜单项分组ID<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="GetGroupIdAt">取菜单项分组ID索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">取菜单项分组ID<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">整数型</span> |


| <span style="color:rgb(128,0,0)" id="SetGroupId">置菜单项分组ID</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置菜单项分组ID<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 分组ID <span style="color: rgb(0, 128, 0)">分组ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetGroupIdAt">置菜单项分组ID索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置菜单项分组ID<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 分组ID <span style="color: rgb(0, 128, 0)">分组ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="GetSubMenu">取子菜单项</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取子菜单<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyMenuModel.md" style ="color: blue">水星菜单</a> |


| <span style="color:rgb(128,0,0)" id="GetSubMenuAt">取子菜单项索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">获取子菜单<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <a href="ProxyMenuModel.md" style ="color: blue">水星菜单</a> |


| <span style="color:rgb(128,0,0)" id="IsVisible">菜单项是否可视</span> |
|:----|
| <span style="color:rgb(0,128,0)">菜单项是否可视<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsVisibleAt">菜单项是否可视索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">菜单项是否可视<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetVisible">置菜单项可视状态</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置菜单可视状态<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 可视 <span style="color: rgb(0, 128, 0)">可视</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetVisibleAt">置菜单项可视状态索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">菜单项是否可视<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 可视 <span style="color: rgb(0, 128, 0)">可视</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsEnabled">菜单项是否可用</span> |
|:----|
| <span style="color:rgb(0,128,0)">菜单项是否可用<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsEnabledAt">菜单项是否可用索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">菜单项是否被启用<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetEnabled">置菜单项可用状态</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置菜单项启用状态<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 启用 <span style="color: rgb(0, 128, 0)">启用</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetEnabledAt">置菜单项可用状态索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">设置菜单项启用状态<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 启用 <span style="color: rgb(0, 128, 0)">启用</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsChecked">菜单项是否被选中</span> |
|:----|
| <span style="color:rgb(0,128,0)">菜单项是否被选中<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="IsCheckedAt">菜单项是否已选中索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">菜单项是否被选中<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetChecked">选择菜单项</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 选中 <span style="color: rgb(0, 128, 0)">选中</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetCheckedAt">选择菜单项索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> 选中 <span style="color: rgb(0, 128, 0)">选中</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="HasAccelerator">菜单项是否有快捷键</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="HasAcceleratorAt">菜单项是否有快捷键索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetAccelerator">置菜单项快捷键</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> key_code <span style="color: rgb(0, 128, 0)">key_code</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> shift_pressed <span style="color: rgb(0, 128, 0)">shift_pressed</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> ctrl_pressed <span style="color: rgb(0, 128, 0)">ctrl_pressed</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> alt_pressed <span style="color: rgb(0, 128, 0)">alt_pressed</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetAcceleratorAt">置菜单项快捷键索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> key_code <span style="color: rgb(0, 128, 0)">key_code</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> shift_pressed <span style="color: rgb(0, 128, 0)">shift_pressed</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> ctrl_pressed <span style="color: rgb(0, 128, 0)">ctrl_pressed</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">逻辑型</span> alt_pressed <span style="color: rgb(0, 128, 0)">alt_pressed</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="RemoveAccelerator">移除菜单项快捷键</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="RemoveAcceleratorAt">移除菜单项快捷键索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetColor">置菜单项颜色</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 颜色类型 <span style="color: rgb(0, 128, 0)">颜色类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 颜色 <span style="color: rgb(0, 128, 0)">颜色</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetColorAt">置菜单项颜色索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 颜色类型 <span style="color: rgb(0, 128, 0)">颜色类型</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 颜色 <span style="color: rgb(0, 128, 0)">颜色</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetFontList">置菜单项字体列表</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 命令ID <span style="color: rgb(0, 128, 0)">命令ID</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 字体列表 <span style="color: rgb(0, 128, 0)">字体列表</span> | 
| <span style="color: rgb(117, 110, 200)">@return </span> <span style ="color: blue">逻辑型</span> |


| <span style="color:rgb(128,0,0)" id="SetFontListAt">置菜单项字体列表索引</span> |
|:----|
| <span style="color:rgb(0,128,0)">-<span> |
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">整数型</span> 菜单项索引 <span style="color: rgb(0, 128, 0)">菜单项索引</span> | 
| <span style="color: rgb(117, 110, 200)">@param</span> <span style ="color: blue">文本型</span> 字体列表 <span style="color: rgb(0, 128, 0)">字体列表</span> | 
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
