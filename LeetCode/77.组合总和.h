// https://leetcode.cn/problems/combination-sum/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>


// 用 dfs(i,left) 来回溯，设当前枚举到 candidates[i]，剩余要选的元素之和为 left
class Solution {
public:
    auto combinationSum(std::vector<int>& candidates, int target)->std::vector<std::vector<int>> {
        std::vector<std::vector<int>> ans;
        std::vector<int> path;

        std::function<void(int, int)> dfs = [&](int i, int left)->void {
            if (left == 0) {
                ans.emplace_back(path);
                return;
            }
            // 当索引超过限制或者剩余要选的元素之和小于0，则不可能成功，直接返回即可
            if (i == candidates.size() || left < 0) {
                return;
            }
            // 不选
            dfs(i + 1, left);
            // 选
            path.emplace_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back();
        };

        dfs(0, target);
        return ans;
    }
};

class Solution {
public:
    auto combinationSum(std::vector<int>& candidates, int target)->std::vector<std::vector<int>> {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> path;

        std::function<void(int, int)> dfs = [&](int i, int left)->void {
            if (left == 0) {
                ans.emplace_back(path);
                return;
            }
            if (i == candidates.size() || left < candidates[i]) {
                return;
            }
            // 不选
            dfs(i + 1, left);
            // 选
            path.emplace_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back();
        };

        dfs(0, target);
        return ans;
    }
};
