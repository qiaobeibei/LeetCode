/*
����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������

��Ч �����������������£�

�ڵ��������ֻ���� С�� ��ǰ�ڵ������
�ڵ��������ֻ���� ���� ��ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
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

// �������֮�����αȽ�
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