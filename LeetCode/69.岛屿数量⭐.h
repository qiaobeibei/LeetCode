//https://leetcode.cn/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int m = grid.size(), n = grid.front().size();
        // 插旗子，将陆地插满棋子
        std::function<void(int i,int j)> dfs = [&](int i,int j ) {
            // 出界，或者不是 '1'，就不再往下递归
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
                return;
            }
            grid[i][j] = '2';// 插旗！避免来回横跳无限递归
            dfs(i, j - 1); // 往左走
            dfs(i, j + 1); // 往右走
            dfs(i - 1, j); // 往上走
            dfs(i + 1, j); // 往下走
        };

        int ans = 0;
        // 查找还未被插旗子的陆地
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') { // 找到了一个新的岛
                    ans++;
                    dfs(i, j);
                }
            }
        }

        return ans;
    }
};
