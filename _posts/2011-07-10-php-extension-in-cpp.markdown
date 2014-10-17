---
layout: post
status: publish
published: true
title: 用C++来编写PHP扩展
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 592
wordpress_url: http://blog.eaxi.com/%e7%94%a8c%e6%9d%a5%e7%bc%96%e5%86%99php%e6%89%a9%e5%b1%95/
date: !binary |-
  MjAxMS0wNy0xMCAxOTozMDozMCArMDgwMA==
date_gmt: !binary |-
  MjAxMS0wNy0xMCAxMTozMDozMCArMDgwMA==
categories:
- C&#47;C++
tags: []
comments: []
---
<p>前面有文章介绍过如何编写一个简单的PHP扩展。简单说，也就下面几步：<br />
<&#47;p>
<ol>
<li>去ext目录用ext_skel生成扩展框架<br />
<&#47;li>
<li>去php源文件目录.&#47;buildconf --force<br />
<&#47;li>
<li>编辑config.m4<br />
<&#47;li>
<li>修改extname.c<br />
<&#47;li>
<li>.&#47;configure &amp;&amp; make &amp;&amp; make install<br />
<&#47;li><&#47;ol>
<p>本文介绍下如何在扩展编写过程中，使用C++。<br />
<&#47;p>
<p>读到这里，如果你还不知道GNU m4或phpize，建议参阅下相关资料。简而言之，GNU m4是一个用于生成文件的宏处理器。这里的phpize是调用了GNU m4来生成configure文件以及其他相关文件。Configure则是生成Makefile的一个bash脚本。<br />
<&#47;p>
<p>PHP扩展默认使用C语言来完成编码。若想使用C++，需要对config.m4文件做出相应修改。<br />
<&#47;p>
<p>
&nbsp;<&#47;p>
<p><span style="font-family:Courier New; font-size:10pt"><br />
			<span style="color:red">PHP_REQUIRE_CXX()<&#47;span><br />
		<&#47;span><&#47;p>
<p>
&nbsp;<&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_ADD_LIBRARY_WITH_PATH(<span style="color:black; text-decoration:underline">tlib<&#47;span>, $LIB_EXPORT_PATH, WANGGOU_SHARED_LIBADD)<br />
<&#47;span><&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_ADD_LIBRARY_WITH_PATH(library_sys, $LIB_EXPORT_PATH, WANGGOU_SHARED_LIBADD)<br />
<&#47;span><&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_ADD_LIBRARY_WITH_PATH(library_util, $LIB_EXPORT_PATH, WANGGOU_SHARED_LIBADD)<br />
<&#47;span><&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_ADD_LIBRARY_WITH_PATH(ip_pool, $LIB_EXPORT_PATH, WANGGOU_SHARED_LIBADD)<br />
<&#47;span><&#47;p>
<p>
&nbsp;<&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_SUBST(WANGGOU_SHARED_LIBADD)<br />
<&#47;span><&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_ADD_LIBRARY(<span style="color:red"><span style="text-decoration:underline">stdc<&#47;span>++<&#47;span>, 1, WANGGOU_SHARED_LIBADD)<br />
<&#47;span><&#47;p>
<p>
&nbsp;<&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_ADD_INCLUDE($INC_EXPORT_PATH)<br />
<&#47;span><&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_ADD_INCLUDE($EXT_PROTOCOL_PATH)<br />
<&#47;span><&#47;p>
<p><span style="font-family:Courier New; font-size:10pt">  PHP_NEW_EXTENSION(<span style="color:black; text-decoration:underline">wanggou<&#47;span>, <span style="color:red">wanggou.cpp<&#47;span>, $ext_shared)<&#47;span><br />
	<&#47;p>
<p>
&nbsp;<&#47;p>
<p>说明：<br />
<&#47;p>
<p>上述宏的第一句，表明了该扩展需要使用CXX编译器。<br />
<&#47;p>
<p>接下来四行，添加扩展中依赖的库，也就是 &ndash;Lpath&#47;to&#47;lib &ndash;lsomelib 段的内容。<br />
<&#47;p>
<p>接下来添加C++标准库。<br />
<&#47;p>
<p>下来两行是头文件包含的目录配置。<br />
<&#47;p>
<p>最后一行表明源代码文件的名字是以.cpp结尾。<span style="color:red">需要自己重命名自动生成的wanggou.c<&#47;span>。<br />
<&#47;p>
<p>
&nbsp;<&#47;p>
<p>接下来就是编码了，像平常一样include头文件，修改完文件，直接make来测试。<br />
<&#47;p>
<p>祝你成功！<br />
<&#47;p>
<p>--EOF&mdash;<br />
<&#47;p></p>
