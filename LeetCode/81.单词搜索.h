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

        // 优化一
        std::unordered_map<char, int> word_cnt;
        for (char c : word) {
            if (++word_cnt[c] > cnt[c]) { // 如果word中某个字母的个数大于board，那么肯定不满足
                return false;
            }
        }

        // 优化二
        if (cnt[word.back()] < cnt[word[0]]) {
            std::reverse(word.begin(), word.end());
        }

        int m = board.size(), n = board.front().size();
        std::function<bool(int i, int j, int k)> dfs = [&](int i, int j, int k) ->bool {
            if (board[i][j] != word[k]) {
                return false;
            }
            // 当匹配word的最后一个字符且匹配成功时（第一个if没成功代表匹配成功）
            if (k == word.length() - 1) {
                return true;
            }
            board[i][j] = 0; // 标记访问过
            for (auto& cor : DIRS) {
                int x = i + cor[0], y = j + cor[1];
                if (0 <= x && x < m && 0 <= y && y < n && dfs(x, y, k + 1)) { // 没超过边界，并且后续的字母都成功匹配
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
