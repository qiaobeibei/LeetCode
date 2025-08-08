// https://leetcode.cn/problems/combination-sum-iii/description/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>


class Solution {
public:
    auto combinationSum3(int k, int n) ->std::vector<std::vector<int>> {
        std::vector<std::vector<int>> ans;
        std::vector<int> path;

        // i 是当前准备要加的数字，left需要加的数字和
        std::function<void(int i, int left)> dfs = [&](int i, int left) {
            if (left == 0 && path.size() == k) {
                ans.emplace_back(path);
                return;
            }
            // 当数字大于9，剩余数字和小于0，path的元素个数大于等于k，这三种任一情况发生都不可能成功
            if (i > 9 || left < 0 || path.size() >= k) {
                return;
            }
            // 不选 i
            dfs(i + 1, left);
            // 选 i
            path.emplace_back(i);
            dfs(i + 1, left - i);
            path.pop_back();
        };

        dfs(1, n);
        return ans;
    }
};