/*
给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target 的那两个整数，并返回它们的
数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// 当返回类型是vector时，可以用{}简化返回，return {}等效于std::vector<int>()
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) // map中存在匹配值
                return { iter->second, i };
            map[nums[i]] = i;
        }
        return {};
    }
};