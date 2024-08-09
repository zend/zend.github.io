---
title: OpenWrt on Time Cloud
date: 2024-08-09 23:28:58
tags:
---

# 目标

这个小盒子主要是满足了几个小功能：

1. 从外地连回家中内网
1. 家中科学上网
1. Windows激活
1. 文件共享
1. 对外提供Web服务

实现方法有很多种，这里记录下我的实践。

# OpenWrt

我使用的硬件是2017年149元购入的迅雷下载宝，小巧、省电、足够强大。256M RAM，16MB Flash，主频880MHz，Ramips/mt7621 架构，软件包架构 mipsel_24kc，芯片是联发科的 MediaTek MT7621A。并且它带有千兆网口、SDCard插槽、USB 3.0接口，又非常容易刷机，可玩性十足。

官方固件：https://openwrt.org/toh/hwdata/thunder/thunder_timecloud

官方固件好在安全，没有人夹带私货，但毛病是不够精简，16MB Flash装完系统后没啥空间装软件了。所以之前我是基于官方源码自己定制编译，移除大量用不上的功能，并增加常用的软件包，比如SDCard支持、文件系统支持等。

最近比较懒了，所以就直接用了网友的构建服务： https://openwrt.ai/

需要移除定制的包：

```
-luci-app-fileassistant -luci-app-advancedplus -nano -odhcp6c -odhcpd-ipv6only -ppp -ppp-mod-pppoe -luci-app-upnp kmod-sdhci kmod-sdhci-mt7620
```

配置信息，替换 localStorage 中的 `op-custom-info` 值：

```
models=Thunder+Timecloud&box-model=s905d&cpackages=-luci-app-fileassistant+-luci-app-advancedplus+-nano+-odhcp6c+-odhcpd-ipv6only+-ppp+-ppp-mod-pppoe+-luci-app-upnp+kmod-sdhci+kmod-sdhci-mt7620+wireguard-tools+vlmcsd&passwall=on&ipaddr=10.10.1.2&theme=bootstrap&kernel_v=6.1.10&webserver=nginx&side=on&gateway=10.10.1.1&efi=on&save=on
```

构建，下载固件刷机完事。

