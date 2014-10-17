---
layout: post
status: publish
published: true
title: LINUX命令xargs的简单应用及举例
author:
  display_name: admin
  login: admin
  email: combbs@gmail.com
  url: http://seaprince.cn/
author_login: admin
author_email: combbs@gmail.com
author_url: http://seaprince.cn/
excerpt: 大多数 Linux 命令都会产生输出：文件列表、字符串列表等。但如果要使用其他某个命令并将前一个命令的输出作为参数该怎么办？例如，file 命令显示文件类型（可执行文件、ascii
  文本等）；您可以处理输出，使其仅显示文件名，现在您希望将这些名称传递给 ls -l 命令以查看时间戳记。xargs 命令就是用来完成此项工作的。它允许您对输出执行其他某些命令。
wordpress_id: 514
wordpress_url: http://seaprince.cn/?p=514
date: !binary |-
  MjAxMC0wNi0wNyAxNzozNjozNCArMDgwMA==
date_gmt: !binary |-
  MjAxMC0wNi0wNyAwOTozNjozNCArMDgwMA==
categories:
- 服务器
tags:
- linux
- xargs
- find
comments:
- id: 1065
  author: 商业服务
  author_email: 284066421@qq.com
  author_url: http://www.china-trades.org
  date: !binary |-
    MjAxMC0wNy0wMiAwODo1MjoxMSArMDgwMA==
  date_gmt: !binary |-
    MjAxMC0wNy0wMiAwMDo1MjoxMSArMDgwMA==
  content: 精彩不容错过！
