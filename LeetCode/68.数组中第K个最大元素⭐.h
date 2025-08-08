// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

// �жϵ�k��Ԫ���Ƿ���big�У��ж�������Ҫ��<=������<
class Solution {
private:
    int quickSelect(std::vector<int>& nums, int k) {
        // ���ѡ���׼��
        int pivot = nums[std::rand() % nums.size()];
        // �����ڡ�С�ڡ����� pivot ��Ԫ�ػ����� big, small, equal ��
        std::vector<int> big, small, equal;
        for (int num : nums) {
            if (num > pivot) {
                big.emplace_back(num);
            }
            else if (num < pivot) {
                small.emplace_back(num);
            }      
            else {
                equal.emplace_back(num);
            }
        }

        // �� k ��Ԫ���� big �У��ݹ黮��
        if (k <= big.size()) {
            return quickSelect(big, k);
        }
        // �� k ��Ԫ���� small �У��ݹ黮��
        /*
        ��� big ������ equal ������Ԫ�ظ���֮��С�� k��˵���� k ���Ԫ���� small �����С�
        ��ʱ����Ҫ�� small �����в��ҵ� k - (big.size() + equal.size()) ���Ԫ�أ���Ϊ big 
        ������ equal �����е�Ԫ�ض���Ҫ�ҵ�Ԫ�ش�
        */
        if (big.size() + equal.size() < k) {
            return quickSelect(small, k - (big.size() + equal.size()));
        }
        // �� k ��Ԫ���� equal �У�ֱ�ӷ��� pivot
        return pivot;
    }
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
};
