/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

// 先将矩阵按对角线反转，然后每一行元素再次反转
class Solution {
private:
    // 其实联想一下 3*3 矩阵即可，第一个需要反转的元素是（0，1）和（1，0），所以i从0开始，j从i+1开始
    void matrixTranspose(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        matrixTranspose(matrix);
        for (auto& vec : matrix) {
            std::reverse(vec.begin(), vec.end());
        }
    }
};