/*
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
*/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
//https://leetcode.cn/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=top-100-liked
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 递归，当某个深度首次到达时，对应的节点就在右视图中。
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::function<void(std::vector<int>& ans, TreeNode* node, int depth)> dfs =
            [&](std::vector<int>& ans, TreeNode* node, int depth) {
            if (node == nullptr) return;

            if (depth == ans.size()) {  // 这个深度首次遇到
                ans.emplace_back(node->val);
            }
            dfs(ans,node->right, depth + 1); // 先递归右子树，保证首次遇到的一定是最右边的节点
            dfs(ans, node->left, depth + 1);
        };

        std::vector<int> ans;
        dfs(ans, root, 0);
        return ans;
    }
};

// 层序遍历取最后一个元素
class Solution {
private:
    std::vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        std::vector<int> ans;
        std::vector<TreeNode*> cur{ root };
        while (cur.size()) {
            std::vector<TreeNode*> nxt;
            std::vector<int> vals;
            for (auto& node : cur) {
                vals.emplace_back(node->val);
                if (node->left) nxt.emplace_back(node->left);
                if (node->right) nxt.emplace_back(node->right);
            }
            cur = std::move(nxt);
            ans.emplace_back(vals.back());
        }
        return ans;
    }
public:
    std::vector<int> rightSideView(TreeNode* root) {
        return levelOrder(root);
    }
};
