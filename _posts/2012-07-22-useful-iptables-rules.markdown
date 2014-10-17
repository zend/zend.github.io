---
layout: post
status: publish
published: true
title: 常用iptables语句
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 608
wordpress_url: http://blog.eaxi.com/?p=608
date: !binary |-
  MjAxMi0wNy0yMiAxNTowMzozOCArMDgwMA==
date_gmt: !binary |-
  MjAxMi0wNy0yMiAwNzowMzozOCArMDgwMA==
categories:
- 不想分类
tags:
- linux iptables
comments: []
---
<p>允许本机ping别人<br />
-A OUTPUT -p icmp --icmp-type echo-request -j ACCEPT<br />
-A INPUT -i eth0 -p icmp --icmp-type echo-reply -j ACCEPT</p>
<p>允许别人ping本机<br />
-A INPUT -i eth0 -p icmp --icmp-type echo-request -j ACCEPT<br />
-A OUTPUT -p icmp --icmp-type echo-reply -j ACCEPT</p>
<p>开放SSH<br />
-A INPUT -s 192.168.1.0&#47;255.255.255.0 -p tcp -m tcp --dport 36000 -j ACCEPT<br />
-A OUTPUT -d 192.168.1.0&#47;255.255.255.0 -p tcp -m tcp --sport 36000 -j ACCEPT</p>
<p>允许本机进行域名解析<br />
-A OUTPUT -p udp -m udp --dport 53 -j ACCEPT<br />
-A INPUT -p udp -m udp --sport 53 -j ACCEPT</p>
<p>如果这是一台DNS服务器<br />
-A INPUT -p udp -m udp --dport 53 -j ACCEPT<br />
-A OUTPUT -p udp -m udp --sport 53 -j ACCEPT</p>
<p>注，上面只是参数部分，完整的命令应该说是<br />
iptables -A OUTPUT -p udp -m udp --sport 53 -j ACCEPT<br />
以此类推。</p>
