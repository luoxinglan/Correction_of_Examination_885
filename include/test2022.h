//
// Created by heihuhu on 25-12-16.
//

#ifndef TEST2022_H
#define TEST2022_H

#define N 3

typedef struct complex {
    int real;
    int imag;
} complex;

void outPutBinary(unsigned x);

int countSubStrings(char *str, char *sub);

complex complexProduct(complex num1, complex num2);

void printComplex(complex num);

void swapLine(int a[N], int b[N]);

double averageLine(int a[], int n);

void sortMatrix(int a[][N], int n);

void printMatrix(int a[][N], int n);

void inputMatrix(int a[][N], int n);
#endif //TEST2022_H
