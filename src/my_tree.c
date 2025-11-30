//
// Created by heihuhu on 25-11-29.
//
#include "../include/my_tree.h"

#include <stdbool.h>
#include <stdlib.h>

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
