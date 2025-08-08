//https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

class Solution {
private:
    // 通过二分查找确定两个递增子数组的分界点。
    int findPivot(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums.front()) { // 说明 [0..mid] 是递增段，旋转点在右侧
                left = mid + 1;
            }
            else { // 说明 [mid..right] 是递增段，旋转点在左侧
                right = mid - 1;
            }
        }
        //循环结束后,left指向旋转点（即右侧递增段的第一个元素位置）。若数组未旋转，left 等于数组长度 n。
        return left; 
    }
public:
    int findMin(std::vector<int>& nums) {
        int pivot = findPivot(nums);
        return pivot == nums.size() ? nums[0] : nums[pivot];
    }
};