// https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

// 二分查找
// 用 《21.搜索二维矩阵》 的方法也行
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // a[i]=matrix[i/n][i % n]，将矩阵看作一个排序好的一维数组，i是一维数组中的索引，
            // i/n和i%n是a[i]对应在二维数组的行和列
            int x = matrix[mid / n][mid % n];
            if (x < target) {
                left = mid + 1;
            }
            else if (x > target) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};