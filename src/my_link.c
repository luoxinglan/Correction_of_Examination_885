//
// Created by heihuhu on 25-11-29.
//
#include"../include/my_link.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/sort.h"

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
 * 初始化单链表（头插法）。
 * @param l 单链表头结点指针
 * @param n 待插入的数据
 */
LinkList initLinkList(int n) {
    LinkList l = (LinkList) malloc(sizeof(LNode));
    l->next = NULL;
    for (int i = 0; i < n; i++) {
        // LNode *p = (LNode *) malloc(sizeof(LNode));
        printf("please enter %d node: ", i);
        int temp = 0;
        scanf("%d", &temp);
        headInsert(l, temp);
    }
    return l;
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
 * 输出单链表。
 * @param l 单链表头结点指针
 */
void outputLinkList(LinkList l) {
    for (LNode *p = l->next; p; p = p->next) {
        printf("%3d", p->data);
    }
    printf("\n");
}

/**
 * 删除单链表中最小元素。
 * @param l 单链表头结点指针
 */
void deleteLintListMin(LinkList l) {
    if (l == NULL) {
        return;
    }
    int min = l->next->data;
    LNode *minP = l->next, *p, *pre;
    for (p = l; p->next; p = p->next) {
        if (min > p->next->data) {
            min = p->next->data;
            pre = p;
            minP = p->next;
        }
    }
    pre->next = minP->next;
    free(minP);
}

/**
 * 使用冒泡排序的方式递增排序单链表。
 * @param l 待排链表
 */
void bubbleSortLink(LinkList l) {
    for (LNode *p = l->next; p; p = p->next) {
        bool flag = false;
        for (LNode *q = p->next; q; q = q->next) {
            if (q->data < p->data) {
                swapInt(&q->data, &p->data);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
};

/**
 * 建立双向循环链表。尾插法。
 * @param n 双向循环链表的结点数目
 * @return 双向循环链表头节点指针
 */
DLinkList initDLinkList(int n) {
    DLinkList l = (DLinkList) malloc(sizeof(DLNode)); //头节点
    l->next = NULL;
    l->pre = NULL;
    l->data = n;
    DLNode *rear = l; //尾指针
    for (int i = 0; i < n; i++) {
        DLNode *p = (DLNode *) malloc(sizeof(DLNode)); //新结点
        p->next = NULL;
        p->pre = NULL;
        printf("please enter %d DLNode: ", i);
        scanf("%d", &p->data);
        //正向
        rear->next = p;
        p->next = l;
        //逆向
        l->pre = p;
        p->pre = rear;
        //更新尾指针
        rear = p;
    }
    return l;
}

/**
 * 输出双向循环链表数据。
 * @param l 双向循环链表头节点指针
 * @param right 是否为正向
 */
void outputDLinkList(DLinkList l, const bool right) {
    DLNode *p = l;
    while (right ? p->next != l : p->pre != l) {
        //right为true则为正向
        right ? (p = p->next) : (p = p->pre); //赋值运算符优先级比三目运算符低。所以要加括号。
        printf("%3d", p->data);
    }
}
