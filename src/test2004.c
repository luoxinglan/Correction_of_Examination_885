//
// Created by heihuhu on 25-11-29.
//
#include "../include/test2004.h"

#include <math.h>
#include <stdio.h>

/**
 * 数据的表示、字符串输出。
 * 转义字符的八进制数、十六进制数和常规的八进制、十六进制。
 * https://www.runoob.com/w3cnote/hex-dec-oct-bin.html
 */
void data_representation() {
    //数据的八进制和十六进制
    int n = '\141'; //字符的八进制数据用转义字符\xxx表示。
    n = 0x8132; //十六进制用0xFFF表示。
    n = !n; //n原本是非零的，“非”以后变成零
    printf("the value of 072=='\\72' is %d\n", 072 == '\72'); //由此可见，字符中的转义字符八进制数'\ddd'，普通的八进制数由零开头0ddd
    printf("the value of 0x072=='\\x072' is %d\n", 0x072 == '\x072'); //由此可见，字符中的转义字符十六进制数'\xddd'，普通的八进制数由零开头0xddd

    //字符串输出
    char *s = "\t\" NULL\111?\n"; //\t制表符是8个空格，\111是八进制，\n也会输出。
    printf("%s", s);
    printf("\n");
}

/**
 * printf的格式控制：
 * longlong整形在printf中%d被截断的情况使用%lld
 */
void format_control_of_printf() {
    /*整型数据输出被截断，只输出低字节的部分*/
    long long m = 0x1234567812345678;
    printf("/*Integer data output is truncated, only the lower byte is output*/\n");
    printf("%%d: %d\n", m); //只输出了低4B的数据305419896
    printf("%%lld: %lld\n", m); //完整输出了8B的数据1311768465173141112
    printf("%%ld: %ld\n", m); //另外，类型不符合，按照%d打印
    printf("\n"); //另外，类型不符合，按照%d打印

    /*整数输出的数据宽度受数据和宽度限制*/
    printf("/*The width of integer output is limited by the data and the width*/\n");
    printf("Left alined data is limited by the data and the width: %-5d%-5u,\n", 60, -80);
    //左对齐输出有符号整数、无符号整数。最小数据宽度小于数据宽度时无效。
    printf("Octal: %5o %5o,\n", 8, 0x80000000); //八进制输出无符号整数
    printf("Hexadecimal: %X %x,\n", 15, 0x80000000); //十六进制输出无符号整数
    printf("\n");

    /*浮点数的格式控制：省略零、控制精度*/
    float i = 1;
    long double x = 0.123456789123456789;
    printf("/*Floating-point format control: omit zeros, control precision*/\n");
    printf("Omitting zeros by using %%g: %f, %g\n", i / 2, i / 2); //%f输出浮点数，%g省略不必要的零
    printf("%%f outputs floating-point numbers with only 6 digits of precision: %f\n", i / 3); //%f输出浮点数只能保留6位精度
    printf("NO %%gf: %gf\n", i / 2); //没有%gf这种组合用法！！！0.5f注意到多输出了一个f
    printf("%%3.4f: %3.4f\n", M_PI); //3位数据的最小宽度、保留到小数点后4位，故数据宽度一共6位
    printf("%%lf: %f\n", M_PI); //lf小数点后六位
    printf("%%llf: %f\n", M_PI); //llf，不会考的。long double
    printf("\n");

    /*指数*/
    printf(
        "%%e outputs floating-point numbers in scientific notation, where 10 represents the data width and .2 indicates two decimal places of precision.\n");
    printf("%10.2e\n", i / 3); //%e以科学计数法输出浮点数，10表示数据宽度.2表示小数点后保留两位精度
    printf("\n");
}

/**
 * 编程题1不会：调换字符串首尾，然后首指针后移，尾指针前移，递归调用。
 * @param s 字符串
 * @param front 未调换的子串首部指针
 * @param rear 未调换的子串尾部指针
 */
void reverseStringRecursively(char *s, int front, int rear) {
    if (front < rear) {
        // printf("s[front]=%c, s[rear]=%c", s[front], s[rear]);
        char temp = s[front];
        s[front] = s[rear];
        s[rear] = temp;
        reverseStringRecursively(s, front + 1, rear - 1);
    }
}
