---
layout: post
status: publish
published: true
title: Javascript中的prototype的一个简单例子
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 175
date: !binary |-
  MjAwOC0wMS0xNiAwODo1NzoxMSArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMS0xNiAwMDo1NzoxMSArMDgwMA==
categories:
- 脚本语言
tags:
- javascript
comments: []
---
<div class="codeText">
<div class="codeHead">XML&#47;HTML代码<&#47;div></p>
<ol class="dp-xml" start="1">
<li class="alt"><span><span><!DOCTYPE&nbsp;html&nbsp;PUBLIC&nbsp;"-&#47;&#47;W3C&#47;&#47;DTD&nbsp;XHTML&nbsp;1.0&nbsp;Transitional&#47;&#47;EN"&nbsp;"http:&#47;&#47;www.w3.org&#47;TR&#47;xhtml1&#47;DTD&#47;xhtml1-transitional.dtd"<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="tag"><<&#47;span><span class="tag-name">html<&#47;span><span>&nbsp;<&#47;span><span class="attribute">xmlns<&#47;span><span>=<&#47;span><span class="attribute-value">"http:&#47;&#47;www.w3.org&#47;1999&#47;xhtml"<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;<span class="tag"><<&#47;span><span class="tag-name">head<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<span class="tag"><<&#47;span><span class="tag-name">title<&#47;span><span class="tag">><&#47;span><span>&nbsp;new&nbsp;document&nbsp;<&#47;span><span class="tag"><&#47;<&#47;span><span class="tag-name">title<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<span class="tag"><<&#47;span><span class="tag-name">meta<&#47;span><span>&nbsp;<&#47;span><span class="attribute">name<&#47;span><span>=<&#47;span><span class="attribute-value">"generator"<&#47;span><span>&nbsp;<&#47;span><span class="attribute">content<&#47;span><span>=<&#47;span><span class="attribute-value">"editplus"<&#47;span><span>&nbsp;<&#47;span><span class="tag">&#47;><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<span class="tag"><<&#47;span><span class="tag-name">meta<&#47;span><span>&nbsp;<&#47;span><span class="attribute">name<&#47;span><span>=<&#47;span><span class="attribute-value">"author"<&#47;span><span>&nbsp;<&#47;span><span class="attribute">content<&#47;span><span>=<&#47;span><span class="attribute-value">""<&#47;span><span>&nbsp;<&#47;span><span class="tag">&#47;><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<span class="tag"><<&#47;span><span class="tag-name">meta<&#47;span><span>&nbsp;<&#47;span><span class="attribute">name<&#47;span><span>=<&#47;span><span class="attribute-value">"keywords"<&#47;span><span>&nbsp;<&#47;span><span class="attribute">content<&#47;span><span>=<&#47;span><span class="attribute-value">""<&#47;span><span>&nbsp;<&#47;span><span class="tag">&#47;><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<span class="tag"><<&#47;span><span class="tag-name">meta<&#47;span><span>&nbsp;<&#47;span><span class="attribute">name<&#47;span><span>=<&#47;span><span class="attribute-value">"description"<&#47;span><span>&nbsp;<&#47;span><span class="attribute">content<&#47;span><span>=<&#47;span><span class="attribute-value">""<&#47;span><span>&nbsp;<&#47;span><span class="tag">&#47;><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;<span class="tag"><&#47;<&#47;span><span class="tag-name">head<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;<span class="tag"><<&#47;span><span class="tag-name">body<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<span class="tag"><<&#47;span><span class="tag-name">script<&#47;span><span>&nbsp;<&#47;span><span class="attribute">type<&#47;span><span>=<&#47;span><span class="attribute-value">"text&#47;javascript"<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<!--&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;var&nbsp;<span class="attribute">call<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="attribute-value">function<&#47;span><span>&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#47;&#47;<span class="attribute">this.a<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="attribute-value">function<&#47;span><span>&nbsp;(a)&nbsp;{&nbsp;alert(a);&nbsp;};&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="attribute">this.num<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="attribute-value">134<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="attribute">call.prototype.a<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="attribute-value">function<&#47;span><span>&nbsp;(a)&nbsp;{&nbsp;alert(a);&nbsp;};&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;var&nbsp;<span class="attribute">v<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="attribute-value">new<&#47;span><span>&nbsp;call;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;v.a(v.num);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&#47;&#47;--<span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<span class="tag"><&#47;<&#47;span><span class="tag-name">script<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;<span class="tag"><&#47;<&#47;span><span class="tag-name">body<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="tag"><&#47;<&#47;span><span class="tag-name">html<&#47;span><span class="tag">><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
