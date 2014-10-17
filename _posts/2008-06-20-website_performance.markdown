---
layout: post
status: publish
published: true
title: 用YSlow优化网站性能
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>本文记录了一个网站优化的过程，可以很大程度上加速网页的加载。</p>
wordpress_id: 198
date: !binary |-
  MjAwOC0wNi0yMCAyMzozMDowNiArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wNi0yMCAxNTozMDowNiArMDgwMA==
categories:
- 脚本语言
tags:
- firefox
- yslow
comments:
- id: 66
  author: HJin
  author_email: anony@mo.us
  author_url: http://www.ihjin.cn
  date: !binary |-
    MjAwOC0wNi0yMyAyMDo0Mjo0NCArMDgwMA==
  date_gmt: !binary |-
    MjAwOC0wNi0yMyAyMDo0Mjo0NCArMDgwMA==
  content: 很棒！以后自己也研究研究！
- id: 67
  author: admin12
  author_email: anony@mo.us
  author_url: ''
  date: !binary |-
    MjAwOC0wOC0wMiAxNToxNTo1NiArMDgwMA==
  date_gmt: !binary |-
    MjAwOC0wOC0wMiAxNToxNTo1NiArMDgwMA==
  content: very nice!!!
- id: 1134
  author: 徐军"薄弱阁" &raquo; 用YSlow优化网站性能
  author_email: ''
  author_url: http://myeblog.3322.org/142.html
  date: !binary |-
    MjAxMC0wOC0xNiAxMzowMjoxMiArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wOC0xNiAwNTowMjoxMiArMDgwMA==
  content: ! '[...] 原文出处： http:&#47;&#47;seaprince.cn&#47;website_performance&#47;
    [...]'
