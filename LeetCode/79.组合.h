// https://leetcode.cn/problems/combinations/description/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>

// 从一个集合中随便选择数字进行组合，并不是找子集
class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        std::vector<int> path;
        std::function<void(int i)> dfs = [&](int i)->void {
            int d = k - path.size(); // 还要选 d 个数
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            /*
            假设当前需要从[1,i]中选数
            如果i < d，最后必然无法选出 k 个数，因为数字个数总和不可能等于 k
            不需要继续递归
            */
            if (i > d) { // 如果 i > d，可以不选 i，其余情况不能不选，因为当i<=d时说明剩下的数字刚好够或者不够，必须要选择
                dfs(i - 1);
            }

            // 选 i
            path.emplace_back(i);
            dfs(i - 1);
            path.pop_back();
        };

        dfs(n);
        return ans;
    }
};
