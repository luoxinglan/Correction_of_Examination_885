//
// Created by heihuhu on 25-11-29.
//

#ifndef MY_LINK_H
#define MY_LINK_H
/**
 * 单链表数据结构定义
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void headInsert(LinkList l, int n);

void initLinkList(LinkList l, int n);

void reverseLinkList(LinkList l);

void outputLinkList(LinkList l);
#endif //MY_LINK_H
