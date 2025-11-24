#include <stdio.h>
/**
 * 当你想分享你的项目时，必须将其推送到上游。
 * 这个命令很简单：git push <remote> <branch>。
 * 当你想要将 master 分支推送到 origin 服务器时（再次说明，克隆时通常会自动帮你设置好那两个名字），
 * 那么运行这个命令就可以将你所做的备份到服务器：
 * $ git push origin master
 * 初始化11.24，合并了在线的readme和本地的main。
 * 新项目开始时，先 clone 远程仓库，而不是 git init + git remote add。
 * 如果必须本地初始化，可先 git clone 空仓库，再把代码复制进去。
 */

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
