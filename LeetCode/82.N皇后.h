// https://leetcode.cn/problems/n-queens/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

/*
������һ�� n * n �ľ����з� n ���ʺ�ÿ���ʺ�֮�䲻��ͬ�С�����ͬ��Ҳ������һ��б��
��ÿ��ÿ�ж�������һ���ʺ��Ҳ�����ͬһ��б�ߣ�ÿ��ÿ�е���˼����[0,n-1]��ȫ���У�76�⣩������Ҫע��
������б�ߵ�Ҫ��
�� r ��ʾ�У�c ��ʾ�У����Ϸ���Ļʺ� r+c ��һ����ֵ������Ҫ��(2,0)�Żʺ���ô֮ǰ������r+c=2�Ļʺ�
���Ϸ���Ļʺ�r-c��һ����ֵ������Ҫ��(2,3)�Żʺ���ô֮ǰ������r-c=-1�Ļʺ�
*/
class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<int> queens(n); // �ʺ���� (r,queens[r])����ʵ���Ǵ�ŵ�r�лʺ��ڵ���λ��
        // diag1 �� diag2 �ֱ��¼֮ǰ���õĻʺ���кż��кţ��Լ��кż��к�
        // (0, 0)��(n-1, n-1)���������кͻ��ķ�ΧΪ0��2n-2��-(n-1)��n-1����Ӧ������Ϊ2n-1�����򲼶������С��Ϊ2n-1
        std::vector<int> diag1(n * 2 - 1), diag2(n * 2 - 1);
        std::vector<int> col(n); // ĳһ���Ƿ�ռ��

        // ������������[0,n-1]��ȫ�����ҶԽǲ����е����⣬���ֻ��Ҫ���л����о��У����￴��
        std::function<void(int r)> dfs = [&](int r)->void {
            if (r == n) {
                std::vector<std::string> board(n); // ���е�һ�ֽ��
                for (int i = 0; i < n; ++i) {
                    // ����ʺ����(r,queens[r])==(0,2)��n=4����ôǰ��λ��'.'������λ��'.'
                    board[i] = std::string(queens[i], '.') + 'Q' + std::string(n - 1 - queens[i], '.');
                }
                ans.emplace_back(board);
                return;
            }
            // ��(r,c)�Żʺ�
            for (int c = 0; c < n; ++c) {
                int rc = r - c + n - 1; // r - c�����Ǹ�����Ϊ������ʼ�մ���0����n-1������r-c�ķ�ΧҲ��[0,2n-2]����Ϊ����������ڵ���0
                if (!col[c] && !diag1[r + c] && !diag2[rc]) { 
                    queens[r] = c; // ֱ�Ӹ��ǣ�����ָ��ֳ�
                    col[c] = diag1[r + c] = diag2[rc] = true; // �ʺ�ռ���� c �к�����б��
                    dfs(r + 1);
                    col[c] = diag1[r + c] = diag2[rc] = false; // �ָ��ֳ�
                }
            }
        };

        dfs(0);
        return ans;
    }
};
