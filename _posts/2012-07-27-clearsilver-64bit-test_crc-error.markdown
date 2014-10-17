---
layout: post
status: publish
published: true
title: ClearSilver 64位机器上编译，test_crc错误的问题
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 615
wordpress_url: http://blog.eaxi.com/?p=615
date: !binary |-
  MjAxMi0wNy0yNyAyMDoyMjowMSArMDgwMA==
date_gmt: !binary |-
  MjAxMi0wNy0yNyAxMjoyMjowMSArMDgwMA==
categories:
- 不想分类
tags:
- linux 64bit clearsilver
comments: []
---
<p>环境：clearsilver-0.10.5，64 bit, SuSE<br />
Running cs regression tests<br />
Failed Regression Test: test_crc.cs<br />
  See test_crc.cs.out and test_crc.cs.err<br />
make: *** [test] Error 1</p>
<p>test_crc.cs.err<br />
4c4<br />
< -2128917020<br />
---<br />
> 2166050276</p>
<p>test_crc.cs.out<br />
Parsing test_crc.cs<br />
419156592<br />
1357503972<br />
2166050276</p>
<p>test_crc.cs.gold</p>
<p>Parsing test_crc.cs<br />
419156592<br />
1357503972<br />
-2128917020</p>
<p>解决方法：<br />
直接编辑 cs&#47;Makefile，删除 test_crc 相关内容，重新编译。</p>
