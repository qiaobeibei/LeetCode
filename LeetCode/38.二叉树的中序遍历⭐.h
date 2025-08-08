/*
����һ���������ĸ��ڵ� root ������ ���� ���� ���� ��
*/

// �ݹ��ע�ⷵ��������������node��=nullptr
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
// �ݹ�
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
// ����
// �������
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
// ǰ�����(�Ƚ��ҽڵ���룬���ҽڵ���󵯳�)
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
// �������������ǰ�������ʱ���Ƚ��ҽڵ�ѹ��ջ�������Ľ���������󣬽��з�ת���������У�
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

