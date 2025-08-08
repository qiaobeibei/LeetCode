// https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

// ���ֲ���
// �� ��21.������ά���� �ķ���Ҳ��
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // a[i]=matrix[i/n][i % n]����������һ������õ�һά���飬i��һά�����е�������
            // i/n��i%n��a[i]��Ӧ�ڶ�ά������к���
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