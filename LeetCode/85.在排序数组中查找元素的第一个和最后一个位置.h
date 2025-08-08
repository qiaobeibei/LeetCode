// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>


class Solution {
private:
    // lower_bound 其实就是 83.搜索插入位置 的解法
    
    // lower_bound 返回最小的满足 nums[i] >= target 的下标 i
    // 如果数组为空，或者所有数都 < target，则返回 nums.size()
    // 要求 nums 是非递减的，即 nums[i] <= nums[i + 1]
    int lower_bound(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            /*
            问：为什么要写 left + (right - left) / 2？

            答：在面试或者实际场景中，你不一定知道输入的数组有多长，万一数组长度达到 int 最大值，
            left + right 可能会发生加法溢出。当然，如果只看本题的数据范围，写 (left + right) / 2 
            也可以。对于 Python 来说，由于没有溢出这个概念，所以可以直接相加。
            */
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        // 循环结束后 left = right+1
        // 此时 nums[left-1] < target 而 nums[left] = nums[right+1] >= target
        // 所以 left 就是第一个 >= target 的元素下标
        return left;
    }
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return { -1,-1 };
        }
        /*
        问：如何理解 end = lowerBound(nums, target + 1) - 1 这段代码？
        答：要想找到 ≤target 的最后一个数，无需单独再写一个二分。我们可以先找到这个数的右边相邻数字，
        也就是 >target 的第一个数。在所有数都是整数的前提下，>target 等价于 ≥target+1，这样就可以复
        用我们已经写好的二分函数了，即 lowerBound(nums, target + 1)，算出这个数的下标后，将其减一，
        就得到 ≤target 的最后一个数的下标。
        */
        int end = lower_bound(nums, target + 1) - 1;
        return { start,end };
    }
};
