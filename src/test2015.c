//
// Created by heihuhu on 25-11-29.
//
#include "../include/test2015.h"

#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 代码题1正确：输入一个整数，判断这个整数是否只有0，1,2，4组成，若是的话.将该整数输出否则不输出。
 * @param x 一个整数
 * @return 是否由0124组成
 */
bool judge0124(int x) {
    for (; x > 0; x /= 10) {
        int d = x % 10;
        if (d != 0 && d != 1 && d != 2 && d != 4) {
            return false;
        }
    }
    return true;
}

/**
 * 根据输入的小数返回满足要求的项数
 * @param x 输入的小数
 * @return 返回满足要求的n（项数）
 */
int searchN(float x) {
    if (x <= 0)return -1;
    int i = 1;
    while (x * pow(i, 2) <= 1) {
        i++;
    }
    return i;
}

/**
 * 递归计算数列的和
 * @param n 数列的项数
 * @return 数列的和
 */
float sumSequence(int n) {
    if (n == 1)return 1;
    return 1 / pow(n, 2) + sumSequence(n - 1);
}

/**
 * 代码题3正确：运用递归方法来求冂,用到的公式为:(Π*Π)/6=1+1/(2*2)+1/(3*3)+..+1/(n*n)，用户输入 x, 使得1/(n*n)<x。
 * 输入x=0.112，则n=3，结果为2.857。
 * @param x 小数x的值用来确定n
 * @return 返回Π的值
 */
float calcuPAI(float x) {
    int i = searchN(x);
    if (i == -1)return -1;
    return pow(sumSequence(i) * 6, 0.5);
}


#include "../include/sort.h"

/**
 * 代码题4正确：输入两个字符串，将两个字符串合并，然后將合并后的字符串中的字符按照 ASCI码顺序输出。同2013一样
 * @param s1 字符串1
 * @param s2 字符串2
 */
void mergeSortStrings2015(char s1[MaxSize * 2], char s2[MaxSize]) {
    strcat(s1, s2);
    qsort(s1, strlen(s1), sizeof(char), charCmp);
    puts(s1);
    printf("\n");
}


/**
 * 交换两个长度为MaxSize的字符串
 * @param a 字符串1
 * @param b 字符串2
 */
void swapString(char *a, char *b) {
    char temp[MaxSize];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}


/**
 * 冒泡排序字符串：长度从小到大；长度相等则按ASCII从小到大
 * @param arr 字符串数组
 * @param n 字符串个数
 */
void sort_str_by_len_and_ASCII(char arr[][MaxSize], int n) {
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 1; j < n; j++) {
            if (strlen(arr[j - 1]) > strlen(arr[j])) {
                //交换两者
                // arr[j-1]=arr[j];//不可以如此赋值。因为二维数组是连续存储的。
                swapString(arr[j - 1], arr[j]);
                flag = true;
            } else if (strlen(arr[j]) == strlen(arr[j - 1])) {
                if (strcmp(arr[j - 1], arr[j]) > 0) {
                    swapString(arr[j - 1], arr[j]);
                    flag = true;
                }
            }
        }
        if (!flag) {
            //未发生交换
            break;
        }
    }
}

/**
 * 输出字符串数组
 * @param arr 字符串数组
 * @param n 字符串个数
 */
void printStrings(char arr[][MaxSize], int n) {
    for (int i = 0; i < n; i++) {
        puts(arr[i]);
    }
}

/**
 * 算法题5注意字符串交换：输入有限个字符串，先按字符串长度从小到大排序，若长度一样，再按照 ASCII码表依次比较字符串中的字符，最后将所有字符串按顺序输出。
 */
void sortSortStrings() {
    char arr[MaxSize][MaxSize] = {
        "hello", "finally we won", "this is it", "HELLO"
    };
    int n = 4;
    // printf("Please enter the number of strings:\n");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     printf("Enter the %d string:", i);
    //     fgets(arr[i], MaxSize, stdin);
    // }
    sort_str_by_len_and_ASCII(arr, n);
    printStrings(arr, n);
}


