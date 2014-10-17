---
layout: post
status: publish
published: true
title: rsync 错误与解决方案收集
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 510
wordpress_url: http://seaprince.cn/?p=510
date: !binary |-
  MjAxMC0wMy0xMSAxMTo1Mzo0MSArMDgwMA==
date_gmt: !binary |-
  MjAxMC0wMy0xMSAwMzo1Mzo0MSArMDgwMA==
categories:
- 服务器
tags:
- linux
- rsync
comments: []
---
<p>问题一：<br />
@ERROR: chroot failed<br />
rsync error: error starting client-server protocol (code 5) at main.c(1522) [receiver=3.0.3]</p>
<p><strong>原因：<br />
服务器端的目录不存在或无权限，创建目录并修正权限可解决问题。<&#47;strong></p>
<p>问题二：<br />
@ERROR: auth failed on module tee<br />
rsync error: error starting client-server protocol (code 5) at main.c(1522) [receiver=3.0.3]</p>
<p><strong>原因：<br />
服务器端该模块（tee）需要验证用户名密码，但客户端没有提供正确的用户名密码，认证失败。<br />
提供正确的用户名密码解决此问题。<&#47;strong></p>
<p>问题三：<br />
@ERROR: Unknown module 'tee_nonexists'<br />
rsync error: error starting client-server protocol (code 5) at main.c(1522) [receiver=3.0.3]</p>
<p><strong>原因：<br />
服务器不存在指定模块。提供正确的模块名或在服务器端修改成你要的模块以解决问题。<&#47;strong></p>
