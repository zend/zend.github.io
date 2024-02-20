# 使用 GPG Agent 管理 SSH Keys

> 和朋友分享 VPS 或 Linux 主机，经常涉及到发送公钥的情形，文件发送很不方便，还要担心发送渠道的安全问题。

## 安装 GPG + GPG Agent

```
apk add gpg gpg-agent
```

如果不是像 alpine 这种极简系统，一般都是不用另外安装了。

## 导入备份的密钥

```
gpg --import private.gpg
```

中间会提示输入密码，按提示输入GPG的密码即可。

密钥的生成、备份传输，本篇不涉及。

## 添加信任

```
gpg --edit-key 863B3E2DAD77B97E
```

选中对应的 uid 之后，输入 `trust` ，再选择`5`  完全信任，再 `ctrl+d` 或 输入 `quit`  退出即可。

## 添加验证用途的子密钥（若无）

```
gpg --edit-key --expert 863B3E2DAD77B97E
```

依次选 `(11) ECC (set your own capabilities)` ， `(11) ECC (set your own capabilities)`， 也可以选择把 `(11) ECC (set your own capabilities)` 关闭，只保留 `Authenticate` 一个选项即可。曲线算法，可以保持默认，`(1) Curve 25519 *default*`。

## 查看密钥的 keygrip

```
gpg -K --with-keygrip 863B3E2DAD77B97E
```

类似下面输出中，`8D334A6DCE44617DE530D86A20C588E81C0FB224` 是我们需要的。

```
ssb   ed25519 2021-11-08 [A]
      Keygrip = 8D334A6DCE44617DE530D86A20C588E81C0FB224
```

## 修改相关配置

```
echo 'pinentry-mode loopback' >> ~/.gnupg/gpg.conf
echo 'enable-ssh-support' >> ~/.gnupg/gpg-agent.conf
echo 'allow-loopback-pinentry' >> ~/.gnupg/gpg-agent.conf
echo 'disable-scdaemon' >> ~/.gnupg/gpg-agent.conf
echo 8D334A6DCE44617DE530D86A20C588E81C0FB224 >> ~/.gnupg/sshcontrol
```

## 导出对应的公钥

```
gpg --export-ssh-key 863B3E2DAD77B97E
```
这里的Keyid，可以是主密钥Key，也可以是子密钥Key。

## 配置自动启动

```
export GPG_TTY=$(tty)
if [[ -n "$SSH_CONNECTION" ]] ;then
    export PINENTRY_USER_DATA="USE_CURSES=1"
fi
gpg-connect-agent updatestartuptty /bye >/dev/null

unset SSH_AGENT_PID
if [ "${gnupg_SSH_AUTH_SOCK_by:-0}" -ne $$ ]; then
  export SSH_AUTH_SOCK="$(gpgconf --list-dirs agent-ssh-socket)"
fi
```

## 验证正确性

重新登录或 `source ~/.profile` 立即生效。

```
ssh-add -L
```

查看是否包含了刚才导出的公钥。若有，就可以放到服务器的 `.ssh/authorized_keys` 中了，或直接使用 `ssh-copy-id` 命令添加。

```
ssh user@example.com
```

Done


