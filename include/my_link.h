//
// Created by heihuhu on 25-11-29.
//

#ifndef MY_LINK_H
#define MY_LINK_H
#include <stdbool.h>
/**
 * 单链表数据结构定义
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 双链表数据结构定义
 */
typedef struct DLNode {
    int data;
    struct DLNode *pre, *next;
} DLNode, *DLinkList;

void headInsert(LinkList l, int n);

LNode *findTail(LinkList l);

LinkList initLinkList(int n);

LinkList initLinkListNoHead(int n);

void reverseLinkList(LinkList l);

void reverseLinkListNoHead(LinkList *l);

void outputLinkList(LinkList l);

void outputLinkListNoHead(LinkList l);

void deleteLintListMin(LinkList l);

void bubbleSortLink(LinkList l);

DLinkList initDLinkList(int n);

void outputDLinkList(DLinkList l, const bool right);
#endif //MY_LINK_H
