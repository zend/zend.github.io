---
layout: post
status: publish
published: true
title: Sed Skills
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 459
wordpress_url: http://seaprince.cn/sed-skills/
date: !binary |-
  MjAwOS0wOS0wMiAyMzozNzowOCArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wOS0wMiAxNTozNzowOCArMDgwMA==
categories:
- 服务器
tags:
- linux
- sed
comments: []
---
<p>测试的环境：<br />
[service@gan .ssh]$ uname -a<br />
Linux gan 2.4.21-20.EL #1 SMP Wed Aug 18 20:34:58 EDT 2004 x86_64 x86_64 x86_64 GNU&#47;Linux</p>
<p>[service@gan .ssh]$ sed -V<br />
GNU sed version 4.0.7<br />
Copyright (C) 2003 Free Software Foundation, Inc.<br />
This is free software; see the source for copying conditions.  There is NO<br />
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE,<br />
to the extent permitted by law.</p>
<p>文章出处：http:&#47;&#47;gan.cublog.cn</p>
<p>1>. 删除普通字符操作<br />
[service@gan .ssh]$ cat dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE4<br />
LINE5<br />
LINE6<br />
LINE7</p>
<p>删除指定行2<br />
[service@gan .ssh]$ sed '2d' dfile.txt<br />
LINE1<br />
LINE3<br />
LINE4<br />
LINE5<br />
LINE6<br />
LINE7<br />
http:&#47;&#47;gan.cublog.cn<br />
删除1到5行数据<br />
[service@gan .ssh]$ sed '1,5d' dfile.txt<br />
LINE6<br />
LINE7</p>
<p>删除除1到4行的所有行<br />
[service@gan .ssh]$ sed '1,4 !d' dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE4</p>
<p>删除1行，3行数据<br />
[service@gan .ssh]$ sed -e '1d' -e '3d' dfile.txt<br />
LINE2<br />
LINE4<br />
LINE5<br />
LINE6<br />
LINE7</p>
<p>删除最后一行数据<br />
[service@gan .ssh]$ sed '$d' dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE4<br />
LINE5<br />
LINE6<br />
http:&#47;&#47;gan.cublog.cn<br />
删除3到最后一行<br />
[service@gan .ssh]$ sed '3,$d' dfile.txt<br />
LINE1<br />
LINE2</p>
<p>删除包含4字符的行<br />
[service@gan .ssh]$ sed '&#47;4&#47;'d dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE5<br />
LINE6<br />
LINE7<br />
[service@gan .ssh]$ sed -e '&#47;4&#47;d' dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE5<br />
LINE6<br />
LINE7</p>
<p>---------------------<br />
[service@gan .ssh]$ cat dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3http:&#47;&#47;gan.cublog.cn<br />
LINE4<br />
LINE5<br />
LINE6<br />
LINE7<br />
ABC123<br />
123XXABC<br />
W00--</p>
<p>删除包含4，5字符的行<br />
[service@gan .ssh]$ sed '&#47;4&#47;,&#47;5&#47;'d dfile.txt    #这种做法不建议使用，因为有时候会不行<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE6<br />
LINE7<br />
ABC123<br />
123XXABC<br />
W00--<br />
[service@gan .ssh]$ sed '&#47;4&#47;d;&#47;5&#47;d' dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE6<br />
LINE7<br />
ABC123<br />
123XXABC<br />
W00--<br />
http:&#47;&#47;gan.cublog.cn<br />
删除开头字符为A和包含5字符的行<br />
[service@gan .ssh]$ sed -e "&#47;^A&#47;d;&#47;5&#47;d" dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE4<br />
LINE6<br />
LINE7<br />
123XXABC<br />
W00--</p>
<p>这样操作产生的结果不知道是什么，很奇怪的结果<br />
[service@gan .ssh]$ sed -e "&#47;^A&#47;,&#47;5&#47;d" dfile.txt<br />
LINE1<br />
LINE2<br />
LINE3<br />
LINE4<br />
LINE5<br />
LINE6<br />
LINE7</p>
<p>删除空行(用上正侧表达式了)<br />
[service@gan .ssh]$ sed -e '&#47;^$&#47;d' dfile.txt  </p>
<p>2>. 特殊字符的删除<br />
[service@gan .ssh]$ cat sp.txt<br />
A"&#47;`!B\C'*<>&%#@~()?{}|+_-=:;K 1<br />
A&#47;`!B\C'*<>&%#@~()?{}|+_-=:;K 2<br />
A`!B\C'*<>&%#@~()?{}|+_-=:;K 3<br />
A!B\C'*<>&%#@~()?{}|+_-=:;K 4<br />
AB\C'*<>&%#@~()?{}|+_-=:;K 5<br />
ABC'*<>&%#@~()?{}|+_-=:;K 6<br />
ABC*<>&%#@~()?{}|+_-=:;K 7<br />
ABC<>&%#@~()?{}|+_-=:;K 8<br />
ABC>&%#@~()?{}|+_-=:;K 9<br />
ABC&%#@~()?{}|+_-=:;K 10<br />
ABC%#@~()?{}|+_-=:;K 11<br />
ABC#@~()?{}|+_-=:;K 12<br />
ABC@~()?{}|+_-=:;K 13<br />
ABC~()?{}|+_-=:;K 14<br />
ABC()?{}|+_-=:;K 15<br />
ABC)?{}|+_-=:;K 16<br />
ABC?{}|+_-=:;K 17<br />
ABC{}|+_-=:;K 18<br />
ABC}|+_-=:;K 19<br />
ABC|+_-=:;K 20<br />
ABC+_-=:;K 21<br />
ABC_-=:;K 22<br />
ABC-=:;K 23<br />
ABC=:;K 24<br />
ABC:;K 25<br />
ABC;K 26<br />
ABCK 27</p>
<p>[service@gan .ssh]$ sed '&#47;"&#47;d' sp.txt<br />
A&#47;`!B\C'*<>&%#@~()?{}|+_-=:;K 2<br />
...... 其他的行省略不写了</p>
<p>[service@gan .ssh]$ sed '&#47;\&#47;&#47;d' sp.txt<br />
A`!B\C'*<>&%#@~()?{}|+_-=:;K 3<br />
...... 采用转义字符\<br />
http:&#47;&#47;gan.cublog.cn<br />
[service@gan .ssh]$ sed '&#47;`&#47;d' sp.txt<br />
A!B\C'*<>&%#@~()?{}|+_-=:;K 4<br />
......<br />
[service@gan .ssh]$ sed '&#47;!&#47;d' sp.txt<br />
AB\C'*<>&%#@~()?{}|+_-=:;K 5<br />
......<br />
[service@gan .ssh]$ sed '&#47;\\&#47;d' sp.txt<br />
ABC'*<>&%#@~()?{}|+_-=:;K 6<br />
...... 采用转义字符\<br />
[service@gan .ssh]$ sed "&#47;'&#47;d" sp.txt<br />
ABC*<>&%#@~()?{}|+_-=:;K 7<br />
...... 使用""符号<br />
[service@gan .ssh]$ sed '&#47;*&#47;d' sp.txt<br />
ABC<>&%#@~()?{}|+_-=:;K 8<br />
...... 后面的其他字符（<>&%#@~()?{}|+_-=:;）同普通字符删除操作一样</p>
<p>对于sed在字符删除部分写的可能还不是很全面，慢慢添加吧。。。</p>
