/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序
*/

#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

// 滑动窗口
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        if (s.length() < p.length()) return {};

        std::unordered_map<char, int> window_s;
        std::unordered_map<char, int> window_p;
        std::vector<int> ans;

        for (const char& c : p)
            window_p[c]++;

        for (int left = 0, right = 0; right < s.length(); right++) {
            window_s[s[right]]++;

            if (right - left + 1 == p.length()) {
                if (window_s == window_p) {
                    ans.emplace_back(left);
                }
                // 移动窗口左边界，缩小窗口（缩小的时候注意得判断是否为0）
                window_s[s[left]]--;
                if (window_s[s[left]] == 0) {
                    window_s.erase(s[left]);
                }
 
                left++;
            }
        }

        return ans;
    }
};

