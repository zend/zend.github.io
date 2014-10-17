---
layout: post
status: publish
published: true
title: 使用IE8的WebSlice 功能
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 259
wordpress_url: http://seaprince.cn/%e4%bd%bf%e7%94%a8ie8%e7%9a%84web-slice-%e5%8a%9f%e8%83%bd/
date: !binary |-
  MjAwOS0wNy0wOSAxNjowMjoyOCArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wNy0wOSAwODowMjoyOCArMDgwMA==
categories:
- 脚本语言
tags:
- ie8
- webslice
comments: []
---
<p>开发人员可以将网页的一部分标记为"源剪辑"，这样，用户在浏览网站时便可以监视它们所依赖的信息。只需在"收藏夹"栏中单击一次，用户即可看到丰富的"源剪辑"视觉效果，开发人员即可建立有价值且一致的最终用户连接。</p>
<p>最终效果：</p>
<p><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;07&#47;070909_0802_IE8WebSlice1.png" alt="" &#47;></p>
<p>点击<img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;07&#47;070909_0802_IE8WebSlice2.png" alt="" &#47;>之后，弹出一个对话框，可以将这个剪辑添加到收藏夹。</p>
<p><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;07&#47;070909_0802_IE8WebSlice3.png" alt="" &#47;></p>
<p>添加后，将会在收藏栏出现：</p>
<p><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;07&#47;070909_0802_IE8WebSlice4.png" alt="" &#47;></p>
<p>怎么样，效果还可以吧？</p>
<p>实现方法：</p>
<pre lang="php">
<div class="hslice" id="randomposts">
<div class="entry-title">这里写标题<&#47;div></p>
<div class="entry-content">
<p>这里是HTML内容&hellip;&hellip;</p>
<p><a style="display:none;" rel="feedurl" href="RSS地址">RSS名字<&#47;a></p>
<p><&#47;div></p>
<p><&#47;div><&#47;pre></p>
<p>大概结构就是这样，里边的内容要你自己去仔细填充哈！</p>
