/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。
*/
//https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked
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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::function<void(std::vector<int>& ans, TreeNode* node)> inorderHelper =
            [&](std::vector<int>& ans, TreeNode* node) {
            if (node == nullptr) return;

            inorderHelper(ans, node->left);
            ans.emplace_back(node->val);
            inorderHelper(ans, node->right);
        };
        std::vector<int> ans;
        inorderHelper(ans, root);
        return ans[k-1];
    }
};