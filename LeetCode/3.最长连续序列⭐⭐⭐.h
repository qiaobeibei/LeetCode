/*
����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�

������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
*/
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>

// ע�⣺��������st������nums�����߻ᳬʱ

// �����ʱ�临�Ӷ��� O(nlogn)������ʹ������
class Solution {
public:
	int longestConsecutive(const std::vector<int>& nums) {
		if (nums.empty()) return 0;

		int ans = 0;

		// ���򼯺ϵĲ��Ҳ���ʱ�临�Ӷ�Ϊ O(1)��������ٲ���Ԫ��
		std::unordered_set<int> st(nums.begin(), nums.end());
		for (const int& num : st) {
			// ��鵱ǰԪ��num��ǰһ��Ԫ��num - 1�Ƿ�����ڼ����У�������ڣ�˵�� num 
			// �����������е���ʼԪ�أ�������ǰԪ�ء�������Ϊ������ʼԪ�أ�Ϊ�˲�����
			if (st.find(num - 1) != st.end()) {
				continue;
			}

			// �ҵ���ʼԪ�غ󣬿�ʼ�����Ը�Ԫ��Ϊ���������Ϊ����
			int start = num + 1;
			while (st.find(start) != st.end()) {
				start++;
			}

			ans = ans > (start - num) ? ans : start - num;
		}
		return ans;
	}
};


