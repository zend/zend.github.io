---
title: SSH Public Key Authentication
date: 2022-08-22 16:59:58
tags:
---



## Why Public Key Authentication

A weak password is dangerous while a strong password is hard to remember. 

For security and convience sake, we should disable password authentication and use Public Key Authentication instead.

## Public Key Authentication in OpenSSH is easy

### Copy Public Key to remote host

OpenSSH has a built-in command to do this:

```
ssh-copy-id -p 22 user@remote.host.com
```

This will copy the default public key to remote server, and append to the `~/.ssh/authorized_keys` file.

If you want to specify a key other that the default one, try the `-i` option:

```
ssh-copy-id -i ~/.ssh/id_ed25519 user@remote.host.com
```

Note the permission of the private key should be readable only for you, e.g `chmod 600 ~/.ssh/id_ed25519`.

### Login with the Public Key Authentication

You can simply type:

```
ssh user@remote.host.com
```

The ssh client will attempt the keys to find the correct one. 

```
~/.ssh/id_rsa
~/.ssh/id_dsa
~/.ssh/id_ecdsa
~/.ssh/id_ed25519
~/.ssh/id_xmss
```

### Disable password authentication

Set configs below in `/etc/ssh/sshd_config`, and restart the sshd with `/etc/init.d/sshd restart`

```
PasswordAuthentication no
PubkeyAuthentication yes
```

## Public Key Authentication in Dropbear SSH

Dropbear is a lightweight ssh server for embedded devices, and it's the default ssh server on a OpenWrt router.

When you are using Dropbear ssh server, ssh-copy-id won't work.

### Set the public key using LuCI

If you have a LuCI installed, it's easy to add a key using the web interface. Navigate to `System - Administration - SSH-Keys` to make it happen.

![System - Administration - SSH-Keys](/uploads/2022/openwrt-ssh-keys.png)

### Set from the command-line

```
echo `YOUR PUBLIC CONTENT` >> /etc/dropbear/authorized_keys
```

