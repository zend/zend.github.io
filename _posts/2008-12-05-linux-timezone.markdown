---
layout: post
status: publish
published: true
title: Linux 时区问题
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 224
date: !binary |-
  MjAwOC0xMi0wNSAxNDoyMTozMiArMDgwMA==
date_gmt: !binary |-
  MjAwOC0xMi0wNSAwNjoyMTozMiArMDgwMA==
categories:
- 服务器
tags:
- linux
comments:
- id: 989
  author: Seaprince
  author_email: seaprince@vip.qq.com
  author_url: http://seaprince.cn
  date: !binary |-
    MjAwOS0xMC0wNiAwMjo1OTo0MSArMDgwMA==
  date_gmt: !binary |-
    MjAwOS0xMC0wNSAxODo1OTo0MSArMDgwMA==
  content: ! 'pool.ntp.org


    中国国家授时中心： 210.72.145.44


    stdtime.gov.tw


    time-b.nist.gov


    香港天文台：stdtime.gov.hk


    time-a.nist.gov


    苹果的服务器：time.asia.apple.com


    time-a.nist.gov


    韩国的一级服务器： 58.73.137.250'
---
<div>安装完系统发现时间与现实时间相差＋8小时，经分析由以下产生。<&#47;div></p>
<div>我们在安装时选择的是上海，而centos5把bios时间认为是utc时间，所以＋8小时给我们。这个时候的bios的时间和软件的时间是不一致的。一个代表 utc&nbsp;一个代表我们设置的cst（＋8时区）。<&#47;div></p>
<div>我们要做的调整是：<&#47;div></p>
<div>1、vi &#47;etc&#47;sysconfig&#47;clock&nbsp;&nbsp;&nbsp;<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>ZONE="Asia&#47;Shanghai"<br &#47;><br />
UTC=false&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; （主要是这个选项，设置硬件时钟不是跟utc一致）<br &#47;><br />
ARC=false<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>2、linux的时区设置为&nbsp; 上海<&#47;div></p>
<div>ln -sf &#47;usr&#47;share&#47;zoneinfo&#47;Asia&#47;Shanghai &#47;etc&#47;localtime<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>3、对准时间<&#47;div></p>
<div><span lang="EN-US" style="font-size: 10.5pt; font-family: 'Times New Roman';">ntpdate 192.43.244.18<&#47;span><&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>4、设置硬件时间和软件时间的一致并校准<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>&#47;sbin&#47;hwclock --systohc<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>这样我们的linux软件和计算机硬件都是cst时间了－－并且是我们设置的上海时区<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div>有什么问题参考以下两篇文章：<&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div><a href="http:&#47;&#47;www.freelamp.com&#47;1003248387&#47;index_html">http:&#47;&#47;www.freelamp.com&#47;1003248387&#47;index_html<&#47;a><&#47;div></p>
<div>&nbsp;<&#47;div></p>
<div><a href="http:&#47;&#47;linux.vbird.org&#47;linux_server&#47;0440ntp.php">http:&#47;&#47;linux.vbird.org&#47;linux_server&#47;0440ntp.php<&#47;a><&#47;div></p>
<div>&nbsp;<&#47;div></p>
