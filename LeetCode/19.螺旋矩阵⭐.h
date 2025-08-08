/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素
*/
// 螺旋矩阵Ⅱ：https://leetcode.cn/problems/spiral-matrix-ii/description/
#pragma once
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<unordered_set>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(); // 行数
        int n = matrix.front().size(); // 列数
        std::vector<std::pair<int, int>> corr; // 记录走过的坐标点
        std::vector<int> res(m * n, 0);
        int x = 0, y = 0;
        int dx = 0, dy = 1;

        for (int i = 0; i < m * n; i++) {
            corr.emplace_back( x,y );
            res[i] = matrix[x][y];
            // 下一个位置是否已经走过
            auto it = std::find(corr.begin(), corr.end(), std::pair<int,int>(x + dx, y + dy));
            // 到达边界或者下一个位置已经走过，则换向
            if (x + dx >= m or x + dx < 0 or y + dy >= n or y + dy < 0 or it != corr.end()) {
                std::tie(dx, dy) = std::make_tuple(dy, -dx);
            }
            x += dx;
            y += dy;
        }

        return res;
    }
};