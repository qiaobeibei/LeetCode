/*
����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] 
���� i != j��i != k �� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ��
���㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

/*
ע��㣺
ȥ�� a���ǵ�Ҫ��i>0��
ȥ�� b �� c ʱ���ǵü� left < right
*/


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) return {};

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return ans; // ÿ����Ԫ���һ��������С��0����Ȼ����������֮��==0
            if (i > 0 and nums[i - 1] == nums[i]) continue; // ȥ�� a���ǵ�Ҫ��i>0��

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[right] + nums[left] > 0) right--;
                else if (nums[i] + nums[right] + nums[left] < 0) left++;
                else {
                    // ans.emplace_back({ nums[i], nums[right], nums[left] });�Ǵ��
                    // ans.push_back({ nums[i], nums[right], nums[left] });�Ƕ���
                    // Ҫ��ʹ�� emplace_back ֻ������������ʹ��
                    ans.emplace_back(std::initializer_list<int>{ nums[i], nums[right], nums[left] });
                    // ѭ��ʱ�ǵü�left < right 
                    while (left < right and nums[left] == nums[left + 1]) left++; // ȥ�� b
                    while (left < right and nums[right] == nums[right - 1]) right--; // ȥ�� c

                    left++;
                    right--;
                }
            }
        }

        return ans;
    }
};


