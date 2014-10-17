---
layout: post
status: publish
published: true
title: 统计一个目录下的文件数
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: ! "<p>※ 来源:&middot;水木社区 <a target=\"_blank\" href=\"http://newsmth.net/\">http://newsmth.net</a>&middot;[FROM:
  218.247.129.*]</p>\r\n<p>发信人: nwn (Lie), 信区: DOS<br />\r\n标 &nbsp;题: Re: 如何用DOS命令，获取一个目录下的文件数目？<br
  />\r\n发信站: 水木社区 (Fri Mar &nbsp;9 09:54:55 2007), 站内</p>"
wordpress_id: 155
date: !binary |-
  MjAwNy0wOC0xMyAxODoyMTo1MSArMDgwMA==
date_gmt: !binary |-
  MjAwNy0wOC0xMyAxMDoyMTo1MSArMDgwMA==
categories:
- 脚本语言
tags:
- linux
comments: []
---
<p>※ 来源:&middot;水木社区 <a target="_blank" href="http:&#47;&#47;newsmth.net&#47;">http:&#47;&#47;newsmth.net<&#47;a>&middot;[FROM: 218.247.129.*]<&#47;p></p>
<p>发信人: nwn (Lie), 信区: DOS<br &#47;><br />
标 &nbsp;题: Re: 如何用DOS命令，获取一个目录下的文件数目？<br &#47;><br />
发信站: 水木社区 (Fri Mar &nbsp;9 09:54:55 2007), 站内<br &#47;><br />
<br &#47;><br />
<font style="background-color: rgb(0,0,0)" color="#00ff00">dir &#47;b | find &#47;v &#47;c "$$$$" > 1.log<br &#47;><br />
<&#47;font>该结果统计当前目录下的文件和目录数。<br &#47;><br />
<br &#47;><br />
如果只需要文件，使用<font style="background-color: rgb(0,0,0)" color="#00ff00"> dir &#47;b &#47;a-d | find &#47;v &#47;c "$$$$" >1.log<&#47;font><br &#47;><br />
<font color="#00ff00">--<br &#47;><br />
<&#47;font>※ 来源:&middot;水木社区 newsmth.net&middot;[FROM: 125.46.17.*]<&#47;p></p>
<p>今天去水木看到的.果然强.我来解释一下意思<&#47;p></p>
<p><font color="#ff0000"><strong>dir &#47;b<&#47;strong><&#47;font>&nbsp; 使用空格式(没有标题信息或摘要)。<&#47;p></p>
<p><font color="#ff0000"><strong>dir &#47;a-d<&#47;strong><&#47;font> &#47;a是显示具有指定属性的文件。d是目录,-d就是去掉目录<&#47;p></p>
<p><strong><font color="#ff0000">| <&#47;font><&#47;strong>通道符,把dir &#47;b的输出当中后面find的输入<&#47;p></p>
<p><font color="#ff0000"><strong>find <&#47;strong><&#47;font><&#47;p></p>
<p><font color="#ff0000"><strong>&#47;v<&#47;strong><&#47;font> 显示所有未包含指定字符串的行。<&#47;p></p>
<p><font color="#ff0000"><strong>&#47;c<&#47;strong><&#47;font> 仅显示包含字符串的行数<&#47;p></p>
<p><font color="#ff0000"><strong>"$$$$"<&#47;strong><&#47;font> 特殊字符,一般文件中都没这个字符,不过可以用$$$$来命名文件夹,所以我建议用冒号,这个不能当作文件夹或者文件的名字.<&#47;p></p>
<p><font color="#ff0000"><strong>><&#47;strong><&#47;font> 输出到<&#47;p></p>
<p><font color="#ff0000"><strong>1.log<&#47;strong><&#47;font>&nbsp; 文件<&#47;p></p>
<p>&nbsp;<&#47;p></p>
<p>这个比较好:<font style="background-color: rgb(0,0,0)" color="#00ff00">dir &#47;b | find &#47;v &#47;c ":" > 1.log<&#47;font><&#47;p></p>
<p><font color="#00ff00">＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝<&#47;font><&#47;p></p>
<p>扩展：<&#47;p></p>
<p>包含子目录：<&#47;p></p>
<p>&nbsp;<&#47;p></p>
<div class="codeText">
<div class="codeHead">C++代码<&#47;div></p>
<ol class="dp-cpp">
<li class="alt"><span><span>tree&nbsp;&#47;F&nbsp;|&nbsp;find&nbsp;&#47;c&nbsp;<&#47;span><span class="string">"."<&#47;span><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><span class="comment">&#47;&#47;&nbsp;带点的文件<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>tree&nbsp;&#47;F&nbsp;|&nbsp;find&nbsp;&#47;v&nbsp;&#47;c&nbsp;<span class="string">"&#47;"<&#47;span><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><span class="comment">&#47;&#47;&nbsp;&nbsp;&#47;是文件命名时禁止使用的，统计全部文件<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p>Linux 下：<&#47;p></p>
<p>&nbsp;<&#47;p></p>
<p>&nbsp;<&#47;p></p>
<div class="codeText">
<div class="codeHead">C++代码<&#47;div></p>
<ol class="dp-cpp">
<li class="alt"><span><span class="preprocessor">#&nbsp;ls&nbsp;-l&nbsp;*&nbsp;|grep&nbsp;"^-"|wc&nbsp;-l&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#47;&#47;&nbsp;to&nbsp;count&nbsp;files<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="preprocessor">#&nbsp;ls&nbsp;-l&nbsp;*&nbsp;|grep&nbsp;"^d"|wc&nbsp;-l&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#47;&#47;&nbsp;to&nbsp;count&nbsp;dir<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p>Linux，包括子目录<&#47;p></p>
<p>&nbsp;<&#47;p></p>
<p>&nbsp;<&#47;p></p>
<div class="codeText">
<div class="codeHead">C++代码<&#47;div></p>
<ol class="dp-cpp">
<li class="alt"><span><span class="preprocessor">#&nbsp;ls&nbsp;-lR&nbsp;*&nbsp;|grep&nbsp;"^-"|wc&nbsp;-l&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#47;&#47;&nbsp;to&nbsp;count&nbsp;files&nbsp;&nbsp;<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="preprocessor">#&nbsp;ls&nbsp;-lR&nbsp;*&nbsp;|grep&nbsp;"^d"|wc&nbsp;-l&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#47;&#47;&nbsp;to&nbsp;count&nbsp;dir&nbsp;&nbsp;<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p>&nbsp;<&#47;p></p>
