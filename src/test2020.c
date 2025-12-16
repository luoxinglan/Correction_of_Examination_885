#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//
// Created by heihuhu on 25-12-16.
//

/**
 * 展示指针自增的效果。指针自增指向下一个字节。*指针运算符优先级高于++自增运算符。
 */
void pointerIncrease() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = a;
    printf("A address   a[0]    : %p\n", a); //数组首地址
    printf("A value     a[0]    : %d\n", a[0]); //数组首值
    printf("A pointer   p       : %p\n", p); //指针
    printf("A value     *(p++)  : %d\n", *(p++)); //注意：指针自增，*优先级比++高。
    printf("A pointer   p       : %p\n", p); //指针自增后，指向下一个字节。
    printf("A value     *p      : %d\n", *p); //指针自增后，指向下一个字节。
}

/**
 * 排列：递归逐个确认每一位数字。
 * @param current 当前将要确定的数字位数。
 */
void permutationSub2020(int current) {
    static int num[4] = {0}; //用于存储每一位选择的数字。
    static int used[5] = {0}; //记录每个数字当前是否使用。
    if (current == 4) {
        //每一位都确定了，就输出。
        for (int i = 0; i < 4; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= 4; i++) {
        //这个循环很关键，每一层递归，都会把所有没有用过的数字在current位用一遍才会返回。
        if (!used[i]) {
            //如果i没有没用过，就加入。
            num[current] = i;
            used[i] = 1;
            permutationSub2020(current + 1);
            used[i] = 0; //注意：这里是最关键的。标志着把刚刚用完的数字又放回去等待下一次使用。
        }
    }
};

/**
 * 代码题3正确：输出四位数字的全排列，由1，2，3，4组成。
 */
void permutation2020() {
    permutationSub2020(0);
}

/**
 * 把数字的每一位存进数组，并且返回一共有多少位。
 * @param n 用来存储数字的每一位。
 * @param x 待处理的数字。
 * @return 数字的位数。
 */
int eachDigit(int n[], int x) {
    int count = 0;
    if (x == 0) {
        n[0] = 0;
        count = 1;
        return count;
    }
    for (int i = 0; x > 0; x /= 10, i++) {
        //注意：i的值也要更新！
        n[i] = x % 10;
        count++;
    }
    return count;
}

/**
 * 判断一个数是否是反数。
 * @param n 数字的每一位。
 * @param count 一共多少位。
 * @return 是否是反数。
 */
bool isReversible(int n[], int count) {
    for (int i = 0; i < count; i++) {
        if (n[i] != n[count - 1 - i]) {
            return false;
        }
    }
    return true;
}

/**
 * 代码题4：输出所有小于2019的反数
 */
void findReversibleNum() {
    for (int i = 0; i < 2019; i++) {
        int n[4] = {0};
        int count = eachDigit(n, i);
        if (isReversible(n, count)) {
            printf("%5d ", i);
        }
    }
}

/**
 * 计算0项到n项的和，1-1/3+1/5-1/7+1/9……。
 * @param x 最后一项的限制，直到最后一项小于x，最后一项也算。
 * @param n 当前项，从0开始。
 * @return 返回0项到n项的和
 */
double sumOfArray(double x, int n) {
    double res;
    if (n == 0) {
        res = 1;
    } else {
        res = 1 / (2 * (double) n + 1);
    }

    if (res < x) {
        return res;
    }
    return res + pow(-1, n + 1) * sumOfArray(x, n + 1);
}
