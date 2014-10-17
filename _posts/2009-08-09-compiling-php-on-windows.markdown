---
layout: post
status: publish
published: true
title: Windows下源码编译PHP
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 434
wordpress_url: http://seaprince.cn/windows%e4%b8%8b%e6%ba%90%e7%a0%81%e7%bc%96%e8%af%91php/
date: !binary |-
  MjAwOS0wOC0wOSAwMTowMTowOCArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wOC0wOCAxNzowMTowOCArMDgwMA==
categories:
- 不想分类
tags:
- php
- windows
comments:
- id: 1075
  author: JeremyWei
  author_email: shuimuqingshu@gmail.com
  author_url: http://weizhifeng.net
  date: !binary |-
    MjAxMC0wNy0wNCAxNjo1MToxNSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNy0wNCAwODo1MToxNSArMDgwMA==
  content: ! '&ldquo;下一篇文章再写怎么编译pecl扩展&rdquo; 什么时候发表啊？'
- id: 1077
  author: admin
  author_email: combbs@gmail.com
  author_url: http://seaprince.cn/
  date: !binary |-
    MjAxMC0wNy0wNyAxMDoxMTo0OSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNy0wNyAwMjoxMTo0OSArMDgwMA==
  content: ! "<a href=\"#comment-1075\" rel=\"nofollow\">@JeremyWei <&#47;a> \n呵呵，后来忙了，就一直没写了。过段时间补上。"
- id: 1135
  author: 在Windows下源码编译PHP | Demon&#039;s Blog
  author_email: ''
  author_url: http://demon.tw/programming/compile-php-on-windows.html
  date: !binary |-
    MjAxMC0wOC0zMSAxNjoxNTo0NSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wOC0zMSAwODoxNTo0NSArMDgwMA==
  content: ! '[...] Windows下源码编译PHP [...]'
- id: 1138
  author: 编写PHP扩展实践 &laquo; 呆呆海族馆
  author_email: ''
  author_url: http://blog.eaxi.com/%e7%bc%96%e5%86%99php%e6%89%a9%e5%b1%95%e5%ae%9e%e8%b7%b5/
  date: !binary |-
    MjAxMS0wMS0xOSAwMDo1NToyNSArMDgwMA==
  date_gmt: !binary |-
    MjAxMS0wMS0xOCAxNjo1NToyNSArMDgwMA==
  content: ! '[...] on 用PHP通过邮箱获取QQ好友列表在Windows下源码编译PHP | Demon&#039;s Blog on Windows下源码编译PHP徐军"薄弱阁"
    &raquo; 用YSlow优化网站性能 on [...]'
---
<h3>开始前准备<&#47;h3><br />
开始之前，你需要准备如下东西：</p>
<ol>
<li>Microsoft Visual C++, 建议Visual C++ 2008, 速成版或专业版都可以。<&#47;li>
<li>Windows SDK，下载地址：<a href="http:&#47;&#47;www.microsoft.com&#47;downloads&#47;details.aspx?FamilyId=F26B1AA4-741A-433A-9BE5-FA919850BDBF&amp;displaylang=en">http:&#47;&#47;www.microsoft.com&#47;downloads&#47;details.aspx?FamilyId=F26B1AA4-741A-433A-9BE5-FA919850BDBF&amp;displaylang=en<&#47;a> 不建议用那个网络安装，慢死，还不知道什么时候能完。还有就是建议全部安装。<&#47;li>
<li>其他工具，下载地址：<a href="http:&#47;&#47;pecl2.php.net&#47;downloads&#47;php-windows-builds&#47;php-libs&#47;binary-tools.zip">http:&#47;&#47;pecl2.php.net&#47;downloads&#47;php-windows-builds&#47;php-libs&#47;binary-tools.zip<&#47;a><&#47;li><br />
<&#47;ol></p>
<h3>编译步骤<&#47;h3></p>
<ol>
<li>下载并安装VC++ 2008，并安装。<&#47;li>
<li>安装windows sdk 6.1<&#47;li>
<li>下载php5.3，下载地址：<a href="http:&#47;&#47;cn.php.net&#47;get&#47;php-5.3.0.tar.bz2&#47;from&#47;this&#47;mirror">http:&#47;&#47;cn.php.net&#47;get&#47;php-5.3.0.tar.bz2&#47;from&#47;this&#47;mirror<&#47;a><&#47;li>
<li>创建文件夹，比如C:\php-sdk<&#47;li>
<li>把上面第三步下载的包解压到这里，解压完时C:\php-sdk里应该有两个子目录bin, script<&#47;li>
<li>在开始菜单处打开Microsoft Windows SDK v6.1&#47;CMD Shell，输入命令：<br />
<span style="color: #ff00ff;">setenv &#47;x86 &#47;xp &#47;release<&#47;span><br />
<span style="color: #ff00ff;"> cd c:\php-sdk<&#47;span><br />
<span style="color: #ff00ff;"> bin\phpsdk_setvars.bat<&#47;span><br />
<span style="color: #ff00ff;"> bin\phpsdk_buildtree.bat php53dev<&#47;span><&#47;li></p>
<li>上一步会创建一些目录。进入vc9\x86，把php5.3.0解压在这里，解压后目录结构：vc9\x86\php5.3.0<&#47;li>
<li>在WIN-SDK的命令行下输入：<br />
<span style="color: #ff00ff;"> cd C:\php-sdk\php53dev\vc9\x86\php5.3.0<&#47;span><br />
<span style="color: #ff00ff;"> buildconf<&#47;span><&#47;li></p>
<li>到了这一步，就和linux下差不多了，你可以看一下编译的选项帮助：<br />
configure &ndash;help<&#47;li></p>
<li>好，我们来一个最小化的编译：<br />
<span style="color: #ff00ff;"> configure &ndash;disable-all &ndash;enable-cli<&#47;span><br />
<span style="color: #ff00ff;"> nmake<&#47;span><&#47;li></p>
<li>这一步在php wiki上是没有问题，但由于我们是中文环境，会报下面的错误：<br />
<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;08&#47;080809_1701_WindowsPHP1.png"><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;08&#47;080809_1701_WindowsPHP1.png" alt="" width="673" height="442" &#47;><&#47;a><&#47;li></p>
<li>用Editplus打开ext\standard\browscap.c这个文件，<br />
<img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;08&#47;080809_1701_WindowsPHP2.png" alt="" &#47;><br />
选是，并选择Western European (Windows)<img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;08&#47;080809_1701_WindowsPHP3.png" alt="" &#47;><br />
然后另存为UTF-8编码。<&#47;li></p>
<li>重新<span style="color: #ff00ff;">nmake<&#47;span>编译，然后用<span style="color: #ff00ff;">nmake snap<&#47;span>编译成最终二进制包。二进制包在php-5.3.0\Release_TS下。可能的名字是php-5.3.0-Win32-VC9-x86.zip<br />
<img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;08&#47;080809_1701_WindowsPHP4.png" alt="" &#47;><&#47;li></p>
<li>测试一下：<br />
<img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;08&#47;080809_1701_WindowsPHP5.png" alt="" &#47;><&#47;li><br />
<&#47;ol><br />
下一篇文章再写怎么编译pecl扩展。</p>
