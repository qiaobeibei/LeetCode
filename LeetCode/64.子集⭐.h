#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<functional>

// https://leetcode.cn/problems/subsets/description/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;  // 用于存储最终生成的所有子集
        std::vector<int> path;         // 用于存储当前正在生成的子集
        int n = nums.size();      // 获取数组 nums 的长度

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) { // 当 i 等于数组长度时，说明已经遍历完所有元素，子集构造完毕
                ans.emplace_back(path);  // 将当前生成的子集 path 加入到结果集 ans 中
                return;  // 结束当前递归调用
            }

            // 不选 nums[i]
            dfs(i + 1);

            // 选 nums[i]
            path.push_back(nums[i]);  // 将 nums[i] 加入到当前子集 path 中
            dfs(i + 1);  // 继续递归处理下一个元素
            path.pop_back(); // 回溯操作，将 nums[i] 从当前子集 path 中移除，恢复现场
        };

        dfs(0);  // 从数组的第一个元素（索引为 0）开始进行深度优先搜索
        return ans;  // 返回最终生成的所有子集
    }
};


class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {{}};
        }
        std::vector<std::vector<int>> ans;
        std::vector<int> path;

        // dfs 中的 i 表示现在要枚举选 nums[i] 到 nums[n−1] 中的一个数，添加到 path 末尾
        std::function<void(int i)> dfs = [&](int i) {
            ans.emplace_back(path);
            for (int j = i; j < n; j++) {
                path.emplace_back(nums[j]);
                dfs(j + 1);
                path.pop_back(); // 将当前数字添加完就删除
            }
        };

        dfs(0);
        return ans;
    }
};

/*
初始状态
n = 3
ans = []
path = []

第一次调用 dfs(0)
    ans.emplace_back(path);：将 [] 加入到 ans 中，此时 ans = [[]]。
    进入 for 循环：
        j = 0，path.emplace_back(nums[0]);：将 1 加入到 path 中，此时 path = [1]。
        调用 dfs(1)。

调用 dfs(1)
    ans.emplace_back(path);：将 [1] 加入到 ans 中，此时 ans = [[], [1]]。
    进入 for 循环：
        j = 1，path.emplace_back(nums[1]);：将 2 加入到 path 中，此时 path = [1, 2]。
        调用 dfs(2)。

调用 dfs(2)
    ans.emplace_back(path);：将 [1, 2] 加入到 ans 中，此时 ans = [[], [1], [1, 2]]。
    进入 for 循环：
        j = 2，path.emplace_back(nums[2]);：将 3 加入到 path 中，此时 path = [1, 2, 3]。
        调用 dfs(3)。

调用 dfs(3)
    ans.emplace_back(path);：将 [1, 2, 3] 加入到 ans 中，此时 ans = [[], [1], [1, 2], [1, 2, 3]]。
    for 循环条件 j < n 不满足，返回上一层。

回溯到 dfs(2)
    path.pop_back();：将 3 从 path 中移除，此时 path = [1, 2]。
    for 循环结束，返回上一层。

回溯到 dfs(1)
    path.pop_back();：将 2 从 path 中移除，此时 path = [1]。
    j = 2，path.emplace_back(nums[2]);：将 3 加入到 path 中，此时 path = [1, 3]。
    调用 dfs(3)。

调用 dfs(3)
    ans.emplace_back(path);：将 [1, 3] 加入到 ans 中，此时 ans = [[], [1], [1, 2], [1, 2, 3], [1, 3]]。
    for 循环条件 j < n 不满足，返回上一层。

回溯到 dfs(1)
    path.pop_back();：将 3 从 path 中移除，此时 path = [1]。
    for 循环结束，返回上一层。

回溯到 dfs(0)
    path.pop_back();：将 1 从 path 中移除，此时 path = []。
    j = 1，path.emplace_back(nums[1]);：将 2 加入到 path 中，此时 path = [2]。

调用 dfs(2)。
    后续过程以此类推，最终得到所有子集

最终 ans = [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]。
*/





