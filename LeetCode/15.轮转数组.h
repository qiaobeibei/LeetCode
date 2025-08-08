/*
* ����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

/*
ע��㣺
 k %= nums.size();
 �����Ƕ�һ������Ϊ n �����������תʱ����ת n �λ�ʹ����ص�ԭʼ״̬��Ҳ����˵����ת k �κ���ת 
 k + m * n �Σ�m Ϊ�����������Ľ������ͬ�ġ����磬�������� [1, 2, 3, 4, 5]������ n = 5����ת 5 
 �κ����黹�� [1, 2, 3, 4, 5]����ת 6 �κ���ת 1 �εĽ����һ���ġ�
 ������
 nums = [1, 2, 3, 4, 5] k=2
 ÿ��Ԫ�������ƶ� 2 ��λ�á�
����ĩβ��Ԫ���Ƶ�ǰ�棺
1 �� �ƶ� 2 λ������ 3��
2 �� �ƶ� 2 λ������ 4��
3 �� �ƶ� 2 λ������ 0��
4 �� �ƶ� 2 λ������ 1��
5 �� �ƶ� 2 λ������ 2��
�����[4, 5, 1, 2, 3]
*/

class Solution {
private:
    void reverse(std::vector<int>& nums,int start,int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            std::swap(nums[i], nums[j]);
        }
    }

public:
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};