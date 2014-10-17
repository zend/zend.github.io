---
layout: post
status: publish
published: true
title: UCenter Home2.0的无法同步登录的修正
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 448
wordpress_url: http://seaprince.cn/ucenter-home2-0%e7%9a%84%e6%97%a0%e6%b3%95%e5%90%8c%e6%ad%a5%e7%99%bb%e5%bd%95%e7%9a%84%e4%bf%ae%e6%ad%a3/
date: !binary |-
  MjAwOS0wOC0xMiAxNjowNDoxNyArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wOC0xMiAwODowNDoxNyArMDgwMA==
categories:
- 脚本语言
tags:
- php
comments: []
---
<p>今天在弄UCenter Home和其他自定义应用同步登录，发现一个UCH 2.0中的一个问题。<br />
<&#47;p>
<p>打开source&#47;do_login.php，你会发现这样的一个代码片段：<br />
<&#47;p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;if($_SCONFIG['uc_status']) {<br />
<&#47;p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;include_once S_ROOT.'.&#47;uc_client&#47;client.php';<br />
<&#47;p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$ucsynlogin = uc_user_synlogin($setarr['uid']);<br />
<&#47;p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;} else {<br />
<&#47;p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$ucsynlogin = '';<br />
<&#47;p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;}<br />
<&#47;p>
<p>这个$_SCONFIG['uc_status']并没有出现中出现在任何配置文件中，所以它始终是未被定义的。也就一直无法同步登录其他应用了。<br />
<&#47;p>
<p>在前边加上一句<br />
<&#47;p>
<p>&nbsp;&nbsp;&nbsp;&nbsp;$_SCONFIG['uc_status'] = 1;<br />
<&#47;p>
<p>可以临时解决这个问题。<br />
<&#47;p>
<p>另外，自己写应用时，例子是最好的老师。ucenter的包中，有examples目录，就包括了两灰常经典的例子，绝对值得参考。<br />
<&#47;p>
<p>--EOF--<&#47;p></p>
