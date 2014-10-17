---
layout: post
status: publish
published: true
title: Chrome扩展编写教程
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 500
wordpress_url: http://seaprince.cn/?p=500
date: !binary |-
  MjAwOS0xMi0yMCAxNjozODozNiArMDgwMA==
date_gmt: !binary |-
  MjAwOS0xMi0yMCAwODozODozNiArMDgwMA==
categories:
- 脚本语言
- 其他技术
tags:
- javascript
- chrome
comments: []
---
<p>今天闲着没事，自己做了一个扩展玩玩，随便写下笔记。</p>
<p>要求Google Chrome 4.0+</p>
<p>首先，我们先建立一个工作目录，我这里是E:\chrome</p>
<p>创建一个文件，名字叫manifest.json，内容如下：</p>
<div id="_mcePaste">{&nbsp;&nbsp;"name": "Seaprince's Blog Reader",&nbsp;&nbsp;"version": "1.0",&nbsp;&nbsp;"description": "You can read the latest blog entry from Seaprince's Blog using this extension.",&nbsp;&nbsp;"browser_action": {&nbsp;&nbsp; &nbsp;"default_icon": "23.gif",&nbsp;&nbsp; &nbsp;"popup": "popup.html"&nbsp;&nbsp;},&nbsp;&nbsp;"permissions": [&nbsp;&nbsp; &nbsp;"http:&#47;&#47;blog.eaxi.com&#47;"&nbsp;&nbsp;]}<&#47;div><br />
自己制作一个小图标放在文件夹中，命名为23.gif</p>
<p>创建一个HTML文件，命名为popup.html，内容为：</p>
<style>
<p>img {</p>
<p>margin:5px;</p>
<p>border:none;</p>
<p>vertical-align:middle;</p>
<p>}</p>
<p><&#47;style></p>
<p><script language="javascript" type="text&#47;javascript" src="http:&#47;&#47;tmdcc.com&#47;home&#47;js.php?id=2"><&#47;script></p>
<p>点击chrome中的小扳手图标，选择&ldquo;扩展程序&rdquo;项。</p>
<p>在开发人员模式这里，点击&ldquo;载入正在开发的扩展程序&rdquo;，选择刚才我们创建的E:\chrome</p>
<p>成功！你会看到工具条中多了一个图标，点击它，就可以看到你的扩展效果！</p>
<p>分享给他人</p>
<p>在开发人员模式这里，点击，打包扩展程序，完成后，会在chrome的平级生成chrome.crx和chrome.pem两个文件，把chrome.crx发给别人，并让他用chrome打开，就可以安装扩展程序！</p>
<p>测试：<a href="http:&#47;&#47;blog.eaxi.com&#47;demo&#47;chrome&#47;chrome.crx">chrome.crx<&#47;a></p>
<p>参考文章：<a href="http:&#47;&#47;code.google.com&#47;chrome&#47;extensions&#47;getstarted.html">http:&#47;&#47;code.google.com&#47;chrome&#47;extensions&#47;getstarted.html<&#47;a></p>
