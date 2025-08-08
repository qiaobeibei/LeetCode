/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵平衡二叉搜索树（BST）。
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
以 nums = [1,2,3] 为例：
初始调用：dfs(0, 3)
  m = 1 → 根节点为2
  左子树：dfs(0, 1) → m=0 → 根节点为1（左/右子树均为nullptr）
  右子树：dfs(2, 3) → m=2 → 根节点为3（左/右子树均为nullptr）
最终树结构：
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
        // 注意，是左闭右开区间，这样能保证分割的区间会将中间点去掉
        std::function<TreeNode* (std::vector<int>& nums, int left, int right)> dfs =
            [&](std::vector<int>& nums, int left, int right)->TreeNode* {
            // 终止条件：区间无元素（左闭右开区间）
            if (left == right) return nullptr; // 当 left == right 时，说明传进来的数组为空，直接返回nullptr即可

            int m = left + (right - left) / 2;
            return new TreeNode(
                nums[m], 
                dfs(nums, left, m),  // 左闭右开，其实只包括了 num[left]...nums[m-1]
                dfs(nums, m + 1, right)); // 左闭右开，其实只包括了 num[m + 1]...nums[right-1]
        };

        return dfs(nums, 0, nums.size()); // 左闭右开，传入的元素其实只包括 num[0]...nums[nums.size()-1]
    }
};