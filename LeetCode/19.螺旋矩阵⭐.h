/*
����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ��
*/
// ���������https://leetcode.cn/problems/spiral-matrix-ii/description/
#pragma once
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<unordered_set>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size(); // ����
        int n = matrix.front().size(); // ����
        std::vector<std::pair<int, int>> corr; // ��¼�߹��������
        std::vector<int> res(m * n, 0);
        int x = 0, y = 0;
        int dx = 0, dy = 1;

        for (int i = 0; i < m * n; i++) {
            corr.emplace_back( x,y );
            res[i] = matrix[x][y];
            // ��һ��λ���Ƿ��Ѿ��߹�
            auto it = std::find(corr.begin(), corr.end(), std::pair<int,int>(x + dx, y + dy));
            // ����߽������һ��λ���Ѿ��߹�������
            if (x + dx >= m or x + dx < 0 or y + dy >= n or y + dy < 0 or it != corr.end()) {
                std::tie(dx, dy) = std::make_tuple(dy, -dx);
            }
            x += dx;
            y += dy;
        }

        return res;
    }
};