---
layout: post
status: publish
published: true
title: proftpd配置的几个要注意的地方
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>这里记录我玩proftpd的一些心得。</p>
wordpress_id: 209
date: !binary |-
  MjAwOC0wNy0yMiAxMDo0OTozNCArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wNy0yMiAwMjo0OTozNCArMDgwMA==
categories:
- 服务器
tags:
- proftpd
comments: []
---
<p>1. 必须要加的两行配置：<br &#47;><br />
<br &#47;><br />
UseReverseDNS off<br &#47;><br />
IdentLookups off<br &#47;><br />
<br &#47;><br />
如果你发现你的ftp超级慢，几秒到十几秒都没有连接完毕，那加上这两行试试。<br &#47;><br />
<br &#47;><br />
2&nbsp; 选择认证方式<br &#47;><br />
proftpd支持很多的认证方式，如passwd, PAM, sql, ldap等。<br &#47;><br />
ldap在国内貌似应用得不广，忽略。<br &#47;><br />
数据库有一个很大的好处就是便于管理，便于和别的程序整合用户系统。但是它的查询非常昂贵，因为每一次登陆都要做很多次的数据库查询。用SQLNegativeCache可以好一点，但是对于一个ftpd来说，还是觉得昂贵了。<br &#47;><br />
看官方的说法：<br &#47;><br />
<a href="http:&#47;&#47;www.castaglia.org&#47;proftpd&#47;doc&#47;contrib&#47;ProFTPD-mini-HOWTO-SQL.html ">http:&#47;&#47;www.castaglia.org&#47;proftpd&#47;doc&#47;contrib&#47;ProFTPD-mini-HOWTO-SQL.html <&#47;a><br &#47;><br />
<font color="red">Question<&#47;font>: How can I make <code>mod_sql<&#47;code> go faster?<br &#47;><br />
<font color="blue">Answer<&#47;font>: There are a couple of things you might try. First, if using a version of <code>mod_sql<&#47;code> from ProFTPD-1.2.7rc1 or later, make use of the <code>SQLNegativeCache<&#47;code> configuration directive.<&#47;p></p>
<p>Other forms of this question are "Why does <code>mod_sql<&#47;code> iterate through every user in the database?", or "Why is <code>mod_sql<&#47;code> so slow during logins?"  Here's the reason: <code>mod_sql<&#47;code> is designed to handle all authentication functions that the daemon throws at it. This includes the functions that iterate through all users (<code>setpwent()<&#47;code>, <code>getpwent()<&#47;code>, <code>endpwent()<&#47;code>) and the functions that iterate through all groups (<code>setgrent()<&#47;code>, <code>getgrent()<&#47;code>, <code>endgrent()<&#47;code>).<&#47;p></p>
<p>When you see <code>mod_sql<&#47;code> iterating through all groups or users, it is doing so because it has been asked to do so by the daemon.  Since there is no good way to keep an open query around without adding more to the various backend modules than we already have, <code>mod_sql<&#47;code> pre-caches all users when <code>setpwent()<&#47;code> is called, and pre-caches all groups when <code>setgrent()<&#47;code> is called.  This allows the <code>getpwent()<&#47;code> and <code>getgrent()<&#47;code> calls to be simple, at the cost of more time during login.<&#47;p></p>
<p>In simple situations, these functions are never called.  When you start limiting access to directories, files, or various FTP commands based on user or group, that is when the daemon needs to iterate through the users and groups to check permissions.  A basic FTP server, including virtual and anonymous servers, will never make the (potentially, very) expensive user iteration calls, but may iterate through all groups.<&#47;p></p>
<p>The <code>SQLAuthenticate<&#47;code> directive provides a method to tune <code>mod_sql<&#47;code>; by default, <code>mod_sql<&#47;code> will handle the various *<code>pwent()<&#47;code> and *<code>grent()<&#47;code> calls. When <code>SQLAuthenticate<&#47;code> is told not to handle <em>userset<&#47;em> or <em>groupset<&#47;em>, <code>mod_sql<&#47;code> simply passes the request on to whatever authentication handlers exist in the system.  Keep in mind that using <code>SQLAuthenticate<&#47;code> in this way means that the <code>proftpd<&#47;code> daemon is <strong>not<&#47;strong> using the same information to authenticate the user as it is to control the user's actions during their session.<&#47;p></p>
<p>For those of you who have used <code>mod_sql<&#47;code> in the past, these lookups should probably be set to <em>off<&#47;em>.  Versions of <code>mod_sql<&#47;code> prior to 3.2.0 (or thereabouts) did not handle the <code>{set|get|end}{pw|gr}ent<&#47;code> functions at all, so by setting these lookups to <em>off<&#47;em>, you lose no functionality.  Those of you new to <code>mod_sql<&#47;code> should to consider your needs: is the cost of iterating through every user stored in the database worth the ability to limit access based on users&#47;groups from the database?  If not, you will need to re-evaluate the way you are using the database, and where you should be storing your user&#47;group information.<&#47;p></p>
<p>PAM是一个不错的选择，但是它默认使用的是系统上真实存在的用户，管理用户（增、删、改）都涉及到系统用户的变动。<br &#47;><br />
<br &#47;><br />
passwd应该是建虚拟用户FTP的首选。它基本文本，速度快，开销小，可以让用户虚拟化，和系统用户可以没有直接关联，因为它指定了passwd文件，并代替系统的&#47;etc&#47;passwd供ftpd使用。<a href="http:&#47;&#47;www.castaglia.org&#47;proftpd&#47;doc&#47;contrib&#47;ProFTPD-mini-HOWTO-AuthFiles.html">http:&#47;&#47;www.castaglia.org&#47;proftpd&#47;doc&#47;contrib&#47;ProFTPD-mini-HOWTO-AuthFiles.html<&#47;a><br &#47;><br />
<br &#47;><br />
其它还有几种认证方式，在这里可以找到介绍：<a href="http:&#47;&#47;proftpd.org&#47;docs&#47;faq&#47;linked&#47;faq-ch7.html">http:&#47;&#47;proftpd.org&#47;docs&#47;faq&#47;linked&#47;faq-ch7.html<&#47;a><&#47;p></p>
