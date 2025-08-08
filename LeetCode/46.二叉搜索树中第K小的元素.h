/*
����һ�������������ĸ��ڵ� root ����һ������ k ���������һ���㷨�������е� k С��Ԫ�أ��� 1 ��ʼ��������
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