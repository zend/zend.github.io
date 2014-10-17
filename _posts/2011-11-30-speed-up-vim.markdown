---
layout: post
status: publish
published: true
title: 调试vim慢的原因方法： vim startuptime message txt 启动后，查看message txt中，哪个脚本最慢，再考虑能否禁用加载。在我这里，c
  vim禁用后，快了非常多。...
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 598
wordpress_url: http://blog.eaxi.com/%e8%b0%83%e8%af%95vim%e6%85%a2%e7%9a%84%e5%8e%9f%e5%9b%a0%e6%96%b9%e6%b3%95%ef%bc%9a-vim-startuptime-message-txt-%e5%90%af%e5%8a%a8%e5%90%8e%ef%bc%8c%e6%9f%a5%e7%9c%8bmessage-txt%e4%b8%ad%ef%bc%8c/
date: !binary |-
  MjAxMS0xMS0zMCAyMDo1OTozOSArMDgwMA==
date_gmt: !binary |-
  MjAxMS0xMS0zMCAxMjo1OTozOSArMDgwMA==
categories:
- status
tags:
- vim gvim linux
comments: []
---
<p>调试vim慢的原因方法：<br />
vim --startuptime message.txt<br />
启动后，查看message.txt中，哪个脚本最慢，再考虑能否禁用加载。在我这里，c.vim禁用后，快了非常多。</p>
<p>接下来，可以正常使用vim，然后输入命令<br />
:scriptnames<br />
看到列表后，也能发现耗时脚本。这一步，发现可以禁用菜单、禁用翻译（vim需要这些东西么！），又提速不少！</p>
