//
// Created by heihuhu on 25-11-29.
//
#include <stdio.h>
#include "../include/test2002.h"

/**
 * 展示对数组元素的正确引用
 */
void referenceToArray() {
    {
        int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, *p = a, i = 5;
        *(a + i); //a[i]
    }
}

/**
 * 展示共用体如何作为函数参数的使用，以及共用体只能存储一种元素
 * @param data 共用体参数
 */
void unionAsFunParam(union unity data) {
    data.f = 0.2;
    printf("unionAsFunParam data.f = %f\n\n", data.f);
}

/**
 * 展示自增和和取余的优先级
 */
void precedence_increment_modulus() {
    for (int i = 0; i < 100000; i++) {
        if (++i % 2 == 0)
            if (++i % 3 == 0)
                if (++i % 5 == 0)
                    printf("%d\n", i);
    }
}
