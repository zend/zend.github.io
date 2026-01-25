---
title: Wireguard behind NAT
date: 2026-01-25 22:03:04
tags: linux, openwrt, wireguard, vpn
---

# 核心诉求

- 连接回家
- 能透明访问局域网其他设备
- 满速，零中转，不依赖vps

# WireGuard

WireGuard 是内核态的VPN实现，高性能，简单易用，也有很多平台的客户端。就是配置时稍微有点抽象。

在 OpenWrt 上，

```Bash
opkg update && opkg install wireguard-tools
```

常用的命令有：
```Bash
root@OpenWrt:~# wg -h
Usage: wg <cmd> [<args>]

Available subcommands:
  show: Shows the current configuration and device information
  showconf: Shows the current configuration of a given WireGuard interface, for use with `setconf'
  set: Change the current configuration, add peers, remove peers, or change peers
  setconf: Applies a configuration file to a WireGuard interface
  addconf: Appends a configuration file to a WireGuard interface
  syncconf: Synchronizes a configuration file to a WireGuard interface
  genkey: Generates a new private key and writes it to stdout
  genpsk: Generates a new preshared key and writes it to stdout
  pubkey: Reads a private key from stdin and writes a public key to stdout
You may pass `--help' to any of these subcommands to view usage.
```

# 生成密钥

生成密钥并配置到 `/etc/config/network`

```Bash
config interface 'vpn'
	option proto 'wireguard'
	option private_key 'mOr+......................................='
	option listen_port '51820'
	list addresses '192.168.9.1/24'
#	list addresses 'fd00:9::1/64'

config wireguard_vpn
	option public_key 'I0i4pvS....................................='
	option preshared_key 'PIfYY....................................c='
	option description 'iPhone'
	option route_allowed_ips '1'
	list allowed_ips '192.168.9.2/32'

config wireguard_vpn
	option public_key 'jW03l....................................vtUk='
	option preshared_key 'KReGAU9R....................................AM='
	option description 'macOS'
	list allowed_ips '192.168.9.3/32'
	option route_allowed_ips '1'

config wireguard_vpn
        option public_key 'Ko+os....................................mDTg='
        option preshared_key 'VmW....................................d1eg='
        option description 'jd'
        list allowed_ips '192.168.9.4/32'
        option route_allowed_ips '1'


config route
	option interface 'vpn'
	option target '10.10.1.0/24'
	option gateway '10.10.1.1'

```

# 配置防火墙

允许访问互联网，并伪装来源IP，避免硬路由拦截。

```Bash
config redirect 'wg'
	option name 'Redirect-WireGuard'
	option src 'wan'
	option src_dport '51820'
	option dest 'lan'
	option dest_ip '10.10.1.1'
	option family 'ipv4'
	option proto 'udp'
	option target 'DNAT'

config nat
	option name 'WG伪装'
	list proto 'all'
	option src 'lan'
	option src_ip '192.168.9.0/24'
	option target 'SNAT'
	option snat_ip '10.10.1.2'
```

把 vpn 接口放到 lan 区域

```Bash
config zone
        option name             lan
        list   network          'lan'
        list network 'MKLAN'
        list network 'vpn'
        option input            ACCEPT
        option output           ACCEPT
        option forward          ACCEPT
```

设置转发

```Bash
config forwarding                          
        option src 'vpn'                   
        option dest 'lan'  
```

# 大功告成

用客户端连接就可以啦～
