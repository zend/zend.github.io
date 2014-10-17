---
layout: post
status: publish
published: true
title: php中的memcached扩展使用
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: ! "<p>本文提供php_memcache.dll 扩展下载，本版本适用于绝大多数PHP 5版本，已经测试5.2.6, 5.2.9-2，欢迎您把测试结果分享出来。</p>\r\n<p>另外，提一下用memcache做session.save_handler的方法。</p>"
wordpress_id: 229
date: !binary |-
  MjAwOS0wNi0yNiAxNzoxODo1MSArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wNi0yNiAwOToxODo1MSArMDgwMA==
categories:
- 服务器
tags:
- memcached
- php
comments: []
---
<p>本文提供php_memcache.dll 扩展下载，本版本适用于绝大多数PHP 5版本，已经测试5.2.6, 5.2.9-2，欢迎您把测试结果分享出来。<&#47;p></p>
<p>另外，提一下用memcache做session.save_handler的方法。<&#47;p></p>
<p>&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; ini_set('session.save_handler', 'memcache');<br &#47;><br />
&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; ini_set('session.save_path', 'tcp:&#47;&#47;192.168.0.240:11211');<&#47;p></p>
<p>以下用正常的方式使用session，呵呵，简单吧！如果有更多的服务器，用逗号分隔即可。<&#47;p></p>
<p>&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; ini_set('session.save_path', 'tcp:&#47;&#47;192.168.0.240:11211,tcp:&#47;&#47;192.168.0.241:11211');<&#47;p></p>
<p>还可以带上参数，这些参数和Memcache::addServer()保持一致：<&#47;p></p>
<p>&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; ini_set('session.save_path', 'tcp:&#47;&#47;192.168.0.240:11211?persistent=1&amp;weight=1&amp;timeout=1&amp;retry_interval=15');<&#47;p></p>
<p>更新：<&#47;p></p>
<p>还可以把tcp换成udp，以得到更好的效率，更低的资源消耗：<&#47;p></p>
<p>&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; ini_set('session.save_path', 'udp:&#47;&#47;192.168.0.240:11211,tcp:&#47;&#47;192.168.0.241:11211');<&#47;p></p>
