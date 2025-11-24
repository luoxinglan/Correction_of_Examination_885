//
// Created by heihuhu on 25-11-24.
//

/*
 * 头文件（Header Files）通常以 .h 为扩展名，它们主要用于声明函数、定义宏和常量、声明结构体和枚举类型等。头文件的主要目的是提供接口信息，让其他源文件知道如何调用函数或使用数据类型，而不需要了解其具体实现。
 *
 * 头文件通常包含以下内容：
 *
 * 函数原型声明：告诉编译器函数的名称、返回类型和参数列表，但不包含函数的具体实现。
 * 宏定义：使用 #define 预处理指令定义常量或简单的代码片段。
 * 类型定义：使用 typedef 关键字创建新的数据类型名称。
 * 结构体和联合体声明：定义复杂的数据结构。
 * 全局变量声明：使用 extern 关键字声明在其他文件中定义的全局变量。
 * //内联函数定义：对于一些简短的函数，可以在头文件中直接定义为内联函数。
 */

#ifndef TEST2013_H
#define TEST2013_H
#define MaxSize 20

/**
 * 单链表数据结构定义
 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 双数据链表数据结构定义
 */
typedef struct LNode2Data {
    int d1;
    int d2;
    struct LNode2Data *next;
} LNode2Data, //LNode2Data别名为LNode2Data
        *LinkList2Data; //LNode2Data*别名为LinkList2Data

/**
 * 树结点定义
 */
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *Tree;


void sizeOfType();

void importantChar();

void sumKKK(int n, int k);

void unevenN(int n);

void mergeSortStrings();

void permutation(int n);

void swapInt(int *a, int *b);

void initList2Data(LinkList2Data l, int n);

void bubbleSortList2Data(LinkList2Data l);

void processLink2Data(int n);

void initLinkList(LinkList l, int n);

void reverseLinkList(LinkList l);

void outputLinkList(LinkList l);

void processLinkList(int n);

TreeNode *createBST(int nums[], int numsSize);

void processBST();

int countLeafNodes(TreeNode *t);

void testCountLeafNodes();

void convertToOctal(int number);
#endif //TEST2013_H
