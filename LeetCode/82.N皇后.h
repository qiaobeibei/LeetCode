// https://leetcode.cn/problems/n-queens/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

/*
就是在一个 n * n 的矩阵中放 n 个皇后，每个皇后之间不能同行、不能同列也不能在一条斜线
即每行每列都仅能有一个皇后，且不能在同一个斜线，每行每列的意思是找[0,n-1]的全排列（76题），但是要注意
这里有斜线的要求：
用 r 表示行，c 表示列，右上方向的皇后 r+c 是一个定值，假设要在(2,0)放皇后，那么之前不能有r+c=2的皇后
左上方向的皇后r-c是一个定值，假设要在(2,3)放皇后，那么之前不能有r-c=-1的皇后
*/
class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<int> queens(n); // 皇后放在 (r,queens[r])，其实就是存放第r行皇后在的列位置
        // diag1 和 diag2 分别记录之前放置的皇后的行号加列号，以及行号减列号
        // (0, 0)到(n-1, n-1)的所有行列和或差的范围为0到2n-2或-(n-1)到n-1，对应个数均为2n-1个，则布尔数组大小均为2n-1
        std::vector<int> diag1(n * 2 - 1), diag2(n * 2 - 1);
        std::vector<int> col(n); // 某一列是否被占用

        // 本质上是找行[0,n-1]的全排列且对角不排列的问题，因此只需要看行或者列就行，这里看行
        std::function<void(int r)> dfs = [&](int r)->void {
            if (r == n) {
                std::vector<std::string> board(n); // 其中的一种结果
                for (int i = 0; i < n; ++i) {
                    // 如果皇后放在(r,queens[r])==(0,2)，n=4，那么前两位是'.'，第四位是'.'
                    board[i] = std::string(queens[i], '.') + 'Q' + std::string(n - 1 - queens[i], '.');
                }
                ans.emplace_back(board);
                return;
            }
            // 在(r,c)放皇后
            for (int c = 0; c < n; ++c) {
                int rc = r - c + n - 1; // r - c可能是负数，为了让其始终大于0，加n-1，这样r-c的范围也是[0,2n-2]，因为索引必须大于等于0
                if (!col[c] && !diag1[r + c] && !diag2[rc]) { 
                    queens[r] = c; // 直接覆盖，无需恢复现场
                    col[c] = diag1[r + c] = diag2[rc] = true; // 皇后占用了 c 列和两条斜线
                    dfs(r + 1);
                    col[c] = diag1[r + c] = diag2[rc] = false; // 恢复现场
                }
            }
        };

        dfs(0);
        return ans;
    }
};
