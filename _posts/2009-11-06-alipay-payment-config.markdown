---
layout: post
status: publish
published: true
title: 即时到账--银行网关提前功能
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
wordpress_id: 478
wordpress_url: http://seaprince.cn/?p=478
date: !binary |-
  MjAwOS0xMS0wNiAxMTo0MjowNCArMDgwMA==
date_gmt: !binary |-
  MjAwOS0xMS0wNiAwMzo0MjowNCArMDgwMA==
categories:
- 不想分类
tags:
- php
- Alipay
comments: []
---
<p>在商家的收银台页面选择银行，提交到支付宝页面后就默认为买家选择的银行。<br />
目的：操作更顺，流程更简单！ 例如：该图是商家自己网站设计的页面。</p>
<p><img src="http:&#47;&#47;www.112club.cn&#47;attachments&#47;month_0906&#47;090630181326c9d30f6e543789.jpg" alt="Alipay form Example" &#47;></p>
<p>测试页面：http:&#47;&#47;alipaysales.cn:8082&#47;cpys&#47;jsdz&#47;</p>
<p>如何集成 ？</p>
<p>即时到账技术文档中有这两个参数：<br />
paymethod ：（bankPay(网银);cartoon(卡通); directPay(余额)）<br />
defaultbank：默认网银 String （见常见银行表）<br />
银行列表：</p>
<p>银行简码 银行名称<br />
ICBCB2C 中国工商银行<br />
CMB 招商银行<br />
CCB 中国建设银行<br />
ABC 中国农业银行<br />
SPDBB2B 上海浦东发展银行(B2B)<br />
CIB 兴业银行<br />
GDB 广东发展银行<br />
SDB 深圳发展银行<br />
CMBC 中国民生银行<br />
COMM 交通银行<br />
POSTGC 邮政储蓄银行<br />
CITIC 中信银行<br />
BOCB2C 中国银行</p>
<p>只需要 在接口中新增加 paymethod，defaultbank 这两个参数，这两个参数也需要经过签名，否则会报错。</p>
<p>比如：买家选择 工行，那这两个参数的值就应该为 paymethod=bankPay； defaultbank=ICBCB2C；</p>
<p>以php即时到账代码为例就是：</p>
<p>require_once("alipay_service.php");<br />
require_once("alipay_config.php");<br />
$parameter = array(<br />
"service" => "create_direct_pay_by_user", &#47;&#47;交易类型<br />
"partner" => $partner, &#47;&#47;合作商户号<br />
"return_url" => $return_url, &#47;&#47;同步返回<br />
"notify_url" => $notify_url, &#47;&#47;异步返回<br />
"_input_charset" => $_input_charset, &#47;&#47;字符集，默认为GBK<br />
"subject" => "商品名称", &#47;&#47;商品名称，必填<br />
"body" => "商品描述", &#47;&#47;商品描述，必填<br />
"out_trade_no" => date(Ymdhms), &#47;&#47;商品外部交易号，必填（保证唯一性）<br />
"total_fee" => "0.01", &#47;&#47;商品总价，必填（价格不能为0）<br />
"payment_type" => "1", &#47;&#47;默认为1,不需要修改</p>
<p>"paymethod" => "bankPay", &#47;&#47;bankPay(网银);cartoon(卡通); directPay(余额)<br />
"defaultbank" => "ICBCB2C", &#47;&#47;见银行简码表<br />
"show_url" => $show_url, &#47;&#47;商品相关网站<br />
"seller_email" => $seller_email &#47;&#47;卖家邮箱，必填<br />
);<br />
$alipay = new alipay_service($parameter,$security_code,$sign_type);<br />
$link=$alipay->create_url();</p>
