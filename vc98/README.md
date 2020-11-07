# 关于

此仓库的存放的是各个版本的 Visual C++ 6.0 安装镜像, 仅为方便使用, 资源均收集于网络, 如有侵权, 敬请告知删除。

* 英文版: [en-us](https://github.com/kirino17/vc60/releases/tag/6.00) 
* 简体中文版: [zh-cn](https://github.com/kirino17/vc60/releases/tag/6.01)
* 命令行环境包: [vc60env](https://github.com/kirino17/vc60/releases/tag/6.02)

# 如何使用命令行环境包

使用命令行环境包无需安装Visual C++ 6.0, 下载仓库中的 init.ps1 脚本文件到你的电脑上, 并给它创建一个文件夹, 如:
```
E:\vc6-toolset\
    init.ps1
```

然后使用 powershell 启动这个脚本, 它会自动下载并配置命令行环境， 如:
```
powershell &E:\vc6-toolset\init.ps1
```

如果没有错误发生, 那么命令行环境包就安装好了。

使用方法:
使用命令行编译, 需要给你的工程项目编写一个cmake的构建脚本, 如果你已经写好了, 启动命令行执行下面的命令即可开始编译:
```
#这是注释

#参数: 项目名称, 在此参数填入你的项目名称, 应与构建脚本中填写的一致, 否则无法完成编译
#参数: 生成目标, 可选值: Debug | Release
#参数: 源代码目录, 你的工程目录
#参数: 构建目录, 用于存放cmake生成的工程文件

powershell &E:\vc6-toolset\init.ps1 [项目名称] [生成目标] [源代码目录] [构建目录]

#例子:

powershell &E:\vc6-toolset\init.ps1 "testdemo" "Debug" "E:\testdemo\src" "E:\testdemo\build"

```


