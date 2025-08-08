/*
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。
*/
// https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<functional>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 该题目和“二叉树的直径”相似
// 需注意这道题返回的是结点值，需要考虑值为负数的情况，如果为负数，则返回0相当于无视这条支路
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        std::function<int(TreeNode* node)> dfs =
            [&](TreeNode* node)->int {
            if (node == nullptr) return 0;

            int right_value = std::max(0, dfs(node->right));
            int left_value = std::max(0, dfs(node->left));

            ans = std::max(ans, left_value + right_value + node->val);
            return std::max(left_value, right_value) + node->val;
        };
        dfs(root);
        return ans;
    }
};