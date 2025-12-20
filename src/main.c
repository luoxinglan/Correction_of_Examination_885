/**
 * 当你想分享你的项目时，必须将其推送到上游。
 * 这个命令很简单：git push <remote> <branch>。
 * 当你想要将 master 分支推送到 origin 服务器时（再次说明，克隆时通常会自动帮你设置好那两个名字），
 * 那么运行这个命令就可以将你所做的备份到服务器：
 * $ git push origin master
 * 初始化11.24，合并了在线的readme和本地的main。
 * 新项目开始时，先 clone 远程仓库，而不是 git init + git remote add。
 * 如果必须本地初始化，可先 git clone 空仓库，再把代码复制进去。
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../include/config.h"
#include "../include/my_link.h"
#include "../include/sort.h"
#include "../include/test2002.h"
#include "../include/test2004.h"
#include "../include/test2013.h"
#include "../include/test2014.h"
#include "../include/test2015.h"
#include "../include/test2016.h"
#include "../include/test2017.h"
#include "../include/test2018.h"
#include "../include/test2019.h"
#include "../include/test2020.h"
#include "../include/test2022.h"
#include "../include/test2023-2025.h"
#include "../include/print_graphs.h"

void basicKnowledge() {
    sizeOfType();
    importantChar();

    showCharConst();
    data_representation();

    format_control_of_printf();

    referenceToArray();
    union unity a;
    a.i = 5;
    unionAsFunParam(a);
    precedence_increment_modulus();

    typeChange();

    pointerIncrease();
}

void printGraph() {
    // printTriangleHollow(4);
    printRightTriangleNumber(4);
}

void mathFunc() {
    fabs(-1.0); //返回函数绝对值。
    pow(-1.0, 2.0); //返回-1的平方。
    getc(stdin); //需要一个 FILE* 类型的参数；可以从任意指定的文件流中读取字符。
    getchar(); //没有参数；固定从标准输入流 stdin 读取字符。
}

void sorts() {
    int *a = randomArray(7, 0, 16);
    printArray(a, 7);
    bubbleSort(a, 7);
    // mergeSort(a, 0, 2);
    // heapSort(a, 7);
    // quickSort(a, 0, 8);
    printArray(a, 7);
}

void fun2004() {
    char s[] = "hello world";
    char *ss = "hello world"; //字符串常量不可被修改
    puts(s);
    reverseStringRecursively(s, 0, strlen(s) - 1);
    puts(s);
}

void fun2013() {
    sumKKK(3, 2);
    unevenN(4);
    mergeSortStrings2013();
    // permutationSub(); //没在头文件中声明的其他文件函数无法使用
    permutation2013(3);
    processLink2Data(8);
    /*
      15 16
      15 19
      15 10
      15 17
      14 16
      14 10
      14 16
      14 9
     */
    processLinkList(3);
    processBST();
    testCountLeafNodes();
    convertToOctal(17);
}

void fun2014() {
    mergeStrings2();
    sumOfSequence(1);
    S_R_substring2014();
    partitionSqList();
    searchTreeXLevel(1);
}

void fun2015() {
    bool is0124 = judge0124(1023);
    float pai = calcuPAI(0.112);
    char s1[MaxSize * 2], s2[MaxSize];
    puts("enter the s1:");
    gets(s1); //不能用fgets，否则会把\n也读入字符串。长度就不对了。
    puts("enter the s2:");
    gets(s2); //不能用fgets，否则会把\n也读入字符串。长度就不对了。
    mergeSortStrings2015(s1, s2);
    sortSortStrings();
}

void fun2016() {
    printSymmetricalLetterSequence('E');
    bool res = isPalindrome();
    printSortedLinkList();
}

void fun2017() {
    char s[MaxSize];
    gets(s);
    deleteSpaceInString(s);
    puts(s);

    //指针数组和数组指针的用法
    intPointerArray();
    //函数指针数组的用法
    executeFunctionPointer();

    int res = sumOfArrays2017(3);

    //双向循环链表
    DLinkList dl = initDLinkList(5);
    outputDLinkList(dl, 0);

    //删除单链表中最小元素
    LinkList l = initLinkList(5);
    outputLinkList(l);
    deleteLintListMin(l);
    outputLinkList(l);
}

void fun2019() {
    char s[] = "abbcccddddeeeee";
    char s2[] = "";
    repeatedLetters(s); //a3b2c4
}

void fun2020() {
    permutation2020();
    findReversibleNum2020();
    printf("sumOfArray: %f\n\n", sumOfArray(1.0 / 2, 0));
    printDiamondHollowXIf(10);
}

void fun2022() {
    printTrapezoid2(5);
    outPutBinary(11);
    printf("\n");
    printf("count of sub strings :%d\n\n", countSubStrings("abababababac", "ab"));
    complex num1 = {1, 1}, num2 = {1, -1}, num3 = complexProduct(num1, num2);
    printComplex(num3);

    //算法题1正确：逆置无头单链表
    LinkList h = initLinkListNoHead(5);
    outputLinkListNoHead(h);
    reverseLinkListNoHead(&h); //由于不带头结点，所以要修改首结点指针的值。
    outputLinkListNoHead(h);

    //算法题2正确：按行给二维数组排序
    int a[N][N];
    inputMatrix(a,N);
    printMatrix(a,N);
    sortMatrix(a,N);
    printMatrix(a,N);
}

void fun2023() {
    printTriangleLetter(5);
    findReversibleNum2023();
    printf("sumOfArray: %f\n\n", sumOfArray2023(1, 2, 2));
    S_R_substring2023();
}

void fun2024() {
    splitEvenNumber();
}

void fun2025() {
    char s[] = "123456789";
    outputReversedString(s);
}

int main(void) {
    // basicKnowledge();
    // fun2004();
    // fun2013();
    // fun2014();
    // fun2015();
    // fun2016();
    // fun2017();
    // fun2019();
    // fun2020();
    // fun2022();
    // fun2023();
    // fun2024();
    fun2025();
    // sorts();
    // printGraph();
    return 0;
}
