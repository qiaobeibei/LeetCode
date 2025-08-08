#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
//https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
	int maxArea(const std::vector<int>& height) {
		int ans = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right) {
			ans = std::max(ans, (right - left) * std::min(height[left], height[right]));
			if (height[left] < height[right])
				left++;
			else
				right--;
		}

		return ans;
	}
};
