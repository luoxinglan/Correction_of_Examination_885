//
// Created by heihuhu on 25-11-26.
//

#include "../include/test2014.h"
#include "../include/config.h"


#include <stdio.h>
#include <string.h>
/**
 * 展示了常见的字符常量的各种形式
 */
void showCharConst() {
    printf("\\x61=\x61, ");
    printf("\\67=\67, ");
    printf("\\t=\t, ");
    printf("\\0=\0WHAT???"); //注意到'\0'之后的任何字符都不会输出了
    printf("\n");
    printf("\n");
}

//
/**
 * 编程题2正确：
 * 从键盘上输入两个字符集5t71str2，合并这两个字符串到 str3 中，
 * 具体规则如下:str1 的第一个字符+str2 的第一个字符，str1 的第二个字符+str2的第二个字符…
 * 如果其中一个字符串合并完毕，将剩余的字符串直接加到str3 之后。
 * ①自增符号优先级高于取值符号②字符串输入gets()、fgets()
 */
void mergeStrings2() {
    char st1[MaxSize], st2[MaxSize], st3[MaxSize * 2];
    printf("Enter string1, string2: ");
    scanf("%s%s", st1, st2); //scanf的读取原理是匹配字符，当scanf从缓冲区读取数据时遇到空格和回车键则会认为读取完毕
    // gets(st1);//它的任务是从 stdin 流中读取字符串，直至接收到换行符或 EOF 时停止，并将读取的结果存放在 buffer 指针所指向的字符数组中
    // gets(st2);
    // fgets(st1, MaxSize, stdin);//会从缓冲区吃掉MaxSize个元素
    // fgets(st2, MaxSize, stdin);//不能用fgets，否则会把\n也读入字符串。长度就不对了。
    char *a = st1, *b = st2, *c = st3;
    while (*a != '\0' && *b != '\0') {
        *(c++) = *(a++);
        *c++ = *b++; //注意到自增符号的优先级高于取值符号
    }
    while (*a != '\0') {
        *c++ = *a++;
    }
    while (*b != '\0') {
        *c++ = *b++;
    }
    *c = '\0';
    printf("The strings after merging are: %s\n\n", st3);
}

/**
 * 编程题3正确：存在某一数列:2/1，3/2，5/3，8/5，13/8……要求从键盘上输入n，输出该数列的前n项和
 * @param n 数列项数
 * @return 前n项和
 */
float sumOfSequence(const int n) {
    float a[2] = {2, 3};
    float b[2] = {1, 2};
    float sum = 0;
    if (n == 1) {
        sum = a[0] / b[0];
    } else if (n == 2) {
        sum = a[1] / b[1] + a[0] / b[0];
    } else {
        sum = a[0] / b[0] + a[1] / b[1];
        for (int i = 2; i < n; i++) {
            float temp = a[0] + a[1];
            a[0] = a[1];
            a[1] = temp;
            temp = b[0] + b[1];
            b[0] = b[1];
            b[1] = temp;
            sum += a[1] / b[1];
        }
    }
    printf("Sum of the sequence is: %5.2f", sum);
    return sum;
}


/**
 * 查找并替换子串
 * @param l_str 主字符串
 * @param s_str 模式串
 * @param r_str 替换字符串
 */
void replaceSubString(char l_str[], char s_str[], char r_str[]) {
    char *pos = strstr(l_str, s_str); //找到首次匹配的地址
    if (!pos || !s_str) {
        return;
    }
    while (pos) {
        char temp[MaxSize] = {0};
        int index = pos - l_str; //匹配在第几个位置的下标
        //把 src 所指向的字符串复制到 dest，最多复制 n 个字符。该函数返回最终复制的字符串。
        strncpy(temp, l_str, index); //把匹配位置之前的元素复制到临时数组
        strcat(temp, r_str); //将替换字符串连接到匹配位置之后，返回值为dest
        strcat(temp, pos + strlen(s_str)); //把剩余位置的主串追加到后面
        strcpy(l_str, temp); //将结果复制到原来的主串
        pos = strstr(l_str, s_str); //查找剩下的匹配位置
    }
}

/**
 * 妙啊！对于string.h的使用出神入化！要认真学习此题。
 * 算法题4思路错误：从键盘上输入一长字符串，一个匹配字符串，一个替换字符串。
 * 首先在长字符串中查找匹配字符串如果有匹配字符串，则用替换字符电代。
 * 例如:输入 abcdd、bc、 输出为 aadd
 */
void S_R_substring2014() {
    char l_str[MaxSize * 2], //主字符串
            s_str[MaxSize], //模式串
            r_str[MaxSize]; //替换字符串
    printf("Enter long string, sub string, replace string: ");
    scanf("%s%s%s", l_str, s_str, r_str);
    replaceSubString(l_str, s_str, r_str);
    printf("The replaced string is: %s\n\n", l_str);
}

#include "../include/my_list.h"
/**
 * 算法设计题1有一个顺序表L，其元素为整型数据，设计一个算法，
 * 将L中所有小干1)表头 元素的整数放在前半部分，大于表头元素的整数放在后半部分，数组下标从1开始存储。
 * (关键代码请给出注释)
 * @param l 顺序表地址
 */
void partL(SqList *l) {
    int pivot = l->data[1];
    int low = 1, high = l->len;
    while (low < high) {
        while (low < high && l->data[high] >= pivot)
            high--;
        l->data[low] = l->data[high];
        while (low < high && l->data[low] <= pivot)
            low++;
        l->data[high] = l->data[low];
    }
    l->data[low] = pivot;
}

/**
 * 算法题1正确：快速排序算法的划分。有一个顺序表L，其元素为整型数据，设计一个算法，
 * 将L中所有小干1)表头 元素的整数放在前半部分，大于表头元素的整数放在后半部分，数组下标从1开始存储。
 * (关键代码请给出注释)
 */
void partitionSqList() {
    SqList l = {{0, 9, 1, 2, 3, 4, 5, 6, 7, 8}, 9};
    partL(&l);
}


#include "../include/test2013.h"

/**
 * 前序遍历，输出找到的值的层数
 * @param t 树
 * @param x 查找
 * @param h 当前层数
 */
void treeLevel(Tree t, int x, int h) {
    if (!t)
        return;
    if (t->data == x) {
        printf("level=%2d, data=%2d\n", h, t->data);
    }
    treeLevel(t->left, x, h + 1);
    treeLevel(t->right, x, h + 1);
}


/**
 * 算法题2正确：
 * 假设二叉树采用二叉链表存储结构。设计一个算法，求二叉树b 中值为x 的 节点的层号，并描述算法的思想。
 * 初始化一个树，然后递归查找层数，找到了输出所在的层数
 * @param x 查找的值
 */
void searchTreeXLevel(int x) {
    Tree t = initTree();
    treeLevel(t, x, 1);
}
