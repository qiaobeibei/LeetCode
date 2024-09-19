/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。
*/

#include <iostream>
#include <vector>
#include <unordered_map>


// 双指针
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) return {};
        int len = 0;
        std::vector<std::vector<int>> vec;

        for (int i = 0, j = 1, k = nums.size() - 1;;) {    
            if (nums[i] + nums[j] + nums[k] == 0)
                vec[len++] = { nums[i], nums[j++], nums[k] };
                
            if (j >= k and i < k - 1) {
                i++;
                j = i + 1;
            }
            else if (i >= k - 1)
                break;
        }

        return vec;
        
    }
};