###
 # @Author: Zidong Yu
 # @Email: chitung.yue@gmail.com
 # @Date: 2020-03-15 00:26:22
 # @LastEditors: Zidong Yu
 # @LastEditTime: 2020-03-16 12:42:36
 # @Description: To be added.
 ###


# symbolic link
# 相当于快捷方式, 对symbolic link的修改也等同于对源文件的修改.
# ln -s (源文件) (快捷方式名)


# hard link: 类似于编程语言中的reference，对hardlink文件的修改等同于对源文件的修改
# 两者的文件编号inode显示，他们是同一文件
# ln (源文件) （硬链接名）


# rmdir用于删除目录，但只能删除空目录


# file 用于查看文件类型

# (pwd;) 加括号执行命令，表示创建子shell后执行命令

# 使用jobs查看后台执行的命令

# corporc 协程 e.g. coproc sleep 10, 使用jobs查看当前后台执行的任务

# 输入!!可获取最近使用的命令


# Environment variables
# 全局变量对于shell本身和他创建的子shell都课件，局部变量只对创建他们的shell可见.
# 使用export xxx将xxx设置为全局变量
# 使用unset xxx删除xxx环境变量

# .bash_profile: 登录linux系统后，bash自动执行的命令
# .bashrc: 交互式（由用户启动的shell）的起始代码, 我们可以放入自定义的代码

# 数组变量
# 定义：arr=(one two three four five)
# 调用: echo arr (仅显示第0个元素)
#      echo ${arr[1]} (显示第1个元素)
#      echo ${arr[*]} (显示整个数组)


# 用户管理
# 显示用户信息 cat /etc/passwd
# 添加用户 useradd （使用-D 按default值添加）
# 用户添加成功后，会创建一个/etc/用户名的文件夹，用于放置用户的资料
# 需要再熟悉下各种参数
# 删除用户
# userdel 用户名：默认只删除/etc/passwd 记录，不删除文件系统
# -r 参数，同时删除文件系统和passwd记录
# 修改用户信息：usermod
# 修改密码： passwd xxx （xxx是用户名）或 chpasswd < text.txt (chpasswd可以导入文件)
# chsh, chfn, chage

# 创建用户组: groupadd
# 修改用户组：groupmod
# 文件权限符
# -rw-rw-r--: 第一位若为-表明为文件，为d则表明为文件夹,l代表链接, c代表字符型设备, b代表块设备，n代表网络设备
# chmod
# setuid: chmod 47xx filename OR chmod u+s filename (+代表增加权限，-代表减少权限), setuid bit ls下不可见
# setgid: chmod 27xx filename OR chmod g+s filename
# set sticky bit: chmod 1755 xxx OR chmod o+t xxx

# tar 
# 打包(不是压缩)：tar -xzvf xxx.tar.gz original_file.xxx
# 压缩: tar -czvf

# make 命令
# ？？？


# vim 
# u  撤销前一个操作
# dd 删除当前光标所在的行
# x  删除当前光标所在的字符
# J 删除当前光标所在行尾的换行符
# yw 复制光标所在的单词
# p 粘贴
# 
# s/pattern/replacement(替换一个pattern), 注意，要先用/pattern找到后才能使用s命令替换
# n,m/pattern/replacement: 替换n到m行的所有pattern，不用事先查找
# %s/pattern/replacement: 替换文件中所有的pattern


# | 称为pipe，可以将前一个命令的stdout作为stdin给后面的命令
# e.g. ls -aliF | grep Hello

# 正则表达式
# s/xxx/yyy/number , s代表替换
# 

# sed的script部分
# N: 把下一行的内容纳入缓冲区当作匹配 ???
# a: append, i: insert
# c: 替换匹配行???
# e.g. sed "2 c This is my monkey, my monkey's name is wukong" my.txt
# 上面这条命令表明，将第2行替换为“This is my monkey, my...”
# d: 删除匹配行
# p: 打印命令
# n: ???


# 删除每行的前n个字符： sed 's/^.\{N\}//' linux.txt
# 查看文件的大小: wc -l
# 使用awk呢？
# 删除每行前5个元素：sed 's/^.\{50\}//' linux.txt