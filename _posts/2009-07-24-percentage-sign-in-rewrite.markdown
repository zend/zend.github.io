---
layout: post
status: publish
published: true
title: 小心对待rewrite中邪恶的百分号（%）
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: 我目前是采用 /key1/value1/key2/value2 方式传递参数，非常干净明了。但是今天我试图传递一个urlencode过的字符串时发现，只要URI里带有百分号%，就会导致Apache服务器400错误，警告说“错误的请求”。
wordpress_id: 412
wordpress_url: http://seaprince.cn/?p=412
date: !binary |-
  MjAwOS0wNy0yNCAxMTo0Nzo0NiArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wNy0yNCAwMzo0Nzo0NiArMDgwMA==
categories:
- 脚本语言
- 服务器
tags:
- php
- apache
- rewrite
comments:
- id: 1047
  author: 小诗
  author_email: datav@126.com
  author_url: ''
  date: !binary |-
    MjAxMC0wNi0yNSAxMToyMTozMSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNi0yNSAwMzoyMTozMSArMDgwMA==
  content: ! '这个问题可以解决了。

    在wp里的重写规则是：


    RewriteEngine On

    RewriteBase &#47;

    RewriteRule ^index\.php$ - [L]

    RewriteCond %{REQUEST_FILENAME} !-f

    RewriteCond %{REQUEST_FILENAME} !-d

    RewriteRule . &#47;index.php [L]


    然后用php中的：$_SERVER[''REQUEST_URI'']获取网址斜杠后的字符串。

    如：

    xx.com&#47;%BF%AA%D0%C4

    $_SERVER[''REQUEST_URI''] 就等于 &#47;%BF%AA%D0%C4'
- id: 1048
  author: 淡淡的阳光
  author_email: alpha1130@gmail.com
  author_url: ''
  date: !binary |-
    MjAxMC0wNi0yNiAxNjo1MTozMyArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNi0yNiAwODo1MTozMyArMDgwMA==
  content: ! '你的路径写得就有问题，如果访问的文件名包含''%''，那么合理的url就应该是


    &#47;key1&#47;value1&#47;key2&#47;value_with_%25_symbol

    而不是

    &#47;key1&#47;value1&#47;key2&#47;value_with_%_symbol'
- id: 1062
  author: admin
  author_email: combbs@gmail.com
  author_url: http://seaprince.cn/
  date: !binary |-
    MjAxMC0wNy0wMSAxMzoxNDozNyArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNy0wMSAwNToxNDozNyArMDgwMA==
  content: ! "<a href=\"#comment-1048\" rel=\"nofollow\">@淡淡的阳光 <&#47;a> \r\n对的，应该先urlencode。"
---
<p>今天遇到一个非常诡异的问题。</p>
<p>我目前是采用 &#47;key1&#47;value1&#47;key2&#47;value2 方式传递参数，非常干净明了。但是今天我试图传递一个urlencode过的字符串时发现，只要URI里带有百分号%，就会导致Apache服务器400错误，警告说&ldquo;错误的请求&rdquo;。</p>
<p>&#47;key1&#47;value1&#47;key2&#47;value_with_%_symbol&nbsp;&nbsp;&nbsp; 400 error</p>
<p>&#47;key1&#47;value1&#47;key2&#47;value_without_symbol&nbsp;&nbsp;&nbsp; 200 OK</p>
<p>查阅手册后，发现%是rewrite语法中的特殊字符，会认为是一个变量的开始，就像PHP中的美元符号$。</p>
<p>经测试，很多知名站点也没有解决这个问题，如WP，discuz，osnews等等。</p>
<p>目前找到一个解决方案，但情况有点不太一样，所以也没有测试成功。链接地址：<a href="http:&#47;&#47;stackoverflow.com&#47;questions&#47;734654&#47;modrewrite-doesnt-work-for-a-url-beginning-in-percent-sign">http:&#47;&#47;stackoverflow.com&#47;questions&#47;734654&#47;modrewrite-doesnt-work-for-a-url-beginning-in-percent-sign<&#47;a></p>
<p>临时解决方案：&#47;key1&#47;value2&#47;?key2=evil_value2 即换回传统的方式来解决问题。</p>
<p>特留此文，以后找到方案时更新。</p>
