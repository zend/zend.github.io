---
layout: post
status: publish
published: true
title: Cygwin安装
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 184
date: !binary |-
  MjAwOC0wMi0xNCAxMjo1Mzo0NCArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMi0xNCAwNDo1Mzo0NCArMDgwMA==
categories:
- 其他技术
tags:
- cygwin
comments: []
---
<p><font color="#ff6600" size="5"><strong>安装<&#47;strong><&#47;font><&#47;p></p>
<p>1. 下载setup.exe，官方下载地址：<a href="http:&#47;&#47;cygwin.com&#47;setup&#47;current&#47;">http:&#47;&#47;cygwin.com&#47;setup&#47;current&#47;<&#47;a>,或从附件下载。<&#47;p></p>
<p>2. 运行，下一步，选择网络安装(Install from Internet)。<&#47;p></p>
<p>3. 选择安装位置，比如E:\Cygwin, 下面两个选项保持默认就好。<&#47;p></p>
<p>4. 选择一个包存放位置，我选的是E:\Cygwin\packages。<&#47;p></p>
<p>5. 网络连接方式，按照你的情况进行代理设置，一般直接下一步就可以了。<&#47;p></p>
<p>6. 选择下载镜像，如果你是电信用户，建议加上<a href="http:&#47;&#47;www.cygwin.cn&#47;pub&#47;">http:&#47;&#47;www.cygwin.cn&#47;pub&#47;<&#47;a>。也就是在User URL处填上<a href="http:&#47;&#47;www.cygwin.cn&#47;pub&#47;">http:&#47;&#47;www.cygwin.cn&#47;pub&#47;<&#47;a> ，点击Add。<&#47;p></p>
<p>7. 等待安装完成。<&#47;p></p>
<p><font color="#ff6600" size="5"><strong>安装GCC<&#47;strong><&#47;font><&#47;p></p>
<p>1。重新运行setup.exe。<&#47;p></p>
<p>2。在软件包选择处选择Devel->gcc-g++, 依赖的软件包也会自动被选择上。<&#47;p></p>
<p>3。安装上一些常用的开发工具，如autoconf, make,glib等。<&#47;p></p>
<p>4。下一步，等待完成。<&#47;p></p>
<p><font color="#ff6600" size="5"><strong>安装编辑器<&#47;strong><&#47;font><&#47;p></p>
<p>按照安装GCC的方法，安装你喜欢的编辑器，或者其它任何软件包。<&#47;p></p>
<p><font color="#ff6600" size="5"><strong>测试<&#47;strong><&#47;font><&#47;p></p>
<p>1. 编写一个简单的C程序，如：<&#47;p></p>
<div class="codeText">
<div class="codeHead">C++代码<&#47;div></p>
<ol class="dp-cpp">
<li class="alt"><span><span class="preprocessor">#include&nbsp;<stdio.h> <&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span class="datatypes">int<&#47;span><span>&nbsp;main() &nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>{ &nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;printf(<&#47;span><span class="string">"%d+%d=%d"<&#47;span><span>,123,456,123+456); &nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>} &nbsp;&nbsp;<&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p>2. 编译，gcc gcctest.c -o add<&#47;p></p>
<p>3. $ .&#47;add 执行，输出123+456=579，成功。<&#47;p></p>
<p>4. 复制add.exe到其他目录，并把cygwin安装目录&#47;bin&#47;下(如E:\cygwin\bin)的cygwin1.dll放在同一目录下，就可以正常运行了。<&#47;p></p>
<p>&nbsp;<&#47;p></p>
