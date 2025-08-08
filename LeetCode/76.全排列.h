// https://leetcode.cn/problems/permutations/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        std::vector<int> path(n), on_path(n);

        std::function<void(int i)> dfs = [&](int i)->void {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!on_path[j]) {
                    path[i] = nums[j]; // 这一步需要注意，不是path[j] = nums[j]
                    on_path[j] = true;
                    dfs(i + 1);
                    on_path[j] = false;
                    // path 无需恢复现场，因为排列长度固定，直接覆盖就行
                }
            }
        };

        dfs(0);
        return ans;
    }
};