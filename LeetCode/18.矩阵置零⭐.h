/*
����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��
*/

#pragma once
#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        // �������Ƿ�Ϊ�ջ��һ���Ƿ�Ϊ��
        if (matrix.empty() || matrix.front().empty()) return;

        int m = matrix.size();
        int n = matrix.front().size();
        // ��¼���� 0 ���к���
        std::unordered_set<int> row;
        std::unordered_set<int> col;
        // ���������ҳ�����ֵΪ 0 ��Ԫ�����ڵ��к���
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.emplace(i);
                    col.emplace(j);
                }
            }
        }
        // �ٴα������󣬽����� 0 ���к��е�Ԫ�ض���Ϊ 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row.find(i) != row.end() || col.find(j) != col.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
