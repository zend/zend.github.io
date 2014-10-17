---
layout: post
status: publish
published: true
title: Javascript下的伪OOP用法测试
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 176
date: !binary |-
  MjAwOC0wMS0xNiAwOTowMDoxNCArMDgwMA==
date_gmt: !binary |-
  MjAwOC0wMS0xNiAwMTowMDoxNCArMDgwMA==
categories:
- 脚本语言
tags:
- javascript
comments: []
---
<div class="codeText">
<div class="codeHead">JavaScript代码<&#47;div></p>
<ol class="dp-c" start="1">
<li class="alt"><span><span><script&nbsp;type=<&#47;span><span class="string">"text&#47;javascript"<&#47;span><span>>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><!--&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="comment">&#47;&#47;&nbsp;方法一<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><span class="keyword">var<&#47;span><span>&nbsp;cellphone&nbsp;=&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;number:&nbsp;13684042440,&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;dial:&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>};&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="comment">&#47;&#47;&nbsp;方法二<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><span class="keyword">var<&#47;span><span>&nbsp;cellphone&nbsp;=&nbsp;<&#47;span><span class="keyword">new<&#47;span><span>&nbsp;Object();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>cellphone.number&nbsp;=&nbsp;13484042440;&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>cellphone.dial&nbsp;=&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="string">"Calling&nbsp;"<&#47;span><span>+<&#47;span><span class="keyword">this<&#47;span><span>.number);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>cellphone.dial();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="comment">&#47;&#47;&nbsp;给已有的类追加方法<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>String.prototype.trim&nbsp;=&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">var<&#47;span><span>&nbsp;tmp&nbsp;=&nbsp;<&#47;span><span class="keyword">this<&#47;span><span>.replace(&#47;^\s+&#47;,<&#47;span><span class="string">''<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;tmp&nbsp;=&nbsp;tmp.replace(&#47;\s+$&#47;,<span class="string">''<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;tmp;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="keyword">var<&#47;span><span>&nbsp;str&nbsp;=&nbsp;<&#47;span><span class="string">"&nbsp;&nbsp;sfdfd&nbsp;&nbsp;sfsd&nbsp;&nbsp;&nbsp;"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>str2=str.trim();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>alert(<span class="string">"'"<&#47;span><span>+str+<&#47;span><span class="string">"'"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>alert(<span class="string">"'"<&#47;span><span>+str2+<&#47;span><span class="string">"'"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="keyword">function<&#47;span><span>&nbsp;Beesn()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">this<&#47;span><span>.member&nbsp;=&nbsp;<&#47;span><span class="keyword">new<&#47;span><span>&nbsp;Array(<&#47;span><span class="string">'Kevin'<&#47;span><span>,<&#47;span><span class="string">'Vonsk'<&#47;span><span>,<&#47;span><span class="string">'Edison'<&#47;span><span>,<&#47;span><span class="string">'Michael'<&#47;span><span>,<&#47;span><span class="string">'Whl'<&#47;span><span>),&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">this<&#47;span><span>.list&nbsp;=&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">for<&#47;span><span>(<&#47;span><span class="keyword">var<&#47;span><span>&nbsp;i=0;i<<&#47;span><span class="keyword">this<&#47;span><span>.member.length;i++)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="keyword">this<&#47;span><span>.member[i]);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;},&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">this<&#47;span><span>.show&nbsp;=&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">this<&#47;span><span>.member&nbsp;=&nbsp;<&#47;span><span class="keyword">this<&#47;span><span>.member.shift();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="keyword">this<&#47;span><span>.member);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="comment">&#47;&#47;for(i&nbsp;in&nbsp;this.member)&nbsp;{<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="comment">&#47;&#47;&nbsp;&nbsp;alert(this.member[i]);<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="comment">&#47;&#47;}<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="keyword">var<&#47;span><span>&nbsp;our&nbsp;=&nbsp;<&#47;span><span class="keyword">new<&#47;span><span>&nbsp;Beesn;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>our.show();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="comment">&#47;&#47;arguments&nbsp;对象的用法。<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><span class="keyword">function<&#47;span><span>&nbsp;ArgTest(a,&nbsp;b,&nbsp;c){&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;<span class="keyword">var<&#47;span><span>&nbsp;i,&nbsp;s&nbsp;=&nbsp;<&#47;span><span class="string">"The&nbsp;ArgTest&nbsp;function&nbsp;expected&nbsp;"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;<span class="keyword">var<&#47;span><span>&nbsp;numargs&nbsp;=&nbsp;arguments.length;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><span class="comment">&#47;&#47;&nbsp;获取被传递参数的数值。<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;<span class="keyword">var<&#47;span><span>&nbsp;expargs&nbsp;=&nbsp;ArgTest.length;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><span class="comment">&#47;&#47;&nbsp;获取期望参数的数值。<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(expargs&nbsp;<&nbsp;2)&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s&nbsp;+=&nbsp;expargs&nbsp;+&nbsp;<span class="string">"&nbsp;argument.&nbsp;"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s&nbsp;+=&nbsp;expargs&nbsp;+&nbsp;<span class="string">"&nbsp;arguments.&nbsp;"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(numargs&nbsp;<&nbsp;2)&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s&nbsp;+=&nbsp;numargs&nbsp;+&nbsp;<span class="string">"&nbsp;was&nbsp;passed."<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s&nbsp;+=&nbsp;numargs&nbsp;+&nbsp;<span class="string">"&nbsp;were&nbsp;passed."<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;s&nbsp;+=&nbsp;<span class="string">"\n\n"<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;<span class="keyword">for<&#47;span><span>&nbsp;(i&nbsp;=0&nbsp;;&nbsp;i&nbsp;<&nbsp;numargs;&nbsp;i++){&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><span class="comment">&#47;&#47;&nbsp;获取参数内容。<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;s&nbsp;+=&nbsp;<span class="string">"&nbsp;&nbsp;&nbsp;Arg&nbsp;"<&#47;span><span>&nbsp;+&nbsp;i&nbsp;+&nbsp;<&#47;span><span class="string">"&nbsp;=&nbsp;"<&#47;span><span>&nbsp;+&nbsp;arguments[i]&nbsp;+&nbsp;<&#47;span><span class="string">"\n"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>(s);&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><span class="comment">&#47;&#47;&nbsp;返回参数列表。<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>alert(&nbsp;ArgTest(1,our,our)&nbsp;);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="comment">&#47;&#47;&nbsp;caller&nbsp;demo<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="keyword">function<&#47;span><span>&nbsp;callerDemo()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(callerDemo.caller)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">var<&#47;span><span>&nbsp;a=&nbsp;callerDemo.caller.toString();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(a);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="string">"this&nbsp;is&nbsp;a&nbsp;top&nbsp;function"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="keyword">function<&#47;span><span>&nbsp;handleCaller()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;callerDemo();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>callerDemo();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="comment">&#47;&#47;callee可以打印其本身<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="keyword">function<&#47;span><span>&nbsp;calleeDemo()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(arguments.callee);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="comment">&#47;&#47;用于验证参数<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="keyword">function<&#47;span><span>&nbsp;calleeLengthDemo(arg1,&nbsp;arg2)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(arguments.length==arguments.callee.length)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;window.alert(<span class="string">"验证形参和实参长度正确！"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="string">"实参长度："<&#47;span><span>&nbsp;+arguments.length);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="string">"形参长度：&nbsp;"<&#47;span><span>&nbsp;+arguments.callee.length);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;aert(calleeLengthDemo.length);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="comment">&#47;&#47;递归计算<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><span class="keyword">var<&#47;span><span>&nbsp;sum&nbsp;=&nbsp;<&#47;span><span class="keyword">function<&#47;span><span>(n){&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<span class="keyword">if<&#47;span><span>&nbsp;(n&nbsp;<=&nbsp;0)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;1;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<span class="keyword">else<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;n&nbsp;+&nbsp;arguments.callee(n&nbsp;-&nbsp;1);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>calleeLengthDemo(1,2,3);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="keyword">var<&#47;span><span>&nbsp;vehicle=Class.create();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>vehicle.prototype.initialize=&nbsp;<span class="keyword">function<&#47;span><span>(type)&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>{&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">this<&#47;span><span>.type=type;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>vehicle.prototype.showSelf=&nbsp;<span class="keyword">function<&#47;span><span>()&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>{&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="string">"this&nbsp;vehicle&nbsp;is&nbsp;"<&#47;span><span>+&nbsp;<&#47;span><span class="keyword">this<&#47;span><span>.type);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="keyword">var<&#47;span><span>&nbsp;Class&nbsp;=&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;create:&nbsp;<span class="keyword">function<&#47;span><span>()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;returnfunction()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">this<&#47;span><span>.initialize.apply(<&#47;span><span class="keyword">this<&#47;span><span>,&nbsp;arguments);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="keyword">var<&#47;span><span>&nbsp;moto=<&#47;span><span class="keyword">new<&#47;span><span>&nbsp;vehicle(<&#47;span><span class="string">"Moto"<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>moto.showSelf();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="comment">&#47;&#47;&nbsp;测试extend<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>Object.extend&nbsp;=&nbsp;<span class="keyword">function<&#47;span><span>(destination,&nbsp;source)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<span class="keyword">for<&#47;span><span>&nbsp;(property&nbsp;<&#47;span><span class="keyword">in<&#47;span><span>&nbsp;source)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;destination[property]&nbsp;=&nbsp;source[property];&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;destination;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>Object.prototype.extend&nbsp;=&nbsp;<span class="keyword">function<&#47;span><span>(object)&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;Object.extend.apply(<&#47;span><span class="keyword">this<&#47;span><span>,&nbsp;[<&#47;span><span class="keyword">this<&#47;span><span>,&nbsp;object]);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="keyword">var<&#47;span><span>&nbsp;obj&nbsp;=&nbsp;<&#47;span><span class="keyword">new<&#47;span><span>&nbsp;Object();&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>obj.extend({&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;f1:&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="string">'f1'<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;},&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;f2:&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alert(<span class="string">'f2'<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>});&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>obj.f2();&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>String.prototype.isEmail&nbsp;=&nbsp;<span class="keyword">function<&#47;span><span>&nbsp;()&nbsp;{&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="keyword">return<&#47;span><span>&nbsp;&#47;^[0-9a-z\-_\.]+@[0-9a-z\-_\.]+\.[a-z]+$&#47;i.test(<&#47;span><span class="keyword">this<&#47;span><span>);&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>};&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span><span class="keyword">var<&#47;span><span>&nbsp;str&nbsp;=&nbsp;<&#47;span><span class="string">"combbs@msn.com"<&#47;span><span>;&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span>alert(&nbsp;&nbsp;str.isEmail()&nbsp;&nbsp;);&nbsp;&nbsp;<&#47;span><&#47;li>
<li class=""><span>&nbsp;&nbsp;<&#47;span><&#47;li>
<li class="alt"><span><span class="comment">&#47;&#47;alert(&#47;^[0-9a-z\-_\.]+@[0-9a-z\-_\.]+\.[a-z]+$&#47;i.test(str));<&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class=""><span><span class="comment">&#47;&#47;--><&#47;span><span>&nbsp;&nbsp;<&#47;span><&#47;span><&#47;li>
<li class="alt"><span><&#47;script>&nbsp;&nbsp;<&#47;span><&#47;li><br />
<&#47;ol><br />
<&#47;div></p>
<p>测试方法：<&#47;p></p>
<p>请一段一段的测试。测试一段时，先把别的行注释。<&#47;p></p>
