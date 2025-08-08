/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
*/

// 递归得注意返回条件，这里是node！=nullptr
#pragma once
#include<iostream>
#include<vector>
#include<stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// 递归
class Solution {
private:
    void inorderHelper(TreeNode* node, std::vector<int>& res) {
        if (node) {
            inorderHelper(node->left, res);
            res.emplace_back(node->val);
            inorderHelper(node->right, res);
        }
    }
public:
    std::vector<int> inorderTraversal(TreeNode* root){
        std::vector<int> res;
        inorderHelper(root, res);
        return res;
    }
};
// 迭代
// 中序遍历
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        std::stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            ans.emplace_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
// 前序遍历(先将右节点存入，则右节点最后弹出)
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        std::stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                ans.emplace_back(root->val);
                stk.push(root->right);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
        }
        return ans;
    }

};
// 后序遍历（就是前序遍历的时候先将右节点压入栈，则最后的结果是中右左，进行翻转就是左右中）
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        std::stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                ans.emplace_back(root->val);
                stk.push(root->left);
                root = root->right;
            }
            root = stk.top();
            stk.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

