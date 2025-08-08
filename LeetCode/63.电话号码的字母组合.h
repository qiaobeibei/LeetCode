#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>

// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-100-liked

// ��Ϊÿ�εݹ鵽 i��һ�����޸� path��i������ô�ݹ鵽�յ�ʱ��ÿ�� path��i�� �������ǳ�Ҫö�ٵ���ĸ��
// ���Բ���Ҫ�ָ��ֳ���
class Solution {
private:
    std::string keyBoard[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    std::vector<std::string> letterCombinations(std::string digits) {  
        int n = digits.length();
        if (n == 0) {
            return {};
        }

        std::vector<std::string> ans;
        std::string path(n, 0); // ע�� path ����һ��ʼ���� n�����ǿմ�

        // dfs(i) ������Ǵ��±� i ��ĩβ��������ĸ���
        std::function<void(int i)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (char c : keyBoard[digits[i] - '0']) {
                path[i] = c; // ����
                dfs(i + 1);
            }
        };

        dfs(0);
        return ans;
    }
};