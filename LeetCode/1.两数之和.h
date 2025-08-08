/*
给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target 的那两个整数，并返回它们的
数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
*/

#pragma once
#include<vector>
#include<iostream>
#include<unordered_map>

class Solution {
public:
	std::vector<int> twoSum(const std::vector<int>& nums, const int target) {
		std::unordered_map<int, int> res;

		for (int i = 0; i < nums.size(); ++i) {
			auto iter = res.find(target - nums[i]);
			if (iter != res.end())
				return { iter->second, i };
			res[nums[i]] = i;	
			// 插入新元素只能放在最后一行或者第二行，不能放在auto iter 前面
			// 因为放在前面可能会导致这个问题：当 target - nums[i] 恰好等于 nums[i] 时，可能会返回同一个元
			// 素的下标两次，而不是两个不同元素的下标
		}
		return {};
	}
};



