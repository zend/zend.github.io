---
layout: post
status: publish
published: true
title: 使用memcached做数据库点击数统计缓冲
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: <p>用memcached缓冲点击数，然后定时写入，可以大大提高效率，降低数据库压力。</p>
wordpress_id: 231
date: !binary |-
  MjAwOS0wNy0wMSAxNToxMDowMyArMDgwMA==
date_gmt: !binary |-
  MjAwOS0wNy0wMSAwNzoxMDowMyArMDgwMA==
categories:
- 脚本语言
tags:
- memcached
comments:
- id: 131
  author: admin
  author_email: combbs@gmail.com
  author_url: http://seaprince.cn/
  date: !binary |-
    MjAwOS0wNy0xMyAwMDo1Njo1MyArMDgwMA==
  date_gmt: !binary |-
    MjAwOS0wNy0xMiAxNjo1Njo1MyArMDgwMA==
  content: redis会不会更好？抽个时间测试一下！
- id: 1033
  author: mr
  author_email: 549479585@qq.com
  author_url: ''
  date: !binary |-
    MjAxMC0wNS0wOCAwODowOToxNiArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNS0wOCAwMDowOToxNiArMDgwMA==
  content: 如何使用？ 添加代码到 functions.php 文件？
---
<p>原理：<&#47;p></p>
<ol>
<li>先从数据库读取最新的点击数，更新到缓存中。<&#47;li>
<li>点击动作产生时，在缓冲做自增操作。<&#47;li>
<li>把被点击的ID写入缓存中，以表名为组。表明缓存中有该ID的点击数，需要进行入库操作。<&#47;li>
<li>定时更新缓存数据到数据库。<&#47;li>
<li>如发现入库周期内，点击数无更新，则放弃入库，并山删除表名组中的ID。<&#47;li><br />
<&#47;ol></p>
<p>且看代码：<&#47;p></p>
<blockquote>
<p>&nbsp;&nbsp;&nbsp; <br &#47;><br />
&nbsp;&nbsp; &nbsp;&#47;**<br &#47;><br />
&nbsp;&nbsp; &nbsp; * 更新点击数<br &#47;><br />
&nbsp;&nbsp; &nbsp; *<br &#47;><br />
&nbsp;&nbsp; &nbsp; * @param string $table<br &#47;><br />
&nbsp;&nbsp; &nbsp; * @param int $id<br &#47;><br />
&nbsp;&nbsp; &nbsp; *&#47;<br &#47;><br />
&nbsp;&nbsp; &nbsp;function click($table, $id) {<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$config = ZFactory::getConfig();<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$key_prefix = $config['click']['key_prefix'];<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$cache = ZFactory::getCache();<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$key = $key_prefix . '_' . $table . '_' . $id; &#47;&#47; 点击数键<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$click = $cache->get($key); &#47;&#47; 获取点击数<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;if (!$click) {<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&#47;&#47; read from table<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$id = intval($id);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$db = ZFactory::getDb();<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$table = $db->escape_string($table);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$sql = "SELECT click_count FROM `log_clicked` WHERE click_id='$id' AND click_type='$table'";<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$db->query($sql);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$result = $db->fetch_object();<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$click = $result ? $result->click_count : 0;<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$cache->set($key, $click);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&#47;&#47; 维护一个ID列表<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$list_key = $key_prefix . '_' . $table; &#47;&#47; 列表键<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$list = $cache->get($list_key);&nbsp;&nbsp; &nbsp;&#47;&#47; 获取列表<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;if (!$list) $list = array($id);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;else $list[] = $id;<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$cache->set($list_key, $list);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;return $cache->increment($key);<br &#47;><br />
&nbsp;&nbsp; &nbsp;}<br &#47;><br />
&nbsp;&nbsp; &nbsp;<br &#47;><br />
&nbsp;&nbsp; &nbsp;&#47;**<br &#47;><br />
&nbsp;&nbsp; &nbsp; * 把缓存中的数据持久化到数据库<br &#47;><br />
&nbsp;&nbsp; &nbsp; *<br &#47;><br />
&nbsp;&nbsp; &nbsp; *&#47;<br &#47;><br />
&nbsp;&nbsp; &nbsp;function click2db() {<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$config = ZFactory::getConfig();<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$key_prefix = $config['click']['key_prefix'];<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$tables = $config['click']['tables'];<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$cache = ZFactory::getCache();<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;foreach ($tables as $table) {<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$ids_key = $key_prefix . '_' . $table;<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$ids = $cache->get($ids_key);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;if (count($ids))<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;foreach ($ids as $k=>$id) {<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$id = intval($id);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&#47;&#47; 缓存内的点击数<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$key = $key_prefix . '_' . $table . '_' . $id;<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$click = $cache->get($key);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&#47;&#47; 读取数据库里的点击数<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$db = ZFactory::getDb();<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$table = $db->escape_string($table);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$sql = "SELECT click_count FROM `log_clicked` WHERE click_id='$id' AND click_type='$table'";<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$db->query($sql);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$result = $db->fetch_object();<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$dbclick = $result ? $result->click_count : 0;<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&#47;&#47; 如果周期内没有人点击<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;if ($dbclick > $click) {<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&#47;&#47; 从缓存中摘除该ID<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;unset($ids[$k]);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;} else {<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&#47;&#47; 把点击数写入数据库<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$sql = "UPDATE `log_clicked` SET click_count='$click' WHERE click_id='$id' AND click_type='$table'";<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$db->query($sql);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}&nbsp;&nbsp; &nbsp;&#47;&#47; foreach ($ids as $k=>$id)<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&#47;&#47; 把ID列表写回缓存中<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;$cache->set($ids_key, $ids);<br &#47;><br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}&nbsp;&nbsp; &nbsp;&#47;&#47; foreach ($tables as $table)<br &#47;><br />
&nbsp;&nbsp; &nbsp;}<br &#47;><br />
&nbsp;&nbsp;&nbsp; <br &#47;><br />
&nbsp;<&#47;p><br />
<&#47;blockquote></p>
