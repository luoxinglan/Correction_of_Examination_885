//
// Created by heihuhu on 25-11-24.
//

/*
 * 源文件（Source Files）通常以 .c 为扩展名，它们包含了 C 程序的实际实现代码。
 * 源文件的主要特点和内容包括：
 * 函数定义：实现在头文件中声明的函数。
 * 全局变量定义：为在头文件中声明的全局变量分配内存空间。
 * 静态函数和变量：定义只在该源文件内部可见的函数和变量。
 * 主函数（main 函数）：程序的入口点通常定义在一个源文件中。
 * 包含必要的头文件：使用 #include 指令来包含所需的头文件。
 * 源文件通常会包含相应的头文件，以获取必要的声明和定义。
 */

#include "../include/test2013.h"

#include <stdio.h>
#include <time.h>

/**
 * 解释了各种数据类型的字节大小
 */
void sizeOfType() {
    printf("Size of char=%d\n", (int) sizeof(char));
    printf("Size of int=%d\n", (int) sizeof(int));
    printf("Size of long int=%d\n", (int) sizeof(long int));
    printf("Size of float=%d\n", (int) sizeof(float));
    printf("Size of long long int=%d\n", (int) sizeof(long long int));
    printf("Size of double=%d\n", (int) sizeof(double));
    printf("\n");
}

/**
 * 展示常见的重要的字符型常量的值。
 */
void importantChar() {
    printf("Important Char: '%c'=%d\n", '0', '0');
    printf("Important Char: '%c'=%d\n", '1', '1');
    // printf("Important Char: '%c'=%d\n",'9','9');
    printf("Important Char: '%c'=%d\n", 'A', 'A');
    // printf("Important Char: '%c'=%d\n",'Z','Z');
    printf("Important Char: '%c'=%d\n", 'a', 'a');
    // printf("Important Char: '%c'=%d\n",'z','z');
    printf("\n");
}

/**
 * 代码题1正确：输入整数k，n(1≤k≤9，1≤n≤9)，对k，n求和sum=k+kk+kkk+..(n个k)。
 * 如输入k=2，n=3，sum=2+22+222
 * @param n 个数
 * @param k
 */
void sumKKK(int n, int k) {
    int sum = 0;
    printf("sum=");
    for (int i = 0; i < n; i++) {
        int temp = 1;
        for (int j = 0; j < i; j++) {
            temp = temp * 10 + 1;
        }
        if (i == 0) {
            printf("%d", temp * k);
        } else {
            printf("+%d", temp * k);
        }
        sum += temp * k;
    }
    printf("=%d\n\n", sum);
}


/**
 * 代码题2不会：每个数的 n次方都可对应几个奇数之和，1^1=1，2^2=1+3，3^3=3+7+17，输入数n，输出n所对应的奇数之和
 * @param n 输入
 */
void unevenN(int n) {
    int target = n; //N^N
    int sum = 0; //n-1个奇数的和
    for (int i = 1; i < n; i++) {
        target = target * n;
    }
    printf("%d^%d=%d=", n, n, target);
    for (int i = 1; i < n; i++) {
        //从1，3，5，7，9……一直到n-1个奇数，剩下的不知怎的总会是奇数。
        sum = sum + 2 * i - 1;
        printf("%d+", 2 * i - 1);
    }
    printf("%d\n\n", target - sum);
}


//代码题3正确：输入两个字符串，将两个学符事合并，并按照ASCII码顺序将合并后的字符串输出。
#include <string.h>
#include <stdlib.h>//有qsort

int cmp(const void *a, const void *b) {
    return *(char *) a - *(char *) b;
}

/**
 * 代码题3正确：输入两个字符串，将两个学符事合并，并按照ASCII码顺序将合并后的字符串输出。
 */
void mergeSortStrings() {
    char s1[MaxSize] = "default"; //可以不用初始化，反正输入以后后面截断了。
    char s2[MaxSize] = "another";
    // printf("Enter String 1: ");
    // scanf("%s", s1);
    // printf("Enter String 2: ");
    // scanf("%s", s2);
    strcat(s1, s2);
    qsort(s1, strlen(s1), sizeof(char), cmp);
    printf("%s\n\n", s1);
}

/**
 * 在还未确定的位置上递归插入字符串。每一层递归只插入一个字符。remnant=0的时候输出字符串。就像只在叶节点输出的森林的遍历。
 * @param remnant 还有多少位没有确定
 * @param existed_s 已经确定的前面的字符串
 */
void permutationSub(int remnant, char *existed_s) {
    char res[3][MaxSize] = {0}; //存储每一层递归的每一种字母的结果
    char tail[2] = {0}; //尾部待插入的字符
    char provided[] = {'a', 'b', 'c'}; //提供的可选的字符
    if (remnant < 1) {
        //递归出口：没有需要处理的位置时，直接输出。
        puts(existed_s);
        return;
    }
    for (int i = 0; i < 3; i++) {
        //每个位置有3种可能
        strcpy(res[i], existed_s); //将已经确定的字符串复制到初始空字符串
        tail[0] = provided[i]; //第i种可能
        strcat(res[i], tail); //新确定的一个字符连接到已确定字符串后面
        permutationSub(remnant - 1, res[i]); //递归处理剩下的字符串
    }
}

/**
 * 代码题4不会：输出长度为 n 的由 a、b、c构成的排列串，如输入n=2，输出 aa、ab、ac、ba、bb、bc、ca、cb、cc，用递归算法编程。
 * @param n 字符串排列的长度
 */
void permutation(int n) {
    char s[MaxSize] = {0};
    permutationSub(n, s);
}

