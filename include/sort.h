//
// Created by heihuhu on 25-11-30.
//
/*
 * qsort函数的比较函数的实现
 */
#ifndef COMPARE_H
#define COMPARE_H

void printArray(int arr[], int size);

int *randomArray(int size, int left, int right);

void swapInt(int *a, int *b);

int charCmp(const void *a, const void *b);

int intCmp(const void *a, const void *b);

void bubbleSort(int *arr, int size);

void mergeSort(int nums[], int low, int high);

void heapSort(int num[], int size);

void quickSort(int num[], int low, int high);
#endif //COMPARE_H
