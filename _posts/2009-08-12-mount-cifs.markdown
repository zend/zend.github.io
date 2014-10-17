---
layout: post
status: publish
published: true
title: 在Debian&#47;Linux下用mount.cifs挂载网上邻居的共享
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 444
wordpress_url: http://seaprince.cn/%e5%9c%a8debianlinux%e4%b8%8b%e6%8c%82%e8%bd%bd%e7%bd%91%e4%b8%8a%e9%82%bb%e5%b1%85%e7%9a%84%e5%85%b1%e4%ba%ab/
date: !binary |-
  MjAwOS0wOC0xMiAxNToyNTo0MyArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wOC0xMiAwNzoyNTo0MyArMDgwMA==
categories:
- 服务器
tags:
- debian
- mount
- mount.cifs
- cifs
comments: []
---
<p>这里只提Debian下的方法，其他发行版类似。</p>
<p>首先，你需要安装一个软件，叫smbfs</p>
<p>aptitude update &amp;&amp; aptitude install smbfs</p>
<p>建一个局域网上其他机器上建立一个共享文件，打开写权限。请在其他WIN机器测试共享可以性，免得防火墙碍事。</p>
<p>在Debian里新建一个目录，如&#47;share，执行命令：</p>
<p>mount.cifs &#47;&#47;192.168.0.254&#47;linux$ &#47;share -o username=user,password=123456</p>
<p>成功。</p>
<p>要在系统启动后自动挂载，可以在&#47;etc&#47;rc.local文件里加一行：（必须写在exit 0前面）</p>
<p>mount.cifs &#47;&#47;192.168.0.254&#47;linux$ &#47;share -o username=xxx,password=txxxxxx</p>
<p>--EOF--</p>
