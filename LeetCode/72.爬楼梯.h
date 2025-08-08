// https://leetcode.cn/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-100-liked

/*
���� dfs(i) ��ʾ�� 0 ���� i �ж����ֲ�ͬ�ķ���
*/
#include<iostream>
#include<vector>

class Solution {
private:
    std::vector<int> memo;

    int dfs(int i) {
        if (i <= 1) {
            return 1;
        }
        int& res = memo[i];
        if (res) {
            return res;
        }

        return res = dfs(i - 1) + dfs(i - 2);
    }
public:
    int climbStairs(int n) {
        memo.resize(n + 1);
        return dfs(n);
    }
};
