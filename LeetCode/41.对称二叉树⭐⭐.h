/*
����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
*/
//https://leetcode.cn/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            // ��� p �� q ��һ��Ϊ�գ���ô�������߶�Ϊ��ʱ�ŷ��� true
            return p == q; 
        }
        // ��� p �� q ����Ϊ��
        // ���ж� p �� q ��ֵ�Ƿ���ͬ��Ȼ���ж�p����������q���������Ƿ���ͬ��p����������q���������Ƿ���ͬ
        // ������������ͬʱ��ʱ���������Գ�
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->right, root->left);
    }
};
