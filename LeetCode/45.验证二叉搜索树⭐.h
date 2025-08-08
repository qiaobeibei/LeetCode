/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
//https://leetcode.cn/problems/validate-binary-search-tree/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<vector>
#include<functional>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 中序遍历之后依次比较
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::function<void(std::vector<int>& ans, TreeNode* node)> inorderHelper =
            [&](std::vector<int>& ans, TreeNode* node) {
            if (node == nullptr) return;

            inorderHelper(ans, node->left);
            ans.emplace_back(node->val);
            inorderHelper(ans, node->right);
        };
        std::vector<int> ans;
        inorderHelper(ans, root);
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i - 1] >= ans[i]) return false;
        }
        return true;
    }
};