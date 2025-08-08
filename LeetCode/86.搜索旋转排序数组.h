//https://leetcode.cn/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

// 第一种解法：两次二分
class Solution {
private:
    int findPivot(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums.front()) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }

    // 有序数组中找 target 的下标
    int lower_bound(std::vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
public:
    int search(std::vector<int>& nums, int target) {
        int pivot = findPivot(nums);

        if (target >= nums.front()) { // target 在pivot（i）左边
            return lower_bound(nums, 0, pivot - 1, target);
        }
        // target 在pivot（i）右边
        return lower_bound(nums, pivot, nums.size() - 1, target);
    }
};

// 第二种解法：一次二分
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int end = nums.back();
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 如果mid在第二段，target在第一段,说明target在mid的左边
            if (nums[mid] <= end && target > end) {
                right = mid - 1;
            }
            // 如果mid在第一，target在第二，说明target在mid的右边
            else if (target <= end && nums[mid] > end) {
                left = mid + 1;
            }
            else { // mid和target在同一个递增段
                if (target > nums[mid]) {
                    left = mid + 1;
                }
                else if(target < nums[mid]){
                    right = mid - 1;
                } 
                else {
                    return mid;
                }
            }
        }
        return -1;
    }
};
