/*
��дһ����Ч���㷨������ m x n ���� matrix �е�һ��Ŀ��ֵ target ���þ�������������ԣ�

ÿ�е�Ԫ�ش������������С�
ÿ�е�Ԫ�ش��ϵ����������С�
*/

#pragma once
#include<iostream>
#include<vector>
#include<tuple>

// �ų���
// �ο���https://leetcode.cn/problems/search-a-2d-matrix-ii/solutions/2783938/tu-jie-pai-chu-fa-yi-tu-miao-dong-python-kytg/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1; // �����Ͻǿ�ʼ
        while (i < m && j >= 0) { // ����ʣ��Ԫ��
            if (matrix[i][j] == target) {
                return true; // �ҵ� target
            }
            if (matrix[i][j] < target) {
                i++; // ��һ��ʣ��Ԫ��ȫ��С�� target���ų�
            }
            else {
                j--; // ��һ��ʣ��Ԫ��ȫ������ target���ų�
            }
        }
        return false;
    }
};
