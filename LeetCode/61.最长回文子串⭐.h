//https://leetcode.cn/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int len = s.size();
        if (len == 0 || len == 1) {
            return s;
        }

        int start = 0; // 回文串起始位置
        int max = 1; //回文串最大长度
        // dp[i][j] 表示从索引 i 到索引 j 的子串是否为回文串
        std::vector<std::vector<int>> dp(len, std::vector<int>(len));

        for (int i = 0; i < len; i++) { // 初始化
            dp[i][i] = 1; // 单个字符肯定是回文串
            if (i + 1 < len && s[i] == s[i + 1]) { // 判断相邻字符是否相同
                dp[i][i + 1] = 1;
                max = 2;
                start = i;
            }
        }
        // l表示检索的子串长度，等于3表示先检索长度为3的子串
        // 长度1和2的字串已经检查过了
        for (int l = 3; l <= len; l++) { 
            // 遍历所有可能的起始位置 i
            for (int i = 0; i + l - 1 < len; i++) {
                int j = l + i - 1; // 终止字符位置
                // 判断子串的首尾字符是否相同，并且去掉首尾字符后的子串是否为回文串
                // 因为是从长度3开始遍历的，而长度1和2已经提前遍历过了
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    start = i;
                    max = l;
                }
            }
        }

        return s.substr(start, max);
    }
};