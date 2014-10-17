---
layout: post
status: publish
published: true
title: 用telnet测试memcached服务器
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>linux下最方便的memcached测试方法了，可以检查缓存服务器是否工作正常。</p>
wordpress_id: 230
date: !binary |-
  MjAwOS0wNi0yOSAxNDoxNDowMyArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wNi0yOSAwNjoxNDowMyArMDgwMA==
categories:
- 服务器
tags:
- memcached
comments: []
---
<p>检查telnet程序是否可用：which telnet<&#47;p></p>
<p>如果没有安装，则安装之：aptitude install telnet<&#47;p></p>
<p>开始测试：<&#47;p></p>
<p>dev-server:~# telnet 192.168.0.240 11211<br &#47;><br />
Trying 192.168.0.240...<br &#47;><br />
Connected to 192.168.0.240.<br &#47;><br />
Escape character is '^]'.<br &#47;><br />
<span style="font-size: large;"><span style="font-family: Tahoma;">set key1 0 60 9<&#47;span><&#47;span><br &#47;><br />
seaprince<br &#47;><br />
STORED<br &#47;><br />
<span style="font-family: Tahoma;"><span style="font-size: large;">get key1<&#47;span><&#47;span><br &#47;><br />
VALUE key1 0 9<br &#47;><br />
seaprince<br &#47;><br />
END<br &#47;><br />
<span style="font-size: large;"><span style="font-family: Tahoma;">stats<&#47;span><&#47;span><br &#47;><br />
STAT pid 2557<br &#47;><br />
STAT uptime 249422<br &#47;><br />
STAT time 1246175982<br &#47;><br />
STAT version 1.2.2<br &#47;><br />
STAT pointer_size 32<br &#47;><br />
STAT rusage_user 0.008000<br &#47;><br />
STAT rusage_system 0.004000<br &#47;><br />
STAT curr_items 2<br &#47;><br />
STAT total_items 24<br &#47;><br />
STAT bytes 121<br &#47;><br />
STAT curr_connections 1<br &#47;><br />
STAT total_connections 30<br &#47;><br />
STAT connection_structures 2<br &#47;><br />
STAT cmd_get 26<br &#47;><br />
STAT cmd_set 24<br &#47;><br />
STAT get_hits 21<br &#47;><br />
STAT get_misses 5<br &#47;><br />
STAT evictions 0<br &#47;><br />
STAT bytes_read 3021<br &#47;><br />
STAT bytes_written 2886<br &#47;><br />
STAT limit_maxbytes 67108864<br &#47;><br />
STAT threads 1<br &#47;><br />
END<br &#47;><br />
<span style="font-size: large;"><span style="font-family: Tahoma;">quit<&#47;span><&#47;span><br &#47;><br />
Connection closed by foreign host.<br &#47;><br />
dev-server:~#<&#47;p></p>
<p>整数操作：<&#47;p></p>
<p>dev-server:~# telnet 192.168.0.240 11211<br &#47;><br />
Trying 192.168.0.240...<br &#47;><br />
Connected to 192.168.0.240.<br &#47;><br />
Escape character is '^]'.<br &#47;><br />
get key1<br &#47;><br />
END<br &#47;><br />
<span style="font-size: large;"><span style="font-family: Tahoma;">set key1 0 3600 3 123<&#47;span><&#47;span><br &#47;><br />
123<br &#47;><br />
STORED<br &#47;><br />
<span style="font-size: large;"><span style="font-family: Tahoma;">incr key1 5<&#47;span><&#47;span><br &#47;><br />
128<br &#47;><br />
<span style="font-size: large;"><span style="font-family: Tahoma;">decr key1 5<&#47;span><&#47;span><br &#47;><br />
123<br &#47;><br />
<span style="font-family: Tahoma;"><span style="font-size: large;">delete key1<&#47;span><&#47;span><br &#47;><br />
DELETED<br &#47;><br />
get key1<br &#47;><br />
END<br &#47;><br />
<span style="font-size: large;"><span style="font-family: Tahoma;">quit<&#47;span><&#47;span><br &#47;><br />
Connection closed by foreign host.<br &#47;><br />
dev-server:~#<&#47;p></p>
<p>高亮的是需要输入的命令。跟随的是返回。<&#47;p></p>
<p>参考：<a href="http:&#47;&#47;lists.danga.com&#47;pipermail&#47;memcached&#47;2005-April&#47;001332.html">http:&#47;&#47;lists.danga.com&#47;pipermail&#47;memcached&#47;2005-April&#47;001332.html<&#47;a><&#47;p></p>
<p>&nbsp;<&#47;p></p>
