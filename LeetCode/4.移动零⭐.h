/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

#pragma once
#include<iostream>
#include<vector>

// 笨办法
class Solution {
public:
	void moveZeroes(std::vector<int>& nums) {
		if (nums.empty() or nums.size() == 1) return;

		std::vector<int> res;
		res.resize(nums.size());

		int left = 0;
		int right = nums.size() - 1;

		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != 0) {
				res[left++] = nums[i];
			}
			else {
				res[right--] = nums[i];
			}
		nums = res;
	}
};

// 时间复杂度相同，但空间复杂度为O(1)的方法
class Solution {
public:
	void moveZeroes(std::vector<int>& nums) {
		int i = 0;
		for (int& num : nums) {
			if (num) {
				// num 是引用，所以这里交换其实是在交换数组中两个元素的位置
				std::swap(num, nums[i++]);
			}
		}
	}
};