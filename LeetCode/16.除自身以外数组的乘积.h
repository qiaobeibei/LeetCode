/*
����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��

��Ŀ���� ��֤ ���� nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����  32 λ ������Χ�ڡ�

�� ��Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣
*/

#pragma once
#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer(nums.size());
        std::vector<int> prefixMul(nums.size() + 1);
        prefixMul[0] = 1;
        std::vector<int> suffixMul(nums.size() + 1);
        suffixMul[nums.size()] = 1;
        for (int i = 1; i < nums.size() + 1; i++) {
            prefixMul[i] = prefixMul[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffixMul[i] = suffixMul[i + 1] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = suffixMul[i + 1] * prefixMul[i];
        }
        return answer;
    }
};