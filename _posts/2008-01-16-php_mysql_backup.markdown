---
layout: post
status: publish
published: true
title: mysql 备份的PHP脚本
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 174
date: !binary |-
  MjAwOC0wMS0xNiAwODo1NDozNCArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMS0xNiAwMDo1NDozNCArMDgwMA==
categories:
- 脚本语言
tags:
- php
- mysql
comments: []
---
<div class="codeText">
<div class="codeHead">PHP代码<&#47;div></p>
<ol class="dp-c" start="1">
<li class="alt"><span><span><?php&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="comment">&#47;&#47;&nbsp;备份数据库<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;sqldumptable(<&#47;span><span class="vars">$table<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$fp<&#47;span><span>=0)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="string">"DROP&nbsp;TABLE&nbsp;IF&nbsp;EXISTS&nbsp;`$table`;\n"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"CREATE&nbsp;TABLE&nbsp;`$table`&nbsp;(\n"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$firstfield<&#47;span><span>=1;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$fields<&#47;span><span>&nbsp;=&nbsp;mysql_query(<&#47;span><span class="string">"SHOW&nbsp;FIELDS&nbsp;FROM&nbsp;`$table`"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">while<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$field<&#47;span><span>&nbsp;=&nbsp;mysql_fetch_array(<&#47;span><span class="vars">$fields<&#47;span><span>))&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(!<&#47;span><span class="vars">$firstfield<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">",\n"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$firstfield<&#47;span><span>=0;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"&nbsp;&nbsp;&nbsp;`$field[Field]`&nbsp;$field[Type]"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(!<&#47;span><span class="keyword">empty<&#47;span><span class="func">empty<&#47;span><span>(<&#47;span><span class="vars">$field<&#47;span><span>[<&#47;span><span class="string">"Default"<&#47;span><span>]))&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>(<&#47;span><span class="vars">$field<&#47;span><span>[<&#47;span><span class="string">'Default'<&#47;span><span>]!=<&#47;span><span class="string">'CURRENT_TIMESTAMP'<&#47;span><span>&nbsp;)&nbsp;<&#47;span><span class="vars">$field<&#47;span><span>[<&#47;span><span class="string">'Default'<&#47;span><span>]&nbsp;=&nbsp;<&#47;span><span class="string">"'{$field['Default']}'"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"&nbsp;DEFAULT&nbsp;$field[Default]"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$field<&#47;span><span>[<&#47;span><span class="string">'Null'<&#47;span><span>]&nbsp;!=&nbsp;<&#47;span><span class="string">"YES"<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"&nbsp;NOT&nbsp;NULL"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$field<&#47;span><span>[<&#47;span><span class="string">'Extra'<&#47;span><span>]&nbsp;!=&nbsp;<&#47;span><span class="string">""<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"&nbsp;$field[Extra]"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mysql_free_result(<span class="vars">$fields<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$keys<&#47;span><span>&nbsp;=&nbsp;mysql_query(<&#47;span><span class="string">"SHOW&nbsp;KEYS&nbsp;FROM&nbsp;`$table`"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">while<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$key<&#47;span><span>&nbsp;=&nbsp;mysql_fetch_array(<&#47;span><span class="vars">$keys<&#47;span><span>))&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$kname<&#47;span><span>=<&#47;span><span class="vars">$key<&#47;span><span>[<&#47;span><span class="string">'Key_name'<&#47;span><span>];&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$kname<&#47;span><span>&nbsp;!=&nbsp;<&#47;span><span class="string">"PRIMARY"<&#47;span><span>&nbsp;<&#47;span><span class="keyword">and<&#47;span><span>&nbsp;<&#47;span><span class="vars">$key<&#47;span><span>[<&#47;span><span class="string">'Non_unique'<&#47;span><span>]&nbsp;==&nbsp;0)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$kname<&#47;span><span>=<&#47;span><span class="string">"UNIQUE|$kname"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>(!<&#47;span><span class="func">is_array<&#47;span><span>(<&#47;span><span class="vars">$index<&#47;span><span>[<&#47;span><span class="vars">$kname<&#47;span><span>]))&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$index<&#47;span><span>[<&#47;span><span class="vars">$kname<&#47;span><span>]&nbsp;=&nbsp;<&#47;span><span class="keyword">array<&#47;span><span>();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$index<&#47;span><span>[<&#47;span><span class="vars">$kname<&#47;span><span>][]&nbsp;=&nbsp;<&#47;span><span class="vars">$key<&#47;span><span>[<&#47;span><span class="string">'Column_name'<&#47;span><span>];&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mysql_free_result(<span class="vars">$keys<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">while<&#47;span><span>(list(<&#47;span><span class="vars">$kname<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$columns<&#47;span><span>)&nbsp;=&nbsp;@each(<&#47;span><span class="vars">$index<&#47;span><span>))&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">",\n"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$colnames<&#47;span><span>=implode(<&#47;span><span class="vars">$columns<&#47;span><span>,<&#47;span><span class="string">","<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$kname<&#47;span><span>&nbsp;==&nbsp;<&#47;span><span class="string">"PRIMARY"<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"&nbsp;&nbsp;&nbsp;PRIMARY&nbsp;KEY&nbsp;($colnames)"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(<&#47;span><span class="func">substr<&#47;span><span>(<&#47;span><span class="vars">$kname<&#47;span><span>,0,6)&nbsp;==&nbsp;<&#47;span><span class="string">"UNIQUE"<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$kname<&#47;span><span>=<&#47;span><span class="func">substr<&#47;span><span>(<&#47;span><span class="vars">$kname<&#47;span><span>,7);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"&nbsp;&nbsp;&nbsp;KEY&nbsp;$kname&nbsp;($colnames)"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"\n);\n\n"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$fp<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fwrite(<span class="vars">$fp<&#47;span><span>,<&#47;span><span class="vars">$tabledump<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="func">echo<&#47;span><span>&nbsp;<&#47;span><span class="vars">$tabledump<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$rows<&#47;span><span>&nbsp;=&nbsp;mysql_query(<&#47;span><span class="string">"SELECT&nbsp;*&nbsp;FROM&nbsp;`$table`"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$numfields<&#47;span><span>&nbsp;=&nbsp;mysql_num_fields(<&#47;span><span class="vars">$rows<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">while<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$row<&#47;span><span>&nbsp;=&nbsp;mysql_fetch_array(<&#47;span><span class="vars">$rows<&#47;span><span>))&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="string">"INSERT&nbsp;INTO&nbsp;`$table`&nbsp;VALUES("<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$fieldcounter<&#47;span><span>=-1;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$firstfield<&#47;span><span>=1;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">while<&#47;span><span>&nbsp;(++<&#47;span><span class="vars">$fieldcounter<&#47;span><span><<&#47;span><span class="vars">$numfields<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(!<&#47;span><span class="vars">$firstfield<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>.=<&#47;span><span class="string">",&nbsp;"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$firstfield<&#47;span><span>=0;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(!isset(<&#47;span><span class="vars">$row<&#47;span><span>[<&#47;span><span class="vars">$fieldcounter<&#47;span><span>]))&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"NULL"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">"'"<&#47;span><span>.mysql_escape_string(<&#47;span><span class="vars">$row<&#47;span><span>[<&#47;span><span class="vars">$fieldcounter<&#47;span><span>]).<&#47;span><span class="string">"'"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$tabledump<&#47;span><span>&nbsp;.=&nbsp;<&#47;span><span class="string">");\n"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(<&#47;span><span class="vars">$fp<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fwrite(<span class="vars">$fp<&#47;span><span>,<&#47;span><span class="vars">$tabledump<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="func">echo<&#47;span><span>&nbsp;<&#47;span><span class="vars">$tabledump<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mysql_free_result(<span class="vars">$rows<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fwrite(<span class="vars">$fp<&#47;span><span>,<&#47;span><span class="string">"\n\n\n"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>?>&nbsp;&nbsp;<&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
