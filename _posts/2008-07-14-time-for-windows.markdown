---
layout: post
status: publish
published: true
title: C语言 程序时间统计器
author:
  display_name: ''
  login: Seaprince
  email: seaprince@mail.com
  url: ''
author_login: Seaprince
author_email: seaprince@mail.com
excerpt: <p>Unix command time for windows.</p>
wordpress_id: 207
date: !binary |-
  MjAwOC0wNy0xNCAxODoxNjoyMCArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wNy0xNCAxODoxNjoyMCArMDgwMA==
categories:
- 个人作品
tags: []
comments: []
---
<p>Unix command time for windows.<&#47;p></p>
<div class="codeText">
<div class="codeHead">C++代码<&#47;div></p>
<ol class="dp-cpp" start="1">
<li class="alt"><span><span class="comment">&#47;&#47;&nbsp;time.cpp&nbsp;:&nbsp;Defines&nbsp;the&nbsp;entry&nbsp;point&nbsp;for&nbsp;the&nbsp;console&nbsp;application.<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="comment">&#47;&#47;<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="preprocessor">#include&nbsp;<stdio.h><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><span class="preprocessor">#include&nbsp;<time.h><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="preprocessor">#include&nbsp;<windows.h><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="datatypes">int<&#47;span><span>&nbsp;gettime()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">time_t<&#47;span><span>&nbsp;t;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;time(&amp;t);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;t;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="keyword">void<&#47;span><span>&nbsp;printtime(<&#47;span><span class="datatypes">int<&#47;span><span>&nbsp;t)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">char<&#47;span><span>&nbsp;buf[20];&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(t<0)&nbsp;sprintf(buf,<&#47;span><span class="string">"%d&nbsp;s"<&#47;span><span>,0);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;<&#47;span><span class="keyword">if<&#47;span><span>&nbsp;(t<60)&nbsp;sprintf(buf,<&#47;span><span class="string">"%d&nbsp;s"<&#47;span><span>,t);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;<&#47;span><span class="keyword">if<&#47;span><span>&nbsp;(t<3600)&nbsp;sprintf(buf,<&#47;span><span class="string">"%d&nbsp;m&nbsp;%d&nbsp;s"<&#47;span><span>,t&#47;60,&nbsp;t%60);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;sprintf(buf,<&#47;span><span class="string">"%d&nbsp;h&nbsp;%d&nbsp;m&nbsp;%d&nbsp;s"<&#47;span><span>,t&#47;3600,&nbsp;(t%3600)&#47;60,&nbsp;(t%3600)%60);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;puts(buf);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="datatypes">int<&#47;span><span>&nbsp;main(<&#47;span><span class="datatypes">int<&#47;span><span>&nbsp;argc,&nbsp;<&#47;span><span class="datatypes">char<&#47;span><span>*&nbsp;argv[])&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>{&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>(argc<2)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;puts(<span class="string">"Nothing&nbsp;to&nbsp;run."<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;0;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;STARTUPINFO&nbsp;si={0};&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;PROCESS_INFORMATION&nbsp;pi;&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">int<&#47;span><span>&nbsp;i,t1,t2;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="datatypes">char<&#47;span><span>&nbsp;argstr[MAX_PATH]={<&#47;span><span class="string">""<&#47;span><span>};&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;si.cb=<span class="keyword">sizeof<&#47;span><span>(STARTUPINFO);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;t1=gettime();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for<&#47;span><span>(i=1;argv[i];i++)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;strcat(argstr,argv[i]);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;strcat(argstr,<span class="string">"&nbsp;"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="comment">&#47;&#47;puts(argv[1]);<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="comment">&#47;&#47;printf("%d\n",t1);<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>(CreateProcess(NULL,argstr,NULL,NULL,FALSE,0,NULL,NULL,&amp;si,&pi;))&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;WaitForSingleObject(pi.hProcess,INFINITE);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;t2=gettime();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="comment">&#47;&#47;printf("%d\n",t2);<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;printtime(t2-t1);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;printf(<span class="string">"Unable&nbsp;to&nbsp;run&nbsp;app!"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;0;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p><br &#47;><br />
仿linux的time程序。<&#47;p></p>
