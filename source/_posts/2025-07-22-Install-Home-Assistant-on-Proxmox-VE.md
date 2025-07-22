---
title: Install Home Assistant on Proxmox VE
date: 2025-07-22 17:47:53
tags:
---

在 Proxmox VE（PVE）中安装 Home Assistant OS（HAOS）使用 qcow2 镜像文件是一个相对简单的过程。以下是详细的步骤，基于你已经下载了最新的 `haos_ova-<version>.qcow2.xz` 文件（如 `haos_ova-15.2.qcow2.xz`）。我将假设你使用的是 Proxmox VE 8.x，并提供手动安装的步骤，同时确保解决可能的常见问题。

---

### 准备工作
1. **确认环境**：
   - 你需要有 Proxmox VE 已安装并可访问（通过 Web 界面或 SSH）。
   - 确保已下载最新的 Home Assistant OS qcow2 镜像文件（从 [Home Assistant GitHub Releases](https://github.com/home-assistant/operating-system/releases)）。
   - 确保你的存储池（如 `local-lvm` 或 `local-zfs`）有足够空间存储解压后的 qcow2 文件（解压后约为 2-4GB，建议至少预留 32GB 用于 VM 磁盘）。

2. **推荐硬件配置**：
   - CPU：至少 2 核。
   - 内存：至少 4GB（推荐 4-8GB）。
   - 存储：至少 32GB（Home Assistant 推荐）。

---

### 安装步骤

#### 1. 上传并解压 qcow2 镜像文件
1. **将压缩的 qcow2 文件上传到 Proxmox**：
   - 使用 SSH 或 SCP 将下载的 `haos_ova-<version>.qcow2.xz` 文件传输到 Proxmox 主机。例如，传输到 `/root` 目录：
     ```bash
     scp haos_ova-15.2.qcow2.xz root@<proxmox-ip>:/root/
     ```
     或者，你可以在 Proxmox 主机上使用 `wget` 直接下载：
     ```bash
     cd /root
     wget https://github.com/home-assistant/operating-system/releases/download/15.2/haos_ova-15.2.qcow2.xz
     ```

2. **安装 xz-utils（如果未安装）并解压文件**：
   - 在 Proxmox 主机上，安装解压工具：
     ```bash
     apt update
     apt install xz-utils
     ```
   - 解压 qcow2 文件：
     ```bash
     unxz /root/haos_ova-15.2.qcow2.xz
     ```
     解压后会生成 `haos_ova-15.2.qcow2` 文件。

3. **（可选）清理空间**：
   - 如果空间有限，可以在后续步骤完成后删除原始的 `.xz` 文件：
     ```bash
     rm /root/haos_ova-15.2.qcow2.xz
     ```

#### 2. 创建虚拟机
1. **登录 Proxmox Web 界面**：
   - 打开浏览器，访问 `https://<proxmox-ip>:8006`，登录 Proxmox。

2. **创建新的虚拟机**：
   - 点击右上角的 **Create VM**。
   - 配置以下设置：
     - **General**：
       - **VM ID**：选择一个唯一的 ID（如 `100`）。
       - **Name**：设置为 `home-assistant` 或其他你喜欢的名称。
     - **OS**：
       - 选择 **Do not use any media**（因为我们稍后会导入 qcow2 镜像）。
     - **System**：
       - **BIOS**：选择 **OVMF (UEFI)**（Home Assistant 需要 UEFI 启动）。
       - **EFI Storage**：选择你的存储池（如 `local-lvm` 或 `local-zfs`）。
       - **Pre-Enroll Keys**：**取消勾选**（禁用 Secure Boot，否则可能导致启动失败）。
       - **Machine**：选择 `q35`（推荐）。
     - **Hard Disk**：
       - 删除默认的磁盘（点击垃圾桶图标），因为我们将使用导入的 qcow2 镜像。
     - **CPU**：
       - 分配至少 2 核（推荐）。
     - **Memory**：
       - 分配至少 4096 MB（4GB，推荐 4-8GB）。
     - **Network**：
       - 选择 `virtio` 网卡，桥接到 `vmbr0`（或你的网络桥接）。
     - **Confirm**：
       - 取消勾选 **Start after created**（我们需要先导入磁盘）。
       - 点击 **Finish** 创建 VM。

#### 3. 导入 qcow2 镜像
1. **使用 `qm importdisk` 命令导入镜像**：
   - 在 Proxmox 主机上通过 SSH 或 Web 界面的 Shell 执行：
     ```bash
     qm importdisk <VM-ID> /root/haos_ova-15.2.qcow2 <storage> --format qcow2
     ```
     - 替换 `<VM-ID>` 为你创建的虚拟机 ID（如 `100`）。
     - 替换 `<storage>` 为你的存储池名称（如 `local-lvm` 或 `local-zfs`）。
     - 示例：
       ```bash
       qm importdisk 100 /root/haos_ova-15.2.qcow2 local-lvm --format qcow2
       ```
   - 导入完成后，输出的最后一行会显示类似 `Successfully imported disk as 'unused0:local-lvm:vm-100-disk-0'`。

2. **将导入的磁盘添加到虚拟机**：
   - 返回 Proxmox Web 界面，选择你的虚拟机（VM ID 如 `100`）。
   - 进入 **Hardware** 标签，找到 `Unused Disk 0`（如 `unused0:local-lvm:vm-100-disk-0`）。
   - 点击 **Edit**，设置：
     - **Bus/Device**：选择 `SCSI`，端口为 `0`。
     - **Discard**：如果使用 SSD，勾选此选项以启用 TRIM 支持。
     - 点击 **Add**。
   - 现在磁盘会显示为 `Hard Disk (scsi0)`。

3. **调整磁盘大小（可选）**：
   - Home Assistant 推荐至少 32GB 磁盘空间。如果导入的 qcow2 磁盘较小，可以扩展：
     - 在 **Hardware** 标签，选择 `Hard Disk (scsi0)`，点击 **Resize disk**。
     - 输入增加的容量（例如，输入 `26` 表示增加 26GB，使总大小达到约 32GB）。

4. **配置 EFI 磁盘**：
   - Home Assistant 需要 EFI 磁盘以支持 UEFI 启动。
   - 在 **Hardware** 标签，点击 **Add** > **EFI Disk**。
   - 选择存储池（如 `local-lvm`），取消勾选 **Pre-Enroll Keys**，点击 **OK**。

5. **设置启动顺序**：
   - 进入虚拟机的 **Options** 标签，双击 **Boot Order**。
   - 勾选 `scsi0`（Home Assistant 磁盘），取消勾选其他选项（如 `ide2`、`net0`）。
   - 点击 **OK** 保存。

6. **启用 QEMU Guest Agent（可选但推荐）**：
   - 在 **Options** 标签，双击 **QEMU Guest Agent**，勾选 **Enabled**。
   - 这有助于 Proxmox 监控和管理 VM。

#### 4. 启动虚拟机并验证
1. **启动虚拟机**：
   - 在 Proxmox Web 界面，选择你的虚拟机，点击 **Start**。

2. **检查控制台**：
   - 打开虚拟机的 **Console**（在 Web 界面）。
   - 如果启动成功，Home Assistant 会显示一个欢迎界面，并提供访问地址，如 `http://homeassistant.local:8123` 或 `http://<VM-IP>:8123`。

3. **访问 Home Assistant**：
   - 在浏览器中输入 `http://<VM-IP>:8123` 或 `http://homeassistant.local:8123`（如果你的网络支持 mDNS）。
   - 按照提示设置管理员账户、位置等信息，完成 Home Assistant 初始化。

#### 5. 清理（可选）
- 导入完成后，可以删除 Proxmox 主机上的原始 qcow2 文件以释放空间：
  ```bash
  rm /root/haos_ova-15.2.qcow2
  ```

---

### 常见问题及解决方法
1. **启动失败，显示 “Access Denied” 或 UEFI 错误**：
   - **原因**：可能是启用了 Secure Boot 或未正确配置 EFI 磁盘。
   - **解决**：
     - 确保在创建 VM 时选择了 **OVMF (UEFI)**，并取消勾选 **Pre-Enroll Keys**。
     - 如果仍失败，在 VM 启动时按 **Esc** 进入 UEFI 菜单，导航到 **Device Manager > Secure Boot Configuration**，禁用 **Attempt Secure Boot**。[](https://forum.proxmox.com/threads/failing-to-boot-home-assistant-qcow2-image-disk-uefi-access-denied.99892/)
   - 检查是否正确设置了启动顺序（仅 `scsi0` 启用）。

2. **导入磁盘失败，提示文件不存在**：
   - **原因**：可能是路径错误或文件名拼写错误（如 `.qcow2` 误写为 `.gcow2`）。
   - **解决**：
     - 使用 `ls /root` 确认文件存在且名称正确。
     - 确保解压命令 (`unxz`) 已成功执行。
     - 示例错误修复：`qm importdisk 100 /root/haos_ova-15.2.qcow2 local-lvm --format qcow2`。[](https://forum.proxmox.com/threads/guide-install-home-assistant-os-in-a-vm.143251/)

3. **无法访问 Web 界面**：
   - **原因**：可能是网络配置错误或防火墙阻止了端口 8123。
   - **解决**：
     - 确保 VM 的网络桥接（`vmbr0`）正确配置。
     - 检查 Proxmox 主机或网络的防火墙规则，允许端口 8123。
     - 使用 VM 控制台查看分配的 IP 地址，或尝试 `http://homeassistant.local:8123`（需要 mDNS 支持）。
     - 如果 IP 不显示，检查网络是否分配了 DHCP 地址，或考虑设置静态 IP。[](https://theprivatesmarthome.com/how-to/install-home-assistant-on-proxmox/)

4. **磁盘性能问题**：
   - **原因**：未启用 `Discard` 或未优化存储设置。
   - **解决**：
     - 如果使用 SSD，确保在添加磁盘时勾选 **Discard**。
     - 使用 `virtio-scsi-pci` 作为 SCSI 控制器以提高性能。

5. **SSH 访问 Home Assistant**：
   - Home Assistant OS 默认不启用 SSH。你需要在 Home Assistant Web 界面中安装 **SSH & Web Terminal** 插件：
     - 进入 **Settings > Add-ons > Add-on Store**，安装 **SSH & Web Terminal**。
     - 配置并启用 SSH 访问。
   - 或者，使用 Proxmox 的 VM 控制台进行调试。[](https://community.home-assistant.io/t/proxmox-with-hassio-qcow2-vm-how-to-access-ssh-support/275151)

---

### 额外建议
- **备份**：安装完成后，配置 Proxmox 备份到外部存储（如 NFS 或 Proxmox Backup Server），以便在需要时恢复 VM。[](https://www.wundertech.net/how-to-set-up-home-assistant-on-proxmox/)
- **更新**：定期检查 Home Assistant OS 的新版本，下载新的 qcow2 镜像并重复上述步骤以升级（或使用 Home Assistant 内置更新功能）。
- **脚本自动化（可选）**：如果你不想手动执行这些步骤，可以使用社区提供的脚本（如 [tteck/Proxmox](https://tteck.github.io/Proxmox/)），但请仔细审查脚本内容以确保安全。[](https://www.reddit.com/r/homeassistant/comments/1gjq2hx/how_to_install_haos_132_on_proxmox_82_in_10/)

---

### 示例命令总结
假设 VM ID 为 `100`，存储为 `local-lvm`，Home Assistant 版本为 `15.2`：
```bash
# 解压镜像
apt install xz-utils
cd /root
unxz haos_ova-15.2.qcow2.xz

# 导入磁盘
qm importdisk 100 /root/haos_ova-15.2.qcow2 local-lvm --format qcow2

# （在 Web 界面配置 VM 后）启动 VM
qm start 100
```

---

### 参考资料
- Home Assistant 官方文档：[https://www.home-assistant.io/installation/linux](https://www.home-assistant.io/installation/linux)
- Proxmox 社区论坛和教程
  * https://forum.proxmox.com/threads/guide-install-home-assistant-os-in-a-vm.143251/
  * https://www.wundertech.net/how-to-set-up-home-assistant-on-proxmox/
  * https://www.reddit.com/r/homeassistant/comments/1gjq2hx/how_to_install_haos_132_on_proxmox_82_in_10/

如果遇到具体错误或需要进一步帮助，请提供以下信息：
- Proxmox 版本（`pveversion` 命令输出）。
- 存储池名称（在 Web 界面查看）。
- 完整的错误日志或截图。
- 网络配置详情（桥接、IP 分配方式）。

祝你成功安装 Home Assistant！