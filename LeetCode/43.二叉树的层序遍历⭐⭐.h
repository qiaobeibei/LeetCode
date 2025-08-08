/*
����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��
*/
//https://leetcode.cn/problems/binary-tree-level-order-traversal/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<vector>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        std::vector<std::vector<int>> ans;
        std::vector<TreeNode*> cur = { root };
        while (cur.size()) {
            std::vector<TreeNode*> nxt; // �洢��һ����Ҫ�����Ľ��
            std::vector<int> vals; // �洢ÿһ��������� val
            for (auto& node : cur) {  // ����ÿһ���Ԫ��
                vals.emplace_back(node->val); 
                if (node->left) nxt.emplace_back(node->left); 
                if (node->right) nxt.emplace_back(node->right);
            }
            cur = std::move(nxt);
            ans.emplace_back(vals);
        }
        return ans;
    }
};