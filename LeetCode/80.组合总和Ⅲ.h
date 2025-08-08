// https://leetcode.cn/problems/combination-sum-iii/description/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>


class Solution {
public:
    auto combinationSum3(int k, int n) ->std::vector<std::vector<int>> {
        std::vector<std::vector<int>> ans;
        std::vector<int> path;

        // i �ǵ�ǰ׼��Ҫ�ӵ����֣�left��Ҫ�ӵ����ֺ�
        std::function<void(int i, int left)> dfs = [&](int i, int left) {
            if (left == 0 && path.size() == k) {
                ans.emplace_back(path);
                return;
            }
            // �����ִ���9��ʣ�����ֺ�С��0��path��Ԫ�ظ������ڵ���k����������һ��������������ܳɹ�
            if (i > 9 || left < 0 || path.size() >= k) {
                return;
            }
            // ��ѡ i
            dfs(i + 1, left);
            // ѡ i
            path.emplace_back(i);
            dfs(i + 1, left - i);
            path.pop_back();
        };

        dfs(1, n);
        return ans;
    }
};