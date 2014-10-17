---
layout: post
status: publish
published: true
title: Slimbox With Iframe support
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>This is a modified version of slimbox, with a iframe support added.</p>
wordpress_id: 219
date: !binary |-
  MjAwOC0xMC0wNyAwOTo1MTo0MiArMDgwMA==
date_gmt: !binary |-
  MjAwOC0xMC0wNyAwMTo1MTo0MiArMDgwMA==
categories:
- 个人作品
tags:
- slimbox
- javascript
comments: []
---
<p>This is a modified version of slimbox, with a iframe support added.<&#47;p></p>
<p>Find:<&#47;p></p>
<blockquote>
<p>this.eventPosition = this.position.bind(this);<&#47;p><br />
<&#47;blockquote></p>
<p>Add a new line after it:<&#47;p></p>
<blockquote>
<p>this.body = top.document.body;<&#47;p><br />
<&#47;blockquote></p>
<p>Find: <&#47;p></p>
<blockquote>
<p>.injectInside(document.body)<&#47;p><br />
<&#47;blockquote></p>
<p>Replace with:<&#47;p></p>
<blockquote>
<p>.injectInside(this.body)<&#47;p><br />
<&#47;blockquote></p>
<p>Done.<&#47;p></p>
<p>Modified slimbox.js file can be download here:<&#47;p></p>
<p>[attach=140]<&#47;p></p>
