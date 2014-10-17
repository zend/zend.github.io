---
layout: post
status: publish
published: true
title: 命令行下CVS使用方法
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>命令行下CVS使用方法总结。</p>
wordpress_id: 201
date: !binary |-
  MjAwOC0wNi0yNyAxNTowNDo1NiArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wNi0yNyAwNzowNDo1NiArMDgwMA==
categories:
- 服务器
tags:
- linux
comments: []
---
<p>第一步，先登陆CVS服务器：<br &#47;><br />
<br &#47;><br />
cvs -d :pserver:seaprince@192.168.1.48:&#47;home&#47;cvsroot&#47;projectdoc login<br &#47;><br />
<br &#47;><br />
第二步，检出文件：<br &#47;><br />
<br &#47;><br />
cvs -d :pserver:seaprince@192.168.1.48:&#47;home&#47;cvsroot&#47;projectdoc checkout swimingtools<br &#47;><br />
<br &#47;><br />
第三步，提交修改。<br &#47;><br />
<br &#47;><br />
cd swimingtools<br &#47;><br />
cvs commit readme.txt<&#47;p></p>
