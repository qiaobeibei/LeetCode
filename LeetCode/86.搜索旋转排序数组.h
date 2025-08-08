//https://leetcode.cn/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

// ��һ�ֽⷨ�����ζ���
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

    // ������������ target ���±�
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

        if (target >= nums.front()) { // target ��pivot��i�����
            return lower_bound(nums, 0, pivot - 1, target);
        }
        // target ��pivot��i���ұ�
        return lower_bound(nums, pivot, nums.size() - 1, target);
    }
};

// �ڶ��ֽⷨ��һ�ζ���
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int end = nums.back();
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // ���mid�ڵڶ��Σ�target�ڵ�һ��,˵��target��mid�����
            if (nums[mid] <= end && target > end) {
                right = mid - 1;
            }
            // ���mid�ڵ�һ��target�ڵڶ���˵��target��mid���ұ�
            else if (target <= end && nums[mid] > end) {
                left = mid + 1;
            }
            else { // mid��target��ͬһ��������
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
