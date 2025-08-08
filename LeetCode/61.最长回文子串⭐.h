//https://leetcode.cn/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int len = s.size();
        if (len == 0 || len == 1) {
            return s;
        }

        int start = 0; // ���Ĵ���ʼλ��
        int max = 1; //���Ĵ���󳤶�
        // dp[i][j] ��ʾ������ i ������ j ���Ӵ��Ƿ�Ϊ���Ĵ�
        std::vector<std::vector<int>> dp(len, std::vector<int>(len));

        for (int i = 0; i < len; i++) { // ��ʼ��
            dp[i][i] = 1; // �����ַ��϶��ǻ��Ĵ�
            if (i + 1 < len && s[i] == s[i + 1]) { // �ж������ַ��Ƿ���ͬ
                dp[i][i + 1] = 1;
                max = 2;
                start = i;
            }
        }
        // l��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
        // ����1��2���ִ��Ѿ�������
        for (int l = 3; l <= len; l++) { 
            // �������п��ܵ���ʼλ�� i
            for (int i = 0; i + l - 1 < len; i++) {
                int j = l + i - 1; // ��ֹ�ַ�λ��
                // �ж��Ӵ�����β�ַ��Ƿ���ͬ������ȥ����β�ַ�����Ӵ��Ƿ�Ϊ���Ĵ�
                // ��Ϊ�Ǵӳ���3��ʼ�����ģ�������1��2�Ѿ���ǰ��������
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    start = i;
                    max = l;
                }
            }
        }

        return s.substr(start, max);
    }
};