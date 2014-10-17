---
layout: post
status: publish
published: true
title: 解决netstat中TIME_WAIT过多的问题
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 583
wordpress_url: http://blog.eaxi.com/?p=583
date: !binary |-
  MjAxMS0wMi0xNCAxNzo1NjoyNiArMDgwMA==
date_gmt: !binary |-
  MjAxMS0wMi0xNCAwOTo1NjoyNiArMDgwMA==
categories:
- 服务器
tags:
- linux
- tcp&#47;ip
comments: []
---
<p>调节内核参数：<br />
net.ipv4.tcp_tw_reuse = 1<br />
net.ipv4.tcp_fin_timeout = 30</p>
<p>如果，你的服务器，和所有可能的客户，都不处于NAT环境，还可以打开<br />
net.ipv4.tcp_tw_recycle = 1</p>
<p>这里要注意一点，普通公网的机器不能起用回收，否则会导致问题。<br />
参考：<br />
http:&#47;&#47;zhangle.is-a-geek.org&#47;2010&#47;11&#47;tcp_tw_recycle%E5%92%8Cnat&#47; </p>
