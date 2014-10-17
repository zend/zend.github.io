---
layout: post
status: publish
published: true
title: JS网页可见大小获取（兼容FF,IE,OP在HTML,XHTML）
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>JS网页可见大小获取（兼容FF,IE,OP在HTML,XHTML）</p>
wordpress_id: 217
date: !binary |-
  MjAwOC0wOC0yNyAxNDo0OToyNSArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wOC0yNyAwNjo0OToyNSArMDgwMA==
categories:
- 脚本语言
tags:
- javascript
comments: []
---
<p>JS网页可见大小获取（兼容FF,IE,OP在HTML,XHTML）<&#47;p></p>
<p>window.client={<br &#47;><br />
&nbsp;&nbsp;&nbsp; width: document.body.clientWidth,<br &#47;><br />
&nbsp;&nbsp;&nbsp; height: Math.min(document.documentElement.clientHeight, document.body.clientHeight)<br &#47;><br />
};<&#47;p></p>
