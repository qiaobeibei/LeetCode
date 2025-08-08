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
                    path[i] = nums[j]; // ��һ����Ҫע�⣬����path[j] = nums[j]
                    on_path[j] = true;
                    dfs(i + 1);
                    on_path[j] = false;
                    // path ����ָ��ֳ�����Ϊ���г��ȹ̶���ֱ�Ӹ��Ǿ���
                }
            }
        };

        dfs(0);
        return ans;
    }
};