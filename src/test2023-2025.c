//
// Created by heihuhu on 25-12-18.
//
#include <math.h>
#include <stdbool.h>

#include "../include/config.h"
#include <stdio.h>
#include <string.h>

/**
 * 2023年代码题2错误：寻找反数。
 */
void findReversibleNum2023() {
    for (int i = 0; i <= 2023; i++) {
        int reverseNum = 0;
        for (int j = i; j > 0; j /= 10) {
            reverseNum = reverseNum * 10 + j % 10; //注意：j%10，求每一位。
        }
        if (reverseNum == i) {
            printf("The reversible number is %d\n", reverseNum);
        }
    }
}

/**
 * 2023年代码题4错误：求分子分母都是斐波那契数列的和。
 * @param under 分母上的数初始数值为1
 * @param upper 分子上的数目初始数值为2
 * @param n 数列的项数
 * @return 数列的和
 */
double sumOfArray2023(int under, int upper, int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return upper * 1.0 / under;
    }
    return upper * 1.0 / under + sumOfArray2023(upper, upper + under, n - 1);
}

/**
 * 查找模式串在主串中首次出现的位置。
 * @param str 主串
 * @param sub 模式串
 * @return 返回首次匹配的主串的位置，没找到则返回-1。
 */
int findSub(char *str, char *sub) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; sub[j] != '\0' && str[i + j] != '\0'; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == strlen(sub)) {
            return i;
        }
    }
    return -1;
}

/**
 * 将模式串替换为替换串。
 * @param str 主串
 * @param sub 模式串
 * @param rep 替换串
 * @param index 替换位置
 */
void replaceSub(char *str, char *sub, char *rep, int index) {
    char still[MaxSize];
    strcpy(still, str + index + strlen(sub)); //注意：把不受影响的子串复制到临时数组。若首先移动到目标位置，后面复制进来的rep末尾携带的\0把字符串截断。
    strcpy(str + index, rep); //将替换字符串复制到目标位置。
    strcpy(str + index + strlen(rep), still); //把不受影响的子串移动相应位置。
}

/**
 * 注意到strcpy后面会默认跟着\0
 * 2023算法题5错误：从键盘上输入一长字符串，一个匹配字符串，一个替换字符串。
 * 首先在长字符串中查找匹配字符串如果有匹配字符串，则用替换字符电代。
 * 例如:输入 abcdd、bc、 输出为 aadd
 */
void S_R_substring2023() {
    char str[MaxSize * 2];
    char sub[MaxSize];
    char rep[MaxSize];
    gets(str);
    gets(sub);
    gets(rep);
    int index = findSub(str, sub);
    while (index != -1) {
        replaceSub(str, sub, rep, index);
        index = findSub(str, sub);
        puts(str);
    }
}

/**
 * 判断一个数是否是质数。
 * @param n 待判断数字
 * @return 是否是质数
 */
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * 2024代码题3正确：证明所有偶数都可以分解为两个质数的和。
 */
void splitEvenNumber() {
    int i, j, k;
    for (i = 6; i <= 2024; i += 2) {
        //从2024的一半开始判断
        for (j = 2; j <= i / 2; j++) {
            //寻找一个质数
            if (isPrime(j) && isPrime(i - j)) {
                printf("%d+%d=%d\n", j, i - j, i);
            }
        }
    }
}

/**
 * 2025代码题3正确：输入一个字符串，递归输出对称的回文串。abc->abcba
 * @param str 一个字符串
 */
void outputReversedString(char str[]) {
    if (str[0] == '\0') {
        return;
    }
    if (strlen(str) == 1) {
        printf("%c", str[0]);
        return;
    }
    printf("%c", str[0]);
    outputReversedString(str + 1);
    printf("%c", str[0]);
}
