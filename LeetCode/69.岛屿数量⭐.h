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
        // �����ӣ���½�ز�������
        std::function<void(int i,int j)> dfs = [&](int i,int j ) {
            // ���磬���߲��� '1'���Ͳ������µݹ�
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
                return;
            }
            grid[i][j] = '2';// ���죡�������غ������޵ݹ�
            dfs(i, j - 1); // ������
            dfs(i, j + 1); // ������
            dfs(i - 1, j); // ������
            dfs(i + 1, j); // ������
        };

        int ans = 0;
        // ���һ�δ�������ӵ�½��
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') { // �ҵ���һ���µĵ�
                    ans++;
                    dfs(i, j);
                }
            }
        }

        return ans;
    }
};
