---
layout: post
status: publish
published: true
title: 在PHP中使用HTTP Proxy(HTTP代理)来访问网络资源
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 563
wordpress_url: http://blog.eaxi.com/?p=563
date: !binary |-
  MjAxMC0xMS0xNyAxMzo0NDoxNSArMDgwMA==
date_gmt: !binary |-
  MjAxMC0xMS0xNyAwNTo0NDoxNSArMDgwMA==
categories:
- 服务器
- 其他技术
tags:
- telnet http
comments: []
---
<p><strong>1. 最简单的方法<&#47;strong><br />
连接HTTP代理，给它发一个GET的HTTP头。<br />
指令如下：<br />
telnet proxy.example.com 8080<br />
GET http:&#47;&#47;www.example.com&#47;some&#47;url.html HTTP&#47;1.0<br />
Host: whatever</p>
<p>最后要跟一个空行表示结束。完了就赶紧读取代理返回的数据就好了。返回的数据是不带HTTP头的文件真实内容。</p>
<p><strong>2. 用CONNECT指令<&#47;strong><br />
上面的例子用于获取一个资源时非常简单，但它也有定制性差的缺点：只能做一些非常简单的应用，想发送一个HEAD请求，或自定义下HTTP请求头的话，这种方法行不通。<br />
CONNECT是这么样的一个指令：允许你先连接上代理服务器，返回连接状态后，再接收HTTP请求头，并帮你转发给目标服务器。<br />
看指令：<br />
> telnet 10.6.234.33 8080<br />
Trying 10.6.234.33...<br />
Connected to 10.6.234.33.<br />
Escape character is '^]'.<br />
CONNECT 10.6.234.33:8080 HTTP&#47;1.0<br />
Host: 10.6.234.33:8080</p>
<p>HTTP&#47;1.1 200 Connection established</p>
<p>HEAD http:&#47;&#47;www.example.com&#47;css&#47;global.css HTTP&#47;1.1<br />
Host: www.example.com<br />
Accept: *&#47;*<br />
Proxy-Connection: Keep-Alive</p>
<p>HTTP&#47;1.1 200 OK<br />
Server: NWS-imgcache<br />
Date: Wed, 17 Nov 2010 04:28:21 GMT<br />
Expires: Wed, 17 Nov 2010 05:28:21 GMT<br />
Cache-Control: max-age=3600<br />
Last-Modified: Mon, 08 Nov 2010 11:01:49 GMT<br />
Content-Type: text&#47;css<br />
Content-Length: 29703<br />
X-Cache-Lookup: MISS from proxy:8080</p>
<p>Connection closed by foreign host.</p>
<p>空行分隔，分别是用户输入、服务器返回、用户输入、服务器返回。</p>
<p>看PHP实现的一个例子。<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2010&#47;11&#47;proxy.zip">proxy.zip<&#47;a></p>
