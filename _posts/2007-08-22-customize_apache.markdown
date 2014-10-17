---
layout: post
status: publish
published: true
title: 个性化你的Apache
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>今天晚上把Apache2.2.4编译了一遍又一遍，颇有味道。若有同好者，请看此文。</p>
wordpress_id: 160
date: !binary |-
  MjAwNy0wOC0yMiAwNDozODoxNyArMDgwMA==
date_gmt: !binary |-
  MjAwNy0wOC0yMSAyMDozODoxNyArMDgwMA==
categories:
- 服务器
tags:
- apache
comments: []
---
<p>今天晚上把Apache2.2.4编译了一遍又一遍，颇有味道。若有同好者，请看此文。<br &#47;><br />
<br &#47;><br />
1. apr.<br &#47;><br />
apr=Apache portable runtime, official website here: http:&#47;&#47;apr.apache.org<br &#47;><br />
View Informations:<&#47;p></p>
<div class="codeText">
<div class="codeHead">C++代码<&#47;div></p>
<ol class="dp-cpp">
<li class="alt"><span><span class="preprocessor">#&nbsp;path&#47;to&#47;httpd&#47;bin&#47;httpd&nbsp;-V<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p>It will show something like this:<&#47;p></p>
<div class="codeText">
<div class="codeHead">C++代码<&#47;div></p>
<ol class="dp-cpp">
<li class="alt"><span><span>Server&nbsp;version:&nbsp;Apache&#47;2.2.4&nbsp;(UNIX&#47;EAXI.COM)&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>Server&nbsp;built:&nbsp;&nbsp;&nbsp;Aug&nbsp;22&nbsp;2007&nbsp;12:28:35&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>Server's&nbsp;Module&nbsp;Magic&nbsp;Number:&nbsp;20051115:4&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>Server&nbsp;loaded:&nbsp;&nbsp;APR&nbsp;1.2.8-dev,&nbsp;APR-Util&nbsp;1.2.8&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>Compiled&nbsp;<span class="keyword">using<&#47;span><span>:&nbsp;APR&nbsp;1.2.8-dev,&nbsp;APR-Util&nbsp;1.2.8&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>Architecture:&nbsp;&nbsp;&nbsp;32-bit&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>Server&nbsp;MPM:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Prefork&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;threaded:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;no&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;forked:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;yes&nbsp;(variable&nbsp;process&nbsp;count)&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>Server&nbsp;compiled&nbsp;with....&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;APACHE_MPM_DIR=<span class="string">"server&#47;mpm&#47;prefork"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;APR_HAS_SENDFILE&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;APR_HAS_MMAP&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;APR_HAVE_IPV6&nbsp;(IPv4-mapped&nbsp;addresses&nbsp;enabled)&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;APR_USE_SYSVSEM_SERIALIZE&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;APR_USE_PTHREAD_SERIALIZE&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;SINGLE_LISTEN_UNSERIALIZED_ACCEPT&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;APR_HAS_OTHER_CHILD&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;AP_HAVE_RELIABLE_PIPED_LOGS&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;DYNAMIC_MODULE_LIMIT=128&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;HTTPD_ROOT=<span class="string">"&#47;usr&#47;local&#47;&#47;httpd&#47;"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;SUEXEC_BIN=<span class="string">"&#47;usr&#47;local&#47;&#47;httpd&#47;&#47;bin&#47;suexec"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;DEFAULT_PIDLOG=<span class="string">"logs&#47;httpd.pid"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;DEFAULT_SCOREBOARD=<span class="string">"logs&#47;apache_runtime_status"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;DEFAULT_LOCKFILE=<span class="string">"logs&#47;accept.lock"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;DEFAULT_ERRORLOG=<span class="string">"logs&#47;error_log"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;-D&nbsp;AP_TYPES_CONFIG_FILE=<span class="string">"conf&#47;mime.types"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;-D&nbsp;SERVER_CONFIG_FILE=<span class="string">"conf&#47;httpd.conf"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p>apr version informations at: path&#47;to&#47;httpd-src&#47;srclib&#47;apr&#47;include&#47;apr_version.h<br &#47;><br />
<br &#47;><br />
2. Operating System Information<br &#47;><br />
It will be displayed at error pages, httpd -V informations list.<br &#47;><br />
os info at path&#47;to&#47;httpd-src&#47;os&#47;<br &#47;><br />
<br &#47;><br />
3. Apache release<br &#47;><br />
It will be displayed at error pages, httpd -V informations list.<br &#47;><br />
Apache release informations defined at path&#47;to&#47;httpd-src&#47;include&#47;ap_release.h<&#47;p></p>
