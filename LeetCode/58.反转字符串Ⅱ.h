#pragma once
#include<iostream>
#include<algorithm>
#include<string>

// https://leetcode.cn/problems/reverse-string-ii/description/

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k <= s.size()) {
                std::reverse(s.begin() + i, s.begin() + i + k);
            }
            else {
                std::reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};