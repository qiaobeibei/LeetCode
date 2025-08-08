// https://leetcode.cn/problems/word-search/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

class Solution {
private:
    static constexpr int DIRS[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        std::unordered_map<char, int> cnt;
        for (auto& row : board) {
            for (char c : row) {
                cnt[c]++;
            }
        }

        // �Ż�һ
        std::unordered_map<char, int> word_cnt;
        for (char c : word) {
            if (++word_cnt[c] > cnt[c]) { // ���word��ĳ����ĸ�ĸ�������board����ô�϶�������
                return false;
            }
        }

        // �Ż���
        if (cnt[word.back()] < cnt[word[0]]) {
            std::reverse(word.begin(), word.end());
        }

        int m = board.size(), n = board.front().size();
        std::function<bool(int i, int j, int k)> dfs = [&](int i, int j, int k) ->bool {
            if (board[i][j] != word[k]) {
                return false;
            }
            // ��ƥ��word�����һ���ַ���ƥ��ɹ�ʱ����һ��ifû�ɹ�����ƥ��ɹ���
            if (k == word.length() - 1) {
                return true;
            }
            board[i][j] = 0; // ��Ƿ��ʹ�
            for (auto& cor : DIRS) {
                int x = i + cor[0], y = j + cor[1];
                if (0 <= x && x < m && 0 <= y && y < n && dfs(x, y, k + 1)) { // û�����߽磬���Һ�������ĸ���ɹ�ƥ��
                    return true;
                }
            }
            board[i][j] = word[k]; 
            return false;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
