---
layout: post
status: publish
published: true
title: 发件人是localhost.localdomain的解决方案
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>大家都说修改主机名就可以了，但是如果不注意每一个细节，而单单修改hostname，肯定不行。</p>
wordpress_id: 202
date: !binary |-
  MjAwOC0wNi0zMCAxNzowNTo1MyArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wNi0zMCAwOTowNTo1MyArMDgwMA==
categories:
- 服务器
tags:
- linux
comments: []
---
<p>大家都说修改主机名就可以了，但是如果不注意每一个细节，而单单修改hostname，肯定不行。<br &#47;><br />
其实，正确的步骤应该是：<&#47;p></p>
<ol>
<li>设置好主机名，域名：<br &#47;><br />
    hostname可以设置临时主机名。保险的做法是修改配置文件，让系统重启后不会失效。<br &#47;><br />
    以centos为例，修改&#47;etc&#47;sysconfig&#47;network，加上或者修改两行：HOSTNAME， DOMAINNAME。<&#47;li></p>
<li>执行hostname newhost, 退出登陆一次，让主机名生效。<&#47;li>
<li>重启sendmail。&#47;etc&#47;init.d&#47;sendmail restart<&#47;li><br />
<&#47;ol></p>
<p>这样就好了，在控制台发封信试试看吧！<br &#47;><br />
我的身份是root，主机名是demo，域名是zhpanel.com，所以，我的默认发件人就是root@demo.zhpanel.com。<br &#47;><br />
这样讲，应该明白了吧&hellip;&hellip;<&#47;p></p>
