// https://leetcode.cn/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>

// ����ֱ�Ӹ��ǣ���˿��Խ������������뵱ǰλ�ã�Ȼ���������Ÿ��ǵ�ǰλ��
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        int m = n * 2; // ���ų���
        std::vector<std::string> ans;
        std::string path(m, 0);

        // open �ǵ�ǰpath�������ŵĸ�����i - open < open��֤�����ŵĸ���ʼ��С�������ŵĸ�����i����������
        std::function<void(int i, int open)> dfs = [&](int i, int open)->void {
            if (i == m) {
                ans.emplace_back(path);
                return;
            }
            if (open < n) {
                path[i] = '(';
                dfs(i + 1, open + 1);
            }
            if (i - open < open) { // �����ܺ���i�������Ÿ�����i-open����֤������ʼ��С��������
                path[i] = ')';
                dfs(i + 1, open);
            }
        };

        dfs(0, 0);
        return ans;
    }
};