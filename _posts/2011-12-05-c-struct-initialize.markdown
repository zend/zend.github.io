---
layout: post
status: publish
published: true
title: C struct initialize
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 597
wordpress_url: http://blog.eaxi.com/?p=597
date: !binary |-
  MjAxMS0xMi0wNSAwMDozNTo0MiArMDgwMA==
date_gmt: !binary |-
  MjAxMS0xMi0wNCAxNjozNTo0MiArMDgwMA==
categories:
- 不想分类
tags:
- c struct
comments: []
---
<p>struct SMyOrder<br />
{<br />
	int quantity;<br />
	int price;<br />
};</p>
<p>int main()<br />
{<br />
	static const struct SMyOrder zero_a;<br />
	struct SMyOrder a = zero_a;</p>
<p>	printf("price=%d, quantity=%d \n", a.price, a.quantity);</p>
<p>	return 0;<br />
}</p>
