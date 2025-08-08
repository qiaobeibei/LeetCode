#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>

// https://leetcode.cn/problems/palindrome-partitioning/?envType=study-plan-v2&envId=top-100-liked

class Solution {
private:
    bool isPalindrome(std::string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        int n = s.length();
        if (n == 0) {
            return { {} };
        }

        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> path;

        std::function<void(int i)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }

            for (int j = i; j < n; j++) {
                if (isPalindrome(s,i,j)) {
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return ans;
    }
};



