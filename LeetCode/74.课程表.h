//https://leetcode.cn/problems/course-schedule/solutions/2992884/san-se-biao-ji-fa-pythonjavacgojsrust-by-pll7/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>

// 给你一个有向图（把每个 prerequisites[i]=[a,b] 看成一条有向边 b→a，构建一个有向图 g），判断图中是否有环
// 是否存在一种顺序，使得所有课程都有被完成（即图中无环）

/*
通过深度优先搜索（DFS）遍历图，用三种颜色标记节点状态，检测是否存在环：
0（未访问）：节点尚未被访问。
1（正在访问）：节点已被访问，但尚未完成对其所有邻接节点的访问（当前在递归栈中，属于当前路径）。
2（已完成）：节点及其所有邻接节点已访问完毕（递归栈中已弹出）。
环的检测逻辑：
如果在访问节点 x 的邻接节点 y 时，发现 y 的颜色为 1（正在访问），说明 y 在当前路径中，
存在环（x → ... → y → x）。
*/
class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // g 是邻接表，g[b] 存储所有以 b 为起点的有向边的终点（即 b 的后续课程）
        // 例如，prerequisites = [[0,1]] 表示「课程 0 的先修课是 1」，对应边 1 → 0，因此 g[1] = [0]或者 g[1] = [0,2,3...]
        std::vector<std::vector<int>> g(numCourses);
        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);  // 把每个 prerequisites[i] = [a, b] 看成一条有向边 b→a
        }

        std::vector<int> colors(numCourses);  // 0:未访问，1:正在访问，2:已完成
        std::function<bool(int x)> dfs = [&](int x) -> bool {
            colors[x] = 1; // x 正在访问中
            for (int y : g[x]) { // 假如课程0的先修可程是1，课程2的先修课程也是1，则g[1]=[0,2]
                // 如果当前学习课程的后续课程处于“正在访问中”或者后续课程“未被访问”，但是后续课程作为先修时，其
                // 子树中存在环则返回true
                if (colors[y] == 1 || colors[y] == 0 && dfs(y)) {
                    return true; // 有环
                }
            }
            colors[x] = 2; // x 访问完毕
            return false; // 没有环
        };

        // 图可能由多个不连通的子图组成，因此需要遍历所有节点，对每个未访问的节点启动 DFS。
        for (int i = 0; i < numCourses; ++i) {
            if (colors[i] == 0 && dfs(i)) {
                return false; // 有环
            }
        }
        return true; // 没有环

    }
};