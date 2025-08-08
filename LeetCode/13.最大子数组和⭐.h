/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组是数组中的一个连续部分。
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>


// 前缀和
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() <= 1) return nums.front();

        // 要使用前缀和，minfixSum、prefixSum必须设为0，不能影响加法；而ans要设为最大或最小值（根据题意决定）
        int ans = INT_MIN; 
        int minfixSum = 0;
        int prefixSum = 0;

        for (int& num : nums) {
            prefixSum += num;
            // 对于当前位置，要找到最大的子数组和，等价于找到两个前缀和prefixSum[i]和prefixSum[j]，
            // 使得 prefixSum[j] - prefixSum[i] 最大。
            // 并且最小前缀和必须是索引从0开始的。（重点）
            ans = std::max(ans, prefixSum - minfixSum);
            minfixSum = std::min(minfixSum, prefixSum); // 最小前缀和
        }

        return ans;
    }
};

// 动态规划
// 定义 f[i] 表示以 nums[i] 结尾的最大子数组和。
// 简单地说，如果 nums[i] 左边的子数组元素和是负的，就不用和左边的子数组拼在一起了。
// [−2,1,−3,4,−1,2,1,−5,4],比如这个例子中，为了找出最大值，[-2,1,-3,4,-1]因为<=0，所以肯定不会将其加入，
// 最大字串和必定是在[-2,1,-3,4,-1]后面开始的。所以我们只需要 将其替换为0与后面的串相加即可
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> f(nums.size());
        f[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            f[i] = std::max(f[i - 1], 0) + nums[i];
        }

        auto max_value = std::max_element(f.begin(), f.end());
        return *max_value;
    }
};