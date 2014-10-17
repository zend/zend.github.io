---
layout: post
status: publish
published: true
title: 用apt-cacher-ng给自己的局域网搭建一个apt缓存
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 445
wordpress_url: http://seaprince.cn/%e7%bb%99%e8%87%aa%e5%b7%b1%e7%9a%84%e5%b1%80%e5%9f%9f%e7%bd%91%e6%90%ad%e5%bb%ba%e4%b8%80%e4%b8%aaapt%e7%bc%93%e5%ad%98/
date: !binary |-
  MjAwOS0wOC0xMiAxNTo0NjozMiArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wOC0xMiAwNzo0NjozMiArMDgwMA==
categories:
- 服务器
tags:
- debian
comments: []
---
<h3>前言<br />
<&#47;h3>
<p>由于内网机器较多，而且需要安装的软件也多数大同小异，所以说萌发了要搭建一个apt缓存的想法。<br />
<&#47;p>
<p>网上说apt-cacher-ng是个不错的选择，所以就下载试试。<br />
<&#47;p><br />
<h3>安装<br />
<&#47;h3>
<p>安装灰常简单：<br />
<&#47;p>
<p>aptitude update &amp;&amp; aptitude install apt-cacher-ng<br />
<&#47;p>
<p>安装完成。<br />
<&#47;p><br />
<h3>简介<br />
<&#47;h3>
<p>软件的配置文件在&#47;etc&#47;apt-cacher-ng&#47;acng.conf<br />
<&#47;p>
<p>缓存目录在&#47;var&#47;cache&#47;apt-cacher-ng<br />
<&#47;p>
<p>日志目录在&#47;var&#47;log&#47;apt-cacher-ng<br />
<&#47;p>
<p>它还提供了一个web接口，默认端口是3142<br />
<&#47;p>
<p>可以访问http:&#47;&#47;192.168.0.251:3142&#47; 来查看。<br />
<&#47;p><br />
<h3>使用<br />
<&#47;h3>
<p>当你在web界面访问它的时候，你就会看到很详细的指引。<br />
<&#47;p>
<p>如果看不懂英文，就按我说的去做吧：<br />
<&#47;p>
<p>在其他debian机器上，用root登录，执行：<br />
<&#47;p>
<p>echo 'Acquire::http { Proxy "http:&#47;&#47;[::ffff:192.168.0.251]:3142";};' > &#47;etc&#47;apt&#47;apt.conf.d&#47;15apt-cacher-ng<br />
<&#47;p>
<p>如果你apt缓存机器本身也想使用这个缓存，那么，也按上面的去做吧。<br />
<&#47;p>
<p>呵呵，现在如果你在某一台机器下载过一个东西，在另外一台就可以直接从缓存读取啦，速度那个没得说。再快的外网也快不过内网吧。<br />
<&#47;p>
<p>--EOF--<&#47;p></p>
