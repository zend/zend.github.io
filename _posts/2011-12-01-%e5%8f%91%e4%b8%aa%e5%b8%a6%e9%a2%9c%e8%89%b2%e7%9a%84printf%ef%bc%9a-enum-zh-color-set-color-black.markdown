---
layout: post
status: publish
published: true
title: 发个带颜色的printf： enum zh color set COLOR BLACK =...
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 606
wordpress_url: http://blog.eaxi.com/%e5%8f%91%e4%b8%aa%e5%b8%a6%e9%a2%9c%e8%89%b2%e7%9a%84printf%ef%bc%9a-enum-zh-color-set-color-black/
date: !binary |-
  MjAxMS0xMi0wMSAyMzoyNzoyMyArMDgwMA==
date_gmt: !binary |-
  MjAxMS0xMi0wMSAxNToyNzoyMyArMDgwMA==
categories:
- status
tags:
- linux c
comments: []
---
<p>发个带颜色的printf：<br />
enum zh_color_set {<br />
	COLOR_BLACK = 30,<br />
	COLOR_RED,<br />
	COLOR_GREEN,<br />
	COLOR_YELLOW,<br />
	COLOR_BLUE,<br />
	COLOR_MAGENTA,<br />
	COLOR_CYAN,<br />
	COLOR_WHITE<br />
};<br />
void zh_printf(int color, char *fmt, ...)<br />
{<br />
	va_list ap;<br />
	printf("%c[1;%d;40m", 0x1B, color);</p>
<p>	va_start(ap, fmt);<br />
	vprintf(fmt, ap);<br />
	va_end(ap);</p>
<p>	printf("%c[0m", 0x1B);<br />
}</p>
