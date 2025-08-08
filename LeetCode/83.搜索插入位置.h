// https://leetcode.cn/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

/*
问：为什么代码没有特判所有数都小于 target 的情况？
答：如果所有数都小于 target，那么循环中更新的只有 left，无论下面哪种二分写法，
最后都一定会返回数组长度，所以无需特判这种情况。

问：如果所有数都大于 target 呢？
答：代码会返回 0。

问：是否需要特判 nums[mid]=target 的情况？
答：可以，但没必要。
*/

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
};