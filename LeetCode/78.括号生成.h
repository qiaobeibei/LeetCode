// https://leetcode.cn/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>

// 这里直接覆盖，因此可以将左括号先填入当前位置，然后用右括号覆盖当前位置
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        int m = n * 2; // 括号长度
        std::vector<std::string> ans;
        std::string path(m, 0);

        // open 是当前path中左括号的个数，i - open < open保证右括号的个数始终小于左括号的个数，i是括号总数
        std::function<void(int i, int open)> dfs = [&](int i, int open)->void {
            if (i == m) {
                ans.emplace_back(path);
                return;
            }
            if (open < n) {
                path[i] = '(';
                dfs(i + 1, open + 1);
            }
            if (i - open < open) { // 括号总和是i，右括号个数是i-open，保证右括号始终小于左括号
                path[i] = ')';
                dfs(i + 1, open);
            }
        };

        dfs(0, 0);
        return ans;
    }
};