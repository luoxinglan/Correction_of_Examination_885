#include <stdbool.h>
#include <stdio.h>
//
// Created by heihuhu on 25-12-16.
//

/**
 * 代码题3正确：将一个数字转换为二进制输出。
 * @param x 待转换为二进制的数字
 */
void outPutBinary(unsigned x) {
    if (x <= 0) return;
    outPutBinary(x >> 1);
    printf("%d", x & 1);
}

/**
 * 代码题4错误：计算子串在主串中出现的次数。
 * @param str 主串。
 * @param sub 模式串。
 * @return 模式串在主串中出现的次数。
 */
int countSubStrings(char *str, char *sub) {
    int count = 0;
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; str[i + j] != '\0' && sub[j] != '\0'; j++) {
            //逐个字符匹配
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (sub[j] == '\0') {
            //注意：到最后一位才算匹配成功！必须的判断。
            count++;
        }
    }
    return count;
}

#include "../include/test2022.h"

/**
 * 代码题5正确：计算两个复数的积
 * @param num1 复数1
 * @param num2 复数2
 * @return 复数结果
 */
complex complexProduct(complex num1, complex num2) {
    complex res;
    res.real = num1.real * num2.real - num1.imag * num2.imag;
    res.imag = num1.real * num2.imag + num1.imag * num2.real;
    return res;
}

/**
 * 打印复数。printf格式控制强制显示正负号。
 * @param num 复数
 */
void printComplex(complex num) {
    printf("%d%+di\n\n", num.real, num.imag); //+强制显示正负号
}

/**
 * 交换两个长度相等的数组。
 * @param a 第一行
 * @param b 第二行
 */
void swapLine(int a[N], int b[N]) {
    for (int i = 0; i < N; i++) {
        int t = a[i];
        a[i] = b[i];
        b[i] = t;
    }
}

/**
 * 计算长度为n的数组平均值。
 * @param a 数组
 * @return 数组平均值
 */
double averageLine(int a[], int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    return res / n;
}

/**
 * 根据每一行的元素平均值对二位数组排序。
 * @param a 二维数组
 */
void sortMatrix(int a[][N], int n) {
    for (int i = 0; i < n; i++) {
        bool key = false;
        for (int j = 1; j < n - i; j++) {
            if (averageLine(a[j - 1], N) > averageLine(a[j], N)) {
                swapLine(a[j], a[j - 1]);
                key = true;
            }
        }
        if (!key) {
            break;
        }
    }
}

/**
 * 输出二维矩阵。
 * @param a 矩阵
 * @param n 矩阵的行
 */
void printMatrix(int a[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

/**
 * 输入二维矩阵。
 * @param a 矩阵
 * @param n 矩阵的行
 */
void inputMatrix(int a[][N], int n) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}
