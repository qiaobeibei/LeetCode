#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

//https://leetcode.cn/problems/longest-increasing-subsequence/?envType=study-plan-v2&envId=top-100-liked
// 这道题目和《3.最长连续序列》看起来有点像，但其实不同
class Solution {
public:
    /*
    要找出一个数组中最长递增子序列的长度，我们可以定义一个函数 dfs(i) 来表示以数组中第 i 个元素 
    nums[i] 结尾的最长递增子序列的长度，memo[i] 用于记录这个长度。对于每个元素 nums[i]，我们需要遍
    历它之前的所有元素 nums[j]（其中 j < i），如果 nums[j] < nums[i]，那么说明可以将 nums[i] 接在以 
    nums[j] 结尾的递增子序列后面，从而得到一个新的递增子序列。通过比较所有可能的情况，我们就能找到以
    nums[i] 结尾的最长递增子序列的长度。
    */

    // [10, 9, 2, 5, 3, 7, 101, 18]
    // 注意：两次dfs的情况不一样，一个是dfs(j)一个是dfs(i)
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> memo(n); // 用于记忆化，初始值都为 0

        std::function<int(int i)> dfs = [&](int i)->int {
            int& res = memo[i]; // 必须是引用
            if (res > 0) {
                return res;  // 如果 memo[i] 已经计算过（即 res > 0），直接返回结果，避免重复计算
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // 如果 nums[j] 小于 nums[i]，说明可以将 nums[i] 接在以 nums[j] 结尾的递增子序列后面
                    // 取当前 res 和 dfs(j) 的最大值，更新 res
                    // 注意，这里不能改为res = std::max(res, memo[j])，因为只有在满足 nums[k] < nums[j]（k < j）的条件下，
                    // 才会更新 memo[j]，所以有可能memo[j]此时是0，所以必须递归查找
                    res = std::max(res, dfs(j)); 
                }
            }

            // 注意，因为res是引用，所以这里的++res同时会对memo中的元素进行修改，所以这里只能
            // 返回++res，而不能返回res+1，后者无法修改memo中的元素
            return ++res; // 最终结果要加 1，因为当前元素 nums[i] 本身也算一个长度
            // 其实这里就是先找到从0~i-1的最长序列，如果能找到则说明能将nums[i]加到后面，则++res；
            // 如果没找到，则将memo[i]设为1（++res）
        };

        int ans = 0; // 用于记录全局最长递增子序列的长度
        for (int i = 0; i < n; i++) {
            // 遍历数组中的每个元素，计算以该元素结尾的最长递增子序列的长度
            ans = std::max(ans, dfs(i));
        }
        return ans;
    }
};

// 打印这个最长子序列
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        std::vector<int> memo(n, 0);      // 存储最长长度
        std::vector<int> prev(n, -1);     // 存储前驱索引

        std::function<int(int)> dfs = [&](int i) {
            if (memo[i] != 0) return memo[i];

            int max_len = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    int current = dfs(j);  // 递归子问题
                    if (current > max_len) {
                        max_len = current;
                        prev[i] = j;      // 关键修改：记录前驱节点
                    }
                }
            }
            memo[i] = max_len + 1;
            return memo[i];
        };

        // 计算最长长度并记录终点
        int max_len = 0, end = -1;
        for (int i = 0; i < n; ++i) {
            int current = dfs(i);
            if (current > max_len) {
                max_len = current;
                end = i;
            }
        }

        // 回溯构造路径
        std::vector<int> path;
        while (end != -1) {
            path.push_back(nums[end]);
            end = prev[end];
        }
        std::reverse(path.begin(), path.end());

        // 打印结果
        std::cout << "LIS: ";
        for (int num : path) std::cout << num << " ";
        std::cout << "\n";

        return max_len;
    }
};

/* 示例用法：
输入：{10,9,2,5,3,7,101,18}
输出：LIS: 2 5 7 101
      返回值：4
*/