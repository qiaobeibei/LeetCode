#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>

// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-100-liked

// 因为每次递归到 i，一定会修改 path【i】，那么递归到终点时，每个 path【i】 都被覆盖成要枚举的字母，
// 所以不需要恢复现场。
class Solution {
private:
    std::string keyBoard[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    std::vector<std::string> letterCombinations(std::string digits) {  
        int n = digits.length();
        if (n == 0) {
            return {};
        }

        std::vector<std::string> ans;
        std::string path(n, 0); // 注意 path 长度一开始就是 n，不是空串

        // dfs(i) 处理的是从下标 i 到末尾的所有字母组合
        std::function<void(int i)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (char c : keyBoard[digits[i] - '0']) {
                path[i] = c; // 覆盖
                dfs(i + 1);
            }
        };

        dfs(0);
        return ans;
    }
};