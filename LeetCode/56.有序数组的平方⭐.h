// https://leetcode.cn/problems/squares-of-a-sorted-array/

#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int n = nums.size() - 1;
        std::vector<int> res(n + 1);

        for (int left = 0, right = n; left <= right;) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                res[n] = nums[right] * nums[right];
                n--;
                right--;
            }
            else {
                res[n] = nums[left] * nums[left];
                n--;
                left++;
            }
        }
        return res;
    }
};