---
title: 给子域名增加SSL自动续期
date: 2025-03-14 11:56:04
tags:
---

# Docker Swarm in Alpine

## Install alpine

1. Boot with alpine ISO
1. Run `setup-alpine` and follow the instructions
1. Reboot when ready.

## Install docker

Make sure you have community repository enabled.

/etc/apk/repositories
```Bash
http://mirrors.ustc.edu.cn/alpine/v3.19/main
http://mirrors.ustc.edu.cn/alpine/v3.19/community
```

```Bash
# install docker
apk add docker

# add openrc service manager
apk add openrc

# run docker at boot
rc-update add docker boot

# check docker service status
rc-service docker status

# start/restart docker if necessary
rc-service docker start
rc-service docker restart
```

## Init docker swarm

```Bash
docker swarm init
```

Use the command on the screen to join this swarm, or run `docker swarm join-token manager` to recall the join command anytime.

On other server, install docker and run following command:
```Bash
docker swarm join --token SWMTKN-1-58ke7scnx4zolgfoce8r4ijnehci78ac9nl48g3txrf4bydvdo-by9hhrndcvq9eqk5hblb92dee 10.10.1.50:2377
```

## docker mirror

```Bash
mkdir /etc/docker
vi /etc/docker/daemon.json
```

cat /etc/docker/daemon.json
```Json
{
    "registry-mirrors": [
        "https://docker.1ms.run",
        "https://docker.xuanyuan.me"
    ]
}
```

## Install portainer

```Bash
apk add curl
curl -L https://downloads.portainer.io/ce-lts/portainer-agent-stack.yml -o portainer-agent-stack.yml
docker stack deploy -c portainer-agent-stack.yml portainer

# check the service list
docker service list
```

If you receive 0 replicas, check your network or docker mirror config.
```Bash
ID             NAME                  MODE         REPLICAS   IMAGE                        PORTS
xr2c6kip60l4   portainer_agent       global       0/1        portainer/agent:lts
jsf5xzk210f0   portainer_portainer   replicated   0/1        portainer/portainer-ce:lts   *:8000->8000/tcp, *:9000->9000/tcp, *:9443->9443/tcp
```

If everything goes well, you will receive:

```Bash
ID             NAME                  MODE         REPLICAS   IMAGE                        PORTS
xr2c6kip60l4   portainer_agent       global       1/1        portainer/agent:lts
jsf5xzk210f0   portainer_portainer   replicated   1/1        portainer/portainer-ce:lts   *:8000->8000/tcp, *:9000->9000/tcp, *:9443->9443/tcp
```

Now you can visit https://10.10.1.50:9443/ to init admin.

## App Templates

Navigate to `Settings - General` on portainer web console, set App Templates URL to `https://storage.360buyimg.com/blogimages/portainer_templates.json`, then you can see application templates list on `Templates - Application`.

