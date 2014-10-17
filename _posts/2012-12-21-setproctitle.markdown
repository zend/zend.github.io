---
layout: post
status: publish
published: true
title: setproctitle
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 621
wordpress_url: http://blog.eaxi.com/?p=621
date: !binary |-
  MjAxMi0xMi0yMSAxNzo0NDowNyArMDgwMA==
date_gmt: !binary |-
  MjAxMi0xMi0yMSAwOTo0NDowNyArMDgwMA==
categories:
- 不想分类
tags:
- linux setproctitle
comments: []
---
<p>setproctitle是个很有用的技巧，它的原理是修改进程的argv[0]来达到修改进程命令行显示的效果。<br />
命令行参数argv和环境变量信息environ是在一块连续的内存中表示的，并且environ紧跟在argv后面。<br />
由于修改前后的命令行长度不一样，为了保证argv和environ的连续性，需要新申请一块内存来存放新的argv，environ，就达到了随意修改进程名字的目的。</p>
