/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。
*/
// https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

// 前缀和 + 哈希表
// 对于数组 nums，定义前缀和 sum[i] 为数组前 i 个元素的和，即 sum[i] = nums[0] + nums[1] + ... + nums[i - 1]
// 那么对于任意两个索引 i 和 j（i < j），子数组 nums[i, j]（包含 nums[i] 和 nums[j]）
// 的和可以表示为 sum[j + 1] - sum[i] = nums[0] + nums[1] + ... + nums[j] - nums[0] + nums[1] + ... + nums[i - 1]
// = nums[i] + nums[1] + ... + nums[j]

/*
什么时候用vector存储前缀和，什么时候用无序map？

若需快速计算特定区间的和或按顺序（数据降序或升序）处理前缀和（如双指针法），应使用vector存储前缀和，
因其支持 O(1) 区间查询并保留顺序；
若需高效查找满足特定条件的前缀和（如差值匹配或统计出现次数），则使用unordered_map，利用哈希表的 O(1) 
平均查找时间优化统计操作。
*/


class Solution {
public:
    int subarraySum(std::vector<int>& nums, const int k) {
        int ans = 0;
        int sum = 0;
        // 用于存储前缀和及其出现的次数
        std::unordered_map<int, int> prefixSumCount;
        // 初始化前缀和为 0 的情况出现 1 次
        // 这一步很重要也很容易忘记，但必须加
        // 假设数组 nums = [1, 2, 3, 4]，k = 3
        // 当[1,2]恰好是3，但是 3 -3 = 0 不存在于前缀和表中，那么这时候会出现错误
        prefixSumCount[0] = 1;

        for (int& num : nums) {
            sum += num;
            // sum 其实就是 sum[j + 1] = sum[0] + ... + sum[j]
            // 至于为什么在前缀和表中存在 sum - k 就能确定存在连续子数组的和==k，通过一个例子解释
            // 假设数组 nums = [1, 2, 3, 4]，k = 5
            // 当 sum[3] = sum[0] + sum[1] + sum[2] = 6时，如果 6 - 5 存在于前缀和表中
            // 说明  sum[3] - prefixSumCount[sum[3] - k] == k，表示 sum[3] - sum[1] = sum[1] + sum[2] = 5
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                ans += prefixSumCount[sum - k];
            }

            prefixSumCount[sum]++;
        }

        return ans;
    }
};



