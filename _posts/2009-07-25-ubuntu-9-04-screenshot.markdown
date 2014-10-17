---
layout: post
status: publish
published: true
title: ubuntu 9.04 screenshot
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: ! "今天有点兴致，就给ubuntu升级到了9.04。\r\n目前比较少用ubuntu了，新版本的发布也不太了解了，呵呵。不过今天升级成功后，发现自己很喜欢那个登录界面！ubuntu的界面真是一个版本比一个版本漂亮！"
wordpress_id: 416
wordpress_url: http://seaprince.cn/ubuntu-9-04-screenshot/
date: !binary |-
  MjAwOS0wNy0yNSAxOToyMzo1OCArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wNy0yNSAxMToyMzo1OCArMDgwMA==
categories:
- 其他技术
tags:
- linux
comments: []
---
<p>今天有点兴致，就给ubuntu升级到了9.04。<br />
目前比较少用ubuntu了，新版本的发布也不太了解了，呵呵。不过今天升级成功后，发现自己很喜欢那个登录界面！ubuntu的界面真是一个版本比一个版本漂亮！</p>
<p>[caption id="attachment_422" align="alignnone" width="379" caption="无线网络"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;07&#47;time.png"><img class="size-full wp-image-422" title="time" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;07&#47;time.png" alt="无线网络" width="379" height="179" &#47;><&#47;a>[&#47;caption]</p>
<p>发一个登录界面的截图：</p>
<p>[caption id="attachment_415" align="alignnone" width="300" caption="gmd登录界面截图"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;07&#47;gdm-shot.png"><img class="size-medium wp-image-415" title="gdm-shot" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2009&#47;07&#47;gdm-shot-300x225.png" alt="gmd登录界面截图" width="300" height="225" &#47;><&#47;a>[&#47;caption]</p>
<p>附上ubuntu登录界面的截图方法：</p>
<blockquote><p>chvt 7; sleep 9; XAUTHORITY=&#47;var&#47;lib&#47;gdm&#47;:0.Xauth DISPLAY=:0.0 import -window root &#47;home&#47;sp&#47;gdm-shot.png<&#47;blockquote><br />
想要记住这么长的命令不容易，可以先把它写到一个bash文件，再用root身份执行。</p>
<p>screenshot.sh文件内容：</p>
<blockquote><p>#!&#47;bin&#47;bash<br />
chvt 7;<br />
sleep 9;<br />
XAUTHORITY=&#47;var&#47;lib&#47;gdm&#47;:0.Xauth DISPLAY=:0.0 import -window root &#47;home&#47;sp&#47;gdm-shot.png</p>
<p>#---END OF FILE---<&#47;blockquote><br />
执行它：</p>
<blockquote><p>chmod +x screenshot.sh<br />
.&#47;screenshot.sh<&#47;blockquote><br />
或者直接更简单的方法：</p>
<blockquote><p>cat > tmp<br />
chvt 7; sleep 9; XAUTHORITY=&#47;var&#47;lib&#47;gdm&#47;:0.Xauth DISPLAY=:0.0 import -window root &#47;home&#47;sp&#47;gdm-shot.png<&#47;blockquote><br />
&#47;&#47; 这里按CTRL+D结束编辑</p>
<blockquote><p># sudo su<br />
# eval `cat tmp`<&#47;blockquote><br />
当然tmp文件也可以用其他编辑器创建！</p>
<p>--EOF--</p>
