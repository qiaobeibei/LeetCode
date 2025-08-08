/*
����һ����������nums��һ������Ŀ��ֵtarget�������ڸ��������ҳ���ΪĿ��ֵtarget �����������������������ǵ�
�����±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸣������㲻��ʹ��������ͬ��Ԫ�ء�

����԰�����˳�򷵻ش𰸡�
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
			// ������Ԫ��ֻ�ܷ������һ�л��ߵڶ��У����ܷ���auto iter ǰ��
			// ��Ϊ����ǰ����ܻᵼ��������⣺�� target - nums[i] ǡ�õ��� nums[i] ʱ�����ܻ᷵��ͬһ��Ԫ
			// �ص��±����Σ�������������ͬԪ�ص��±�
		}
		return {};
	}
};



