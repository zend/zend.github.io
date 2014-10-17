---
layout: post
status: publish
published: true
title: nginx 下QUERY_STRING 的一个bug
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 505
wordpress_url: http://seaprince.cn/nginx-%e4%b8%8bquery_string-%e7%9a%84%e4%b8%80%e4%b8%aabug/
date: !binary |-
  MjAwOS0xMi0yNSAxNTozMjo1MiArMDgwMA==
date_gmt: !binary |-
  MjAwOS0xMi0yNSAwNzozMjo1MiArMDgwMA==
categories:
- 服务器
tags:
- php
- nginx
comments:
- id: 1142
  author: Nginx QUERY_STRING BUG | Nginx Lighttpd
  author_email: ''
  author_url: http://nginxvslighttpd.com/2011/06/nginx-query_string-bug/
  date: !binary |-
    MjAxMS0wNi0wMSAyMTo0Nzo0OSArMDgwMA==
  date_gmt: !binary |-
    MjAxMS0wNi0wMSAxMzo0Nzo0OSArMDgwMA==
  content: ! '[...] http:&#47;&#47;blog.eaxi.com&#47;nginx-query_string-bug&#47; [...]'
---
<p>配置选项：<br />
        location &#47; {<br />
            root   "D:&#47;xampp&#47;htdocs&#47;teeume.com";<br />
	    try_files $uri &#47;t.php;<br />
        }</p>
<p>实现重写后，我们用 &#47;search&#47;?q=test 请求，会发现$_GET['q'] 无值，$_SERVER['QUERY_STRING']无值。</p>
<p>这就影响了正常的取值方式。<br />
我们做如下修正：<br />
			$uri = $_SERVER['REQUEST_URI'];<br />
			$uri = strtok($uri, '?');<br />
			$qs = $_SERVER['QUERY_STRING'] = strtok('?');<br />
			parse_str($qs, $qs_arr);<br />
			$_REQUEST = array_merge($_REQUEST, $qs_arr);</p>
