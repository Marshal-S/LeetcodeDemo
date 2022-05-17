//
//  inorderSuccessor.c
//  LeetCode
//
//  Created by Marshal on 2022/5/17.
//

#include "inorderSuccessor.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    if (root == NULL) return NULL;
    //如果当前节点比目标小，去右子树找，否则去左子树找
    if (p->val >= root->val) {
        return inorderSuccessor(root->right, p);
    }
    //左边没有比他小的了，去右边找，右边仍然从左边开始找下一个节点
    struct TreeNode* node = inorderSuccessor(root->left, p);
    //找到了后面的第一个叶子节点，为空取根节点即可，否则取当前节点，用于结束前面的函数栈
    return node != NULL ? node : root;
}
