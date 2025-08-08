// https://leetcode.cn/problems/combination-sum/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>


// �� dfs(i,left) �����ݣ��赱ǰö�ٵ� candidates[i]��ʣ��Ҫѡ��Ԫ��֮��Ϊ left
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
            // �������������ƻ���ʣ��Ҫѡ��Ԫ��֮��С��0���򲻿��ܳɹ���ֱ�ӷ��ؼ���
            if (i == candidates.size() || left < 0) {
                return;
            }
            // ��ѡ
            dfs(i + 1, left);
            // ѡ
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
            // ��ѡ
            dfs(i + 1, left);
            // ѡ
            path.emplace_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back();
        };

        dfs(0, target);
        return ans;
    }
};
