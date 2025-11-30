//
// Created by heihuhu on 25-11-29.
//
#include"../include/my_link.h"

#include <stdio.h>
#include <stdlib.h>

//原地逆置单链表
/**
 * 头插法插入单链表
 * @param l 头结点指针。
 * @param n 待插入的数据
 */
void headInsert(LinkList l, int n) {
    if (l == NULL) {
        return;
    }
    LNode *p = (LNode *) malloc(sizeof(LNode));
    p->data = n;
    p->next = l->next;
    l->next = p;
}

/**
 * 初始化单链表
 * @param l 单链表头结点指针
 * @param n 待插入的数据
 */
void initLinkList(LinkList l, int n) {
    if (l == NULL) {
        return;
    }
    l->next = NULL;
    for (int i = 0; i < n; i++) {
        // LNode *p = (LNode *) malloc(sizeof(LNode));
        printf("please enter %d node: ", i);
        int temp = 0;
        scanf("%d", &temp);
        headInsert(l, temp);
    }
}

/**
 * 原地逆置单链表
 * @param l 单链表头结点指针
 */
void reverseLinkList(LinkList l) {
    if (l == NULL) {
        return;
    }
    LNode *p, *q;
    for (p = l->next, l->next = NULL, q = p->next; p; p = q) {
        q = p->next;
        p->next = l->next;
        l->next = p;
    }
}

/**
 * 输出单链表
 * @param l 单链表头结点指针
 */
void outputLinkList(LinkList l) {
    for (LNode *p = l->next; p; p = p->next) {
        printf("%3d", p->data);
    }
    printf("\n");
}
