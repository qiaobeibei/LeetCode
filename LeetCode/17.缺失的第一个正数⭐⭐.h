/*
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
*/

#pragma once
#include<vector>
#include<iostream>

// 参考：https://leetcode.cn/problems/first-missing-positive/solutions/304894/zhao-zuo-wei-de-gu-shi-onyuan-di-jie-fa-by-java_le/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        // 第一步：将不在 [1, n] 范围内的数置为 0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 || nums[i] > nums.size()) { // 小于0或者大于size的数肯定不是最小的正整数
                nums[i] = 0;
            }
        }
        // 第二步：将元素放到正确的位置上
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]!=0 and nums[i] != i + 1) { // 若当前位置不为零并且和目标值不符合（坐错位置了）
                int a = nums[i]; // 让 a起身
                nums[i] = 0; // 座位变空
                while (nums[a - 1] != a) { //循环直到a坐对位置nums[a-1](给做错位置的a找位置)
                    if (nums[a - 1]==0) {  // 如果座位为空，a直接坐下去
                        nums[a - 1] = a;
                    }
                    else { // 如果a的位置上还有人
                        int other = nums[a - 1]; // 让这个人起来
                        nums[a - 1] = a; // 让a坐下来
                        a = other; // other相当于新的a，去找自己的座位(递归调用)
                    }
                }
            }
        }
        // 第三步：找到第一个缺失的正整数
        int i;
        for (i = 0; i < nums.size() && nums[i] != 0; ++i);
        /*
        返回值有两种情况：
        1）如果 i 小于数组的大小，说明在数组中找到了一个位置 i，使得 nums[i] == 0。这意味着在数组中，
        原本应该在位置 i + 1 的正整数缺失了，所以返回 i + 1。
        2）如果 i 等于数组的大小，说明数组中所有位置的元素都不为 0，即数组中包含了从 1 到 nums.size() 
        的所有正整数。那么缺失的最小正整数就是 nums.size() + 1，此时 i 刚好等于 nums.size()，返回 i + 1 
        也符合要求。
        */
        return i + 1;
    }
};