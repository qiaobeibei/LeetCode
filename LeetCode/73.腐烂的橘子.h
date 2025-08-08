//https://leetcode.cn/problems/rotting-oranges/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>

// �����������
/*
�ʣ�������벻�� while ���ж� fresh>0���ᷢ��ʲô��
�𣺻��ڸ����������������Ӻ󣬶�ѭ��һ�Ρ���ᵼ�� ans ��ʵ�ʶ� 1��
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
                    ++fresh; // �������ӵ�����
                }
                else if (grid[i][j] == 2) {
                    q.emplace_back(i, j); // һ��ʼ���õ�����
                }
            }
        }

        int ans = 0;
        while (fresh && !q.empty()) {
            ++ans; // ÿ��ѭ����һ����
            std::vector<std::pair<int, int>> nxt; // ��¼�����õ�����
            // ��ȡ��һ�������ӣ��������������ҷ���������
            for (std::pair<int, int>& cor : q) {
                for (auto d : DIRECTIONS) {
                    int i = cor.first + d[0], j = cor.second + d[1];
                    if (0 <= i && i < m && 0 <= j && j < n && grid[i][j]==1) { // ���ûԽ�粢�ҵ�ǰ��������������
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