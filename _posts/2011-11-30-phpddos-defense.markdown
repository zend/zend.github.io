---
layout: post
status: publish
published: true
title: phpddos应对 最近新起一种udp flood的攻击形式，是利用php中的fsockopen函数往特定机器发送大量UDP包，耗费大量流量，直到网络瘫痪。
  php当前只支持用allow url fopen整个禁用 启用网络文件访问，而不支持更细粒度的控制。这里介绍一种源码patch的方式，对该类型的攻击做一些防范。
  1...
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 600
wordpress_url: http://blog.eaxi.com/phpddos%e5%ba%94%e5%af%b9-%e6%9c%80%e8%bf%91%e6%96%b0%e8%b5%b7%e4%b8%80%e7%a7%8dudp-flood%e7%9a%84%e6%94%bb%e5%87%bb%e5%bd%a2%e5%bc%8f%ef%bc%8c%e6%98%af%e5%88%a9%e7%94%a8php%e4%b8%ad%e7%9a%84fsockopen/
date: !binary |-
  MjAxMS0xMS0zMCAyMzozOTozNSArMDgwMA==
date_gmt: !binary |-
  MjAxMS0xMS0zMCAxNTozOTozNSArMDgwMA==
categories:
- status
tags:
- php linux fsockopen
comments: []
---
<p>phpddos应对<br />
最近新起一种udp flood的攻击形式，是利用php中的fsockopen函数往特定机器发送大量UDP包，耗费大量流量，直到网络瘫痪。<br />
php当前只支持用allow_url_fopen整个禁用&#47;启用网络文件访问，而不支持更细粒度的控制。这里介绍一种源码patch的方式，对该类型的攻击做一些防范。</p>
<p>1. 捕蛇打三、七寸<br />
在ext&#47;standard&#47;fsock.c中的php_fsockopen_stream函数中，加入如下代码：<br />
	if (!strncasecmp("udp:&#47;&#47;", host, 6)) {<br />
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Unsupported wrapper UDP");<br />
		RETURN_FALSE;<br />
	}</p>
<p>	if (!strncasecmp("tcp:&#47;&#47;", host, 6)) {<br />
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Unsupported wrapper TCP");<br />
		RETURN_FALSE;<br />
	}</p>
<p>2. 频率限制<br />
创建一个全局变量数组，给每个用户维护一个计数器，执行一次函数加一。<br />
	fsock_counter[uid] ++;<br />
	if (fsock_counter[uid] > 10) {<br />
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Too many calls.");<br />
		RETURN_FALSE;<br />
	}<br />
一个请求，禁止发送超过10次的网络请求！</p>
