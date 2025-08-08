/*
* 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

/*
注意点：
 k %= nums.size();
 当我们对一个长度为 n 的数组进行旋转时，旋转 n 次会使数组回到原始状态。也就是说，旋转 k 次和旋转 
 k + m * n 次（m 为任意整数）的结果是相同的。例如，对于数组 [1, 2, 3, 4, 5]，长度 n = 5，旋转 5 
 次后数组还是 [1, 2, 3, 4, 5]，旋转 6 次和旋转 1 次的结果是一样的。
 举例：
 nums = [1, 2, 3, 4, 5] k=2
 每个元素向右移动 2 个位置。
超出末尾的元素绕到前面：
1 → 移动 2 位到索引 3。
2 → 移动 2 位到索引 4。
3 → 移动 2 位到索引 0。
4 → 移动 2 位到索引 1。
5 → 移动 2 位到索引 2。
结果：[4, 5, 1, 2, 3]
*/

class Solution {
private:
    void reverse(std::vector<int>& nums,int start,int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            std::swap(nums[i], nums[j]);
        }
    }

public:
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};