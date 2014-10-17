---
layout: post
status: publish
published: true
title: 安装好samba，也启动了，也能看到共享目录，但就是无权限访问？试试： setsebool P samba enable home dirs on
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 612
wordpress_url: http://blog.eaxi.com/%e5%ae%89%e8%a3%85%e5%a5%bdsamba%ef%bc%8c%e4%b9%9f%e5%90%af%e5%8a%a8%e4%ba%86%ef%bc%8c%e4%b9%9f%e8%83%bd%e7%9c%8b%e5%88%b0%e5%85%b1%e4%ba%ab%e7%9b%ae%e5%bd%95%ef%bc%8c%e4%bd%86%e5%b0%b1%e6%98%af/
date: !binary |-
  MjAxMi0wNS0yNiAwMTozNDoxMyArMDgwMA==
date_gmt: !binary |-
  MjAxMi0wNS0yNSAxNzozNDoxMyArMDgwMA==
categories:
- status
tags:
- linux samba
comments: []
---
<p>安装好samba，也启动了，也能看到共享目录，但就是无权限访问？试试：<br />
setsebool -P samba_enable_home_dirs on</p>
