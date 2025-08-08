/*
���������������� preorder �� inorder ������ preorder �Ƕ���������������� 
inorder ��ͬһ����������������빹�����������������ڵ㡣
*/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<unordered_map>
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-100-liked
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*
ǰ����������ա���-������-����������˳�������������
������������ա�������-��-����������˳�������������
������������ա�������-������-������˳�������������

ǰ������ĵ�һ��Ԫ���Ǹ������������Ԫ�ص�������������������ұ�������������
����������ǰ������ĵ�һ��Ԫ�����������ĸ�
����������ǰ������ĵ�һ��Ԫ�����������ĸ�

������
    3
   / \
  9  20
    /  \
   15   7
ǰ���������� [3, 9, 20, 15, 7]�������������� [9, 3, 15, 20, 7]��



*/
class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        
        int n = preorder.size();
        std::unordered_map<int, int> index; // �洢���������ÿ��Ԫ�ض�Ӧ������
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
             
        std::function<TreeNode* (int pre_l, int pre_r, int in_l, int in_r)> dfs =
            [&](int pre_l, int pre_r, int in_l, int in_r)->TreeNode* {
            // ���ǰ���������߽�����ұ߽磬˵��������û�нڵ㣬���ؿ�ָ��
            if (pre_l == pre_r) return nullptr;
            // ǰ������ĵ�һ��Ԫ�ؾ��ǵ�ǰ�����ĸ��ڵ�
            // �����������Ĵ�С�������ڵ�����������е�λ�ü�ȥ�����������߽�
            int left_size = index[preorder[pre_l]] - in_l; 
            // �ݹ鹹��������
            // ǰ��������������ķ�Χ�� [pre_l + 1, pre_l + 1 + left_size)
            // ����������������ķ�Χ�� [in_l, in_l + left_size)
            // ��Ϊǰ������и�����ڵ�һλ�����������������ȶ���߽�+1������һλԪ��
            // ������������������ӱ߽翪ʼ����������������߽粻��+1������������������ұ߽�+1������Ԫ��
            TreeNode* left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            // �ݹ鹹��������
            // ǰ��������������ķ�Χ�� [pre_l + 1 + left_size, pre_r)
            // ����������������ķ�Χ�� [in_l + 1 + left_size, in_r)
            // ǰ����������������������ţ���������������߽�������������б߽�
            // ���������������Ǹ������Ա����Ƚ��߽�+1������Ԫ��
            TreeNode* right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
            return new TreeNode(preorder[pre_l], left, right);
        };
        // ǰ������ķ�Χ��[0, n)����������ķ�Χ��[0, n)
        return dfs(0, n, 0, n); // ���ұ�����
    }
};