//代码题5：构造一个链表、具体要求如下:该链表每个结点都包含两个整数，讲所有结点按照第一个整数从小到关排序，如果第一个整数相同，则按第二个整数从小到大排序。
#include <stdbool.h>
/**
 * 交换两个整数的值
 * @param a 变量1地址
 * @param b 变量2地址
 */
void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 头插法插入双数据节点
 * @param l 双数据单链表头结点指针
 * @param n 待插入的数据
 */
void initList2Data(LinkList2Data l, int n) {
    for (int i = 0; i < n; i++) {
        LNode2Data *p = (LNode2Data *) malloc(sizeof(LNode2Data));
        printf("please enter %d node: ", i);
        scanf("%d%d", &p->d1, &p->d2);
        p->next = l->next;
        l->next = p;
    }
}

/**
 * 冒泡排序双数据单链表。结点按照第一个整数从小到关排序，如果第一个整数相同，则按第二个整数从小到大排序
 * @param l 双数据单链表头结点指针
 */
void bubbleSortList2Data(LinkList2Data l) {
    for (LNode2Data *p = l->next; p; p = p->next) {
        bool key = false;
        for (LNode2Data *q = p; q->next; q = q->next) {
            if (q->d1 > q->next->d1) {
                swapInt(&q->d1, &q->next->d1);
                swapInt(&q->d2, &q->next->d2);
                key = true;
            } else if (q->d1 == q->next->d1) {
                if (q->d2 > q->next->d2) {
                    swapInt(&q->d1, &q->next->d1);
                    swapInt(&q->d2, &q->next->d2);
                    key = true;
                }
            }
        }
        if (key == false) {
            break;
        }
    }
    for (LNode2Data *p = l->next; p; p = p->next) {
        printf("%2d,%2d\n", p->d1, p->d2);
    }
}

/**
 * 代码题5正确：建立双数据链表。对链表进行冒泡排序（只交换值）
 * 该链表每个结点都包含两个整数，讲所有结点按照第一个整数从小到关排序，如果第一个整数相同，则按第二个整数从小到大排序。
 */
void processLink2Data(int n) {
    LinkList2Data l = (LNode2Data *) malloc(sizeof(LNode2Data)); //初始化头节点
    l->next = NULL;
    initList2Data(l, n);
    bubbleSortList2Data(l);
}


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

/**
 * 算法题1正确：原地逆置单链表
 * @param l 单链表头结点指针
 * @param n 单链表节点个数
 */
void processLinkList(int n) {
    LinkList l = (LNode *) malloc(sizeof(LNode));
    initLinkList(l, n);
    reverseLinkList(l);
    outputLinkList(l);
}

//建立二叉排序树
/**
 * 根据数组建立一个二叉排序树
 * @param nums 待插入的数组
 * @param numsSize 数组大小
 * @return 返回树的根结点指针
 */
TreeNode *createBST(int nums[], int numsSize) {
    TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
    t->data = nums[0];
    t->left = NULL;
    t->right = NULL;
    for (int i = 1; i < numsSize; i++) {
        //初始化一个结点
        TreeNode *new = (TreeNode *) malloc(sizeof(TreeNode));
        new->data = nums[i];
        new->left = NULL;
        new->right = NULL;
        //查找待插入位置
        TreeNode *p = t;
        while (true) {
            if (nums[i] < p->data) {
                //小于，在左子树
                if (p->left == NULL) {
                    //左子树为空
                    p->left = new;
                    break;
                }
                p = p->left; //一直到左子树为空
            } else {
                if (p->right == NULL) {
                    p->right = new;
                    break;
                }
                p = p->right;
            }
        } //插入一个结点nums[i]完成
    } //全部插入完成
    return t;
}

/**
 * 算法题2正确：建立一个二叉排序树
 */
void processBST() {
    int nums[] = {7, 4, 5, 6, 1, 8, 9};
    int n = 7;
    TreeNode *t = createBST(nums, n);
}


/**
 * 算法题3正确：请给出统计二叉树叶子节点个数的递归算法。
 * @param t 树根结点指针
 * @return 叶子结点个数
 */
int countLeafNodes(TreeNode *t) {
    if (!t) {
        return 0;
    }
    if (t->left == NULL && t->right == NULL) {
        return 1;
    }
    return countLeafNodes(t->left) + countLeafNodes(t->right);
}

/**
 * 依据数组建立BST，然后统计叶结点数目
 */
void testCountLeafNodes() {
    int nums[] = {7, 4, 5, 6, 1, 8, 9};
    int n = 7;
    TreeNode *t = createBST(nums, n);
    printf("%d\n", countLeafNodes(t));
}

/**
 * 任意建立一个二叉排序树
 * @return 返回一个任意数组建立的二叉排序树。
 */
Tree initTree() {
    //首先随便初始化一个树。就创建一个BST吧。
    int nums[] = {7, 4, 5, 6, 1, 8, 1};
    int n = 7;
    // int nums[MaxSize];
    // srand(time(0)); // 设置随机数种子
    // for (int i = 0; i < MaxSize; i++) {
    //     nums[i] = rand() % 5; // 生成随机数并赋值给数组元素
    // }
    TreeNode *t = createBST(nums, 7);
    return t;
}


/**
 * 算法题4正确：已知一个无符号整数number，写一算法，将其转换为八进制数(要求用链栈来实现)
 * 除数留余法
 * @param number 待转换的十进制整数
 */
void convertToOctal(int number) {
    LNode *stack = (LNode *) malloc(sizeof(LNode));
    stack->next = NULL;

    for (; number > 0; number /= 8) {
        headInsert(stack, number % 8);
    }
    outputLinkList(stack);
}
