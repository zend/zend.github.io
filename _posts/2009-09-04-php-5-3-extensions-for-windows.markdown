---
layout: post
status: publish
published: true
title: PHP 5.3 Extensions For Windows
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 460
wordpress_url: http://seaprince.cn/?p=460
date: !binary |-
  MjAwOS0wOS0wNCAxNTo0NTowNCArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wOS0wNCAwNzo0NTowNCArMDgwMA==
categories:
- 不想分类
tags:
- php
- windows
comments:
- id: 947
  author: jianfen
  author_email: shan8018@126.com
  author_url: ''
  date: !binary |-
    MjAwOS0wOS0wNiAyMToyNjoyMiArMDgwMA==
  date_gmt: !binary |-
    MjAwOS0wOS0wNiAxMzoyNjoyMiArMDgwMA==
  content: 怎么编译的，能把编译的步骤写一些吗，谢谢
- id: 985
  author: bya
  author_email: 8888zqw@163.com
  author_url: ''
  date: !binary |-
    MjAwOS0wOS0xNiAxMTozMzozNCArMDgwMA==
  date_gmt: !binary |-
    MjAwOS0wOS0xNiAwMzozMzozNCArMDgwMA==
  content: 可否提供一个3.13p1的php_apc.dll
- id: 986
  author: admin
  author_email: combbs@gmail.com
  author_url: http://seaprince.cn/
  date: !binary |-
    MjAwOS0xMC0wNSAxMDoyMDowMSArMDgwMA==
  date_gmt: !binary |-
    MjAwOS0xMC0wNSAwMjoyMDowMSArMDgwMA==
  content: ! "<a href=\"#comment-985\" rel=\"nofollow\">@bya <&#47;a> \n已经附上，请测试。"
- id: 987
  author: admin
  author_email: combbs@gmail.com
  author_url: http://seaprince.cn/
  date: !binary |-
    MjAwOS0xMC0wNSAxMDozMTowOCArMDgwMA==
  date_gmt: !binary |-
    MjAwOS0xMC0wNSAwMjozMTowOCArMDgwMA==
  content: ! "<a href=\"#comment-947\" rel=\"nofollow\">@jianfen <&#47;a> \n请参考： http:&#47;&#47;seaprince.cn&#47;compiling-php-on-windows&#47;\n比如说APC扩展，只需要下载APC的扩展包，放入ext目录中，再重新\nbuildconf\nconfigure
    --disable-all --enable-cli --enable-apc=shared\nnmake\n成功完成后，在Release_TS 中，就可找到php_apc.dll"
- id: 1036
  author: luckgo
  author_email: luckgo@21cn.com
  author_url: ''
  date: !binary |-
    MjAxMC0wNS0yNiAxODo1MjoyOSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNS0yNiAxMDo1MjoyOSArMDgwMA==
  content: ! '兄弟，我装了PHP5.3 VC6，里面没有php_mcrypt.dll和libmcrypt.dll， 但我要启动php_mcrypt.dll，我就把PHP5.2中的php_mcrypt.dll和libmcrypt.dll拿来用，启动Apache后在日志中发现有这样错误：

    PHP Warning:  PHP Startup: mcrypt: Unable to initialize module\nModule compiled
    with module API=20060613\nPHP    compiled with module API=20090626\nThese options
    need to match\n in Unknown on line 0


    估计是不兼容问题，但我在网上找不到相关下载，也不知道如何编译，兄弟能不能帮忙编译个？'
- id: 1037
  author: luckgo
  author_email: luckgo@21cn.com
  author_url: ''
  date: !binary |-
    MjAxMC0wNS0yNiAyMDoxMDowOSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNS0yNiAxMjoxMDowOSArMDgwMA==
  content: 再请教个问题，PHP官方说在windows+apache环境下装PHP 5.3要选择VC6版本，网上搜到的全是相同的内容，而我当初却装了VC9Visual
    C++ 2008 Redistributable
- id: 1038
  author: luckgo
  author_email: luckgo@21cn.com
  author_url: ''
  date: !binary |-
    MjAxMC0wNS0yNiAyMDoxMjo1NSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNS0yNiAxMjoxMjo1NSArMDgwMA==
  content: ! '（不小心提交了，晕）

    而我当初却装了apache和PHP5.3 VC9，但已安装Visual C++ 2008 Redistributable，结果完全正常，这说明应该没问题吧？'
- id: 1042
  author: seaprince
  author_email: combbs@gmail.com
  author_url: http://seaprince.cn/
  date: !binary |-
    MjAxMC0wNi0wMyAxNDozMTo0MCArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNi0wMyAwNjozMTo0MCArMDgwMA==
  content: ! "<a href=\"#comment-1036\" rel=\"nofollow\">@luckgo <&#47;a> \nPHP Warning:
    PHP Startup: mcrypt: Unable to initialize module\\nModule compiled with module
    API=20060613\\nPHP compiled with module API=20090626\\nThese options need to match\\n
    in Unknown on line 0\n\n这个错误是版本不一致导致的。比如，mcrypt的编译环境是VC9，它就不能运行在VC6版本的PHP中。否则你就报你这个错。"
- id: 1148
  author: analy
  author_email: man_zl@sina.com.cn
  author_url: http://phpming
  date: !binary |-
    MjAxMy0wMS0yMyAyMzowMDoyNyArMDgwMA==
  date_gmt: !binary |-
    MjAxMy0wMS0yMyAxNTowMDoyNyArMDgwMA==
  content: 楼主，能否把你编译php_ming.dll的过程写个说明啊。我下载了你的php_ming.dll在php的VC9 x86 Non Thread
    Safe 版本下，加载这个dll不成功。谢谢。
---
<p>自己动手丰衣足食。继续编译中，有好的扩展可以推荐来~~</p>
<p><em>这里的dll都是仅适用于php 5.3 vc9版本。<&#47;em></p>
<p>注：下边扩展只适用于PHP 5.3，至于其他扩展，估计到处都有了，不用重复造轮子。</p>
<p><a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;09&#47;php_imagick.dll">php_imagick.dll<&#47;a></p>
<p><a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;09&#47;php_ming.dll">php_ming.dll<&#47;a></p>
<p><a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;09&#47;php_apc.dll">php_apc.dll<&#47;a></p>
<p>Updated 2009-09-09：Add php_ming.dll for php5.3.0</p>
<p>Updated 2009-10-05: &nbsp; &nbsp;php_apc.dll 已经添加，应bya之求。</p>
<p>--EOF--</p>
