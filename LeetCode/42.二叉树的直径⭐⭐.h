/*
给你一棵二叉树的根节点，返回该树的 直径 。

二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

两节点之间路径的 长度 由它们之间边数表示。
*/
//https://leetcode.cn/problems/diameter-of-binary-tree/description/?envType=study-plan-v2&envId=top-100-liked
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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        std::function<int(TreeNode* node)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return -1;
            }
            int left_len = dfs(node->left) + 1;
            int right_len = dfs(node->right) + 1;
            ans = std::max(ans,left_len + right_len); // 将当前结点以及左右子树的链长合并
            return std::max(right_len, left_len); // 返回左右子树中最大的链长
        };
        dfs(root);
        return ans;
    }
};