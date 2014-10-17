---
layout: post
status: publish
published: true
title: Coreseek Fulltext Search
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 486
wordpress_url: http://seaprince.cn/coreseek-fulltext-search/
date: !binary |-
  MjAwOS0xMS0xMCAxOTowMzo0MyArMDgwMA==
date_gmt: !binary |-
  MjAwOS0xMS0xMCAxMTowMzo0MyArMDgwMA==
categories:
- 服务器
tags: []
comments:
- id: 993
  author: admin
  author_email: combbs@gmail.com
  author_url: http://seaprince.cn/
  date: !binary |-
    MjAwOS0xMS0xMCAyMDo0ODozNiArMDgwMA==
  date_gmt: !binary |-
    MjAwOS0xMS0xMCAxMjo0ODozNiArMDgwMA==
  content: http:&#47;&#47;www.coreseek.cn&#47;opensource&#47;mmseg&#47;
- id: 1034
  author: zmh
  author_email: truezmh@gmail.com
  author_url: ''
  date: !binary |-
    MjAxMC0wNS0xMiAxNzo1MjowNSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNS0xMiAwOTo1MjowNSArMDgwMA==
  content: 下载了，没有用于转换工作的小程序，想看看是怎么写的，可以的话发我一份到我邮箱，谢谢了
---
<h1>资料准备<&#47;h1><br />
<a href="http:&#47;&#47;www.coreseek.cn&#47;products&#47;ft_down&#47;">http:&#47;&#47;www.coreseek.cn&#47;products&#47;ft_down&#47;<&#47;a></p>
<p>下载csft和mmseg，并且分别解压到~&#47;coreseek</p>
<h1>安装<&#47;h1><br />
开始编译mmseg</p>
<p>.&#47;configure --prefix=&#47;usr&#47;local&#47;mmseg</p>
<p>make &amp;&amp; make install</p>
<p>复制词库</p>
<p>cp -R ~&#47;coreseek&#47;mmseg-3.1&#47;data &#47;usr&#47;local&#47;mmseg&#47;</p>
<p>生成词库</p>
<p>cd &#47;usr&#47;local&#47;mmseg&#47;data</p>
<p>..&#47;bin&#47;mmseg -u unigram.txt</p>
<p>mv unigram.txt.uni uni.lib</p>
<p>开始编译sphinx (coreseek)</p>
<p>.&#47;configure --with-mmseg=&#47;usr&#47;local&#47;mmseg --with-mmseg-includes=&#47;usr&#47;local&#47;mmseg&#47;include&#47;<strong>mmseg<&#47;strong> --with-mmseg-libs=&#47;usr&#47;local&#47;mmseg&#47;lib --prefix=&#47;usr&#47;local&#47;csft</p>
<p>make &amp;&amp; make install</p>
<p>特别要注意的是mmseg&#47;include下还有一层文件夹，必须写成--with-mmseg-includes=&#47;usr&#47;local&#47;mmseg&#47;include&#47;<strong>mmseg<&#47;strong>，否则出错。</p>
<h1>配置<&#47;h1><br />
创建&#47;usr&#47;local&#47;csft&#47;etc&#47;csft.conf，内容参见附件，但必须注意的几点：</p>
<p>1. 防止中文乱码</p>
<p>sql_query_pre                   = SET NAMES utf8</p>
<p>2. 加载中文词库</p>
<p>index test1</p>
<p>{</p>
<p>source                                  = src1</p>
<p>path                                    = &#47;usr&#47;local&#47;csft&#47;var&#47;data&#47;test1</p>
<p>docinfo                                 = extern</p>
<p>charset_type                    = zh_cn.utf-8</p>
<p>charset_dictpath                = &#47;usr&#47;local&#47;mmseg&#47;data</p>
<p>}</p>
<p>数据库的建立要注意utf8编码，可以直接下载附件在phpmyadmin导入。</p>
<h1>使用Sogou的词库<&#47;h1><br />
搜狗提供了一个优秀的词库，地址在：<a href="http:&#47;&#47;www.sogou.com&#47;labs&#47;dl&#47;w.html">http:&#47;&#47;www.sogou.com&#47;labs&#47;dl&#47;w.html<&#47;a>，许可证位于：<a href="http:&#47;&#47;www.sogou.com&#47;labs&#47;dl&#47;license.html">http:&#47;&#47;www.sogou.com&#47;labs&#47;dl&#47;license.html<&#47;a></p>
<p>但Sogou的词库和mmseg的格式还是有差别的，需要自己转换格式。</p>
<p>为了方便，我在研究的同时写了一个小程序，用于转换工作，感兴趣的可以在附件处下载。（有小BUG，自己解决，呵呵）</p>
<p>附件也有我转换好的版本，可以直接使用。</p>
<h1>PHP中使用sphinx （coreseek）<&#47;h1><br />
可以直接安装扩展<a href="http:&#47;&#47;pecl.php.net&#47;package&#47;sphinx">http:&#47;&#47;pecl.php.net&#47;package&#47;sphinx<&#47;a></p>
<p>或者使用coreseek包中自带的csft-3.1&#47;api&#47;sphinxapi.php</p>
<p>附件中有使用例子（PHP扩展方式）。</p>
<p>附录（附件列表）</p>
<p><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;11&#47;111009_1104_CoreseekFul1.png" alt="" &#47;><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;11&#47;111009_1104_CoreseekFul2.png" alt="" &#47;><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;11&#47;111009_1104_CoreseekFul3.png" alt="" &#47;><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;11&#47;111009_1104_CoreseekFul4.png" alt="" &#47;><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;11&#47;111009_1104_CoreseekFul5.png" alt="" &#47;><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;11&#47;111009_1104_CoreseekFul6.png" alt="" &#47;></p>
<p>附件下载：<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;11&#47;mmseg.zip">mmseg.zip<&#47;a></p>
