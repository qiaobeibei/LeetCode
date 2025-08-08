/*
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
*/

#pragma once
#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer(nums.size());
        std::vector<int> prefixMul(nums.size() + 1);
        prefixMul[0] = 1;
        std::vector<int> suffixMul(nums.size() + 1);
        suffixMul[nums.size()] = 1;
        for (int i = 1; i < nums.size() + 1; i++) {
            prefixMul[i] = prefixMul[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffixMul[i] = suffixMul[i + 1] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = suffixMul[i + 1] * prefixMul[i];
        }
        return answer;
    }
};