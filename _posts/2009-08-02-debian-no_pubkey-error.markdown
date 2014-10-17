---
layout: post
status: publish
published: true
title: Debian NO_PUBKEY error
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: aptitude update 是Debian下用得最多的命令之一了，但这个命令有个毛病，还是会报错，往往向人不知道如何处理。比如NO_PUBKEY错误。
wordpress_id: 426
wordpress_url: http://seaprince.cn/?p=426
date: !binary |-
  MjAwOS0wOC0wMiAxMToxODozNiArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wOC0wMiAwMzoxODozNiArMDgwMA==
categories:
- 服务器
tags:
- linux
- keyring
comments: []
---
<p>aptitude update 是Debian下用得最多的命令之一了，但这个命令有个毛病，还是会报错，往往向人不知道如何处理。</p>
<p>如：</p>
<blockquote><p>W: GPG error: http:&#47;&#47;ftp.us.debian.org stable&#47;non-US Release: The following signatures couldn't be verified because the public key is not available: NO_PUBKEY F1D53D8C4F368D5D<br />
W: You may want to run apt-get update to correct these problems<&#47;blockquote><br />
看文字，是说找不到公钥，更新失败。它的建议是使用apt-get update来解决问题，但恰恰这个问题就是这个命令导致的，呵呵。因为apt-get update和aptitude update是基本类似的。aptitude是替代apt-*的新版工具罢了。</p>
<p>Google后，发现有类似问题的人巨多。常见的解决方案是：</p>
<blockquote><p># apt-get install gnupg<br />
# gpg --keyserver wwwkeys.eu.pgp.net --recv-keys F1D53D8C4F368D5D<br />
# gpg --armor --export F1D53D8C4F368D5D | apt-key add -<&#47;blockquote><br />
这里的F1D53D8C4F368D5D是错误信息中的那一串。</p>
<p>但是据我测试，这里的关键，wwwkeys.en.pgp.net这个地址，有时并无法正常使用。下面是我收集的一些keyservers，持续更新中。</p>
<p>wwwkeys.eu.pgp.net</p>
<p>pgpkeys.mit.edu</p>
<p><strong>Update 2009&#47;12&#47;31:<&#47;strong><br />
更加优雅的解决方案：<br />
<code>apt-get install debian-archive-keyring debian-keyring<&#47;code></p>
