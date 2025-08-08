// https://leetcode.cn/problems/word-break/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int max_len = 0; // 字典中字串的最大长度
        if (!wordDict.empty()) {
            auto longest = std::max_element(wordDict.begin(), wordDict.end(),
                [](const std::string& a, const std::string& b) {
                    return a.length() < b.length();
                });
            max_len = longest->length();
        }

        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());

        int n = s.length();
        // 当 i = 0 时，s[:0] 表示的是空字符串。在单词拆分问题中，空字符串可以被认为是可以拆分的
        // （因为不需要任何单词来组成它），所以 memo[0] 对应的就是空字符串的拆分情况。
        // 因此长度必须是n+1而不是n
        std::vector<int> memo(n + 1, -1); // -1 表示没有计算过

        // dfs(i) 表示能否把前缀 s[:i]（即 s[0] 到 s[i - 1] 这段子串）划分成若干段，使得每段都在 wordDict 中
        std::function<int(int i)> dfs = [&](int i)->int {
            if (i == 0) { // 递归到空串，成功拆分
                return true;
            }

            int& res = memo[i];
            if (res != -1) { // 之前计算过
                return res;
            }
            /*
            从 i - 1 开始枚举 j，是因为要尝试所有可能的拆分点。当 j = i - 1 时，s[j:i] 是一个长度为 1 的子串；
            随着 j 逐渐减小，s[j:i] 的长度会逐渐增加。通过这种方式，可以覆盖 s[:i] 的所有可能拆分方式。

            max_len 是 wordDict 中最长单词的长度。这意味着在字典里，不存在长度超过 max_len 的单词。所以，
            当 s[j:i] 的长度超过 max_len 时，它肯定不在 wordDict 中，也就没必要再继续检查了。因此，j 的下限
            是 std::max(i - max_len, 0)，这样可以避免不必要的检查，提高算法的效率。
            */
            for (int j = i - 1; j >= std::max(i - max_len,0); j--) {
                if (words.count(s.substr(j, i - j)) && dfs(j)) {
                    return res = true; // 记忆化
                }
            }
            return res = false; // 记忆化
        };

        return dfs(n);
    }
};
