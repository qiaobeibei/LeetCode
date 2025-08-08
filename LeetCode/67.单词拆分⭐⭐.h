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
        int max_len = 0; // �ֵ����ִ�����󳤶�
        if (!wordDict.empty()) {
            auto longest = std::max_element(wordDict.begin(), wordDict.end(),
                [](const std::string& a, const std::string& b) {
                    return a.length() < b.length();
                });
            max_len = longest->length();
        }

        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());

        int n = s.length();
        // �� i = 0 ʱ��s[:0] ��ʾ���ǿ��ַ������ڵ��ʲ�������У����ַ������Ա���Ϊ�ǿ��Բ�ֵ�
        // ����Ϊ����Ҫ�κε������������������ memo[0] ��Ӧ�ľ��ǿ��ַ����Ĳ�������
        // ��˳��ȱ�����n+1������n
        std::vector<int> memo(n + 1, -1); // -1 ��ʾû�м����

        // dfs(i) ��ʾ�ܷ��ǰ׺ s[:i]���� s[0] �� s[i - 1] ����Ӵ������ֳ����ɶΣ�ʹ��ÿ�ζ��� wordDict ��
        std::function<int(int i)> dfs = [&](int i)->int {
            if (i == 0) { // �ݹ鵽�մ����ɹ����
                return true;
            }

            int& res = memo[i];
            if (res != -1) { // ֮ǰ�����
                return res;
            }
            /*
            �� i - 1 ��ʼö�� j������ΪҪ�������п��ܵĲ�ֵ㡣�� j = i - 1 ʱ��s[j:i] ��һ������Ϊ 1 ���Ӵ���
            ���� j �𽥼�С��s[j:i] �ĳ��Ȼ������ӡ�ͨ�����ַ�ʽ�����Ը��� s[:i] �����п��ܲ�ַ�ʽ��

            max_len �� wordDict ������ʵĳ��ȡ�����ζ�����ֵ�������ڳ��ȳ��� max_len �ĵ��ʡ����ԣ�
            �� s[j:i] �ĳ��ȳ��� max_len ʱ�����϶����� wordDict �У�Ҳ��û��Ҫ�ټ�������ˡ���ˣ�j ������
            �� std::max(i - max_len, 0)���������Ա��ⲻ��Ҫ�ļ�飬����㷨��Ч�ʡ�
            */
            for (int j = i - 1; j >= std::max(i - max_len,0); j--) {
                if (words.count(s.substr(j, i - j)) && dfs(j)) {
                    return res = true; // ���仯
                }
            }
            return res = false; // ���仯
        };

        return dfs(n);
    }
};
