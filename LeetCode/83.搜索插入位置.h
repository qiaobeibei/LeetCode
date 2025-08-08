// https://leetcode.cn/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

/*
�ʣ�Ϊʲô����û��������������С�� target �������
�������������С�� target����ôѭ���и��µ�ֻ�� left�������������ֶ���д����
���һ���᷵�����鳤�ȣ����������������������

�ʣ���������������� target �أ�
�𣺴���᷵�� 0��

�ʣ��Ƿ���Ҫ���� nums[mid]=target �������
�𣺿��ԣ���û��Ҫ��
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