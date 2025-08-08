/*
����һ�ö������ĸ��ڵ㣬���ظ����� ֱ�� ��

�������� ֱ�� ��ָ�������������ڵ�֮���·���� ���� ������·�����ܾ���Ҳ���ܲ��������ڵ� root ��

���ڵ�֮��·���� ���� ������֮�������ʾ��
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
            ans = std::max(ans,left_len + right_len); // ����ǰ����Լ����������������ϲ�
            return std::max(right_len, left_len); // ����������������������
        };
        dfs(root);
        return ans;
    }
};