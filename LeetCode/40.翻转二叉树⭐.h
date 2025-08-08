/*
����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
*/
//https://leetcode.cn/problems/invert-binary-tree/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<algorithm>

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        return new TreeNode(root->val, right, left);
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            auto left = invertTree(root->left); // ��ת������
            auto right = invertTree(root->right); // ��ת������
            root->left = right; // �������Ҷ���
            root->right = left;
        }
        return root;
    }
};