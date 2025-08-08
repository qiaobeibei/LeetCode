// https://leetcode.cn/problems/minimum-size-subarray-sum/

#pragma once

#include<iostream>
#include<vector>
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int prefixSum = 0;
        int n = nums.size();
        int ans = INT_MAX;

        for (int left = 0, right = 0; right < n; ++right) {
            prefixSum += nums[right];
            while (prefixSum >= target) {
                ans = std::min(ans, right - left + 1);
                prefixSum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};