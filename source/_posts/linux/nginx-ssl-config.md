# Nginx的安全配置

2025年，WEB服务的安全有哪些变化吗？

## 自动申请证书

见下一篇笔记。

## 证书使用建议

注意选用 `fullchain` 证书，单证书证书容易造成中间证书不识别的问题。

```Nginx
	ssl_certificate /etc/nginx/ssl/hk2.fullchain.pem;
	ssl_certificate_key /etc/nginx/ssl/hk2.key;
```

## 禁用低版本的协议

只启用 TLS v1.3 和 TLSv1.2
```Nginx
  ssl_protocols      TLSv1.2 TLSv1.3;
```

## 控制使用的算法白名单

```Nginx
ssl_ecdh_curve X25519:prime256v1:secp384r1;
ssl_prefer_server_ciphers on;
ssl_ciphers ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-CHACHA20-POLY1305:ECDHE-RSA-CHACHA20-POLY1305:DHE-RSA-AES128-GCM-SHA256:DHE-RSA-AES256-GCM-SHA384:DHE-RSA-CHACHA20-POLY1305;
```

## 生成专有的DH参数

```Bash
cd /etc/ssl/certs
openssl dhparam -out dhparam.pem 4096
```

```Nginx
ssl_dhparam /etc/ssl/certs/dhparam.pem;
```

## 启用OCSP装订

用新协议检查证书的吊销情况。
```Nginx
ssl_stapling on;
ssl_stapling_verify on;
resolver 8.8.8.8 8.8.4.4 valid=300s;
resolver_timeout 5s;
```

## CA白名单

配置仅白名单的CA才能为某个域名
```Nginx
ssl_trusted_certificate /etc/nginx/ssl/hk2-ca.cer;
```

## 安全相关头

```Nginx
add_header Strict-Transport-Security max-age=31536000;
add_header X-Frame-Options DENY;
add_header X-Content-Type-Options nosniff;
```

## Gualys SSL Labs A+

![Gualys SSL Labs A+](/uploads/assets/ssllabs-hk2-Aplus.png)
