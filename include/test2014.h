//
// Created by heihuhu on 25-11-26.
//
/*
* 当在main.c中调用函数时，编译器会查找该函数的声明。这个声明通常位于对应的头文件.h中。
在main.c中使用了#include "fun.h"指令，这意味着编译器会将fun.h的内容包含到main.c中进行编译。
在fun.h中，函数的声明告诉编译器有一个函数存在，但没有具体的实现。这就是所谓的函数原型或函数声明。
编译器在编译过程中并不关心函数的具体实现在哪个.c文件中，它只需要找到对应的函数声明。
在链接阶段，编译器会将所有.c文件中的函数实现链接起来，生成最终的可执行文件。在这个阶段，编译器会查找所有被调用的函数的实现，并将它们合并到可执行文件中。
因此，对于编译器来说，只需要在编译过程中找到函数的声明即可，具体的函数实现会在链接阶段解决。
解决方案：
在fun.h中声明函数的原型，例如：void fun();，这是函数的声明。
在fun.c中实现函数，例如：void fun() { // 函数实现 }。
在main.c中调用函数fun()，并在文件开头包含#include "fun.h"。
这样，编译器在编译main.c时会找到函数fun()的声明，而具体的实现会在链接阶段解决，无需显式指定函数的实现文件。

在大型 C 项目中，头文件常常被多个源文件引用。如果头文件没有适当的保护机制，可能会发生以下情况：

重复定义：同一个头文件可能会被多次包含，导致符号、变量等重复定义的错误。
性能问题：每次头文件被包含时，都会编译头文件内容，增加编译时间。
通过 #ifndef 和 #endif 可以防止这些问题，通常称为“头文件保护”。
————————————————
版权声明：本文为CSDN博主「Crazy 0211」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_52734695/article/details/143768958
 */
#ifndef TEST2014_H
#define TEST2014_H

void showCharConst();

void mergeStrings2();

float sumOfSequence(const int n);

void S_R_substring2014();

void partitionSqList();

void searchTreeXLevel(int x);

#endif //TEST2014_H
