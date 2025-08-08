/*
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
*/

#pragma once
#include<iostream>
#include<algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return std::max(left, right) + 1;
    }
};

class Solution {
private:
    int getDepth(TreeNode* node) {
        if (node) {
            return std::max(getDepth(node->left), getDepth(node->right)) + 1;
        }
        return 0;
    }
public:
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};
