---
layout: post
status: publish
published: true
title: jsoncpp执行时错误： json test src lib json json value...
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 613
wordpress_url: http://blog.eaxi.com/jsoncpp%e6%89%a7%e8%a1%8c%e6%97%b6%e9%94%99%e8%af%af%ef%bc%9a-json-test-src-lib-json-json-value/
date: !binary |-
  MjAxMi0wNi0wNSAxMzowNjoxNCArMDgwMA==
date_gmt: !binary |-
  MjAxMi0wNi0wNSAwNTowNjoxNCArMDgwMA==
categories:
- status
tags:
- Jsoncpp json cpp
comments: []
---
<p>jsoncpp执行时错误：<br />
json_test: src&#47;lib_json&#47;json_value.cpp:1025: Json::Value& Json::Value::resolveReference(const char*, bool): Assertion `type_ == nullValue || type_ == objectValue' failed.</p>
<p>原因分析：<br />
Jsoncpp解析非法json时，会自动容错成字符类型。对字符类型取下标时，会触发assert终止进程。</p>
<p>解决方法：<br />
方案1 对Json::Value取下标前，先判断(value.type()==Json::objectValue)。<br />
方案2 启用严格模式，让非法的json解析时直接返回false，不自动容错。<br />
        Json::Features f = Json::Features::strictMode();<br />
        Json::Reader reader(f);</p>
