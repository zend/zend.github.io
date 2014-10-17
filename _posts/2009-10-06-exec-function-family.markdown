---
layout: post
status: publish
published: true
title: 对于exec函数家族的理解
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 471
wordpress_url: http://seaprince.cn/?p=471
date: !binary |-
  MjAwOS0xMC0wNiAyMzoxMjo1NSArMDgwMA==
date_gmt: !binary |-
  MjAwOS0xMC0wNiAxNToxMjo1NSArMDgwMA==
categories:
- 不想分类
tags:
- linux
comments: []
---
<p>在百度快照看到这篇文章，为了保护文物，特转之留念。<br />
原文链接：http:&#47;&#47;fenglei.blog.com.cn&#47;archives&#47;2005&#47;39431.shtml （运气好的话或许还能复活。）</p>
<p>很早就知道了exec这个函数家族，也知道它们的作用，但是没有认真分析过它们之间的区别，也不知道该在什么时候用哪个，近来看到这里，顺便总结出来，以方便自己并方便大家。总结如下：<br />
exec家族一共有六个函数，分别是：</p>
<p>int execl(const char *path, const char *arg, ......);<br />
int execle(const char *path, const char *arg, ...... , char * const envp[]);<br />
int execv(const char *path, char *const argv[]);<br />
int execve(const char *filename, char *const argv[], char *const envp[]);<br />
int execvp(const char *file, char * const argv[]);<br />
int execlp(const char *file, const char *arg, ......);</p>
<p>这些函数之间的<br />
第一个区别是：<br />
前四个取路径名做为参数，后两个取文件名做为参数，如果文件名中不包含 &ldquo;&#47;&rdquo; 则从PATH环境变量中搜寻可执行文件， 如果找到了一个可执行文件，但是该文件不是连接编辑程序产生的可执行代码文件，则当做shell脚本处理。<br />
第二个区别：<br />
前两个和最后一个函数中都包括&ldquo; l &rdquo;这个字母 ，而另三个都包括&ldquo; v &rdquo;， " l "代表 list即表 ，而" v "代表 vector即矢量，也是是前三个函数的参数都是以list的形式给出的，但最后要加一个空指针，如果用常数0来表示空指针，则必须将它强行转换成字符指 针，否则有可能出错。，而后三个都是以矢量的形式给出，即数组。<br />
最后一个区别：<br />
与向新程序传递环境变量有关，如第二个和第四个以e结尾的函数，可以向函数传递一个指向环境字符串指针数组的指针。即自个定义各个环境变量，而其它四个则使用进程中的环境变量。<br />
exec家族虽然有六个函数，但根据函数名还是可以很容易的区别开来，简单说到这里。<br />
本文参考一本UNIX编程书籍，很可惜我不知道书叫什么名字。</p>
<p>--转载结束--</p>
<p>我是看Beginning Linux Programming 3rd时，对这个家族的函数产生了兴趣，特百度之查明区别。下面是英文说明：</p>
<p>There is a whole family of related functions grouped under the exec heading. They differ in the way<br />
that they start processes and present program arguments. An exec function replaces the current process<br />
with a new process specified by the path or file argument.<br />
#include<br />
char **environ;<br />
int execl(const char *path, const char *arg0, ...,  (char *)0);<br />
int execlp(const char *file, const char *arg0, ...,  (char *)0);<br />
int execle(const char *path, const char *arg0, ...,  (char *)0, char *const<br />
envp[]);<br />
int execv(const char *path, char *const argv[]);<br />
int execvp(const char *file, char *const argv[]);<br />
int execve(const char *path, char *const argv[], char *const envp[]);<br />
In general, using system is a far from ideal way to start other processes, because it<br />
invokes the desired program using a shell. This is both inefficient, because a shell is<br />
started before the program is started, and also quite dependent on the installation<br />
for the shell and environment that are used. In the next section, we see a much better<br />
way of invoking programs, which should almost always be used in preference to the<br />
system call.<br />
453<br />
Processes and Signals<br />
b544977 Ch11.qxd  12&#47;1&#47;03  8:56 AM  Page 453These functions belong to two types. execl, execlp, and execle take a variable number of arguments<br />
ending with a null pointer. execv and execvp have as their second argument an array of strings. In both<br />
cases, the new program starts with the given arguments appearing in the argv array passed to main.<br />
These functions are usually implemented using execve, though there is no requirement for it to be done<br />
this way.<br />
The functions with names suffixed with a p differ in that they will search the PATH environment variable<br />
to find the new program executable file. If the executable isn&rsquo;t on the path, an absolute file name, includ-<br />
ing directories, will need to be passed to the function as a parameter.<br />
The global variable environ is available to pass a value for the new program environment.<br />
Alternatively, an additional argument to the functions execle and execve is available for passing an<br />
array of strings to be used as the new program environment.<br />
If we wish to use an exec function to start the ps program, we can choose from among the six exec family<br />
functions, as shown in the calls in the code fragment that follows</p>
