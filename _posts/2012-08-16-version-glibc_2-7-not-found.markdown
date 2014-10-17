---
layout: post
status: publish
published: true
title: version `GLIBC_2.7' not found
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 618
wordpress_url: http://blog.eaxi.com/?p=618
date: !binary |-
  MjAxMi0wOC0xNiAyMjoxNjozMiArMDgwMA==
date_gmt: !binary |-
  MjAxMi0wOC0xNiAxNDoxNjozMiArMDgwMA==
categories:
- 不想分类
tags:
- Go Golang glibc
comments: []
---
<p>今天运行Golang二进制包时，发现提示这个错误：<br />
    version `GLIBC_2.7' not found</p>
<p>老习惯，去Google看下，别人的经验。但无外乎升级glibc这种解决方案。其实Google还不至于这么依赖一个如此新的库！<br />
最终找到解决方案：<br />
    cd $GOROOT&#47;src && .&#47;all.bash</p>
