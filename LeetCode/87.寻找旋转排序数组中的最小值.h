//https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>

class Solution {
private:
    // ͨ�����ֲ���ȷ����������������ķֽ�㡣
    int findPivot(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums.front()) { // ˵�� [0..mid] �ǵ����Σ���ת�����Ҳ�
                left = mid + 1;
            }
            else { // ˵�� [mid..right] �ǵ����Σ���ת�������
                right = mid - 1;
            }
        }
        //ѭ��������,leftָ����ת�㣨���Ҳ�����εĵ�һ��Ԫ��λ�ã���������δ��ת��left �������鳤�� n��
        return left; 
    }
public:
    int findMin(std::vector<int>& nums) {
        int pivot = findPivot(nums);
        return pivot == nums.size() ? nums[0] : nums[pivot];
    }
};