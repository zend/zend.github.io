---
layout: post
status: publish
published: true
title: apache mod_negotiation与MultiViews的奥妙
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 475
wordpress_url: http://seaprince.cn/apache-mod_negotiation%e4%b8%8emultiviews%e7%9a%84%e5%a5%a5%e5%a6%99/
date: !binary |-
  MjAwOS0xMC0yMiAxNToxNzowMiArMDgwMA==
date_gmt: !binary |-
  MjAwOS0xMC0yMiAwNzoxNzowMiArMDgwMA==
categories:
- 服务器
tags:
- php
- linux
- apache
comments: []
---
<p>今天遇到一个奇怪的问题，取URL请求字符串时，明明访问的是&#47;index&#47;welcome&#47;，取回来的却是&#47;welcome&#47;。<br />
框架在处理这个问题时的处理流程是：</p>
<p>		$php_self = $_SERVER['PHP_SELF'];<br />
		$uri = $_SERVER['REQUEST_URI'];</p>
<p>		if (isset($_SERVER['PATH_INFO'])) {<br />
			$uri = $_SERVER['PATH_INFO'];<br />
		} else {<br />
			$uri = substr($uri, strlen(dirname($php_self)) );<br />
		}<br />
		$uri[0]!='?' || $uri = "&#47;$uri";<br />
		$uri = strtok($uri, '?');</p>
<p>先判断PATH_INFO，然后再处理其他情况。<br />
但我这里直接是http:&#47;&#47;xxx.com&#47;index&#47;welcome&#47; 怎么会存在PATH_INFO变量呢？<br />
后来打印$_SERVER变量时发现，apache认为我访问的这个链接是&#47;index.php&#47;welcome&#47; ！<br />
原来apache可以在访问&#47;path&#47;foo时，如果找不到&#47;path&#47;foo，就会去找&#47;path&#47;foo.*，并且选一个合适的返回来，为你服务。<br />
我这里存在着&#47;index.php，所以访问&#47;index&#47;welcome&#47;时，它就自动去找&#47;index.php了！<br />
而这些功能是一个模块提供的，它的名字叫mod_negotiation。相关说明：http:&#47;&#47;httpd.apache.org&#47;docs&#47;2.2&#47;content-negotiation.html<br />
同时，这个模块还提供了一个目录级别的控制开关，也就是<Directory段下的Options MultiViews，如果options中带有MultiViews字样，则启用这种功能，否则禁用。刚好，我的机器启用了mod_negotiation模块，并且Options中带有了MultiViews，所以出现了上面这种现象。</p>
<p>网上有很多相关的问题，但很多回复都没有回中点子上，比如：<br />
http:&#47;&#47;www.phpx.com&#47;happy&#47;thread-125808-1-1.html<br />
大多人都是想到用url rewrite来实现，呵呵。</p>
<p>其实，这个模块还有很多其他的强大功能，等待我们去发现，嘿嘿。</p>
