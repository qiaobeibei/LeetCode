//
//#include <iostream>
//#include <vector>
//#include <tuple>
//
//namespace day4 {
//    /*
//给你一个正整数 n ，生成一个包含 1 到 n*n 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//*/
//
//
///*
//1.方向向量dx和dy的含义
//    (dx, dy)->(dy, -dx)表示顺时针旋转90°：可以想象成一个点（0，1）在xy坐标上进行90°旋转后的点坐标
//    (dx, dy) = (0, 1) 表示向右移动。
//    (dx, dy) = (1, 0) 表示向下移动。
//    (dx, dy) = (0, -1) 表示向左移动。
//    (dx, dy) = (-1, 0) 表示向上移动。
//
//    (dx, dy)->(-dy, dx)表示逆时针旋转90°
//2.下一个位置的计算
//    在生成螺旋矩阵时，需要不断检查下一个位置 (x + dx, y + dy) 是否仍在矩阵的范围内，并且该位置是否已经填
//    充过数字。如果下一个位置超出边界或者已经被填充，则需要改变方向。
//3.if条件解释：if (res[(x + dx + n) % n][(y + dy + n) % n] != 0)
//    * x + dx 和 y + dy 分别是下一个位置的行和列坐标；
//    * 如果直接使用 x + dx 或 y + dy，可能会遇到越界情况（即 x + dx < 0 或 x + dx >= n，y + dy < 0 或 y + dy >= n）；
//    * + n 的操作确保即使 x + dx 或 y + dy 是负数，加上 n 后结果为正。例如，如果 n = 3 且 x + dx = -1，那么 -1 + 3 = 2；
//    * %n 的操作确保最终结果在 [0, n-1] 范围内。无论 x + dx 或 y + dy 是多少，经过 (x + dx + n) % n 后，结果都会被限
//        制在有效的索引范围内 [0, n-1]。
//    1）为什么这样可以防止越界？
//    * 取模 % n 是关键，它将任何超出范围的索引值变换回一个合法的矩阵索引值；
//    * 例如：
//        如果 n = 3，而 x = 2，dx = 1（即我们试图向下移动），那么 x + dx = 3 超出了边界。但是
//        (3 + 3) % 3 = 0，所以计算结果将重新指向第一行。同样地，如果我们在 (x, y) = (0, 0)，
//        并且试图向左移动（dy = -1），y + dy = -1 超出了边界。但是 (-1 + 3) % 3 = 2，将计算
//        结果重新指向最后一列。
//    2） != 0的解释？
//        res[(x + dx + n) % n][(y + dy + n) % n] != 0 检查下一个位置是否已经被填充了数字。
//        如果下一个位置不为 0，说明已经有数字填入，当前方向需要改变。
//*/
//
//
//// 方向向量法
//    class Solution {
//    public:
//        std::vector<std::vector<int>> generateMatrix(int n) {
//            std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));   // 存储矩阵
//            int dx = 0, dy = 1;                                             // 方向向量，初始向右移动
//            int x = 0, y = 0;                                               // 当前元素的坐标起始为 (0, 0)
//
//            for (int i = 1; i <= n * n; i++) {
//                res[x][y] = i;                                              // 填充数字从 1 到 n*n
//                // 用于判断当前方向的下一个位置是否已经填充了数字，并防止数组越界
//                if (res[(x + dx + n) % n][(y + dy + n) % n] != 0)           // 取模防止越界，当发生越界时，指针重新回到0，此时0处有填充值
//                    std::tie(dx, dy) = std::make_tuple(dy, -dx);            // 方向向量旋转90°，(dx, dy)->(dy, -dx)
//
//                x += dx, y += dy;                                           // 更新坐标
//            }
//            return res;
//        }
//    };
//
//
//    class Solution {
//    public:
//        std::vector<std::vector<int>> generateMatrix(int n) {
//            std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
//            int dx = 0, dy = 1;
//            int x = 0, y = 0;
//            for (int i = 1; i <= n * n; i++) {
//                res[x][y] = i;
//                if (res[(x + dx + n) % n][(y + dy + n) % n] != 0)
//                    std::tie(dx, dy) = std::make_tuple(dy, -dx);
//                x += dx, y += dy;
//            }
//            return res;
//        }
//    };
//}