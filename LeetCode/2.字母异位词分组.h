/*
����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�

��ĸ��λ��:������������Դ���ʵ�������ĸ�õ���һ���µ��ʡ�
*/

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
		if (strs.empty() or strs.size() == 1)
			return { {strs.front()} };

		std::unordered_map<std::string, std::vector<std::string>> res;

		for (const auto& str : strs) {
			std::string sorted_str = str;
			std::sort(sorted_str.begin(), sorted_str.end());
			if (res.find(sorted_str) != res.end()) {
				res[sorted_str].emplace_back(str);
			}
			else {
				res[sorted_str] = { str };
			}
		}

		std::vector<std::vector<std::string>> vec_res;
		for (const auto& pair : res) {
			vec_res.emplace_back(pair.second);
		}

		return vec_res;
	}
};


