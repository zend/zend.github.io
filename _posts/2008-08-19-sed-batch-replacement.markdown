---
layout: post
status: publish
published: true
title: Sed batch replacement
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: ! "<p>linux sed 批量替换多个文件中的字符串<br />\r\n<br />\r\nsed -i &quot;s/oldstring/newstring/g&quot;
  `grep oldstring -rl yourdir`<br />\r\n<br />\r\n例如：替换/home下所有文件中的gao为gaoxilin<br
  />\r\n<br />\r\nsed -i &quot;s/seaprince/TEMPLATE/g&quot; `grep seaprince -rl /home`
  </p>\r\n<p>或者 </p>\r\n<p>sed -i &quot;s/seaprince/TEMPLATE/g&quot; /home/*.cgi</p>"
wordpress_id: 215
date: !binary |-
  MjAwOC0wOC0xOSAxMTozNTo1MiArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wOC0xOSAwMzozNTo1MiArMDgwMA==
categories:
- 脚本语言
tags:
- sed
comments: []
---
<p>linux sed 批量替换多个文件中的字符串<&#47;p></p>
<blockquote>
<p>sed -i "s&#47;oldstring&#47;newstring&#47;g" `grep oldstring -rl yourdir`<&#47;p><br />
<&#47;blockquote></p>
<p>例如：替换&#47;home下所有文件中的gao为gaoxilin<&#47;p></p>
<blockquote>
<p>sed -i "s&#47;seaprince&#47;TEMPLATE&#47;g" `grep seaprince -rl &#47;home` <&#47;p><br />
<&#47;blockquote></p>
<p>或者 <&#47;p></p>
<blockquote>
<p>sed -i "s&#47;seaprince&#47;TEMPLATE&#47;g" &#47;home&#47;*.cgi<&#47;p><br />
<&#47;blockquote></p>
