---
layout: post
status: publish
published: true
title: 国外的PHP程序员面试题目一解
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 180
date: !binary |-
  MjAwOC0wMS0xNiAwOToyOTowOSArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMS0xNiAwMToyOTowOSArMDgwMA==
categories:
- 脚本语言
tags:
- php
- yahoo
comments: []
---
<p><font size="2" face="Courier New">一朋友说是国外的PHP程序员面试题目，解之：<br &#47;><br />
<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">题目三：<&#47;font> <br &#47;><br />
<font size="2" face="Courier New">Create a class, Test3, with the following behavior:<br &#47;><br />
The class must take a string of the format&nbsp; <br &#47;><br />
name1=value1:name2=value2:name3=value3 consisting of name and value&nbsp; <br &#47;><br />
pairs, separated by the : symbol. I must be able to enter as many&nbsp; <br &#47;><br />
pairs as I like when I call the class, the only limit is that each&nbsp; <br &#47;><br />
pair is formated as name=value and multiple pairs are separated by&nbsp; <br &#47;><br />
the : symbol.<br &#47;><br />
When an object of the class is created it must end up with a variable&nbsp; <br &#47;><br />
for each name=value pair. The name of the variable must be the same&nbsp; <br &#47;><br />
as the name part of the substring and the value of the variable must&nbsp; <br &#47;><br />
be the same as the value part of the substring. For example:<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">creating an object with new Test3("firstname=david:lastname=smith")&nbsp; <br &#47;><br />
must create variables within the class:<br &#47;><br />
$firstname = "david";<br &#47;><br />
$lastname = "smith";<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">and new Test3("food1=pasta:food2=chocolate") must create variables&nbsp; <br &#47;><br />
within the class:<br &#47;><br />
$food1 = "pasta";<br &#47;><br />
$food2 = "chocolate";<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">I should be able to use any variable names and values provided they&nbsp; <br &#47;><br />
do not include the symbols : or =<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">You should then write a function print_all that will print the all&nbsp; <br &#47;><br />
the names of the defined variables in the class along with their&nbsp; <br &#47;><br />
values in the following format:<br &#47;><br />
Variable 1 - Name = (whatever the actual name is), Value = (whatever&nbsp; <br &#47;><br />
the actual value is)<br &#47;><br />
Variable 2 - Name = (whatever the actual name is), Value = (whatever&nbsp; <br &#47;><br />
the actual value is)<br &#47;><br />
Variable 3 - Name = (whatever the actual name is), Value = (whatever&nbsp; <br &#47;><br />
the actual value is)<br &#47;><br />
and so on until all the variables are listed.<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">The last line of output of the print_all function should be the words&nbsp; <br &#47;><br />
"The original input was " followed by a string that is an exact&nbsp; <br &#47;><br />
representation of the string parameter supplied when creating the&nbsp; <br &#47;><br />
class object.<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">For example, if you did new Test3("firstname=david:lastname=smith")&nbsp; <br &#47;><br />
then the print_all function should output:<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">Variable 1 - Name = firstname, Value = david<br &#47;><br />
Variable 2 - Name = lastname, Value = smith<br &#47;><br />
The original imput was ("firstname=david:lastname=smith")<&#47;font><&#47;p></p>
<p><font size="2" face="Courier New">This must work for any input string that has the correct format and&nbsp; <br &#47;><br />
you may not store the complete input string or directly output it to&nbsp; <br &#47;><br />
produce the last line of the print_all function output as that would&nbsp; <br &#47;><br />
be too easy.<br &#47;><br />
<&#47;font><&#47;p></p>
<div class="codeText">
<div class="codeHead">PHP代码<&#47;div></p>
<ol start="1" class="dp-c">
<li class="alt"><span><span><?php&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="keyword">class<&#47;span><span>&nbsp;Test3&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">private<&#47;span><span>&nbsp;<&#47;span><span class="vars">$keys<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="keyword">array<&#47;span><span>();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;__construct(<&#47;span><span class="vars">$args<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$this<&#47;span><span>->Test3(<&#47;span><span class="vars">$args<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;Test3(<&#47;span><span class="vars">$args<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$arr<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="func">explode<&#47;span><span>(<&#47;span><span class="string">":"<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$args<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">foreach<&#47;span><span>(<&#47;span><span class="vars">$arr<&#47;span><span>&nbsp;<&#47;span><span class="keyword">as<&#47;span><span>&nbsp;<&#47;span><span class="vars">$v<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$varr<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="func">explode<&#47;span><span>(<&#47;span><span class="string">"="<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$v<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$key<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="vars">$varr<&#47;span><span>[0];&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$value<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="vars">$varr<&#47;span><span>[1];&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$this<&#47;span><span>-><&#47;span><span class="vars">$key<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="vars">$value<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="func">array_push<&#47;span><span>(<&#47;span><span class="vars">$this<&#47;span><span>->keys,&nbsp;<&#47;span><span class="vars">$key<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;print_all()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="vars">$ret<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="keyword">array<&#47;span><span>();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">foreach<&#47;span><span>(<&#47;span><span class="vars">$this<&#47;span><span>->keys&nbsp;<&#47;span><span class="keyword">as<&#47;span><span>&nbsp;<&#47;span><span class="vars">$key<&#47;span><span>)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="func">array_push<&#47;span><span>(<&#47;span><span class="vars">$ret<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$key<&#47;span><span>.<&#47;span><span class="string">"="<&#47;span><span>.<&#47;span><span class="vars">$this<&#47;span><span>-><&#47;span><span class="vars">$key<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;implode(<&#47;span><span class="string">":"<&#47;span><span>,&nbsp;<&#47;span><span class="vars">$ret<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="vars">$t<&#47;span><span>&nbsp;=&nbsp;<&#47;span><span class="keyword">new<&#47;span><span>&nbsp;Test3(<&#47;span><span class="string">"name=seaprince:name2=renothing"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>print_r(<span class="vars">$t<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>print&nbsp;<span class="vars">$t<&#47;span><span>->print_all();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>?>&nbsp;&nbsp;<&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p>&nbsp;<&#47;p></p>
