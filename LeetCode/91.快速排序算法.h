
// https://leetcode.cn/problems/sort-an-array/description/
#pragma once

#include <iostream>
#include <vector>

class Solution {
private:
    int partition(std::vector<int>& nums, int left, int right) {
        //三数取中,让首元素，尾元素和中间元素三者中的中间值放在首，作为pivot
        int mid = left + ((right - left) >> 1);
        if (nums[left] > nums[right]){
            std::swap(nums[left], nums[right]);
        } 
        if (nums[mid] > nums[right]) {
            std::swap(nums[mid], nums[right]);
        }
        if (nums[mid] > nums[left]) {
            std::swap(nums[mid], nums[left]);
        }
        int pivot = nums[left]; // 取三数中间的作为基准
        int i = left; // 记录基准的初始位置（后续用于将基准放到最终位置）
        while (left < right) {
            // 从右向左找第一个小于基准的元素
            while (left < right && nums[right] >= pivot) right--;
            // 从左向右找第一个大于基准的元素
            while (left < right && nums[left] <= pivot) left++;
            if (left >= right) break; 
            std::swap(nums[left], nums[right]); // 交换左右指针指向的元素
        }
        std::swap(nums[i], nums[left]); // 将基准放到最终位置（指针相遇处）
        return left;
    }
    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        std::srand(time(nullptr));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};