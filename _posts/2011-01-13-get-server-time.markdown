---
layout: post
status: publish
published: true
title: 取服务器时间的最佳实践
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 565
wordpress_url: http://blog.eaxi.com/?p=565
date: !binary |-
  MjAxMS0wMS0xMyAxMDo0OToyNCArMDgwMA==
date_gmt: !binary |-
  MjAxMS0wMS0xMyAwMjo0OToyNCArMDgwMA==
categories:
- 不想分类
tags:
- javascript js
comments: []
---
<p>很多场景中，我们都需要拿到服务器的时间，一般的实现方式是写个CGI，把服务器时间吐出来。但CGI容易带来安全或性能的问题。<br />
这里的例子，使用HEAD请求，解析HTTP HEADER中的时间，从而达到同样目的。</p>
<p>var xhr=null;<br />
try{xhr=new XMLHttpRequest();}catch(e){try{xhr=new ActiveXObject("Msxml2.XMLHTTP");}catch(e){try {xhr=new ActiveXObject("Microsoft.XMLHTTP");}catch (e){xhr=null;} } };<br />
xhr.open("HEAD", window.location.href, false);<br />
xhr.send(null);<br />
var t = parseInt(new Date(Date.parse(xhr.getResponseHeader("Date"))).getTime() &#47; 1000);</p>
