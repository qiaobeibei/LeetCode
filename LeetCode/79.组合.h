// https://leetcode.cn/problems/combinations/description/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>

// ��һ�����������ѡ�����ֽ�����ϣ����������Ӽ�
class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        std::vector<int> path;
        std::function<void(int i)> dfs = [&](int i)->void {
            int d = k - path.size(); // ��Ҫѡ d ����
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            /*
            ���赱ǰ��Ҫ��[1,i]��ѡ��
            ���i < d������Ȼ�޷�ѡ�� k ��������Ϊ���ָ����ܺͲ����ܵ��� k
            ����Ҫ�����ݹ�
            */
            if (i > d) { // ��� i > d�����Բ�ѡ i������������ܲ�ѡ����Ϊ��i<=dʱ˵��ʣ�µ����ָպù����߲���������Ҫѡ��
                dfs(i - 1);
            }

            // ѡ i
            path.emplace_back(i);
            dfs(i - 1);
            path.pop_back();
        };

        dfs(n);
        return ans;
    }
};
