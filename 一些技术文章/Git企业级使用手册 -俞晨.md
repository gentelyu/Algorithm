# Git企业级使用手册

## ssh命令使用

![image-20231127090446477](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127090446477.png)

ssh root@+目标服务器IP地址，注意@前后没有空格，按下回车后只需要输入服务器登录密码即可。

> 如果嫌每次登录都比较麻烦，可以利用ssh密钥通信的方式进行连接，详情请看《ssh密钥的添加》
>
> 使用ssh-keygen命令可以获取到公钥和私钥。将本机的公钥放到远程gitLab平台上面。
>
> 公钥位置在~/.ssh/authorized_keys。 切勿放私钥哦，私钥保密。

## GIt仓库的使用

### 克隆GItHub仓库的代码

![image-20231127105443267](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127105443267.png)

克隆到本机的位置？是不是如果不加路径默认克隆到当前路径下



![image-20231127110747270](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127110747270.png)

进入目标文件，查看是否克隆成功             



### 查看分支

![image-20231127112157077](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127112157077.png)

git branch 查看当前分支
git branch-a  查看所有分支，其中head 后面的箭头表示当前所在的分支

![image-20231127112355430](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127112355430.png)

可以到github上验证是否有这些分支



### 切换分支

![image-20231127113253164](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127113253164.png)

```
git checkout master //切换到amster分支
```





![image-20231127113931973](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127113931973.png)

```
touch + filename       //创建filenam文件

```



### 将文件提交到暂存区

![image-20231127144935445](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127144935445.png)

```
git add +文件名
git status 查看当前工作目录的状态
```

执行上述操作发现，提交的README.md 文件已经从红色变成了绿色，那么就代表五年间已经从工作区提交到暂存区了！



![image-20231127145856508](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127145856508.png)

add函数还可以一次性提交多个文件，如图绿色对应的两个绿色文件就是一次性提交的



### GitHub分区模型

![image-20231127150123839](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127150123839.png)

这里引入Github提交代码的三个地方：

- 工作区： 这里是我们写代码的地方
- 暂存区： 这里是在工作区第一次提价文件保存的地方
- 对象区： 这里是最终提交的地方，别人可以看到



![image-20231127150520661](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127150520661.png)

这里有创建了若干个文件，后面用于进行git提交多个文件的高阶操作



![image-20231127150742677](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127150742677.png)

```
pwd  查看当前位置绝对路径
ls   查看当前文件夹下所有文件
```



![image-20231127152254293](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127152254293.png)

这边给小伙伴提醒一下相对路径和u而对路径的区别



### git批量提交文件大法

![image-20231127152429545](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127152429545.png)

```
git add。		//一次提交工作区所有文件
```

这是我们发现所有的文件都已经成了绿色！



### 将提交的暂存区文件 回到工作区

####  方法一：git restore --staged + 文件名

![image-20231127152925247](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127152925247.png)

```
git restore --staged + 文件名
```

git status 发现目标文件变红，已经召回



#### 方法二 git rm --cache + 文件名

![image-20231127153421982](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127153421982.png)

```
git rm   : 这是用于从版本控制中删除文件的命令。
--cached ：这个选项告诉 Git 仅从暂存区中删除文件，而不是删除工作目录中的实际文件。文件将被保留在你的工作目录中但不再被 Git 跟踪。
```



#### 方法三 vi + 文件名

![image-20231127154456043](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127154456043.png)

进入文件，即需要对文件进行处理，文件被拉回到工作区，文件名变红



### 查看文件修改的信息

![image-20231127161732184](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127161732184.png)

承接上面 ，在vi进入文件中当我们修改了里面的文件内容，可以通过 `git diff` + 文件名查看，并且可以看到修改位置的行号。



![image-20231127162347754](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127162347754.png)

注意，若文件已经被提交到暂存区就不会显示修改信息了，只有在工作区的才可以看到！



### 如何将暂存区的文件提交到对象区

![image-20231127162453503](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127162453503.png)

```
git commit -m "[备注信息类型] 具体干了什么事"
```

这里遇到了信息位置的问题，解决方法见配置用户名和邮箱

![image-20231127163101944](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127163101944.png)





### 配置用户名和邮箱（这是必不可少的一步）

1. git config -- global user.name XXX
2. git config -- global user.email XXX

> 执行完之后配置保存在 ~/.gitconfig 文件中

示例

![image-20231127163728667](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127163728667.png)



这时再将暂存区文件推到对象区就成功了

![image-20231127163747705](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127163747705.png)

其实这里的 -m +[XXX] XXX 类似于日志一样



### 查看git提交日志

![image-20231127165833132](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127165833132.png)

这里会显示作者信息、提交时间、和自己写的日志信息



git commit --amend -m "[XX] XXX"  修改上次日志信息

![image-20231127170443844](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127170443844.png)

这里指的是修改上一次的，上上次的都修改不了



### 版本回退

![image-20231127170722102](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127170722102.png)

查看最近三条日志，暂且命名为版本3.0 、2.0 、 1.0， 我们想回到版本1.0



git reset --hard + commit：

![image-20231127170945887](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127170945887.png)

git reset --hard + 版本1.0的commit : 回退到版本1.0
回退之后的信息就会消失（  [修改] 修复 coredumpbug 和 Create README.md 消失）



![image-20231127172313002](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127172313002.png)

回退到版本1.0 之后，git branch 创建了version_1.1



### 进入指定分支

![image-20231127172419084](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127172419084.png)

git checkout + 分支：进入指定分支



### 查看全部日志信息

git reflog  

![image-20231127172527581](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127172527581.png)

这里是包括回退版本之后的



### 回退到指定版本

git reset -- hard 版本号 ： 回退到指定版本

![image-20231127173829829](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127173829829.png)

回退到3.0 版本，虽然一开始回退到了1.0版本，1.0 之后的版本不可见，但是git reflog 查看项目所有日志，所以我们能看到3.0 版本，并且回到3.0版本



![image-20231127174325134](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127174325134.png)

回到 指定版本号3.0 之后，我们对文件README.md 内容进行了修改，并使用指令查看了修改的内容



![image-20231127174456818](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127174456818.png)



回退到指定版本

![image-20231127174549020](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127174549020.png)





![image-20231127174642375](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127174642375.png)

这时发现之前README.mdl 里面的 “别忘了我” 没了，说明回退版本之后的信息消失了





### 分支管理和冲突

首先，在master分支下创建文件 method1.c  (未提交到暂存区)，此时因为一些原因需要到version_1.1,发现version_1.1 分支下还有未进行操作完成的文件

![image-20231127175055860](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127175055860.png)



切回master分支，还是可以看到未操作的文件

![image-20231127175521813](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127175521813.png)



在version_1.1 分支下，我们可以对master分支下未操作的文件进行处理，将其推到暂存区，切回master分支，能查看文件被推到暂存区

![image-20231127180026235](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127180026235.png)



**如何避免这样的问题呢？**

当我们在master分支下时，我们可以把待处理的文件放入栈中，也就是我们常说的压栈操作。压栈后，我们在version_1.1 分支就查看不到master分支下待处理的文件了

![image-20231127180308446](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127180308446.png)



![image-20231127180326487](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127180326487.png)



### 查看栈里的内容

![image-20231127180514019](C:/Users/HP/AppData/Roaming/Typora/typora-user-images/image-20231127180514019.png)

git stach pop 出栈



### 推送到分支

git push 



