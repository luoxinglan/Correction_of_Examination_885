//
// Created by heihuhu on 25-12-9.
//


#include <math.h>
#include <stdio.h>
/**
 * 删除字符串中的空格。使用快慢指针。
 * @param str 字符串头指针
 */
void deleteSpaceInString(char str[]) {
    int fast, slow;
    for (fast = slow = 0; str[fast] != '\0'; fast++) {
        if (str[fast] != ' ') {
            str[slow++] = str[fast];
        }
    }
    str[slow] = '\0';
}

/**
 * 函数指针作为函数参数的使用。
 * @param x 参数
 * @param func 函数指针
 * @return 值
 */
double execute(const double x, double (*func)(double)) {
    double temp;
    return (*func)(x); //调用函数指针时，直接将(*p)代替函数名了。
    return temp;
}

/**
 * 指针数组！数组指针！总结：先算*是指针，先算[]是数组。
 */
void intPointerArray() {
    int *intArray[3]; //指针【数组】。[3]首先与intArray结合为intArray[3]，这是【数组】形式。然后intArray与*结合，*表示这个数组是指针类型的。
    int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; i++) {
        intArray[i] = a[i];
    }
    int (*intP)[3] = a + 1; //整型数组【指针】。()优先级是所有运算符中优先级最高的，且是左结合，说明是指针类型。其次运算[3]，指针变量的基类型是int[3]。
    //()优先级最高。intP首先与*结合，*inP显然是【指针类型】。然后*intP与[3]结合，A[3]形式是数组。那么指针的基类型是int[3]，是一个数组。那么这个变量是数组指针。
}

/**
 * 函数指针的使用！函数指针数组！总结：先算[]是数组，*是指针，(type)是函数。
 */
void executeFunctionPointer() {
    double (*func[3])(double); //函数指针数组，基类型是(*func)(double)
    //func首先与[3]结合，是【数组】。func[3]与*结合，是【指针数组】。*func[3]与()结合，指针的基类型是参数为一个double的函数(*func)(double)
    double x = 1;
    func[0] = sin;
    func[1] = cos;
    func[2] = tan;
    for (int i = 0; i < 3; i++) {
        printf("func No:%d----%f\n", i + 1, execute(x, func[i]));
    }
    double (*func4)(double, double) = pow;
    printf("func No:%d----%f\n", 3 + 1, (*func4)(x, x));
}

/**
 * 代码题3正确：找规律。不用递归。
 * @param n 项数
 * @return 和
 */
int sumOfArrays2017(int n) {
    long long sum = 0;
    int a_pre = 1;
    for (int i = 0; i < n; i++) {
        int a_i = a_pre + i;
        sum += a_i;
        a_pre = a_i;
    }
    return sum;
}


