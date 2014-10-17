---
layout: post
status: publish
published: true
title: 编写PHP扩展实践
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 580
wordpress_url: http://blog.eaxi.com/%e7%bc%96%e5%86%99php%e6%89%a9%e5%b1%95%e5%ae%9e%e8%b7%b5/
date: !binary |-
  MjAxMS0wMS0xOSAwMDo1NToxNSArMDgwMA==
date_gmt: !binary |-
  MjAxMS0wMS0xOCAxNjo1NToxNSArMDgwMA==
categories:
- post
tags:
- c php linux
comments: []
---
<p>之前写过一篇关于在Windows下搭建PHP编译环境的文章http:&#47;&#47;blog.eaxi.com&#47;compiling-php-on-windows&#47;，现在接着介绍下如何编写一个属于自己的PHP扩展。<br />
从PHP5开始，PHP自带了一个ext_skel的脚本，帮助开发者快速的创建一个扩展，现在我们就从这里开始。<br />
首先我们切换到源码目录。</p>
<p>cd ext&#47;<br />
.&#47;ext_skel --extname=new_ext</p>
<p>值得注意的是，需要先切换到ext&#47;目录再执行.&#47;ext_skel，否则会有些资源文件找不到。<br />
现在脚本就已经帮我们创建好了扩展目录，可以开始编写程序了。</p>
<p>vi new_ext&#47;config.m4</p>
<p>编辑如下几行，以启用这个扩展：</p>
<p><a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2011&#47;01&#47;config.m4.jpg"><img src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2011&#47;01&#47;config.m4.jpg" alt="" title="config.m4" width="532" height="195" class="alignnone size-full wp-image-579" &#47;><&#47;a></p>
<p>cd ..<br />
.&#47;buildconf --force</p>
<p>.&#47;buildconf的命令我们加了--force，是因为我们选择基于正式版来编写扩展。从svn或者snaps.php.net下载的开发版则无需加此参数。</p>
<p>.&#47;configure --help | grep new_ext</p>
<p>现在，我们就已经可以在编译时使用上新的参数了，在帮助输出中已经有所体现。加上 --enable-new_ext 就可以启用我们的新扩展！</p>
<p>.&#47;configure --disable-all --enable-cli --enable-new_ext<br />
make<br />
.&#47;sapi&#47;cli&#47;php ext&#47;new_ext&#47;new_ext.php</p>
<p>为了加快编译，我们先用--disable-all禁用默认的扩展，只启用cli,和我们的新扩展。<br />
最后一句是执行默认的测试程序，确认扩展已经成功编译进到PHP。<br />
如果编译无错，就可以继续往下了。接下来我们修改下源文件，实现一个自己的小功能：实现一个函数，它接受一个用户名参数，返回这个用户在系统中的信息，用户不存在则返回NULL。</p>
<p>PHP_FUNCTION(getpwnam);</p>
<p>在php_new_ext.h中，加上这一句，声明我们的新函数名。加入的位置参考例子程序。</p>
<p>zend_function_entry new_ext_functions[] = {<br />
	PHP_FE(getpwnam,	NULL)	&#47;*  *&#47;<br />
	{NULL, NULL, NULL}	&#47;* Must be the last line in new_ext_functions[] *&#47;<br />
};</p>
<p>在new_ext.c中，先在这个数组中加上函数名，以便系统知道我们的新函数。</p>
<p>PHP_FUNCTION(getpwnam)<br />
{<br />
	char *arg = NULL;<br />
	int arg_len, len;<br />
	struct passwd *pw;</p>
<p>	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {<br />
		RETURN_NULL();<br />
	}</p>
<p>	if (NULL == arg || arg_len == 0) RETURN_NULL();</p>
<p>	pw = getpwnam(arg);<br />
	if (NULL == pw) RETURN_NULL();</p>
<p>	array_init(return_value);<br />
	add_assoc_stringl(return_value, "name", arg, arg_len, 1);<br />
	add_assoc_string(return_value, "gecos", pw->pw_gecos, 1);<br />
	add_assoc_string(return_value, "home", pw->pw_dir, 1);<br />
	add_assoc_string(return_value, "shell", pw->pw_shell, 1);<br />
	add_assoc_long(return_value, "uid", pw->pw_uid);<br />
	add_assoc_long(return_value, "gid", pw->pw_gid);<br />
}</p>
<p>加上这段实现的代码，其他的代码保留原样。其中，return_value是PHP_FUNCTION()宏给每个PHP函数预先定义好的，类型为zval*，表示返回值。初始化为NULL，要返回变量时，修改它就可以了。</p>
<p>make</p>
<p>修改代码后，返回源码根目录直接make就可以了。</p>