---
<p><strong>知识点：<&#47;strong><&#47;p></p>
<ol>
<li>怎么样加快网页的加载速度？<&#47;li>
<li><a href="http:&#47;&#47;developer.yahoo.com&#47;performance&#47;rules.html">什么是YAHOO优化十三条规则<&#47;a>？<&#47;li>
<li>什么是<a href="https:&#47;&#47;addons.mozilla.org&#47;zh-CN&#47;firefox&#47;search?q=firebug&amp;cat=all">firebug<&#47;a>? 什么是<a href="https:&#47;&#47;addons.mozilla.org&#47;zh-CN&#47;firefox&#47;downloads&#47;file&#47;30781&#47;yslow-0.9.5b2-fx.xpi">YSlow<&#47;a>?<&#47;li>
<li>我想优化我的网站加载速度，应该从哪里开始？<&#47;li><br />
<&#47;ol></p>
<p><strong>最终效果：<&#47;strong><&#47;p></p>
<ol>
<li>网页加载速度有了明显的提升。<&#47;li>
<li>YSlow的分数明显增长。<&#47;li>
<li>用户浏览时，停顿感明显减少。<&#47;li><br />
<&#47;ol></p>
<p>&nbsp;<&#47;p></p>
<p><strong>结果数据：<&#47;strong><&#47;p></p>
<p>分项结果：<br &#47;><br />
[attach=124]<&#47;p></p>
<p>统计数据：<br &#47;><br />
[attach=125]<&#47;p></p>
<p>Performance Grade: A (99)&nbsp;&nbsp;&nbsp; Expand All Collapse All<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 1. Make fewer HTTP requests<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 2. Use a CDN<br &#47;><br />
Using these CDN hostnames from your preferences: cdn.eaxi.com<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 3. Add an Expires header<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 4. Gzip components<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 5. Put CSS at the top<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 6. Put JS at the bottom<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 7. Avoid CSS expressions<br &#47;><br />
n&#47;a&nbsp;&nbsp;&nbsp; 8. Make JS and CSS external<br &#47;><br />
Only consider this if your property is a common user home page.<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 9. Reduce DNS lookups<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 10. Minify JS<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 11. Avoid redirects<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 12. Remove duplicate scripts<br &#47;><br />
A&nbsp;&nbsp;&nbsp; 13. Configure ETags<&#47;p></p>
<p><strong>下面一条条地说说，怎么实现。<&#47;strong><&#47;p></p>
<ol>
<li>尽可能减少HTTP请求，一般采取的办法是减少图片量，多图组合成一图。<&#47;li>
<li>使用CDN。使用专门的域名来存放图片、JS脚本、CSS样式文件、FLASH文件等静态的内容。用独立于主域名的域名来做CDN，主要的原 因是防止COOKIE的干扰，因为如果有COOKIE的情况下，浏览器在HTTP请求时会把COOKIE发送给服务器。这里使用了 cdn.eaxi.com。这里也可以使用智能解析，让网通、电信、教育网的的用户选择最快的CDN。<&#47;li>
<li>给静态文件加上过期标志。让浏览器或者CDN服务器缓存起来，加速图片和其他静态文件的加载。<&#47;li>
<li>启用gzip压缩。gzip对文本的压缩效果非常好，而且主流浏览器也都支持gzip，建议启用。<&#47;li>
<li>把CSS文件置顶。这个主要是为了让浏览器可以即时渲染。也就是说，加载了一部分HTML，浏览器马上就可以将其渲染到最终效果，不用等待加载完毕。<&#47;li>
<li>把JS放到底部，这主要是防止JS在HTML加载完成前运行，加长网页的加载时间。<&#47;li>
<li>不用CSS expressions。这个IE-only的垃圾，考都不考虑。<&#47;li>
<li>把JS, CSS放到外部，让浏览器缓存。<&#47;li>
<li>减少域名解析次数。这里只使用了两个域名：http:&#47;&#47;blog.eaxi.com&#47; (主站)，http:&#47;&#47;cdn.eaxi.com&#47; (CDN)，这样，只需要进行两次域名解析。域名解析也是个耗时的头儿，要注意。这CDN一多，域名查询也多，是冲突的。大家按自己情况合理取舍。当然，如果是大站，可以考虑多几个CDN服务器，比如css.eaxi.com, js.eaxi.com，方便管理。<&#47;li>
<li>压缩JS, CSS。<&#47;li>
<li>避免重定向，重定向是浪费时间。<&#47;li>
<li>删除重复的脚本。<&#47;li>
<li>不用ETag。ETag是用于服务器和浏览器间文档校验的一种手段，如果匹配就使用缓存版本，不匹配的话，重新下载。但是使用CDN的时候，不同镜像间的ETag是不一样的，这就导致了ETag的失灵。我们删除ETag。<&#47;li><br />
<&#47;ol></p>
<p>这样处理后，网页速度已经得到极大的提升。<&#47;p></p>
<p><strong>技巧<&#47;strong><&#47;p></p>
<p>在处理过程中，有一些我发现的技巧可以参考：<&#47;p></p>
<p>CDN。很多朋友可能没有经济能力去架设CDN服务器，或者根本就没有必要。这时就可以考虑用别名的方式。比如，cdn.eaxi.com 只是blog.eaxi.com的一个别名，它们属于同一个虚拟主机。但是，blog.eaxi.com下的cookie不会干扰到 cdn.eaxi.com，这达到了CDN的一部分效果。<&#47;p></p>
<p>过期。对于Apache服务器，可以选择使用mod_expires或者mod_headers。我使用的是mod_headers。可以在.htaccess文件中加上：<&#47;p></p>
<p>&nbsp;# YEAR<br &#47;><br />
<FilesMatch "\.(flv|gif|ico|jpg|png|bmp)$"><br &#47;><br />
Header set Cache-Control "max-age=2592000"<br &#47;><br />
Header unset ETag<br &#47;><br />
Header set X-Powered-By "blog.eaxi.com"<br &#47;><br />
Header set Expires "Mon, 18 Jun 2018 05:30:47 GMT"<br &#47;><br />
Header set Age "567"<br &#47;><br />
Header set Connection "keep-alive"<br &#47;><br />
Header set Server "nginx 0.7.1"<br &#47;><br />
<&#47;FilesMatch><br &#47;><br />
<br &#47;><br />
# WEEK<br &#47;><br />
<FilesMatch "\.(pdf|swf|js|css)$"><br &#47;><br />
Header set Cache-Control "max-age=604800"<br &#47;><br />
Header unset ETag<br &#47;><br />
Header set X-Powered-By "blog.eaxi.com"<br &#47;><br />
Header set Expires "Mon, 18 Jun 2018 05:30:47 GMT"<br &#47;><br />
Header set Age "567"<br &#47;><br />
Header set Connection "keep-alive"<br &#47;><br />
Header set Server "nginx 0.7.1"<br &#47;><br />
<&#47;FilesMatch><&#47;p></p>
<p>如果你的服务器不支持mod_headers，可以选择mod_expires的方法：<&#47;p></p>
<p>ExpiresDefault "access plus 4 months"<br &#47;><br />
ExpiresByType text&#47;html "access plus 4 months"<br &#47;><br />
ExpiresByType image&#47;gif "modification plus 5 hours 3 minutes"<br &#47;><br />
ExpiresByType image&#47;jpg "modification plus 5 hours 3 minutes"<br &#47;><br />
ExpiresByType image&#47;png "modification plus 5 hours 3 minutes"<br &#47;><br />
ExpiresByType image&#47;bmp "modification plus 5 hours 3 minutes"<br &#47;><br />
ExpiresByType image&#47;js "modification plus 5 hours 3 minutes"<br &#47;><br />
ExpiresByType image&#47;css "modification plus 5 hours 3 minutes"<&#47;p></p>
<p>其中的时间可以按需要自己定制。<&#47;p></p>
<p>删除ETag。这个可以使用Header unset ETag禁用服务器ETag的发送。<&#47;p></p>
<p>&nbsp;<&#47;p></p>
<p>要完全关闭这个功能，可以使用YAHOO推荐的：<&#47;p></p>
<p>FileETag none<&#47;p></p>
<pre>可以直接加在.htaccess文件中。<&#47;pre></p>
