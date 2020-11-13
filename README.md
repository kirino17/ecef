# 水星浏览器

### 介绍
水星浏览器是在2016年时创建的一个浏览器项目, 它的前身有Kirinoium、遥望浏览器、易CEF、CEF视图等等。项目的目标是跟踪 Google Chromium 嵌入式分支做成一个免费开源的易语言版 chromium 实现, 让广大易开发者们享受到来自 Chromium 的现代化浏览器技术。水星浏览器的典型应用场景包括:
* 作为一个兼容HTML5的浏览器控件嵌入到应用程序中。
* 创建一个轻量化的壳浏览器用于托管Web技术开发的应用程序。
* 使用浏览器进行自动化的Web适应性测试。

### 开发指南

[https://bbs.125.la/forum.php?mod=viewthread&tid=14648940&extra=page%3D1](https://bbs.125.la/forum.php?mod=viewthread&tid=14648940&extra=page%3D1)

### 编译
编译支持库需要准备:
* Visual Studio 2015 或者更高版本。
* Windows 10 SDK 18362.0
* Visual Studio Code

项目: src/aquarius2 为实现易语言调用CEF所需要的胶水代码工程。已进行自动化配置可使用Visual Studio打开.sln 项目方案进行编译。 <br/>
项目: src/TestRenderer 为多进程模式下用于挂载浏览器进程的壳程序工程, 壳程序提供了执行Javascript脚本, DOM访问, 以及一些其它功能性方法。已进行自动化配置可使用Visual Studio打开.sln 项目方案进行编译。 <br/>
项目: src/ 为支持库工程代码, 项目方案使用Visual Studio Code构建, 在项目根文件夹下打开Visual Studio Code运行生成任务即可编译支持库。<br/>

### 授权

水星浏览器使用 BSD-3 Clause 开源协议免费授权, 欢迎使用。

### 讨论组

如果你对浏览器技术富有兴趣并且乐于交流或者说有更好的建议或是意见欢迎加入我们的讨论组一起分享交流:
* chrome chan · 爱好会: 89456201
* chrome chan · 爱好会Δ: 649931225



