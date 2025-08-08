// https://leetcode.cn/problems/remove-element/

#include<iostream>
#include<vector>

// 其实就是力扣的“移动零”
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) return 0;

        int i = 0;
        int ans = 0;
        for (int& num : nums) {
            if (num != val) {
                std::swap(num, nums[i++]);
            }
        }

        return i;
    }
};
