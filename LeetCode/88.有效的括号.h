// https://leetcode.cn/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>
#include <stack>

class Solution {
private:
    std::unordered_map<char, char> mp = { {')', '('}, {']', '['}, {'}', '{'} };
public:
    bool isValid(std::string s) {
        if (s.length() % 2) {
            return false;
        }
        std::stack<char> st;
        // �ж� c �ǲ��� mp ��һ�� key
        for (char c : s) {
            if (!mp.count(c)) { // c ��������
                st.push(c);
            }
            else { // c ��������
                if (st.empty() || st.top() != mp[c]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};