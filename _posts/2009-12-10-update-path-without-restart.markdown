---
layout: post
status: publish
published: true
title: 修改系统PATH不用重启
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 492
wordpress_url: http://seaprince.cn/%e4%bf%ae%e6%94%b9%e7%b3%bb%e7%bb%9fpath%e4%b8%8d%e7%94%a8%e9%87%8d%e5%90%af/
date: !binary |-
  MjAwOS0xMi0xMCAxNjoxNzo0MiArMDgwMA==
date_gmt: !binary |-
  MjAwOS0xMi0xMCAwODoxNzo0MiArMDgwMA==
categories:
- 不想分类
tags: []
comments: []
---
<p>利用wmic修改是直接生效的：（e:\tools 是新添加的目录）<br />
wmic ENVIRONMENT where "name='path'" and username="" set VariableValue="%path%e:\tools"</p>
