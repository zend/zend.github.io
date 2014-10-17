---
layout: post
status: publish
published: true
title: PHP的改进型urlencode，全部编码包括英文字符
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 179
date: !binary |-
  MjAwOC0wMS0xNiAwOToyMzoyMCArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMS0xNiAwMToyMzoyMCArMDgwMA==
categories:
- 脚本语言
tags:
- php
comments:
- id: 65
  author: 跑跑卡丁车
  author_email: anony@mo.us
  author_url: http://www.paokart.cn
  date: !binary |-
    MjAwOC0wMi0wMSAxMTozMzozMiArMDgwMA==
  date_gmt: !binary |-
    MjAwOC0wMi0wMSAxMTozMzozMiArMDgwMA==
  content: 学习了。。
- id: 1147
  author: 浪静无声
  author_email: 87015959@qq.com
  author_url: ''
  date: !binary |-
    MjAxMi0xMi0yOCAxMzoyNDo0MiArMDgwMA==
  date_gmt: !binary |-
    MjAxMi0xMi0yOCAwNToyNDo0MiArMDgwMA==
  content: 学习了，真的受用，大爱博主~
---
<div class="codeText">
<div class="codeHead">PHP代码<&#47;div></p>
<ol start="1" class="dp-c">
<li class="alt"><span><span><?&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="keyword">function<&#47;span><span>&nbsp;pureencode(<&#47;span><span class="vars">$str<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$ret<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="string">""<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for<&#47;span><span>(<&#47;span><span class="vars">$i<&#47;span><span>=0;&nbsp;<&#47;span><span class="vars">$i<&#47;span><span><<&#47;span><span class="func">strlen<&#47;span><span>(<&#47;span><span class="vars">$str<&#47;span><span>);&nbsp;<&#47;span><span class="vars">$i<&#47;span><span>++)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$ret<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"%"<&#47;span><span>&nbsp;.&nbsp;<&#47;span><span class="func">dechex<&#47;span><span>(ord(<&#47;span><span class="vars">$str<&#47;span><span>[<&#47;span><span class="vars">$i<&#47;span><span>]));&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;<&#47;span><span class="vars">$ret<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="func">echo<&#47;span><span>&nbsp;pureencode(<&#47;span><span class="string">'abcdef'<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>print_r(<span class="vars">$_GET<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>?>&nbsp;&nbsp;<&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
