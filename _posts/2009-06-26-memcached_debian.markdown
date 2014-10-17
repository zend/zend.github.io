---
layout: post
status: publish
published: true
title: debian下memcached的安装与使用
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>memcached在debian系统下的安装，使用方法。</p>
wordpress_id: 228
date: !binary |-
  MjAwOS0wNi0yNiAxNzowOTowOCArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wNi0yNiAwOTowOTowOCArMDgwMA==
categories:
- 服务器
tags:
- memcached
- debian
comments: []
---
<p>下载并安装memcached:<&#47;p></p>
<p>aptitude install memcached<&#47;p></p>
<p>安装成功后，本机可以正常连接，但局域网内依然不行。后发现是配置文件的问题：<&#47;p></p>
<p>vim &#47;etc&#47;memcached.conf<&#47;p></p>
<p>将-l 127.0.0.1的一行注释掉。因为这一行说明了只监听本地的11211端口，局域网当然无法连接。<&#47;p></p>
<p>然后重启memcached：<&#47;p></p>
<p>&#47;etc&#47;init.d&#47;memcached restart<&#47;p></p>
<p>成功！<&#47;p></p>
<p>另附memcached简单测试方法和控制命令：<&#47;p></p>
<p>telnet 192.168.0.240 11211&nbsp;&nbsp;&nbsp;&nbsp; 测试连接是否正常<&#47;p></p>
<p>&#47;etc&#47;init.d&#47;memcached start&nbsp; 启动&nbsp;&nbsp;&nbsp; 同理，restart 重新启动，stop是停止。<&#47;p></p>
<p>&nbsp;<&#47;p></p>
