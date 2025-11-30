//
// Created by heihuhu on 25-11-30.
//


#include <stdio.h>
#include "../include/config.h"

/**
 * 交换两个整数的值
 * @param a 变量1的地址
 * @param b 变量2的地址
 */
void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int charCmp(const void *a, const void *b) {
    return *(char *) a - *(char *) b;
}

int intCmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

/**
 * 归并两个有序的串。
 * @param nums 待排序数组
 * @param low 左界限
 * @param mid 中点（属于左子串）
 * @param high 右界限
 */
void merge(int nums[], int low, int mid, int high) {
    int temp[MaxSize];
    //左半边小于等于mid，右半边大于mid
    //0123,01,23; 012,01,2
    int i, j, k;
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (nums[i] <= nums[j]) {
            //递增
            temp[k] = nums[i++];
        } else {
            temp[k] = nums[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= high) {
        temp[k++] = nums[j++];
    }
    for (i = 0; i <= high - low; i++) {
        nums[low + i] = temp[i];
    }
}

/**
 * 归并排序：将每一个序列划分成左右两半，直到只有一个元素；接着进行归并有序的串，1、2、4、8……
 * @param nums 待排序数组
 * @param low 左界限
 * @param high 右界限
 */
void mergeSort(int nums[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

/**
 * 将以当前节点为根的子堆调整为大根堆
 * @param nums 堆
 * @param current 当前调整的结点
 * @param size 堆的大小
 */
void heapAdjust(int nums[], int current, int size) {
    int temp = nums[current]; //存储当前结点
    //从当前节点的左子树出发
    for (int i = 2 * current + 1; i < size; i = i * 2 + 1) {
        //筛选左右孩子中较大的结点
        if (i + 1 < size && nums[i] < nums[i + 1]) {
            i++;
        }
        //根大于孩子
        if (nums[current] >= nums[i]) {
            break;
        }
        //孩子大于根，孩子上浮，并继续向下调整子堆
        nums[current] = nums[i];
        current = i; //这是关键一步。现在的根节点是current了。
        nums[current] = temp; //较小的根结点下沉到current，接下来继续从current向下调整。（王道教材有误，放到for循环外面了。我在这里卡了很久）
    }
}

/**
 * 从第一个非叶结点调整子堆，逐渐调整到根
 * @param nums 堆
 * @param size 堆的大小
 */
void buildHeap(int nums[], int size) {
    for (int k = size / 2 - 1; k >= 0; k--) {
        heapAdjust(nums, k, size);
    }
}

/**
 * 建堆，交换堆顶与无序序列尾部，调整删掉一个结点的堆的根结点。
 * @param num 堆
 * @param size 堆大小
 */
void heapSort(int num[], int size) {
    buildHeap(num, size);
    for (int i = size - 1; i > 0; i--) {
        swapInt(&num[0], &num[i]);
        heapAdjust(num, 0, i);
    }
}

/**
 * 快速排序的划分算法。关键。
 * @param nums 待排子列
 * @param low 左限位
 * @param high 右限位
 * @return 枢轴元素下标
 */
int partition(int nums[], int low, int high) {
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low; //low==high
}

/**
 * 快速排序。先进行划分，为左右子列。
 * @param num 待排数组
 * @param low 低位
 * @param high 高位
 */
void quickSort(int num[], int low, int high) {
    if (low < high) {
        int pivotPos = partition(num, low, high);
        quickSort(num, low, pivotPos - 1);
        quickSort(num, pivotPos + 1, high);
    }
}
