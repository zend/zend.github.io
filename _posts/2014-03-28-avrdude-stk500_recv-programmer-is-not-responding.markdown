---
layout: post
status: publish
published: true
title: ! 'avrdude: stk500_recv(): programmer is not responding'
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 625
wordpress_url: http://blog.eaxi.com/?p=625
date: !binary |-
  MjAxNC0wMy0yOCAwODoyNjoxNSArMDgwMA==
date_gmt: !binary |-
  MjAxNC0wMy0yOCAwMDoyNjoxNSArMDgwMA==
categories:
- 其他技术
tags: []
comments: []
---
<p>新到手arduino pro mini，马上焊好针脚，下载arduino IDE，烧写了个blink进去。一切顺利，程序完美运行。</p>
<p>但当想修改下参数，再烧新程序时，问题就来了。IDE提示：<br />
avrdude: stk500_recv(): programmer is not responding</p>
<p>编程器不响应？？这么快就坏掉应该是不可能的。Google搜索也没在国内社区发现有什么有用的信息，最后在stackoverflow得到了答案。</p>
<p>0、确认链路无误；<br />
1、确认板卡类型、串口类型（现在一般通过USB）选对。<br />
2、打开IDE的调试模式，输出详细信息。<br />
3、在Send [30] [20]之前，按一下板卡上的RESET按钮。</p>
<p>&nbsp;</p>
<p><a href="http:&#47;&#47;eaxi.com&#47;wp-content&#47;uploads&#47;2014&#47;03&#47;choose-arduino.jpg"><img class="alignnone size-full wp-image-632" alt="choose-arduino" src="http:&#47;&#47;eaxi.com&#47;wp-content&#47;uploads&#47;2014&#47;03&#47;choose-arduino.jpg" width="566" height="550" &#47;><&#47;a> <a href="http:&#47;&#47;eaxi.com&#47;wp-content&#47;uploads&#47;2014&#47;03&#47;choose-serial.jpg"><img class="alignnone size-full wp-image-633" alt="choose-serial" src="http:&#47;&#47;eaxi.com&#47;wp-content&#47;uploads&#47;2014&#47;03&#47;choose-serial.jpg" width="443" height="257" &#47;><&#47;a> <a href="http:&#47;&#47;eaxi.com&#47;wp-content&#47;uploads&#47;2014&#47;03&#47;choose-verbose-mode.jpg"><img class="alignnone size-full wp-image-635" alt="choose-verbose-mode" src="http:&#47;&#47;eaxi.com&#47;wp-content&#47;uploads&#47;2014&#47;03&#47;choose-verbose-mode.jpg" width="389" height="175" &#47;><&#47;a> <a href="http:&#47;&#47;eaxi.com&#47;wp-content&#47;uploads&#47;2014&#47;03&#47;choose-timeframe-to-reset.jpg"><img class="alignnone size-full wp-image-634" alt="choose-timeframe-to-reset" src="http:&#47;&#47;eaxi.com&#47;wp-content&#47;uploads&#47;2014&#47;03&#47;choose-timeframe-to-reset.jpg" width="499" height="228" &#47;><&#47;a></p>
<p>新手遇到的，估计99%都是上面的第3点没做。</p>
