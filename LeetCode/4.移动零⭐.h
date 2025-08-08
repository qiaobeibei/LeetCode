/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

��ע�� �������ڲ���������������ԭ�ض�������в�����
*/

#pragma once
#include<iostream>
#include<vector>

// ���취
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

// ʱ�临�Ӷ���ͬ�����ռ临�Ӷ�ΪO(1)�ķ���
class Solution {
public:
	void moveZeroes(std::vector<int>& nums) {
		int i = 0;
		for (int& num : nums) {
			if (num) {
				// num �����ã��������ｻ����ʵ���ڽ�������������Ԫ�ص�λ��
				std::swap(num, nums[i++]);
			}
		}
	}
};