---
layout: post
status: publish
published: true
title: Linux&#47;Unix网络编程指南(Socket 编程)
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: ! "<p><strong>介绍 <br />\r\n</strong>Hey! Socket 编程让你沮丧吗？从 man pages 中很难得到有用的信息吗？你想
  跟上时代去做一做 Internet 程序，但是为你在调用 connect() 前的 bind() 的结构而愁眉不展？&hellip; <br />\r\n好了，我现在已经来了，我将和所有人共享我的知识了。如果你了解
  C 语言并想穿过 网络编程的沼泽，那么你来对地方了。</p>"
wordpress_id: 183
date: !binary |-
  MjAwOC0wMi0xMCAyMTo1NzowMSArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMi0xMCAxMzo1NzowMSArMDgwMA==
categories:
- 收藏夹
tags:
- linux
comments: []
---
<p><strong>介绍 <br &#47;><br />
<&#47;strong>Hey! Socket 编程让你沮丧吗？从 man pages 中很难得到有用的信息吗？你想 跟上时代去做一做 Internet 程序，但是为你在调用 connect() 前的 bind() 的结构而愁眉不展？&hellip; <br &#47;><br />
好了，我现在已经来了，我将和所有人共享我的知识了。如果你了解 C 语言并想穿过 网络编程的沼泽，那么你来对地方了。 <br &#47;><br />
<strong>读者<&#47;strong> <br &#47;><br />
这个文档是写成一个指南，而不是参考书。如果你刚开始 socket 编程并想找一本 入门书，那么你是我的读者。这可不是一本完全的 socket 编程书。 <br &#47;><br />
<strong>平台和编译器 <br &#47;><br />
<&#47;strong>这篇文章中的大多数代码都在一台 Linux PC 上用 GNU 的 gcc 成功编译过。 而且他们在一台 HPUX 上用 gcc 也成功编译过。但是注意，并不是每个代码 片段都独立测试过。 <br &#47;><br />
<a name="more"><&#47;a>-------------------------------------------------------------------------------- <br &#47;><br />
<strong>目录<&#47;strong>： <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#什么是 socket？">什么是套接口？ <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#Internet 套接口的两种类型">Internet 套接口的两种类型 <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#网络理论">网络理论 <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#structs">struct--要么了解他们，要么等异形入侵地球<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#Convert the Natives!">Convert the Natives! <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#IP 地址和如何处理他们">IP 地址和如何处理他们 <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#socket()--得到文件描述符！">socket()--得到文件描述符！<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#bind()--我在哪个端口">bind()--我们在哪个端口？<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#connect()--Hello！">connect()--Hello！<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#listen">listen()--有人给我打电话吗？<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#accept">accept()--"Thank you for calling port 3490." <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#send">send() 和 recv()--Talk to me, baby! <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#sendto">sendto() 和 recvfrom()--Talk to me, DGRAM-style <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#close">close() 和 shutdown()--滚开！<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#getpeername">getpeername()--你是谁？<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#gethostname">gethostname()--我是谁？<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#DNS">DNS--你说&ldquo;白宫&rdquo;，我说 "198.137.240.100"<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#Client-Server Background">客户-服务器背景知识 <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#简单的服务器">简单的服务器<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#简单的客户程序">简单的客户端 <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#数据报 Sockets">数据报 Socket<&#47;a> <br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#阻塞">阻塞 <&#47;a><br &#47;><br />
<a href="http:&#47;&#47;www.winterxy.com&#47;blog&#47;000050.html#select()--多路同步 I&#47;O">select()--多路同步 I&#47;O，酷！<&#47;a> <br &#47;><br />
<br &#47;><br />
参考资料 <br &#47;><br />
Disclaimer and Call for Help <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="什么是 socket？">什么是 socket？<&#47;a> <br &#47;><br />
你始终听到人们谈论着 "socket"，而你不知道他的确切含义。那么，现在我告诉你： 他是使用 Unix 文件描述符 (fiel descriptor) 和其他程序通讯的方式。 <br &#47;><br />
什么？ <br &#47;><br />
Ok--你也许听到一些 Unix 高手 (hacker) 这样说：&ldquo;呀，Unix 中所有的东西就是文件！&rdquo;那个家伙也许正在说到一个事实：Unix 程序在执行任何形式的 I&#47;O 的时候，程序是在读或者写一个文件描述符。一个文件描述符只是一个和打开的文件相关联的整数。但是(注意后面的话)，这个文件可能是一个网络连接，FIFO，管道，终端，磁盘上的文件 或者什么其他的东西。Unix 中所有的东西是文件！因此，你想和 Internet 上别 的程序通讯的时候，你将要通过文件描述符。最好相信刚才的话。 <br &#47;><br />
现在你脑海中或许冒出这样的念头：&ldquo;那么我从哪里得到网络通讯的文件描述符呢，聪明 人？&rdquo;无论如何，我要回答这个问题：你利用系统调用 socket()。他返回套接口描 述符 (socket descriptor)，然后你再通过他来调用 send() 和 recv()。 <br &#47;><br />
&ldquo;但是...&rdquo;，你可能现在叫起来，&ldquo;如果他是个文件描述符，那么为什么不用一般的调用 read() 和 write() 来通过套接口通讯？&rdquo;简单的答案是：&ldquo;你可以使用 一般的函数！&rdquo;。详细的答案是：&ldquo;你可以，但是使用 send() 和 recv() 让你更好的控制数据传输。&rdquo; <br &#47;><br />
有这样一个事实：在我们的世界上，有很多种套接口。有 DARPA Internet 地址 (Internet 套接口)，本地节点的路径名 (Unix 套接口)，CCITT X.25 地址 (你可以完全忽略 X.25 套接口)。 也许在你的 Unix 机器上还有其他的。我们在这里只讲第一种：Internet 套接口。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="Internet 套接口的两种类型">Internet 套接口的两种类型 <&#47;a><br &#47;><br />
什么意思？有两种 Internet 套接口？是的。不，我在撒谎。其实还有很多，但是我可不想 吓着你。我们这里只讲两种。 Except for this sentence, where I'm going to tell you that "Raw Sockets" are also very powerful and you should look them up. <br &#47;><br />
好了，好了。那两种类型是什么呢？一种是 "Stream Sockets"，另外一种是 "Datagram Sockets"。我们以后谈到他们的时候也会用到 "SOCK_STREAM" 和 "SOCK_DGRAM"。数据报套接口有时也叫&ldquo;无连接套接口&rdquo;(如果你确实要连接的时候用 connect()。) <br &#47;><br />
流式套接口是可靠的双向通讯的数据流。如果你向套接口安顺序输出&ldquo;1，2&rdquo;，那么他们 将安顺序&ldquo;1，2&rdquo;到达另一边。他们也是无错误的传递的，有自己的错误控制。 <br &#47;><br />
有谁在使用流式套接口？你可能听说过 telnet，不是吗？他就使用流式套接口。你需要你所输入的字符按顺序到达，不是 吗？同样，WWW 浏览器使用的 HTTP 协议也使用他们。实际上，当你通过端口80 telnet 到一个 WWW 站点，然后输入 &ldquo;GET pagename&rdquo; 的时候，你也可以得到 HTML 的内容。 <br &#47;><br />
为什么流式套接口可以达到高质量的数据传输？他使用了&ldquo;传输控制协议 (The Transmission Control Protocol)&rdquo;，也叫 &ldquo;TCP&rdquo; (请参考 RFC-793 获得详细资料。)TCP 控制你的数据 按顺序到达并且没有错误。你也许听到 &ldquo;TCP&rdquo; 是因为听到过 &ldquo;TCP&#47;IP&rdquo;。这里的 IP 是指 &ldquo;Internet 协议&rdquo;(请参考 RFC-791.) IP 只是处理 Internet 路由而已。 <br &#47;><br />
那么数据报套接口呢？为什么他叫无连接呢？为什么他是不可靠的呢？恩，有这样的事实：如果你发送一个数据报，他可能到达，他可能次序颠倒了。如果他到达，那么在这个包的内部是无错误的。 <br &#47;><br />
数据报也使用 IP 作路由，但是他不选择 TCP。他使用&ldquo;用户数据报协议 (User Datagram Protocol)&rdquo;，也叫 &ldquo;UDP&rdquo; (请参考 RFC-768.) <br &#47;><br />
为什么他们是无连接的呢？主要原因是因为他并不象流式套接口那样维持一个连接。 你只要建立一个包，在目标信息中构造一个 IP 头，然后发出去。不需要连接。应用程序有： tftp, bootp 等等。 <br &#47;><br />
&ldquo;够了！&rdquo;你也许会想，&ldquo;如果数据丢失了这些程序如何正常工作？&rdquo;我的朋友，每个程序在 UDP 上有自己的协议。例如，tftp 协议每发出一个包，收到者发回一个包来说&ldquo;我收到了！&rdquo; (一个&ldquo;命令正确应答&rdquo;也叫&ldquo;ACK&rdquo; 包)。如果在一定时间内(例如5秒)，发送方没有收到应答， 他将重新发送，直到得到 ACK。这一点在实现 SOCK_DGRAM 应用程序的时候非常重要。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="网络理论">网络理论 <&#47;a><br &#47;><br />
既然我刚才提到了协议层，那么现在是讨论网络究竟如何工作和演示 SOCK_DGRAM 的工作。当然，你也可以跳过这一段，如果你认为 已经熟悉的话。 <br &#47;><br />
朋友们，现在是学习 数据封装 (Data Encapsulation) 的时候了！ 这非常非常重要。It's so important that you might just learn about it if you take the networks course here at Chico State ;-). 主要的内容是：一个包，先是被第一个协议(在这里是 TFTP )包装(&ldquo;封装&rdquo;)， 然后，整个数据(包括 TFTP 头)被另外一个协议(在这里是 UDP )封装，然后下 一个( IP )，一直重复下去，直到硬件(物理)层( Ethernet )。 <br &#47;><br />
当另外一台机器接收到包，硬件先剥去 Ethernet 头，内核剥去 IP 和 UDP 头，TFTP 程序再剥去 TFTP 头，最后得到数据。 <br &#47;><br />
现在我们终于讲到臭名远播的 网络分层模型 (Layered Network Model)。这种网络模型在描述网络系统上相对其他模型有很多优点。例如，你可以写一个套接口 程序而不用关心数据的物理传输(串行口，以太网，连接单元接口 (AUI) 还是其他介质。 因为底层的程序为你处理他们。实际的网络硬件和拓扑对于程序员来说是透明的。 <br &#47;><br />
不说其他废话了，我现在列出整个层次模型。如果你要参加网络考试，可一定要记住： <br &#47;><br />
应用层 (Application) <br &#47;><br />
表示层 (Presentation) <br &#47;><br />
会话层 (Session) <br &#47;><br />
传输层 (Transport) <br &#47;><br />
网络层 (Network) <br &#47;><br />
数据链路层 (Data Link) <br &#47;><br />
物理层 (Physical) <br &#47;><br />
物理层是硬件(串口，以太网等等)。应用层是和硬件层相隔最远的--他是用户和网络 交互的地方。 <br &#47;><br />
这个模型如此通用，如果你想，你可以把他作为修车指南。把他应用到 Unix，结果是: <br &#47;><br />
应用层 (Application Layer) (telnet, ftp, 等等) <br &#47;><br />
传输层 (Host-to-Host Transport Layer) (TCP, UDP) <br &#47;><br />
Internet 层 (Internet Layer) (IP 和路由) <br &#47;><br />
网络访问层 (Network Access Layer) (网络层，数据链路层和物理层) <br &#47;><br />
现在，你可能看到这些层次如何协调来封装原始的数据了。 <br &#47;><br />
看看建立一个简单的数据包有多少工作？哎呀，你将不得不使用 "cat" 来完成 他们！简直是笑话。对于流式套接口你要作的是 send() 发送数据。对于数据报 式套接口你按照你选择的方式封装数据然后用 sendto()。内核将为你建立传输 层和 Internet 层，硬件完成网络访问层。这就是现代科技。 <br &#47;><br />
现在结束我们的网络理论速成班。哦，忘记告诉你关于路由的事情了。但是我不准备谈他。 如果你真的想知道，那么参考 IP RFC。如果你从来不曾了解他，也没有 关系，你还活着不是吗。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="structs">structs <&#47;a><br &#47;><br />
终于到达这里了，终于谈到编程了。在这章，我将谈到被套接口用到的各种数据类型。因为 他们中的一些太重要了。 <br &#47;><br />
首先是简单的一个：socket descriptor。他是下面的类型： <br &#47;><br />
&nbsp; int <br &#47;><br />
仅仅是一个常见的 int。 <br &#47;><br />
从现在起，事情变得不可思议了。请跟我一起忍受苦恼吧。注意这样的事实： 有两种字节排列顺序：重要的字节在前面(有时叫 "octet")，或者不重要的字节在前面。 前一种叫&ldquo;网络字节顺序 (Network Byte Order)&rdquo;。有些机器在内部是按照这个顺序储存数据，而另外一些则不然。当我说某数据必须按照 NBO 顺序，那么你要调用函数(例 如 htons() )来将他从本机字节顺序 (Host Byte Order) 转换过来。如果我 没有提到 NBO， 那么就让他是本机字节顺序吧。 <br &#47;><br />
我的第一个结构(TM)--struct sockaddr. 这个数据结构 为许多类型的套接口储存套接口地址信息： <br &#47;><br />
<font color="#0000ff">struct<&#47;font> sockaddr { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">unsigned<&#47;font> <font color="#0000ff">short<&#47;font>&nbsp;&nbsp;sa_family;&nbsp;&nbsp;&#47;* address family, AF_xxx&nbsp;&nbsp;&nbsp; *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">char<&#47;font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sa_data[14];&nbsp;&#47;* 14 bytes of protocol address *&#47; <br &#47;><br />
}; <br &#47;><br />
sa_family 能够是各种各样的事情，但是在这篇文章中是 "AF_INET"。 sa_data 为套接口储存目标地址和端口信息。看上去很笨拙，不是吗。 <br &#47;><br />
为了对付 struct sockaddr，程序员创造了一个并列的结构： struct sockaddr_in ("in" 代表 "Internet".) <br &#47;><br />
<font color="#0000ff">struct<&#47;font> sockaddr_in { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">short<&#47;font> <font color="#0000ff">int<&#47;font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sin_family;&nbsp;&#47;* Address family&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">unsigned<&#47;font> <font color="#0000ff">short<&#47;font> <font color="#0000ff">int<&#47;font> sin_port;&nbsp;&nbsp;&#47;* Port number&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> in_addr&nbsp;&nbsp; sin_addr;&nbsp;&nbsp;&#47;* Internet address&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">unsigned<&#47;font> <font color="#0000ff">char<&#47;font>&nbsp;&nbsp;&nbsp;sin_zero[8]; &#47;* Same size as struct sockaddr *&#47; <br &#47;><br />
<br &#47;><br />
}; <br &#47;><br />
这个数据结构让可以轻松处理套接口地址的基本元素。注意 sin_zero (他 被加入到这个结构，并且长度和 struct sockaddr 一样) 应该使用函数 bzero() 或 memset() 来全部置零。 Also, and this is the important bit, a pointer to a struct sockaddr_in can be cast to a pointer to a struct sockaddr and vice-versa. 这样的话 即使 socket() 想要的是 struct sockaddr *， 你仍然可以使用 struct sockaddr_in，and cast it at the last minute! 同时，注意 sin_family 和 struct sockaddr 中的 sa_family 一致并能够设置为 "AF_INET"。最后， sin_port 和 sin_addr 必须是网络字节顺序 (Network Byte Order)！ <br &#47;><br />
你也许会反对道："但是，怎么让整个数据结构 struct in_addr sin_addr 按照网络字节顺序呢?" 要知道这个问题的答案，我们就要仔细的看一 看这个数据结构： struct in_addr, 有这样一个联合 (unions)： <br &#47;><br />
&#47;* Internet address (a structure for historical reasons) *&#47; <br &#47;><br />
&nbsp; <font color="#0000ff">struct<&#47;font> in_addr { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">unsigned<&#47;font> <font color="#0000ff">long<&#47;font> s_addr; <br &#47;><br />
&nbsp; }; <font color="#0000ff"><br &#47;><br />
<&#47;font>他曾经是个最坏的联合，但是现在那些日子过去了。如果你声明 "ina" 是 数据结构 struct sockaddr_in 的实例，那么 "ina.sin_addr.s_addr" 就储存4字节的 IP 地址(网络字节顺序)。如果你不幸的 系统使用的还是恐怖的联合 struct in_addr ，你还是可以放心4字 节的 IP 地址是和上面我说的一样(这是因为 #define。) <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="Convert the Natives!">Convert the Natives! <&#47;a><br &#47;><br />
我们现在到达下个章节。我们曾经讲了很多网络到本机字节顺序，现在是采取行动的时刻了！ <br &#47;><br />
你能够转换两种类型： short (两个字节)和 long (四个字节)。这个 函数对于变量类型 unsigned 也适用。假设你想将 short 从本机字节顺序 转换为网络字节顺序。用 "h" 表示 "本机 (host)"，接着是 "to"，然后用 "n" 表示 "网络 (network)"，最后用 "s" 表示 "short"： h-to-n-s, 或者 htons() ("Host to Network Short")。 <br &#47;><br />
太简单了... <br &#47;><br />
如果不是太傻的话，你一定想到了组合 "n"，"h"，"s"，和 "l"。但是这里没有 stolh() ("Short to Long Host") 函数，但是这里有： <br &#47;><br />
htons()--"Host to Network Short" <br &#47;><br />
htonl()--"Host to Network Long" <br &#47;><br />
ntohs()--"Network to Host Short" <br &#47;><br />
ntohl()--"Network to Host Long" <br &#47;><br />
现在，你可能想你已经知道他们了。你也可能想："如果我改变 char 的顺序会 怎么样呢? 我的 68000 机器已经使用了网络字节顺序，我没有必要去调用 htonl() 转换 IP 地址。" 你可能是对的，但是当你移植你的程序到别的机器上的时候，你的程序将 失败。可移植性！这里是 Unix 世界！记住：在你将数据放到网络上的时候，确信他们是网络字 节顺序。 <br &#47;><br />
最后一点：为什么在数据结构 struct sockaddr_in 中， sin_addr 和 sin_port 需要转换为网络字节顺序，而 sin_family 不需要呢? 答案是：sin_addr 和 sin_port 分别封装在包的 IP 和 UDP 层。因此，他们必须要是网络字节顺序。 但是 sin_family 域只是被内核 (kernel) 使用来决定在数据结构中包含什么类型的地址，所以他应该是本机字节顺序。也即 sin_family 没有 发 送到网络上，他们可以是本机字节顺序。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="IP 地址和如何处理他们">IP 地址和如何处理他们 <&#47;a><br &#47;><br />
现在我们很幸运，因为我们有很多的函数来方便地操作 IP 地址。没有必要用手工计算 他们，也没有必要用 << 操作符来操作 long。 <br &#47;><br />
首先，假设你用 struct sockaddr_in ina，你想将 IP 地址 "132.241.5.10" 储存到其中。你要用的函数是 inet_addr()，转换 numbers-and-dots 格式的 IP 地址到 unsigned long。这个工作可以这样来做： <br &#47;><br />
&nbsp; ina.sin_addr.s_addr = inet_addr("132.241.5.10"); <br &#47;><br />
注意：inet_addr() 返回的地址已经是按照网络字节顺序的，你没有必要再去调用 htonl()。 <br &#47;><br />
上面的代码可不是很健壮 (robust)，因为没有错误检查。inet_addr() 在发生错误 的时候返回-1。记得二进制数吗? 在 IP 地址为 255.255.255.255 的时候返回的是 (unsigned)-1！这是个广播地址！记住正确的使用错误检查。 <br &#47;><br />
好了，你现在可以转换字符串形式的 IP 地址为 long 了。那么你有一个数据结构 struct in_addr，该如何按照 numbers-and-dots 格式打印呢? 在这个 时候，也许你要用函数 inet_ntoa() ("ntoa" 意思是 "network to ascii")： <br &#47;><br />
&nbsp; printf("%s",inet_ntoa(ina.sin_addr)); <br &#47;><br />
他将打印 IP 地址。注意的是：函数 inet_ntoa() 的参数是 struct in_addr，而不是 long。同时要注意的是他返回的是一个指向字符的指针。 在 inet_ntoa 内部的指针静态地储存字符数组，因此每次你调用 inet_ntoa() 的时候他将覆盖以前的内容。例如： <br &#47;><br />
&nbsp; <font color="#0000ff">char<&#47;font> *a1, *a2; <br &#47;><br />
&nbsp; . <br &#47;><br />
&nbsp; . <br &#47;><br />
&nbsp; a1 = inet_ntoa(ina1.sin_addr);&nbsp;&#47;* this is 198.92.129.1 *&#47; <br &#47;><br />
&nbsp; a2 = inet_ntoa(ina2.sin_addr);&nbsp;&#47;* this is 132.241.5.10 *&#47; <br &#47;><br />
&nbsp; <font color="#0000ff">printf<&#47;font>("address 1: %s\n",a1); <br &#47;><br />
&nbsp; <font color="#0000ff">printf<&#47;font>("address 2: %s\n",a2); <br &#47;><br />
运行结果是： <br &#47;><br />
&nbsp; address 1: 132.241.5.10 <br &#47;><br />
&nbsp; address 2: 132.241.5.10 <br &#47;><br />
如果你想保存地址，那么用 strcpy() 保存到自己的字符数组中。 <br &#47;><br />
这就是这章的内容了。以后，我们将学习转换 "whitehouse.gov" 形式的字符串到正确 的 IP 地址(请看后面的 DNS 一章。) <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="socket()--得到文件描述符！">socket()--得到文件描述符！<&#47;a> <br &#47;><br />
我猜我不会再扯远了--我必须讲 socket() 这个系统调用了。这里是详细的定义： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; int socket(int domain, int type, int protocol); <br &#47;><br />
但是他们的参数怎么用? 首先，domain 应该设置成 "AF_INET"，就象上面的 数据结构 struct sockaddr_in 中一样。然后，参数 type 告诉内核是 SOCK_STREAM 类型还是 SOCK_DGRAM 类型。最后，把 protocol 设置为 "0"。(注意：有很多种 domain、type， 我不可能一一列出了，请看 socket() 的 man page。当然，还有一个"更好"的方式 去得到 protocol。请看 getprotobyname() 的 man page。) <br &#47;><br />
socket() 只是返回你以后在系统调用种可能用到的 socket 描述符，或者在错误 的时候返回-1。全局变量 errno 中储存错误值。(请参考 perror() 的 man page。) <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="bind()--我在哪个端口">bind()--我在哪个端口? <&#47;a><br &#47;><br />
一旦你得到套接口，你可能要将套接口和机器上的一定的端口关联起来。(如果你想用 listen() 来侦听一定端口的数据，这是必要一步--MUD 经常告诉你说用命令 "telnet x.y.z 6969".)如果你只想用 connect()，那么这个步骤没有必要。但是无论如何，请继续读下去。 <br &#47;><br />
这里是系统调用 bind() 的大略： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> bind(<font color="#0000ff">int<&#47;font> sockfd, <font color="#0000ff">struct<&#47;font> sockaddr *my_addr, <font color="#0000ff">int<&#47;font> addrlen); <br &#47;><br />
sockfd 是调用 socket 返回的文件描述符。my_addr 是指向 数据结构 struct sockaddr 的指针，他保存你的地址(即端口和 IP 地址) 信息。addrlen 设置为 sizeof(struct sockaddr)。 <br &#47;><br />
简单得很不是吗? 再看看例子： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <string.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> MYPORT 3490 <br &#47;><br />
&nbsp; <font color="#0000ff">main<&#47;font>() <br &#47;><br />
&nbsp; { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> sockfd; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in my_addr; <br &#47;><br />
&nbsp;&nbsp;&nbsp; sockfd = socket(AF_INET, SOCK_STREAM, 0); &#47;* do some error checking! *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_family = AF_INET;&nbsp;&nbsp; &#47;* host byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_port = htons(MYPORT); &#47;* short, network byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_addr.s_addr = inet_addr("132.241.5.10"); <br &#47;><br />
&nbsp;&nbsp;&nbsp; bzero(&amp;(my_addr.sin_zero), 8);&nbsp;&nbsp;&#47;* zero the rest of the struct *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; &#47;* don't forget your error checking for bind(): *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; bind(sockfd, (struct sockaddr *)&amp;my_addr, sizeof(struct sockaddr)); <br &#47;><br />
&nbsp;&nbsp;&nbsp;. <br &#47;><br />
&nbsp;&nbsp;&nbsp;. <br &#47;><br />
&nbsp;&nbsp;&nbsp;. <br &#47;><br />
这里也有要注意的几件事情。my_addr.sin_port 是网络字节顺序，my_addr.sin_addr.s_addr 也是的。另外要注意到的事情是因系统的不同， 包含的头文件也不尽相同，请查阅自己的 man page。 <br &#47;><br />
在 bind() 主题中最后要说的话是，在处理自己的 IP 地址和&#47;或端口的时候，有些工作 是可以自动处理的。 <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_port = 0; &#47;* choose an unused port at random *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_addr.s_addr = INADDR_ANY;&nbsp;&#47;* use my IP address *&#47; <br &#47;><br />
通过将0赋给 my_addr.sin_port，你告诉 bind() 自己选择合适的端口。同样， 将 y_addr.sin_addr.s_addr 设置为 INADDR_ANY，你告诉他自动填上 他所运行的机器的 IP 地址。 <br &#47;><br />
如果你一向小心谨慎，那么你可能注意到我没有将 INADDR_ANY 转换为网络字节顺序！这是因为我知道内部的东西：INADDR_ANY 实际上就是 0！即使你 改变字节的顺序，0依然是0。但是完美主义者说安全第一，那么看下面的代码： <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_port = htons(0); &#47;* choose an unused port at random *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_addr.s_addr = htonl(INADDR_ANY);&nbsp;&#47;* use my IP address *&#47; <br &#47;><br />
你可能不相信，上面的代码将可以随便移植。 <br &#47;><br />
bind() 在错误的时候依然是返回-1，并且设置全局变量 errno。 <br &#47;><br />
在你调用 bind() 的时候，你要小心的另一件事情是：不要采用小于1024的端口号。所有小于1024的端口号都 被系统保留！你可以选择从1024到65535(如果他们没有被别的程序使用的话)。 <br &#47;><br />
你要注意的另外一件小事是：有时候你根本不需要调用他。如果你使用 connect() 来和远程机器通讯，你不要关心你的本地端口号(就象你在使用 telnet 的时候)，你只要 简单的调用 connect() 就够可，他会检查套接口是否绑定，如果没有，他会自己绑定 一个没有使用的本地端口。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="connect()--Hello！">connect()--Hello！ <&#47;a><br &#47;><br />
现在我们假设你是个 telnet 程序。你的用户命令你(就象电影 TRON 中一样)得到套接口 的文件描述符。你听从命令调用了 socket()。下一步，你的用户告诉你通过端口23(标 准 telnet 端口)连接到"132.241.5.10"。你该怎么做呢? <br &#47;><br />
幸运的是，你正在疯狂地阅读 connect()--如何连接到远程主机这一章。你可不想让 你的用户失望。 <br &#47;><br />
connect() 系统调用是这样的： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> connect(<font color="#0000ff">int<&#47;font> sockfd, <font color="#0000ff">struct<&#47;font> sockaddr *serv_addr, <font color="#0000ff">int<&#47;font> addrlen); <br &#47;><br />
sockfd 是系统调用 socket() 返回的套接口文件描述符。serv_addr 是保存着目的地端口和 IP 地址的数据结构 struct sockaddr。addrlen 设置为 sizeof(struct sockaddr)。 <br &#47;><br />
让我们来看个例子： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <string.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> DEST_IP&nbsp; "132.241.5.10" <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> DEST_PORT 23 <br &#47;><br />
&nbsp; main() <br &#47;><br />
&nbsp; { <font color="#0000ff"><br &#47;><br />
<&#47;font>&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> sockfd; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in dest_addr;&nbsp; &#47;* will hold the destination addr *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;sockfd = socket(AF_INET, SOCK_STREAM, 0); &#47;* do some error checking! *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; dest_addr.sin_family = AF_INET;&nbsp;&nbsp;&nbsp;&nbsp;&#47;* host byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; dest_addr.sin_port = htons(DEST_PORT); &#47;* short, network byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; dest_addr.sin_addr.s_addr = inet_addr(DEST_IP); <br &#47;><br />
&nbsp;&nbsp;&nbsp; bzero(&amp;(dest_addr.sin_zero), 8);&nbsp;&nbsp;&nbsp; &#47;* zero the rest of the struct *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; &#47;* don't forget to error check the connect()! *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; connect(sockfd, (struct sockaddr *)&amp;dest_addr, <font color="#0000ff">sizeof<&#47;font>(<font color="#0000ff">struct<&#47;font> sockaddr)); <br &#47;><br />
&nbsp;&nbsp;&nbsp; . <br &#47;><br />
&nbsp;&nbsp;&nbsp; . <br &#47;><br />
&nbsp;&nbsp;&nbsp; . <br &#47;><br />
再一次，你应该检查 connect() 的返回值--他在错误的时候返回-1，并 设置全局变量 errno。 <br &#47;><br />
同时，你可能看到，我没有调用 bind()。另外，我也没有管本地的端口号。我只关心 我在连接。内核将为我选择一个合适的端口号，而我们所连接的地方也自动地获得这些信息。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="listen">listen<&#47;a>()--Will somebody please call me? <br &#47;><br />
Ok, time for a change of pace. What if you don't want to connect to a remote host. Say, just for kicks, that you want to wait for incoming connections and handle them in some way. 处理过程分两步：首先，你听--listen()，然后，你接受--accept() (请看 下面的内容)。 <br &#47;><br />
除了要一点解释外，系统调用 listen 相当简单。 <br &#47;><br />
&nbsp;int listen(int sockfd, int backlog); <br &#47;><br />
sockfd 是调用 socket() 返回的套接口文件描述符。backlog 是 在进入队列中允许的连接数目。是什么意思呢? 进入的连接是在队列中一直等待直到你接受 (accept() 请看下面的文章)的连接。他们的数目限制于队列的允许。大多数系统的允许数目是20，你也可以设置为5到10。 <br &#47;><br />
和别的函数一样，在发生错误的时候返回-1，并设置全局变量 errno。 <br &#47;><br />
你可能想象到了，在你调用 listen() 前你或者要调用 bind() 或者让 内核随便选择一个端口。如果你想侦听进入的连接，那么系统调用的顺序可能是这样的： <br &#47;><br />
&nbsp; socket(); <br &#47;><br />
&nbsp; bind(); <br &#47;><br />
&nbsp; listen(); <br &#47;><br />
&nbsp; &#47;* accept() goes here *&#47; <br &#47;><br />
因为他相当的明了，我将在这里不给出例子了。(在 accept() 那一章的代码将更加 完全。)真正麻烦的部分在 accept()。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="accept">accept<&#47;a>()--"Thank you for calling port 3490." <br &#47;><br />
准备好了，系统调用 accept() 会有点古怪的地方的！你可以想象发生这样的事情： 有人从很远的地方通过一个你在侦听 (listen()) 的端口连接 (connect()) 到你的机器。他的连接将加入到等待接受 (accept()) 的队列中。你调用 accept() 告诉他你有空闲的连接。他将返回一个新的套接口文件描述符！ 原来的一个还在侦听你的那个端口，新的最后在准备发送 (send()) 和接收 ( recv()) 数据。这就是这个过程！ <br &#47;><br />
函数是这样定义的： <br &#47;><br />
&nbsp;&nbsp;#include <sys&#47;socket.h> <br &#47;><br />
&nbsp;&nbsp;int accept(int sockfd, void *addr, int *addrlen); <br &#47;><br />
sockfd 相当简单，是和 listen() 中一样的套接口描述符。addr 是个指向局部的数据结构 struct sockaddr_in 的指针。This is where the information about the incoming connection will go (and you can determine which host is calling you from which port). 在他的地址传递给 accept 之前，addrlen 是个局部的整形变量，设置为 sizeof(struct sockaddr_in)。accept 将 不会将多余的字节给 addr。如果你放入的少些，那么在 addrlen 的值中反映 出来。 <br &#47;><br />
同样，在错误时返回-1并设置全局变量 errno。 <br &#47;><br />
现在是你应该熟悉的代码片段。 <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <string.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> MYPORT 3490&nbsp;&nbsp;&#47;* the port users will be connecting to *&#47; <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> BACKLOG 10&nbsp;&nbsp; &#47;* how many pending connections queue will hold *&#47; <br &#47;><br />
&nbsp; <font color="#0000ff">main<&#47;font>() <br &#47;><br />
&nbsp; { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> sockfd, new_fd;&nbsp;&#47;* listen on sock_fd, new connection on new_fd *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;<font color="#0000ff">struct<&#47;font> sockaddr_in my_addr;&nbsp;&nbsp;&#47;* my address information *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in their_addr; &#47;* connector's address information *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int <&#47;font>sin_size; <br &#47;><br />
&nbsp;&nbsp;&nbsp; sockfd = socket(AF_INET, SOCK_STREAM, 0); &#47;* do some error checking! *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_family = AF_INET;&nbsp;&nbsp;&nbsp;&nbsp; &#47;* host byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_port = htons(MYPORT);&nbsp;&nbsp; &#47;* short, network byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_addr.s_addr = INADDR_ANY; &#47;* auto-fill with my IP *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; bzero(&amp;(my_addr.sin_zero), 8);&nbsp;&nbsp;&nbsp;&nbsp;&#47;* zero the rest of the struct *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; &#47;* don't forget your error checking for these calls: *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; bind(sockfd, (<font color="#0000ff">struct<&#47;font> sockaddr *)&amp;my_addr, <font color="#0000ff">sizeof<&#47;font>(struct sockaddr)); <br &#47;><br />
&nbsp;&nbsp;&nbsp; listen(sockfd, BACKLOG); <br &#47;><br />
&nbsp;&nbsp;&nbsp;sin_size = sizeof(<font color="#0000ff">struct<&#47;font> sockaddr_in); <br &#47;><br />
&nbsp;&nbsp;&nbsp; new_fd = accept(sockfd, &amp;their_addr, &amp;sin_size); <br &#47;><br />
&nbsp;&nbsp;&nbsp; . <br &#47;><br />
&nbsp;&nbsp;&nbsp; . <br &#47;><br />
&nbsp;&nbsp;&nbsp; . <br &#47;><br />
注意，在系统调用 send() 和 recv() 中你应该使用新的文件描述符。 如果你只想让一个连接进来，那么你可以使用 close() 去关闭原来的文件描述 符 sockfd 来避免同一个端口更多的连接。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="send">send<&#47;a>() and recv()--Talk to me, baby! <br &#47;><br />
这两个函数用于流式套接口和数据报套接口的通讯。如果你喜欢使用无连接的数据报 套接口，你应该看一看下面关于 sendto() 和 recvfrom() 的章节。 <br &#47;><br />
send() 是这样的： <br &#47;><br />
&nbsp; int send(int sockfd, const void *msg, int len, int flags); <br &#47;><br />
sockfd 是你想发送数据的套接口描述符(或者是调用 socket() 或者是 accept() 返回的。)msg 是指向你想发送的数据的指针。len 是 数据的长度。把 flags 设置为 0 就可以了。(详细的资料请看 send() 的 man page)。 <br &#47;><br />
这里是一些可能的例子： <br &#47;><br />
&nbsp; <font color="#0000ff">char<&#47;font> *msg = "Beej was here!"; <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> len, bytes_sent; <br &#47;><br />
&nbsp; . <br &#47;><br />
&nbsp; . <br &#47;><br />
&nbsp; len = strlen(msg); <br &#47;><br />
&nbsp; bytes_sent = send(sockfd, msg, len, 0); <br &#47;><br />
&nbsp;. <br &#47;><br />
. <br &#47;><br />
&nbsp; . <br &#47;><br />
send() 返回实际发送的数据的字节数--他可能小于你要求发送的数目！也即你告诉他要发送一堆数据可是他不能处理成功。他只是发送他可能发送的数据，然后 希望你以后能够发送其他的数据。记住，如果 send() 返回的数据和 len 不 匹配，你应该发送其他的数据。但是这里也有个好消息：如果你要发送的包很小(小于大约 1K)，他可能处理让数据一次发送完。最后，在错误的时候返回-1，并设置 errno。 <br &#47;><br />
recv() 函数很相似： <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> recv(<font color="#0000ff">int<&#47;font> sockfd, <font color="#0000ff">void<&#47;font> *buf, <font color="#0000ff">int<&#47;font> len, <font color="#0000ff">unsigned<&#47;font> <font color="#0000ff">int<&#47;font> flags); <br &#47;><br />
sockfd 是要读的套接口描述符。buf 是要读的信息的缓冲。len 是 缓冲的最大长度。flags 也可以设置为0。(请参考recv() 的 man page。) <br &#47;><br />
recv() 返回实际读入缓冲的数据的字节数。或者在错误的时候返回-1，同时设置 errno。 <br &#47;><br />
很简单，不是吗? 你现在可以在流式套接口上发送数据和接收数据了。你现在是 Unix 网络程序员了！ <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="sendto">sendto<&#47;a>() 和 recvfrom()--Talk to me, DGRAM-style <br &#47;><br />
"这很不错啊"，我听到你说，"但是你还没有讲无连接数据报套接口呢。"没问题，现在我们开始 这个内容。 <br &#47;><br />
既然数据报套接口不是连接到远程主机的，那么在我们发送一个包之前需要什么信息呢? 不错，是目标地址！看下面的： <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> sendto(<font color="#0000ff">int<&#47;font> sockfd, <font color="#0000ff">const<&#47;font> <font color="#0000ff">void<&#47;font> *msg, <font color="#0000ff">int<&#47;font> len, <font color="#0000ff">unsigned<&#47;font> <font color="#0000ff">int<&#47;font> flags, <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff">const<&#47;font> <font color="#0000ff">struct<&#47;font> sockaddr *to, <font color="#0000ff">int<&#47;font> tolen); <br &#47;><br />
你已经看到了，除了另外的两个信息外，其余的和函数 send() 是一样的。 to 是个指向数据结构 struct sockaddr 的指针，他包含了目的地的 IP 地址和断口信息。tolen 可以简单地设置为 sizeof(struct sockaddr)。 <br &#47;><br />
和函数 send() 类似，sendto() 返回实际发送的字节数(他也可能小于你 想要发送的字节数！)，或者在错误的时候返回 -1。 <br &#47;><br />
相似的还有函数 recv() 和 recvfrom()。recvfrom() 的定义是 这样的： <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> recvfrom(<font color="#0000ff">int<&#47;font> sockfd, <font color="#0000ff">void<&#47;font> *buf, <font color="#0000ff">int<&#47;font> len, <font color="#0000ff">unsigned<&#47;font> <font color="#0000ff">int<&#47;font> flags <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff">struct<&#47;font> sockaddr *from, in<font color="#0000ff">t<&#47;font> *fromlen); <br &#47;><br />
又一次，除了一点多余的参数外，这个函数和 recv() 也是一样的。from 是 一个指向局部数据结构 struct sockaddr 的指针，他的内容是源机器 的 IP 地址和端口信息。fromlen 是个 int 型的局部指针，他的初始值 为 sizeof(struct sockaddr)。函数调用后，fromlen 保存着 实际储存在 from 中的地址的长度。 <br &#47;><br />
recvfrom() 返回收到的字节长度，或者在发生错误后返回 -1。 <br &#47;><br />
记住，如果你是用 connect() 连接一个数据报套接口，你可以简单的调用 send() 和 recv() 来满足你的要求。这个时候依然是数据报套接口，依然使用 UDP，系统 自动的加上了目标和源的信息。 <br &#47;><br />
------------------------------------------------------------------------------- <br &#47;><br />
<a name="close">close<&#47;a>() 和 shutdown()--Get outta my face! <br &#47;><br />
你已经整天都在发送 (send()) 和接收 (recv()) 数据了，现在你准备 关闭你的套接口描述符了。这很简单，你可以使用一般的 Unix 文件描述符的 close() 函 数： <br &#47;><br />
&nbsp; close(sockfd); <br &#47;><br />
他将防止套接口上更多的数据的读写。任何在另一端读写套接口的企图都将返回错误信息。 <br &#47;><br />
如果你想在如何关闭套接口上有多一点的控制，你可以使用函数 shutdown()。他能够让 你将一定方向的通讯或者双向的通讯(就象 close() 一样)关闭，你可以使用： <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> shutdown(<font color="#0000ff">int<&#47;font> sockfd, i<font color="#0000ff">n<&#47;font>t how); <br &#47;><br />
sockfd 是你想要关闭的套接口文件描述复。how 的值是下面的其中之一： <br &#47;><br />
0 - Further receives are disallowed <br &#47;><br />
1 - Further sends are disallowed <br &#47;><br />
2 - Further sends and receives are disallowed (和 close() 一样 <br &#47;><br />
shutdown() 成功时返回 0，失败时返回 -1(同时设置 errno。) <br &#47;><br />
如果在无连接的数据报套接口中使用 shutdown()，那么只不过是让 send() 和 recv() 不能使用(记得你在数据报套接口中使用了 connect 后是可以 使用他们的吗?) <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="getpeername">getpeername<&#47;a>()--Who are you? <br &#47;><br />
这个函数太简单了。 <br &#47;><br />
他太简单了，以至我都不想单列一章。但是我还是这样做了。 <br &#47;><br />
函数 getpeername() 告诉你在连接的流式套接口上谁在另外一边。函数是这样的： <br &#47;><br />
&nbsp; #include <sys&#47;socket.h> <br &#47;><br />
&nbsp; int getpeername(int sockfd, struct sockaddr *addr, int *addrlen); <br &#47;><br />
sockfd 是连接的流式套接口的描述符。addr 是一个指向结构 struct sockaddr (或者是 struct sockaddr_in) 的指针，他保存着 连接的另一边的信息。addrlen 是一个 int 型的指针，他初始化为 sizeof(struct sockaddr)。 <br &#47;><br />
函数在错误的时候返回 -1，设置相应的 errno。 <br &#47;><br />
一旦你获得他们的地址，你可以使用 inet_ntoa() 或者 gethostbyaddr() 来打印或者获得更多的信息。但是你不能得到他的帐号。(如果他运行着愚蠢的守护进程，这是 可能的，但是他的讨论已经超出了本文的范围，请参考 RFC-1413 以获得更多的信息。) <br &#47;><br />
------------------------------------------------------------------------------- <br &#47;><br />
<a name="gethostname">gethostname<&#47;a>()--Who am I? <br &#47;><br />
甚至比 getpeername() 还简单的函数是 gethostname()。他返回你程序 所运行的机器的主机名字。然后你可以使用 gethostbyname() 以获得你的机器的 IP 地址。 <br &#47;><br />
下面是定义： <br &#47;><br />
&nbsp; #include <unistd.h> <br &#47;><br />
&nbsp; int gethostname(char *hostname, size_t size); <br &#47;><br />
参数很简单：hostname 是一个字符数组指针，他将在函数返回时保存 主机名。size 是 hostname 数组的字节长度。 <br &#47;><br />
函数调用成功时返回 0，失败时返回 -1，并设置 errno。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="DNS">DNS<&#47;a>--You say "whitehouse.gov", I say "198.137.240.100" <br &#47;><br />
如果你不知道 DNS 的意思，那么我告诉你，他代表"域名服务 (Domain Name Service)"。他主要的功能是：你给他一个容易记忆的某站点的地址，他给你 IP 地址(然后你就可以 使用 bind(), connect(), sendto() 或者其他函数。)当一个人 输入： <br &#47;><br />
&nbsp; $ telnet whitehouse.gov <br &#47;><br />
telnet 能知道他将连接 (connect()) 到 "198.137.240.100"。 <br &#47;><br />
但是这是如何工作的呢? 你可以调用函数 gethostbyname()： <br &#47;><br />
&nbsp; #include <netdb.h> <br &#47;><br />
&nbsp; struct hostent *gethostbyname(const char *name); <br &#47;><br />
很明白的是，他返回一个指向 struct hostent 的指针。这个数据结构是 这样的： <br &#47;><br />
&nbsp; <font color="#0000ff">struct<&#47;font> hostent { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">char<&#47;font>&nbsp;&nbsp;*h_name; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">char<&#47;font>&nbsp;&nbsp;**h_aliases; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font>&nbsp;&nbsp; h_addrtype; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font>&nbsp;&nbsp; h_length; <br &#47;><br />
&nbsp;&nbsp;&nbsp;<font color="#0000ff">char<&#47;font>&nbsp;&nbsp;**h_addr_list; <br &#47;><br />
&nbsp; }; <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> h_addr h_addr_list[0] <br &#47;><br />
这里是这个数据结构的详细资料： struct hostent: <br &#47;><br />
h_name - Official name of the host. <br &#47;><br />
h_aliases - A NULL-terminated array of alternate names for the host. <br &#47;><br />
h_addrtype - The type of address being returned; usually AF_INET. <br &#47;><br />
h_length - The length of the address in bytes. <br &#47;><br />
h_addr_list - A zero-terminated array of network addresses for the host. Host addresses are in Network Byte Order. <br &#47;><br />
h_addr - The first address in h_addr_list. <br &#47;><br />
gethostbyname() 成功时返回一个指向 struct hostent 的 指针，或者是个空 (NULL) 指针。(但是和以前不同，errno 不设置，h_errno 设置错误信息。请看下面的 herror()。) <br &#47;><br />
但是如何使用呢? 这个函数可不象他看上去那么难用。 <br &#47;><br />
这里是个例子： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdio.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdlib.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <errno.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <netdb.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <netinet&#47;in.h> <br &#47;><br />
&nbsp; <font color="#0000ff">int <&#47;font>main(int argc, char *argv[]) <br &#47;><br />
&nbsp; { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> hostent *h; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> (argc != 2) {&nbsp;&#47;* error check the command line *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; fprintf(stderr,"usage: getip address\n"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <font color="#0000ff"><br &#47;><br />
<&#47;font>&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((h=gethostbyname(argv[1])) == NULL) {&nbsp;&#47;* get the host info *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; herror("gethostbyname"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; exit(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">printf<&#47;font>("Host name&nbsp;: %s\n", h->h_name); <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">printf<&#47;font>("IP Address : %s\n",inet_ntoa(*((struct in_addr *)h->h_addr))); <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">return<&#47;font> 0; <br &#47;><br />
&nbsp; } <br &#47;><br />
在使用 gethostbyname() 的时候，你不能用 perror() 打印错误信息(因 为 errno 没有使用)，你应该调用 herror()。 <br &#47;><br />
相当简单，你只是传递一个保存机器名的自负串(例如 "whitehouse.gov") 给 gethostbyname()，然后从返回的数据结构 struct hostent 中 收集信息。 <br &#47;><br />
唯一让人迷惑的是打印 IP 地址信息。h->h_addr 是一个 char *， 但是 inet_ntoa() 需要的是 struct in_addr。因此，我 转换 h->h_addr 成 struct in_addr *，然后得到数据。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="Client-Server Background">Client-Server Background <&#47;a><br &#47;><br />
这里是个客户--服务器的世界。在网络上的所有东西都是在处理客户进程和服务器进程的交谈。 举个 telnet 的例子。当你用 telnet (客户)通过 23 号端口登陆到主机，主机上运行 的一个程序(一般叫 telnetd，服务器)激活。他处理这个连接，显示登陆界面，等等。 <br &#47;><br />
Figure 2. The Client-Server Relationship. <br &#47;><br />
图 2 说明了客户和服务器之间的信息交换。 <br &#47;><br />
注意，客--服务器之间可以使用SOCK_STREAM、SOCK_DGRAM 或者其他(只要他们采用相同的)。一些很好的客户--服务器的例子有 telnet&#47;telnetd、 ftp&#47;ftpd 和 bootp&#47;bootpd。每次你使用 ftp 的 时候，在远端都有一个 ftpd 为你服务。 <br &#47;><br />
一般，在服务端只有一个服务器，他采用 fork() 来处理多个客户的连接。基本的 程序是：服务器等待一个连接，接受 (accept()) 连接，然后 fork() 一个 子进程处理他。这是下一章我们的例子中会讲到的。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="简单的服务器">简单的服务器 <&#47;a><br &#47;><br />
这个服务器所做的全部工作是在留式连接上发送字符串 "Hello, World!\n"。你要 测试这个程序的话，可以在一台机器上运行该程序，然后在另外一机器上登陆： <br &#47;><br />
&nbsp; $ telnet remotehostname 3490 <br &#47;><br />
remotehostname 是该程序运行的机器的名字。 <br &#47;><br />
服务器代码： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdio.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdlib.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <errno.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <string.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <netinet&#47;in.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;wait.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> MYPORT 3490&nbsp;&nbsp;&#47;* the port users will be connecting to *&#47; <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> BACKLOG 10&nbsp;&nbsp; &#47;* how many pending connections queue will hold *&#47; <br &#47;><br />
&nbsp; <font color="#0000ff">main<&#47;font>() <br &#47;><br />
&nbsp; { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> sockfd, new_fd;&nbsp;&#47;* listen on sock_fd, new connection on new_fd *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in my_addr;&nbsp;&nbsp;&#47;* my address information *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in their_addr; &#47;* connector's address information *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> sin_size; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("socket"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_family = AF_INET;&nbsp;&nbsp;&nbsp;&nbsp; &#47;* host byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_port = htons(MYPORT);&nbsp;&nbsp; &#47;* short, network byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_addr.s_addr = INADDR_ANY; &#47;* auto-fill with my IP *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; bzero(&amp;(my_addr.sin_zero), 8);&nbsp;&nbsp;&nbsp;&nbsp;&#47;* zero the rest of the struct *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> (bind(sockfd, (struct sockaddr *)&amp;my_addr, sizeof(struct sockaddr)) \ <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("bind"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if <&#47;font>(listen(sockfd, BACKLOG) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("listen"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">while<&#47;font>(1) {&nbsp;&#47;* main accept() loop *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; sin_size = sizeof(struct sockaddr_in); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; if ((new_fd = accept(sockfd, (struct sockaddr *)&amp;their_addr, \ <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&amp;sin_size)) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;perror("accept"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; continue; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; printf("server: got connection from %s\n", \ <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; inet_ntoa(their_addr.sin_addr)); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> (!fork()) { &#47;* this is the child process *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff">if<&#47;font> (send(new_fd, "Hello, world!\n", 14, 0) == -1) <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("send"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff">close<&#47;font>(new_fd); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(0); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;} <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; close(new_fd);&nbsp;&#47;* parent doesn't need this *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">while<&#47;font>(waitpid(-1,NULL,WNOHANG) > 0); &#47;* clean up child processes *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp; } <br &#47;><br />
如果你很挑剔的话，一定不满意我所有的代码都在一个很大的 main() 函数 中。如果你不喜欢，可以划分得更细点。 <br &#47;><br />
你也可以用我们下一章中的程序得到服务器端发送的字符串。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="简单的客户程序">简单的客户程序<&#47;a> <br &#47;><br />
这个程序比服务器还简单。这个程序的所有工作是通过 3490 端口连接到命令行中制定的主机， 然后得到服务器的字符串。 <br &#47;><br />
客户代码: <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdio.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdlib.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <errno.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <string.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <netdb.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <netinet&#47;in.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> PORT 3490&nbsp;&nbsp;&#47;* the port client will be connecting to *&#47; <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> MAXDATASIZE 100 &#47;* max number of bytes we can get at once *&#47; <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> main(<font color="#0000ff">i<&#47;font>nt argc, <font color="#0000ff">char<&#47;font> *argv[]) <br &#47;><br />
&nbsp; { <br &#47;><br />
&nbsp;&nbsp;&nbsp;<font color="#0000ff">int<&#47;font> sockfd, numbytes;&nbsp; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">char<&#47;font> buf[MAXDATASIZE]; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> hostent *he; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in their_addr; &#47;* connector's address information *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if <&#47;font>(argc != 2) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; fprintf(stderr,"usage: client hostname\n"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; exit(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((he=gethostbyname(argv[1])) == NULL) {&nbsp;&#47;* get the host info *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; herror("gethostbyname"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;exit(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("socket"); <br &#47;><br />
<br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; exit(1); <br &#47;><br />
<br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
<br &#47;><br />
&nbsp;&nbsp;&nbsp; their_addr.sin_family = AF_INET;&nbsp;&nbsp;&nbsp;&#47;* host byte order *&#47; <br &#47;><br />
<br &#47;><br />
&nbsp;&nbsp;&nbsp; their_addr.sin_port = htons(PORT);&nbsp;&nbsp;&#47;* short, network byte order *&#47; <br &#47;><br />
<br &#47;><br />
&nbsp;&nbsp;&nbsp; their_addr.sin_addr = *((struct in_addr *)he->h_addr); <br &#47;><br />
<br &#47;><br />
&nbsp;&nbsp;&nbsp; bzero(&amp;(their_addr.sin_zero), 8);&nbsp;&nbsp; &#47;* zero the rest of the struct *&#47; <br &#47;><br />
<br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> (connect(sockfd, (struct sockaddr *)&amp;their_addr, \ <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; sizeof(struct sockaddr)) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("connect"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;exit(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp;} <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((numbytes=recv(sockfd, buf, MAXDATASIZE, 0)) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("recv"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;exit(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; buf[numbytes] = '\0'; <br &#47;><br />
&nbsp;&nbsp;&nbsp; printf("Received: %s",buf); <br &#47;><br />
&nbsp;&nbsp;&nbsp;close(sockfd); <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">return<&#47;font> 0; <br &#47;><br />
&nbsp; } <br &#47;><br />
注意，如果你在运行服务器之前运行客户程序，connect() 将返回 "Connection refused" 信息。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="数据报 Sockets">数据报 Sockets <&#47;a><br &#47;><br />
我不想讲更多了，所以我给出代码 talker.c 和 listener.c。 <br &#47;><br />
listener 在机器上等待在端口 4590 来的数据包。talker 发送数据包到一定的 机器，他包含用户在命令行输入的东西。 <br &#47;><br />
这里就是 listener.c： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdio.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdlib.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <errno.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <string.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <netinet&#47;in.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;wait.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> MYPORT 4950&nbsp;&nbsp;&#47;* the port users will be sending to *&#47; <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> MAXBUFLEN 100 <br &#47;><br />
&nbsp; <font color="#0000ff">main<&#47;font>() <br &#47;><br />
&nbsp; { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> sockfd; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in my_addr;&nbsp;&nbsp;&#47;* my address information *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in their_addr; &#47;* connector's address information *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;<font color="#0000ff">int<&#47;font> addr_len, numbytes; <br &#47;><br />
&nbsp;&nbsp;&nbsp;<font color="#0000ff">char<&#47;font> buf[MAXBUFLEN]; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("socket"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp;} <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_family = AF_INET;&nbsp;&nbsp;&nbsp;&nbsp; &#47;* host byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_port = htons(MYPORT);&nbsp;&nbsp; &#47;* short, network byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; my_addr.sin_addr.s_addr = INADDR_ANY; &#47;* auto-fill with my IP *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; bzero(&amp;(my_addr.sin_zero), 8);&nbsp;&nbsp;&nbsp;&nbsp;&#47;* zero the rest of the struct *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> (bind(sockfd, (struct sockaddr *)&amp;my_addr, sizeof(struct sockaddr)) \ <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;== -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("bind"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp;} <br &#47;><br />
&nbsp;&nbsp;&nbsp; addr_len = sizeof(struct sockaddr); <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((numbytes=recvfrom(sockfd, buf, MAXBUFLEN, 0, \ <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(struct sockaddr *)&amp;their_addr, &amp;addr_len)) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("recvfrom"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; printf("got packet from %s\n",inet_ntoa(their_addr.sin_addr)); <br &#47;><br />
&nbsp;&nbsp;&nbsp; printf("packet is %d bytes long\n",numbytes); <br &#47;><br />
&nbsp;&nbsp;&nbsp; buf[numbytes] = '\0'; <br &#47;><br />
&nbsp;&nbsp;&nbsp; printf("packet contains \"%s\"\n",buf); <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">close<&#47;font>(sockfd); <br &#47;><br />
&nbsp; } <br &#47;><br />
注意在我们的调用 socket()，我们最后使用了 SOCK_DGRAM。同时，没有 必要去使用 listen() 或者 accept()。我们在使用无连接的数据报套接口！ <br &#47;><br />
下面是 talker.c： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdio.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <stdlib.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <errno.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <string.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <netinet&#47;in.h> <br &#47;><br />
&nbsp;#<font color="#0000ff">include<&#47;font> <netdb.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;socket.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;wait.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">define<&#47;font> MYPORT 4950&nbsp;&nbsp;&#47;* the port users will be sending to *&#47; <br &#47;><br />
&nbsp; <font color="#0000ff">int<&#47;font> main(<font color="#0000ff">int<&#47;font> argc, <font color="#0000ff">char<&#47;font> *argv[]) <br &#47;><br />
&nbsp; { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> sockfd; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> sockaddr_in their_addr; &#47;* connector's address information *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">struct<&#47;font> hostent *he; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> numbytes; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> (argc != 3) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; fprintf(stderr,"usage: talker hostname message\n"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((he=gethostbyname(argv[1])) == NULL) {&nbsp;&#47;* get the host info *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; herror("gethostbyname"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">if<&#47;font> ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;perror("socket"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp;their_addr.sin_family = AF_INET;&nbsp;&nbsp;&nbsp;&#47;* host byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; their_addr.sin_port = htons(MYPORT);&nbsp;&#47;* short, network byte order *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; their_addr.sin_addr = *((struct in_addr *)he->h_addr); <br &#47;><br />
&nbsp;&nbsp;&nbsp; bzero(&amp;(their_addr.sin_zero), 8);&nbsp;&nbsp; &#47;* zero the rest of the struct *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;<font color="#0000ff">if<&#47;font> ((numbytes=sendto(sockfd, argv[2], strlen(argv[2]), 0, \ <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(struct sockaddr *)&amp;their_addr, sizeof(struct sockaddr))) == -1) { <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; perror("sendto"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff">exit<&#47;font>(1); <br &#47;><br />
&nbsp;&nbsp;&nbsp; } <br &#47;><br />
&nbsp;&nbsp;&nbsp; printf("sent %d bytes to %s\n",numbytes,inet_ntoa(their_addr.sin_addr)); <br &#47;><br />
&nbsp;&nbsp;&nbsp; close(sockfd); <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">return<&#47;font> 0; <br &#47;><br />
&nbsp; } <br &#47;><br />
这就是所有的了。在一台机器上运行 listener，然后在另外一台机器上运行 talker。观察他们的通讯！ <br &#47;><br />
Except for one more tiny detail that I've mentioned many times in the past: connected datagram sockets. I need to talk about this here, since we're in the datagram section of the document. Let's say that talker calls connect() and specifies the listener's address. From that point on, talker may only sent to and receive from the address specified by connect(). For this reason, you don't have to use sendto() and recvfrom(); you can simply use send() and recv(). <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="阻塞">阻塞 <&#47;a><br &#47;><br />
阻塞，你也许早就听说了。"阻塞"是 "sleep" 的科技行话。你可能注意到前面运行的 listener 程序，他在那里不停地运行，等待数据包的到来。实际在运行的是 他调用 recvfrom()，然后没有数据，因此 recvfrom() 说"阻塞 (block)" 直到数据的到来。 <br &#47;><br />
很多函数都利用阻塞。accept() 阻塞，所有的 recv*() 函数阻塞。他们之所以能这样做是因为他们被允许这样做。当你第一次调用 socket() 建立套接口描述符的时候，内核就将他设置为阻塞。如果你不想套接口阻塞，你就要调用函数 fcntl()： <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <unistd.h> <br &#47;><br />
&nbsp; #<font color="#0000ff">include<&#47;font> <fcntl.h> <br &#47;><br />
&nbsp;. <br &#47;><br />
&nbsp;. <br &#47;><br />
&nbsp; sockfd = socket(AF_INET, SOCK_STREAM, 0); <br &#47;><br />
&nbsp; fcntl(sockfd, F_SETFL, O_NONBLOCK); <br &#47;><br />
&nbsp; . <br &#47;><br />
&nbsp; . <br &#47;><br />
通过设置套接口为非阻塞，你能够有效地"询问"套接口以获得信息。如果你尝试着 从一个非阻塞的套接口读信息并且没有任何数据，他不会变成阻塞--他将返回 -1 并 将 errno 设置为 EWOULDBLOCK。 <br &#47;><br />
但是一般说来，这种轮询不是个好主意。如果你让你的程序在忙等状态查询套接口的数据， 你将浪费大量的 CPU 时间。更好的解决之道是用下一章讲的 select() 去查询 是否有数据要读进来。 <br &#47;><br />
-------------------------------------------------------------------------------- <br &#47;><br />
<a name="select()--多路同步 I&#47;O">select()--多路同步 I&#47;O <&#47;a><br &#47;><br />
虽然这个函数有点奇怪，但是他很有用。假设这样的情况：你是个服务器，你一边在不停地 从连接上读数据，一边在侦听连接上的信息。 <br &#47;><br />
没问题，你可能会说，不就是一个 accept() 和两个 recv() 吗? 这么容易 吗，朋友? 如果你在调用 accept() 的时候阻塞呢? 你怎么能够同时接受 recv() 数据? "用非阻塞的套接口啊！" 不行！你不想耗尽所有的 CPU，不是吗? 那么，该如何是好? <br &#47;><br />
select() 让你可以同时监视多个套接口。如果你想知道的话，那么他就会告诉你哪个套接口准备读，哪个又 准备好了写，哪个套接口又发生了例外 (exception)。 <br &#47;><br />
闲话少说，下面是 select()： <br &#47;><br />
&nbsp;&nbsp;&nbsp;#<font color="#0000ff">include<&#47;font> <sys&#47;time.h> <br &#47;><br />
&nbsp;&nbsp; #<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp;&nbsp;&nbsp;#<font color="#0000ff">include<&#47;font> <unistd.h> <br &#47;><br />
&nbsp;&nbsp;&nbsp;<font color="#0000ff">int<&#47;font> <font color="#0000ff">select<&#47;font>(<font color="#0000ff">int<&#47;font> numfds, fd_set *readfds, fd_set *writefds, <br &#47;><br />
<font color="#0000ff">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <&#47;font>fd_set *exceptfds, <font color="#0000ff">struct<&#47;font> timeval *timeout); <br &#47;><br />
这个函数监视一系列文件描述符，特别是 readfds、writefds 和 exceptfds。如果你想知道你是否能够从标准输入和套接口描述符 sockfd 读 入数据，你只要将文件描述符 0 和 sockfd 加入到集合 readfds 中。 参数 numfds 应该等于最高的文件描述符的值加1。在这个例子中，你应该设置该值 为 sockfd+1。因为他一定大于标准输入的文件描述符 (0)。 <br &#47;><br />
当函数 select() 返回的时候，readfds 的值修改为反映你选择的哪个文件 描述符可以读。你可以用下面讲到的宏 FD_ISSET() 来测试。 <br &#47;><br />
在我们继续下去之前，让我来讲讲如何对这些集合进行操作。每个集合类型都是 fd_set。 下面有一些宏来对这个类型进行操作： <br &#47;><br />
FD_ZERO(fd_set *set) - clears a file descriptor set <br &#47;><br />
FD_SET(int fd, fd_set *set) - adds fd to the set <br &#47;><br />
FD_CLR(int fd, fd_set *set) - removes fd from the set <br &#47;><br />
FD_ISSET(int fd, fd_set *set) - tests to see if fd is in the set <br &#47;><br />
最后，是有点古怪的数据结构 struct timeval。有时你可不想永远等待别人发送数据过来。也许什么事情都没有发生的时候你也想每隔96秒在终端 上打印字符串 "Still Going..."。这个数据结构允许你设定一个时间，如果时间到了， 而 select() 还没有找到一个准备好的文件描述符，他将返回让你继续处理。 <br &#47;><br />
数据结构 struct timeval 是这样的： <br &#47;><br />
&nbsp; <font color="#0000ff">struct<&#47;font> timeval { <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> tv_sec;&nbsp;&nbsp; &#47;* seconds *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp; <font color="#0000ff">int<&#47;font> tv_usec;&nbsp;&nbsp;&#47;* microseconds *&#47; <br &#47;><br />
&nbsp; }; <br &#47;><br />
只要将 tv_sec 设置为你要等待的秒数，将 tv_usec 设置为你要等待的微秒数就可以了。是的，是微秒而不是毫秒。1,000微秒等于1豪秒，1,000毫秒等于1秒。也就是说，1秒等于1,000,000微秒。为什么用符号 "usec" 呢? 字母 "u" 很象希腊字母 Mu， 而 Mu 表示 "微" 的意思。当然，函数返回的时候 timeout 可能是剩余的 时间，之所以是可能，是因为他依赖于你的 Unix 操作系统。 <br &#47;><br />
哈！我们现在有一个微秒级的定时器！不要计算了，标准的 Unix 系统的时间片是100毫秒，所以 无论你如何设置你的数据结构 struct timeval，你都要等待那么长的 时间。 <br &#47;><br />
还有一些有趣的事情：如果你设置数据结构 struct timeval 中的 数据为 0，select() 将立即超时，这样就可以有效地轮询集合中的 所有的文件描述符。如果你将参数 timeout 赋值为 NULL，那么将永远不会发生超时，即一直等到第一个文件描述符就绪。最后，如果你不是很关心等待多长时间，那么 就把他赋为 NULL 吧。 <br &#47;><br />
下面的代码演示了在标准输入上等待 2.5 秒： <br &#47;><br />
&nbsp;&nbsp;&nbsp;#<font color="#0000ff">include<&#47;font> <sys&#47;time.h> <br &#47;><br />
&nbsp;&nbsp;&nbsp;#<font color="#0000ff">include<&#47;font> <sys&#47;types.h> <br &#47;><br />
&nbsp;&nbsp;&nbsp;#<font color="#0000ff">include<&#47;font> <unistd.h> <br &#47;><br />
&nbsp;&nbsp;&nbsp;#<font color="#0000ff">define<&#47;font> STDIN 0&nbsp;&#47;* file descriptor for standard input *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;<font color="#0000ff">main<&#47;font>() <br &#47;><br />
&nbsp;&nbsp;&nbsp;{ <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff">struct<&#47;font> timeval tv; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fd_set readfds; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;tv.tv_sec = 2; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp; tv.tv_usec = 500000; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FD_ZERO(&amp;readfds); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FD_SET(STDIN, &amp;readfds); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#47;* don't care about writefds and exceptfds: *&#47; <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;select(STDIN+1, &amp;readfds, <font color="#0000ff">NULL<&#47;font>, <font color="#0000ff">NULL<&#47;font>, &amp;tv); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff">if<&#47;font> (FD_ISSET(STDIN, &amp;readfds)) <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color="#0000ff"> <&#47;font>printf("A key was pressed!\n"); <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp; <font color="#0000ff">else<&#47;font> <br &#47;><br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; printf("Timed out.\n"); <br &#47;><br />
&nbsp;&nbsp;} <br &#47;><br />
如果你是在一个 line buffered 终端上，那么你敲的键应该是回车 (RETURN)，否则无论如何 他都会超时。 <br &#47;><br />
现在，你可能回认为这就是在数据报套接口上等待数据的方式--你是对的：他可能是。 有些 Unix 系统可以按这种方式，而另外一些则不能。你在尝试以前可能要先看看本系统 的 man page 了。 <br &#47;><br />
最后一件关于 select() 的事情：如果你有一个正在侦听 (listen()) 的套接口，你可以通过将该套接口的文件描述符加入到 readfds 集合中来看 是否有新的连接。 <br &#47;><br />
这就是我关于函数 select() 要讲的所有的东西。<&#47;p></p>
