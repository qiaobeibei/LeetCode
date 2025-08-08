/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/

#pragma once
#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        // 检查矩阵是否为空或第一行是否为空
        if (matrix.empty() || matrix.front().empty()) return;

        int m = matrix.size();
        int n = matrix.front().size();
        // 记录包含 0 的行和列
        std::unordered_set<int> row;
        std::unordered_set<int> col;
        // 遍历矩阵，找出所有值为 0 的元素所在的行和列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.emplace(i);
                    col.emplace(j);
                }
            }
        }
        // 再次遍历矩阵，将包含 0 的行和列的元素都置为 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row.find(i) != row.end() || col.find(j) != col.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
