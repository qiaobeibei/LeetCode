/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/
//https://leetcode.cn/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            // 如果 p 和 q 有一个为空，那么仅当二者都为空时才返回 true
            return p == q; 
        }
        // 如果 p 和 q 都不为空
        // 先判断 p 和 q 的值是否相同，然后判断p的左子树和q的右子树是否相同，p的右子树和q的左子树是否相同
        // 仅当三者条件同时真时，两个树对称
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->right, root->left);
    }
};
