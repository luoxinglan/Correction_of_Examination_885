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

#include <stdio.h>
#include <string.h>
#include "../include/config.h"
#include "../include/sort.h"
#include "../include/test2002.h"
#include "../include/test2004.h"
#include "../include/test2013.h"
#include "../include/test2014.h"
#include "../include/test2015.h"

void basicKnowledge() {
    sizeOfType();
    importantChar();

    showCharConst();
    data_representation();

    format_control_of_printf();

    referenceToArray();
    union unity a;
    a.i = 5;
    unionAsFunParam(a);
    precedence_increment_modulus();
}

void sorts() {
    int a[] = {5, 6, 7, 1, 2, 9, 8, 4, 3};
    // mergeSort(a, 0, 2);
    // heapSort(a, 9);
    quickSort(a, 0, 8);
}

void fun2004() {
    char s[] = "hello world";
    char *ss = "hello world"; //字符串常量不可被修改
    puts(s);
    reverseStringRecursively(s, 0, strlen(s) - 1);
    puts(s);
}

void fun2013() {
    sumKKK(3, 2);
    unevenN(4);
    mergeSortStrings2013();
    // permutationSub(); //没在头文件中声明的其他文件函数无法使用
    permutation(3);
    processLink2Data(8);
    /*
      15 16
      15 19
      15 10
      15 17
      14 16
      14 10
      14 16
      14 9
     */
    processLinkList(3);
    processBST();
    testCountLeafNodes();
    convertToOctal(17);
}

void fun2014() {
    mergeStrings2();
    sumOfSequence(1);
    S_R_substring();
    partitionSqList();
    searchTreeXLevel(1);
}

void fun2015() {
    bool is0124 = judge0124(1023);
    float pai = calcuPAI(0.112);
    char s1[MaxSize * 2], s2[MaxSize];
    puts("enter the s1:");
    fgets(s1, MaxSize * 2, stdin);
    puts("enter the s2:");
    fgets(s2, MaxSize, stdin);
    mergeSortStrings2015(s1, s2);
    sortSortStrings();
}

int main(void) {
    // basicKnowledge();
    // fun2004();
    // fun2013();
    // fun2014();
    // fun2015();
    sorts();
    return 0;
}
