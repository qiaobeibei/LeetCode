/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>

// 注意：遍历的是st而不是nums，后者会超时

// 排序的时间复杂度是 O(nlogn)，不能使用排序
class Solution {
public:
	int longestConsecutive(const std::vector<int>& nums) {
		if (nums.empty()) return 0;

		int ans = 0;

		// 无序集合的查找操作时间复杂度为 O(1)，方便快速查找元素
		std::unordered_set<int> st(nums.begin(), nums.end());
		for (const int& num : st) {
			// 检查当前元素num的前一个元素num - 1是否存在于集合中，如果存在，说明 num 
			// 不是连续序列的起始元素，跳过当前元素。我们是为了找起始元素（为了不排序）
			if (st.find(num - 1) != st.end()) {
				continue;
			}

			// 找到起始元素后，开始查找以该元素为起点的序列最长为多少
			int start = num + 1;
			while (st.find(start) != st.end()) {
				start++;
			}

			ans = ans > (start - num) ? ans : start - num;
		}
		return ans;
	}
};


