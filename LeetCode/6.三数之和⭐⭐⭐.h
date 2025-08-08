/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

/*
注意点：
去重 a（记得要加i>0）
去重 b 和 c 时，记得加 left < right
*/


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) return {};

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return ans; // 每个三元组第一个数必须小于0，不然构不成三数之和==0
            if (i > 0 and nums[i - 1] == nums[i]) continue; // 去重 a（记的要加i>0）

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[right] + nums[left] > 0) right--;
                else if (nums[i] + nums[right] + nums[left] < 0) left++;
                else {
                    // ans.emplace_back({ nums[i], nums[right], nums[left] });是错的
                    // ans.push_back({ nums[i], nums[right], nums[left] });是对是
                    // 要想使用 emplace_back 只能像下面这样使用
                    ans.emplace_back(std::initializer_list<int>{ nums[i], nums[right], nums[left] });
                    // 循环时记得加left < right 
                    while (left < right and nums[left] == nums[left + 1]) left++; // 去重 b
                    while (left < right and nums[right] == nums[right - 1]) right--; // 去重 c

                    left++;
                    right--;
                }
            }
        }

        return ans;
    }
};


