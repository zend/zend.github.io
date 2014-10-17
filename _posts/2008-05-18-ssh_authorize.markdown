---
layout: post
status: publish
published: true
title: ssh不用输入密码
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>有些时候，我们在复制/移动文件到另一台机器时会用到scp，因为它比较安全。但如果每次都要输入密码，就比较烦了，尤其是在script里。不过，ssh有另一种用密钥对来验证的方式。下面写出我生成密匙对的过程，供大家参考。</p>
wordpress_id: 196
date: !binary |-
  MjAwOC0wNS0xOCAwMToyODozMiArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wNS0xNyAxNzoyODozMiArMDgwMA==
categories:
- 服务器
tags:
- linux
comments: []
---
<h3>起因<&#47;h3><br />
有些时候，我们在复制&#47;移动文件到另一台机器时会用到scp，因为它比较安全。但如果每次都要输入密码，就比较烦了，尤其是在script里。不过，ssh有另一种用密钥对来验证的方式。下面写出我生成密匙对的过程，供大家参考。</p>
<h3>生成公钥、私钥<&#47;h3><br />
第一步：生成密匙对，我用的是rsa的密钥。使用命令 "ssh-keygen -t rsa"</p>
<p>代码:</p>
<p>[user1@rh user1]$ ssh-keygen -t rsa</p>
<p>Generating public&#47;private rsa key pair.</p>
<p>Enter file in which to save the key (&#47;home&#47;user1&#47;.ssh&#47;id_rsa):</p>
<p>Created directory '&#47;home&#47;user1&#47;.ssh'.</p>
<p>Enter passphrase (empty for no passphrase):</p>
<p>Enter same passphrase again:</p>
<p>Your identification has been saved in &#47;home&#47;user1&#47;.ssh&#47;id_rsa.</p>
<p>Your public key has been saved in &#47;home&#47;user1&#47;.ssh&#47;id_rsa.pub.</p>
<p>The key fingerprint is:</p>
<p>e0:f0:3b:d3:0a:3d:da:42:01:6a:61:2f:6c:a0:c6:e7 user1@rh.test.com</p>
<p>[user1@rh user1]$</p>
<p>生成的过程中提示输入密钥对保存位置，直接回车，接受默认值就行了。接着会提示输入一</p>
<p>个不同于你的password的密码，直接回车，让它空着。当然，也可以输入一个。(我比较懒</p>
<p>，不想每次都要输入密码。) 这样，密钥对就生成完了。</p>
<p>其中公共密钥保存在 ~&#47;.ssh&#47;id_rsa.pub</p>
<p>私有密钥保存在 ~&#47;.ssh&#47;id_rsa</p>
<p>然后改一下 .ssh 目录的权限，使用命令 "chmod 755 ~&#47;.ssh"</p>
<p>代码:</p>
<p>[user1@rh user1]$ chmod 755 ~&#47;.ssh</p>
<p>[user1@rh user1]$</p>
<h3>配置服务器端<&#47;h3><br />
之后把这个密钥对中的公共密钥复制到你要访问的机器上去，并保存为</p>
<p>~&#47;.ssh&#47;authorized_keys.</p>
<p>代码:</p>
<p>[user1@rh user1]$ scp ~&#47;.ssh&#47;id_rsa.pub rh1:&#47;home&#47;user1&#47;.ssh&#47;authorized_keys</p>
<p>user1@rh1's password:</p>
<p>id_rsa.pub                                    100%  228     3.2MB&#47;s   00:00</p>
<p>[user1@rh user1]$</p>
<p>之这样就大功告成了。之后你再用ssh scp sftp 之类的访问那台机器时，就不用输入密码</p>
<p>了，用在script上更是方便。</p>
<h3>PuTTY自动登录SSH服务器<&#47;h3><br />
如果你是使用putty连接，你需要先对PuTTY作一些配置，并且把id_rsa转换成PuTTY认识的ppk格式。一步一步看我操作。</p>
<p>首先，选择编码：</p>
<p>[caption id="attachment_518" align="alignnone" width="454" caption="选择编码"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;1.png"><img class="size-full wp-image-518" title="1" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;1.png" alt="" width="454" height="432" &#47;><&#47;a>[&#47;caption]</p>
<p>然后设置下自动登录的用户名：</p>
<p>[caption id="attachment_519" align="alignnone" width="456" caption="设置自动登录的用户名"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;2.png"><img class="size-full wp-image-519" title="2" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;2.png" alt="" width="456" height="434" &#47;><&#47;a>[&#47;caption]</p>
<p>接着，把id_rsa私钥转换成ppk格式：</p>
<p>[caption id="attachment_520" align="alignnone" width="482" caption="用PuTTYGen.exe将私钥转换成ppk格式"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;3.png"><img class="size-full wp-image-520" title="3" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;3.png" alt="" width="482" height="462" &#47;><&#47;a>[&#47;caption]</p>
<p>点击&ldquo;保存私钥&rdquo; Save private key 按钮，将私钥保存成ppk文件。</p>
<p>[caption id="attachment_521" align="alignnone" width="305" caption="不需要密码，否则每次连接都要输入"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;4.png"><img class="size-full wp-image-521" title="4" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;4.png" alt="" width="305" height="115" &#47;><&#47;a>[&#47;caption]</p>
<p>在PuTTY配置使用刚才保存好的ppk文件。</p>
<p>[caption id="attachment_522" align="alignnone" width="457" caption="选择刚才保存的PPK文件"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;13.png"><img class="size-full wp-image-522" title="13" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;13.png" alt="" width="457" height="435" &#47;><&#47;a>[&#47;caption]</p>
<p>[caption id="attachment_524" align="alignnone" width="457" caption="把会话配置保存起来"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;6.png"><img class="size-full wp-image-524" title="6" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;6.png" alt="" width="457" height="436" &#47;><&#47;a>[&#47;caption]</p>
<p>双击刚保存好的项目，登录到服务器上：</p>
<p>[caption id="attachment_523" align="alignnone" width="665" caption="成功自动登录"]<a href="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;14.png"><img class="size-full wp-image-523" title="14" src="http:&#47;&#47;blog.eaxi.com&#47;wp-content&#47;uploads&#47;2008&#47;05&#47;14.png" alt="" width="665" height="411" &#47;><&#47;a>[&#47;caption]</p>
<p>如果你看到的信息和我的大概一致，那么恭喜你，你已经成功登录到服务器。</p>
