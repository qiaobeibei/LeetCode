/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
*/
// https://leetcode.cn/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>

/*
问：保证 m≤n 有什么好处？

答：如果 m>n，我们没法从 i=0 开始枚举。以 m=5,n=3 为例，i=0 时，b 数组需要有 4 个数在第一组，
但 n=3<4，无法做到。保证 m≤n 可以让我们从 i=0 开始枚举，写起来更方便。
*/

// 注意：m和n的值必须在插入INT_MAX和INT_MIN之前求出，之前求的才是真实m和n
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }

        int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        // 这样插入后，nums1=[INT_MIN,x,x,x,x,INT_MAX],nums1[0] = INT_MIN,nums[n + 1] = INT_MAX


        // m + n 是偶数时，j是(m+n)/2
        // m + n 是奇数时，要求第一组比第二组多一个数字，第一组大小为(m+n+1)/2

        // 枚举 nums1 有 i 个数在第一组
        // 那么 nums2 有 (m + n + 1) / 2 - i 个数在第一组
        int i = 0, j = (m + n + 1) / 2;
        while (true) {
            /*
            判断条件其实是【第一组的最大值】<=【第二组的最小值】：
            std::max(nums1[i], nums2[j]) <=  std::min(nums1[i + 1], nums2[j + 1])
            但是，nums1[i] <= nums1[i + 1]，且 nums2[j]<= nums2[j + 1]
            所以，只需判断 nums1[i] <= nums2[j + 1] && nums2[j] <= nums1[i + 1]
            */
            if (nums1[i] <= nums2[j + 1] && nums2[j] <= nums1[i + 1]) {
                int max1 = std::max(nums1[i], nums2[j]); // 第一组的最大值
                int min2 = std::min(nums1[i + 1], nums2[j + 1]); // 第二组的最小值
                return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
            }
            i++;
            j--;
        }
    }
};