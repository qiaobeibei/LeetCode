/*
����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ��ƽ�������������BST����
*/
//https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-100-liked
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

/*
�� nums = [1,2,3] Ϊ����
��ʼ���ã�dfs(0, 3)
  m = 1 �� ���ڵ�Ϊ2
  ��������dfs(0, 1) �� m=0 �� ���ڵ�Ϊ1����/��������Ϊnullptr��
  ��������dfs(2, 3) �� m=2 �� ���ڵ�Ϊ3����/��������Ϊnullptr��
�������ṹ��
    2
   / \
  1   3
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        std::function<TreeNode* (int left, int right)> sortVec =
            [&](int left, int right)->TreeNode* {
            if (left == right) {
                return nullptr;
            }
            int mid = left + (right - left) / 2;
            TreeNode* left_tree = sortVec(left, mid);
            TreeNode* right_tree = sortVec(mid + 1, right);
            return new TreeNode(nums[mid], left_tree, right_tree);
        };

        return sortVec(0, nums.size());
    }
};


class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        // ע�⣬������ҿ����䣬�����ܱ�֤�ָ������Ὣ�м��ȥ��
        std::function<TreeNode* (std::vector<int>& nums, int left, int right)> dfs =
            [&](std::vector<int>& nums, int left, int right)->TreeNode* {
            // ��ֹ������������Ԫ�أ�����ҿ����䣩
            if (left == right) return nullptr; // �� left == right ʱ��˵��������������Ϊ�գ�ֱ�ӷ���nullptr����

            int m = left + (right - left) / 2;
            return new TreeNode(
                nums[m], 
                dfs(nums, left, m),  // ����ҿ�����ʵֻ������ num[left]...nums[m-1]
                dfs(nums, m + 1, right)); // ����ҿ�����ʵֻ������ num[m + 1]...nums[right-1]
        };

        return dfs(nums, 0, nums.size()); // ����ҿ��������Ԫ����ʵֻ���� num[0]...nums[nums.size()-1]
    }
};