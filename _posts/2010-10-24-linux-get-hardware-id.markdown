---
layout: post
status: publish
published: true
title: Linux获取硬件标识
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 538
wordpress_url: http://blog.eaxi.com/?p=538
date: !binary |-
  MjAxMC0xMC0yNCAwMDoxMDoxNiArMDgwMA==
date_gmt: !binary |-
  MjAxMC0xMC0yMyAxNjoxMDoxNiArMDgwMA==
categories:
- 服务器
- C&#47;C++
tags: []
comments: []
---
<p>1. gethostid()</p>
<p>首先，unistd.h中有提供一个获取主机标识的函数： gethostid(); 可以返回一个以32位整数表示的标识符，它是由机器的IP经过移位后得到的。</p>
<p>long hostid = gethostid();</p>
<p>正因为这个hostid是由IP地址转换得来的，我们可以用它来快速获得当前机器的主IP：</p>
<p>如hostid为：AABBCCDD，则IP为 BB.AA.DD.CC，当然各个部分还得转换成二进制数。</p>
<p>2. Get harddisk Product ID</p>
<p>这步的关键是ioctl的使用。首先，以只读的方式打开硬盘设备，给ioctl的第一个参数传递fd, 第二个参数传递HDIO_GET_IDENTITY，第三个地址是out类型参数，给它一个struct hd_driveid的结构体指针即可。</p>
<p>ioctl(fd, HDIO_GET_IDENTITY, &amp;hid);</p>
<p>3. Get MAC address</p>
<p>MAC地址的获取也是通过ioctl。</p>
<p>4. Get CPU ID</p>
<p>这个就是汇编了。</p>
<p>见附件。</p>
<p><a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2010&#47;10&#47;mac.c">mac.c<&#47;a> <a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2010&#47;10&#47;ip.c">ip.c<&#47;a> <a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2010&#47;10&#47;hostid.c">hostid.c<&#47;a> <a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2010&#47;10&#47;cpuid.c">cpuid.c<&#47;a> <a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2010&#47;10&#47;disk.c">disk.c<&#47;a></p>
