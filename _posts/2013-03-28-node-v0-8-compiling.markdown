---
layout: post
status: publish
published: true
title: node v0.8+ compiling
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 623
wordpress_url: http://blog.eaxi.com/?p=623
date: !binary |-
  MjAxMy0wMy0yOCAxNDo1NzoyMyArMDgwMA==
date_gmt: !binary |-
  MjAxMy0wMy0yOCAwNjo1NzoyMyArMDgwMA==
categories:
- 不想分类
tags:
- node
- nodejs
- make
comments:
- id: 1151
  author: simon
  author_email: xugaofan@foxmail.com
  author_url: ''
  date: !binary |-
    MjAxMy0wOC0zMCAxMzoxMTozMiArMDgwMA==
  date_gmt: !binary |-
    MjAxMy0wOC0zMCAwNToxMTozMiArMDgwMA==
  content: 泪流满面，被这问题折腾了一天。呜呜呜
- id: 1271
  author: 祈祷幸福
  author_email: babyliner1026@gmail.com
  author_url: ''
  date: !binary |-
    MjAxMy0xMC0yMSAxODoyMzoxOCArMDgwMA==
  date_gmt: !binary |-
    MjAxMy0xMC0yMSAxMDoyMzoxOCArMDgwMA==
  content: 我这边是另外个原因：gcc有两个版本共存，$PATH虽然变成了新版，但是CC -v还是旧版的。。设置一下CC=&#47;path&#47;to&#47;gcc就好了。。。
---
<p> To build:</p>
<p>Prerequisites (Unix only):</p>
<p>* Python 2.6 or 2.7<br />
* GNU Make 3.81 or newer<br />
* libexecinfo (FreeBSD and OpenBSD only)</p>
<p>如果不想升级系统make版本，可以在其他目录安装一个，再alias过去。</p>
<p>常用错误：<br />
out&#47;Release&#47;linker.lock: No such file or directory<br />
解决方法：<br />
export FLOCK<br />
export LINK=g++</p>