---
<p>xargs<br />
大多数 Linux 命令都会产生输出：文件列表、字符串列表等。但如果要使用其他某个命令并将前一个命令的输出作为参数该怎么办？例如，file 命令显示文件类型（可执行文件、ascii 文本等）；您可以处理输出，使其仅显示文件名，现在您希望将这些名称传递给 ls -l 命令以查看时间戳记。xargs 命令就是用来完成此项工作的。它允许您对输出执行其他某些命令。记住下面这个来自于第 1 部分中的语法：</p>
<p>file -Lz * | grep ASCII | cut -d":" -f1 | xargs ls -ltr</p>
<p>让我们来剖析这个命令字符串。第一个，file -Lz *，用于查找是符号链接或者经过压缩的文件。它将输出传递给下一个命令 grep ASCII，该命令在其中搜索 "ASCII" 字符串并产生如下所示的输出：<br />
alert_DBA102.log:        ASCII English text<br />
alert_DBA102.log.Z:      ASCII text (compress'd data 16 bits)<br />
dba102_asmb_12307.trc.Z: ASCII English text (compress'd data 16 bits)<br />
dba102_asmb_20653.trc.Z: ASCII English text (compress'd data 16 bits)</p>
<p>由于我们只对文件名感兴趣，因此我们应用下一个命令 cut -d":" -f1，仅显示第一个字段：<br />
alert_DBA102.log<br />
alert_DBA102.log.Z<br />
dba102_asmb_12307.trc.Z<br />
dba102_asmb_20653.trc.Z</p>
<p>现在，我们希望使用 ls -l 命令，将上述列表作为参数进行传递，一次传递一个。xargs 命令允许您这样做。最后一部分，xargs ls -ltr，用于接收输出并对其执行 ls -ltr 命令，如下所示：</p>
<p>ls -ltr alert_DBA102.log<br />
ls -ltr alert_DBA102.log.Z<br />
ls -ltr dba102_asmb_12307.trc.Z<br />
ls -ltr dba102_asmb_20653.trc.Z</p>
<p>因此，xargs 本身虽然没有多大用处，但在与其他命令相结合时，它的功能非常强大。</p>
<p>下面是另一个示例，我们希望计算这些文件中的行数：</p>
<p>$ file * | grep ASCII | cut -d":" -f1 | xargs wc -l<br />
47853 alert_DBA102.log<br />
     19 dba102_cjq0_14493.trc<br />
29053 dba102_mmnl_14497.trc<br />
    154 dba102_reco_14491.trc<br />
     43 dba102_rvwr_14518.trc<br />
77122 total</p>
<p>（注：上述任务还可用以下命令完成：）</p>
<p>$ wc -l &lsquo;file * | grep ASCII | cut -d":" -f1 | grep ASCII | cut -d":" -f1&lsquo;</p>
<p>该 xargs 版本用于阐释概念。Linux 可以用几种方法来完成同一个任务；请使用最适合您的情况的方法。</p>
<p>使用该方法，您可以快速重命名目录中的文件。</p>
<p>$ ls | xargs -t -i mv {} {}.bak</p>
<p>-i 选项告诉 xargs 用每项的名称替换 {}。-t 选项指示 xargs 先打印命令，然后再执行。</p>
<p>另一个非常有用的操作是当您使用 vi 打开要编辑的文件时：</p>
<p>$ file * | grep ASCII | cut -d":" -f1 | xargs vi</p>
<p>该命令使用 vi 逐个打开文件。当您希望搜索多个文件并打开它们进行编辑时，使用该命令非常方便。</p>
<p>它还有几个选项。最有用的可能是 -p 选项，它使操作具有可交互性：</p>
<p>$ file * | grep ASCII | cut -d":" -f1 | xargs -p vi<br />
vi alert_DBA102.log dba102_cjq0_14493.trc dba102_mmnl_14497.trc   dba102_reco_14491.trc dba102_rvwr_14518.trc ?...</p>
<p>此处的 xarg 要求您在运行每个命令之前进行确认。如果您按下 "y"，则执行命令。当您对文件进行某些可能有破坏且不可恢复的操作（如删除或覆盖）时，您会发现该选项非常有用。</p>
<p>-t 选项使用一个详细模式；它显示要运行的命令，是调试过程中一个非常有帮助的选项。</p>
<p>如果传递给 xargs 的输出为空怎么办？考虑以下命令：</p>
<p>$ file * | grep SSSSSS | cut -d":" -f1 | xargs -t wc -l<br />
wc -l<br />
            0<br />
$</p>
<p>在此处，搜索 "SSSSSS" 后没有匹配的内容；因此 xargs 的输入均为空，如第二行所示（由于我们使用 -t 这个详细选项而产生的结果）。虽然这可能会有所帮助，但在某些情况下，如果没有要处理的内容，您可能希望停止 xargs；如果是这样，可以使用 -r 选项：<br />
$ file * | grep SSSSSS | cut -d":" -f1 | xargs -t -r wc -l<br />
$</p>
<p>如果没有要运行的内容，该命令退出。</p>
<p>假设您希望使用 rm 命令（该命令将作为 xargs 命令的参数）删除文件。然而，rm 只能接受有限数量的参数。如果您的参数列表超出该限制怎么办？xargs 的 -n 选项限制单个命令行的参数个数。</p>
<p>下面显示了如何限制每个命令行仅使用两个参数：即使向 xargs ls -ltr 传递五个文件，但每次向 ls -ltr 仅传递两个文件。</p>
<p>$ file * | grep ASCII | cut -d":" -f1 | xargs -t -n2 ls -ltr<br />
ls -ltr alert_DBA102.log dba102_cjq0_14493.trc<br />
-rw-r-----    1 oracle   dba           738 Aug 10 19:18 dba102_cjq0_14493.trc<br />
-rw-r--r--    1 oracle   dba       2410225 Aug 13 05:31 alert_DBA102.log<br />
ls -ltr dba102_mmnl_14497.trc dba102_reco_14491.trc<br />
-rw-r-----    1 oracle   dba       5386163 Aug 10 17:55 dba102_mmnl_14497.trc<br />
-rw-r-----    1 oracle   dba          6808 Aug 13 05:21 dba102_reco_14491.trc<br />
ls -ltr dba102_rvwr_14518.trc<br />
-rw-r-----    1 oracle   dba          2087 Aug 10 04:30 dba102_rvwr_14518.trc</p>
<p>使用该方法，您可以快速重命名目录中的文件。</p>
<p>$ ls | xargs -t -i mv {} {}.bak</p>
<p>-i 选项告诉 xargs 用每项的名称替换 {}。</p>
<p>我需要将一个用.svn管理的项目改成由CVS来管理，因此，在导入整个项目到CVS中之前，我需要删除所有目录下以及子孙目录下的.svn目录及.svn目录下的的子目录和文件。我一直寻找一种最简单的方法，最后写了一个程序去干这事情。结果同事告诉我只需要一条指令就可以了：find -name '.svn' |xargs rm -rf<br />
这个教训非常惨重，我一生讨厌傻瓜，可那一刻发现自己是最大的傻瓜！</p>
<p>是的，虽然我们&mdash;&mdash;至少是我，天天使用LINUX但是真的是在高效的使用这个系统吗？不，很多时候并没有花时间去研究它，使用一些固有愚蠢的方式和思维模式在使用这个系统。</p>
<p>1. 建立多级目录:</p>
<p>mkidr 指令用来建立目录，事实上，我们一直都是这么干的。但是在这么使用的时候我们并没有去看它的那些参数提供了哪些额外的功能.</p>
<p>mkidr -p &#47;share&#47;dragon   ; 在根目录下建立share目录，并在&#47;share目录下建立dragon目录。mkdir -p guicmd&#47;{bin,lib,src,share&#47;version,doc&#47;{html,pdf,info,man}}<br />
;用来建立一个复杂的项目目录树。</p>
<p>2.find 配合xargs使用：</p>
<p>find -name '.svn' |xargs rm -rf ;这个不用说了，就是我前面提到的。<br />
xargs更加象一个筛选器，将符合管道传递过来的文件名的内容一并处理掉，这是一个极度高效的方法。</p>
