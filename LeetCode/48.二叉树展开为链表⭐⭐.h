/*
����������ĸ���� root �����㽫��չ��Ϊһ��������

չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
չ����ĵ�����Ӧ��������� ������� ˳����ͬ��
*/
//https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-100-liked
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

// ͷ�巨������������ - ������ - ����˳�� DFS �����
class Solution {
    TreeNode* head;
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};