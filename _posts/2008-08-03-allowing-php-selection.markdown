---
layout: post
status: publish
published: true
title: PHP4, PHP5, PHP6自由选择
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>今天给服务器装起了PHP4, PHP5, PHP6，并且可以让用户通过.htaccess自由选择PHP版本。同时也对mod_fcgid的的用法有了更深入的了解。</p>
wordpress_id: 212
date: !binary |-
  MjAwOC0wOC0wMyAxNTo0NTowNyArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wOC0wMyAwNzo0NTowNyArMDgwMA==
categories:
- 个人作品
tags:
- php
comments: []
---
<p>今天给服务器装起了PHP4, PHP5, PHP6，并且可以让用户通过.htaccess自由选择PHP版本。同时也对mod_fcgid的的用法有了更深入的了解。<br &#47;><br />
<br &#47;><br />
<strong>安装方法<&#47;strong>：<br &#47;><br />
PHP4: <br &#47;><br />
<a href="http:&#47;&#47;blog.eaxi.com&#47;wiki&#47;index.php&#47;Installing_PHP4">http:&#47;&#47;blog.eaxi.com&#47;wiki&#47;index.php&#47;Installing_PHP4<&#47;a><br &#47;><br />
<br &#47;><br />
PHP5:<br &#47;><br />
<a href="http:&#47;&#47;blog.eaxi.com&#47;wiki&#47;index.php&#47;Installing_PHP4">http:&#47;&#47;blog.eaxi.com&#47;wiki&#47;index.php&#47;Installing_PHP5<&#47;a><br &#47;><br />
<br &#47;><br />
PHP6:<br &#47;><br />
<a href="http:&#47;&#47;blog.eaxi.com&#47;wiki&#47;index.php&#47;Installing_PHP4">http:&#47;&#47;blog.eaxi.com&#47;wiki&#47;index.php&#47;Installing_PHP6<&#47;a><br &#47;><br />
<br &#47;><br />
<strong>使用方法<&#47;strong>：<br &#47;><br />
<br &#47;><br />
把后缀.php4的文件定义为PHP4文件。<br &#47;><br />
AddType application&#47;x-httpd-php .php4<br &#47;><br />
AddHandler php4-script .php4<br &#47;><br />
Action php4-script &#47;php4-bin&#47;php-cgi<br &#47;><br />
<br &#47;><br />
<br &#47;><br />
把后缀.php5的文件定义为PHP5文件。<br &#47;><br />
AddType application&#47;x-httpd-php .php5<br &#47;><br />
AddHandler php5-script .php5<br &#47;><br />
Action php5-script &#47;php5-bin&#47;php-cgi<br &#47;><br />
<br &#47;><br />
<br &#47;><br />
把后缀.php6的文件定义为PHP6文件。<br &#47;><br />
AddType application&#47;x-httpd-php .php6<br &#47;><br />
AddHandler php6-script .php6<br &#47;><br />
Action php6-script &#47;php6-bin&#47;php-cgi<br &#47;><br />
<br &#47;><br />
系统默认使用PHP5来解析.php的文件，你可以覆盖这个设置，用其他版本PHP来解析.php文件。<br &#47;><br />
AddType application&#47;x-httpd-php .php<br &#47;><br />
AddHandler php-script .php<br &#47;><br />
Action php-script &#47;php5-bin&#47;php-cgi<br &#47;><br />
<br &#47;><br />
<strong>前提<&#47;strong>：<br &#47;><br />
Apache必须有mod_actions, mod_fcgid支持。<&#47;p></p>
<p><strong>DEMO<&#47;strong>:<&#47;p></p>
<p><a href="http:&#47;&#47;u.eaxi.com&#47;phpinfo.php4">http:&#47;&#47;u.eaxi.com&#47;phpinfo.php4<&#47;a><br &#47;><br />
<a href="http:&#47;&#47;u.eaxi.com&#47;phpinfo.php5">http:&#47;&#47;u.eaxi.com&#47;phpinfo.php5<&#47;a><br &#47;><br />
<a href="http:&#47;&#47;u.eaxi.com&#47;phpinfo.php6">http:&#47;&#47;u.eaxi.com&#47;phpinfo.php6<&#47;a><br &#47;><br />
<a href="http:&#47;&#47;u.eaxi.com&#47;phpinfo.php">http:&#47;&#47;u.eaxi.com&#47;phpinfo.php<&#47;a><&#47;p></p>
<p>请留言报告BUG。。呵呵！<&#47;p></p>
