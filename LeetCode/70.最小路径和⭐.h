//https://leetcode.cn/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));

        /*
        定义 dfs(i,j) 表示从左上角到第 i 行第 j 列这个格子（记作 (i,j)）的最小价值和.
            如果是从左边过来，则 dfs(i,j)=dfs(i,j−1)+grid[i][j]；
            如果是从上边过来，则 dfs(i,j)=dfs(i−1,j)+grid[i][j]。
            二者取最小值，得 dfs(i,j)=min(dfs(i,j−1),dfs(i−1,j))+grid[i][j]
        */
        std::function<int(int i, int j)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0) { // 出界
                return INT_MAX;
            }
            if (i == 0 && j == 0) { // dfs(0,0)=grid[0][0]
                return grid[i][j];
            }
            int& res = memo[i][j];
            if (res != -1) { // 之前计算过
                return res;
            }

            return res = std::min(dfs(i, j - 1), dfs(i - 1, j)) + grid[i][j];
        };

        return dfs(m - 1, n - 1);
    }
};
