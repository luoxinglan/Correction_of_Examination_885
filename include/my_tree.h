//
// Created by heihuhu on 25-11-29.
//

#ifndef MY_TREE_H
#define MY_TREE_H
/**
 * 树结点的定义
 */
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *Tree;

TreeNode *createBST(int nums[], int numsSize);

Tree initTree();
#endif //MY_TREE_H
