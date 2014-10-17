---
layout: post
status: publish
published: true
title: php interface
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 172
date: !binary |-
  MjAwOC0wMS0xNiAwODo1MDowNiArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMS0xNiAwMDo1MDowNiArMDgwMA==
categories:
- 脚本语言
tags:
- php
comments: []
---
<div class="codeText">
<div class="codeHead">PHP代码<&#47;div></p>
<ol start="1" class="dp-c">
<li class="alt"><span><span><?php&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="keyword">interface<&#47;span><span>&nbsp;IA&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">public<&#47;span><span>&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>&nbsp;a();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">public<&#47;span><span>&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>&nbsp;b();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="keyword">class<&#47;span><span>&nbsp;Test&nbsp;<&#47;span><span class="keyword">implements<&#47;span><span>&nbsp;IA&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">public<&#47;span><span>&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>&nbsp;a()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="func">echo<&#47;span><span>&nbsp;<&#47;span><span class="string">'aa'<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">public<&#47;span><span>&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>&nbsp;b()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="func">echo<&#47;span><span>&nbsp;<&#47;span><span class="string">'bb'<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">public<&#47;span><span>&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>&nbsp;c()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="func">echo<&#47;span><span>&nbsp;<&#47;span><span class="string">'cc'<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="keyword">class<&#47;span><span>&nbsp;Test2&nbsp;<&#47;span><span class="keyword">extends<&#47;span><span>&nbsp;Test&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">public<&#47;span><span>&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>&nbsp;a()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="func">echo<&#47;span><span>&nbsp;<&#47;span><span class="string">'aaaa!!'<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="vars">$o<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="keyword">new<&#47;span><span>&nbsp;Test2();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="vars">$o<&#47;span><span>->a();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>?>&nbsp;&nbsp;<&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
