---
layout: post
status: publish
published: true
title: 玩PHP源文件－把LOGO的gif文件转成.h文件中的数据
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 173
date: !binary |-
  MjAwOC0wMS0xNiAwODo1MjoxOCArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMS0xNiAwMDo1MjoxOCArMDgwMA==
categories:
- 脚本语言
tags:
- php
comments: []
---
<div class="codeText">
<div class="codeHead">PHP代码<&#47;div></p>
<ol class="dp-c" start="1">
<li class="alt"><span><span><?php&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="comment">&#47;&#47;&nbsp;将GIF转换为C语言中的H文件<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><span class="vars">$filename<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="string">"logo.gif"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="vars">$fp<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="func">fopen<&#47;span><span>(<&#47;span><span class="vars">$filename<&#47;span><span>,&nbsp;<&#47;span><span class="string">"rb"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><span class="vars">$buffer<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="func">fread<&#47;span><span>(<&#47;span><span class="vars">$fp<&#47;span><span>,&nbsp;<&#47;span><span class="func">filesize<&#47;span><span>(<&#47;span><span class="vars">$filename<&#47;span><span>));&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>fclose(<span class="vars">$fp<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><span class="vars">$len<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="func">strlen<&#47;span><span>(<&#47;span><span class="vars">$buffer<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="vars">$fp<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="func">fopen<&#47;span><span>(<&#47;span><span class="string">"mylogo.h"<&#47;span><span>,&nbsp;<&#47;span><span class="string">"wb"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>fwrite(<span class="vars">$fp<&#47;span><span>,&nbsp;<&#47;span><span class="string">"unsigned&nbsp;char&nbsp;php_logo[]&nbsp;=&nbsp;{"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="keyword">for<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$i<&#47;span><span>=0;&nbsp;<&#47;span><span class="vars">$i<&#47;span><span><=<&#47;span><span class="vars">$len<&#47;span><span>;&nbsp;<&#47;span><span class="vars">$i<&#47;span><span>++)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>(<&#47;span><span class="vars">$i<&#47;span><span>&nbsp;%&nbsp;10&nbsp;==&nbsp;0)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fwrite(<span class="vars">$fp<&#47;span><span>,&nbsp;<&#47;span><span class="string">"\n\t\t"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>(<&#47;span><span class="vars">$i<&#47;span><span>&nbsp;==&nbsp;<&#47;span><span class="vars">$len<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$str<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="func">str_pad<&#47;span><span>(ord(<&#47;span><span class="func">substr<&#47;span><span>(<&#47;span><span class="vars">$buffer<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$i<&#47;span><span>,&nbsp;1)),&nbsp;3,&nbsp;<&#47;span><span class="string">"&nbsp;"<&#47;span><span>,&nbsp;STR_PAD_LEFT);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$str<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="func">str_pad<&#47;span><span>(ord(<&#47;span><span class="func">substr<&#47;span><span>(<&#47;span><span class="vars">$buffer<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$i<&#47;span><span>,&nbsp;1)),&nbsp;3,&nbsp;<&#47;span><span class="string">"&nbsp;"<&#47;span><span>,&nbsp;STR_PAD_LEFT)&nbsp;.&nbsp;<&#47;span><span class="string">",&nbsp;"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;fwrite(<span class="vars">$fp<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$str<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>fwrite(<span class="vars">$fp<&#47;span><span>,&nbsp;<&#47;span><span class="string">"&nbsp;};\n"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>fclose(<span class="vars">$fp<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>?>&nbsp;&nbsp;<&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
