//https://leetcode.cn/problems/rotting-oranges/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>

// 广度优先搜索
/*
问：如果代码不在 while 中判断 fresh>0，会发生什么？
答：会在腐烂完所有新鲜橘子后，多循环一次。这会导致 ans 比实际多 1。
*/
class Solution {
private:
    int DIRECTIONS[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) {
            return -1;
        }
        int m = grid.size(), n = grid.front().size();
        int fresh = 0;
        std::vector<std::pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++fresh; // 新鲜橘子的数量
                }
                else if (grid[i][j] == 2) {
                    q.emplace_back(i, j); // 一开始腐烂的橘子
                }
            }
        }

        int ans = 0;
        while (fresh && !q.empty()) {
            ++ans; // 每个循环是一分钟
            std::vector<std::pair<int, int>> nxt; // 记录被腐烂的橘子
            // 先取出一个烂橘子，并将其上下左右方法都腐烂
            for (std::pair<int, int>& cor : q) {
                for (auto d : DIRECTIONS) {
                    int i = cor.first + d[0], j = cor.second + d[1];
                    if (0 <= i && i < m && 0 <= j && j < n && grid[i][j]==1) { // 如果没越界并且当前坐标是新鲜橘子
                        fresh--;
                        grid[i][j] = 2;
                        nxt.emplace_back(i, j);
                    }
                }
            }
            q = std::move(nxt);
        }

        return fresh ? -1 : ans;
    }
};