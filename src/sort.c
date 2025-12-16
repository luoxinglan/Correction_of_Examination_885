//
// Created by heihuhu on 25-11-30.
//


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/config.h"

/**
 * 打印数组
 * @param arr 数组
 * @param size 数组大小
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}

/**
 * 生成一个随机数组
 * @param size 随机数组的大小
 * @param left 随机数组最小值
 * @param right 随机数组最大值
 * @return 返回数组的首地址
 */
int *randomArray(int size, int left, int right) {
    int *nums = (int *) malloc(sizeof(int) * size);
    srand(time(0)); // 设置随机数种子
    for (int i = 0; i < size; i++) {
        nums[i] = rand() % (right - left + 1) + left; // 生成随机数并赋值给数组元素
    }
    return nums;
}


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
 * 冒泡排序。（还有一种优化就是每次交换后判断是否产生新的逆序？？？王道说的）
 * @param arr 待排数组
 * @param size 数组大小
 */
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        bool swapped = false;
        for (int j = 1; j < size - i; j++) {
            //大的元素往后移动。每一趟排序确定一个最大元素的位置。故size-i
            if (arr[j - 1] > arr[j]) {
                swapInt(&arr[j - 1], &arr[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

/**
 * 归并两个有序的串。空间复杂度n。
 * @param nums 待排序数组
 * @param low 左界限
 * @param mid 中点（属于左子串）
 * @param high 右界限
 */
void merge(int nums[], int low, int mid, int high) {
    int temp[MaxSize]; //临时数组，用于存放归并后的有序元素，空间复杂度为n。
    //左半边小于等于mid，右半边大于mid
    //0123,01,23; 012,01,2
    int i; //左半边起始下标
    int j; //右半边起始下标
    int k; //计数变量
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        //将元素按从小到大复制到临时数组
        if (nums[i] <= nums[j]) {
            //两个队列头中选一个更小的复制到临时数组
            temp[k] = nums[i++];
        } else {
            temp[k] = nums[j++];
        }
    }
    //若左半边还有剩余元素
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    //若右半边还有剩余元素
    while (j <= high) {
        temp[k++] = nums[j++];
    }
    //将临时数组复制到原来的数组完成归并
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
        int mid = (low + high) / 2; //此元素右边为右半有序表
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

/**
 * 向下调整堆：把以当前节点为堆顶的子堆调整为大根堆。
 * @param nums 堆
 * @param current 当前调整的结点
 * @param size 堆的大小
 */
void heapAdjust(int nums[], int current, int size) {
    int temp = nums[current]; //存储当前结点。在最后下沉完毕的时候赋值到最终位置。
    for (int i = 2 * current + 1; i < size; i = i * 2 + 1) {
        //从当前节点的左子树出发
        if (i + 1 < size && nums[i] < nums[i + 1]) {
            //筛选左右孩子中较大的结点
            i++;
        }
        if (nums[current] < nums[i]) {
            //孩子大于根，孩子上浮，并继续向下调整子堆
            nums[current] = nums[i]; //孩子上浮。
            current = i; //续向下调整子堆。这是关键一步。现在的根节点是2 * current + 1了。
        } else {
            //根大于孩子则已调整完毕，退出循环。
            break;
        }
        nums[current] = temp;
        //为什么不更新temp而且每次调整都要赋值给current？因为要下沉到最底部
        //较小的根结点下沉到current，接下来继续从current向下调整。（王道教材有误，放到for循环外面了。我在这里卡了很久）
    }
}

/**
 * 建堆：本质上是调整堆。从第一个非叶结点开始，调整所有非叶结点。
 * @param nums 堆
 * @param size 堆的大小
 */
void buildHeap(int nums[], int size) {
    for (int k = (size - 1) / 2; k >= 0; k--) {
        //最末一个分支结点下标为 (size - 1) / 2。
        heapAdjust(nums, k, size);
    }
}

/**
 * 堆排序：①建堆，②交换，③调整，循环执行②③直到所有元素均已有序。
 * @param num 堆
 * @param size 堆大小
 */
void heapSort(int num[], int size) {
    buildHeap(num, size);
    for (int i = size - 1; i > 0; i--) {
        //i表示最后一个元素。
        swapInt(&num[0], &num[i]); //最后一个元素与堆顶交换。
        heapAdjust(num, 0, i); //交换后，堆的大小减一。
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
    int pivot = nums[low]; //初始枢轴元素。
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            //从右往左找到小于枢轴的元素。
            high--;
        }
        nums[low] = nums[high]; //将较小元素赋值到左边位置
        while (low < high && nums[low] <= pivot) {
            //从左往右找到大于枢轴的元素
            low++;
        }
        nums[high] = nums[low]; //将较大元素赋值到右边位置
    } //退出循环时low==high，都指向枢轴元素最终位置。
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
