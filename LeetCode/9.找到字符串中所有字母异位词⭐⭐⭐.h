/*
���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��
*/

#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

// ��������
class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        if (s.length() < p.length()) return {};

        std::unordered_map<char, int> window_s;
        std::unordered_map<char, int> window_p;
        std::vector<int> ans;

        for (const char& c : p)
            window_p[c]++;

        for (int left = 0, right = 0; right < s.length(); right++) {
            window_s[s[right]]++;

            if (right - left + 1 == p.length()) {
                if (window_s == window_p) {
                    ans.emplace_back(left);
                }
                // �ƶ�������߽磬��С���ڣ���С��ʱ��ע����ж��Ƿ�Ϊ0��
                window_s[s[left]]--;
                if (window_s[s[left]] == 0) {
                    window_s.erase(s[left]);
                }
 
                left++;
            }
        }

        return ans;
    }
};

