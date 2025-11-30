//
// Created by heihuhu on 25-11-29.
//

#ifndef TEST2002_H
#define TEST2002_H

//共用体类型定义
union unity {
    int i;
    char c;
    float f;
};

void referenceToArray();

void unionAsFunParam(union unity data);

void precedence_increment_modulus();
#endif //TEST2002_H
