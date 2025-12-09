//
// Created by heihuhu on 25-12-9.
//

#include <string.h>
#include <stdio.h>
#include "../include/config.h"
#include "../include/test2016.h"
#include "../include/my_link.h"

#include <stdlib.h>


/**
 * 代码题2：打印对称的字符串。
 * @param n 正中间的字母
 */
void printSymmetricalLetterSequence(char n) {
    if (n < 'A' || n > 'Z') {
        return;
    }
    int dist = n - 'A';
    for (int i = 0; i <= dist; i++) {
        printf("%c", 'A' + i + 32 * (i % 2 == 1));
    }
    for (int i = 1; i <= dist; i++) {
        printf("%c", n - i + 32 * (i % 2 == 1));
    }
}

/**
 * 代码题3：输入一个字符串，判断是否是回文。
 * @return 是否是回文字符串
 */
bool isPalindrome() {
    char s[MaxSize];
    gets(s); //不能用fgets，否则会把\n也读入字符串。长度就不对了。
    int len = strlen(s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != s[len - i - 1]) {
            printf("is not a palindrome\n");
            return false;
        }
    }
    printf("is  a palindrome\n");
    return true;
}

/**
 * 代码题5：初始化一个单链表，递增排序后输出。
 */
void printSortedLinkList() {
    LinkList L = initLinkList(5);
    outputLinkList(L);
    bubbleSortLink(L);
    outputLinkList(L);
}
