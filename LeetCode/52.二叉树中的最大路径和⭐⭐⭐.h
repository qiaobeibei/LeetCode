/*
�������е� ·�� ������Ϊһ���ڵ����У�������ÿ�����ڽڵ�֮�䶼����һ���ߡ�
ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ㡣

·���� ��·���и��ڵ�ֵ���ܺ͡�

����һ���������ĸ��ڵ� root �������� ���·���� ��
*/
// https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-100-liked
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

// ����Ŀ�͡���������ֱ��������
// ��ע������ⷵ�ص��ǽ��ֵ����Ҫ����ֵΪ��������������Ϊ�������򷵻�0�൱����������֧·
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        std::function<int(TreeNode* node)> dfs =
            [&](TreeNode* node)->int {
            if (node == nullptr) return 0;

            int right_value = std::max(0, dfs(node->right));
            int left_value = std::max(0, dfs(node->left));

            ans = std::max(ans, left_value + right_value + node->val);
            return std::max(left_value, right_value) + node->val;
        };
        dfs(root);
        return ans;
    }
};