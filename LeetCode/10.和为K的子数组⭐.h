/*
����һ���������� nums ��һ������ k ������ͳ�Ʋ����� �������к�Ϊ k ��������ĸ��� ��

��������������Ԫ�ص������ǿ����С�
*/
// https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

// ǰ׺�� + ��ϣ��
// �������� nums������ǰ׺�� sum[i] Ϊ����ǰ i ��Ԫ�صĺͣ��� sum[i] = nums[0] + nums[1] + ... + nums[i - 1]
// ��ô���������������� i �� j��i < j���������� nums[i, j]������ nums[i] �� nums[j]��
// �ĺͿ��Ա�ʾΪ sum[j + 1] - sum[i] = nums[0] + nums[1] + ... + nums[j] - nums[0] + nums[1] + ... + nums[i - 1]
// = nums[i] + nums[1] + ... + nums[j]

/*
ʲôʱ����vector�洢ǰ׺�ͣ�ʲôʱ��������map��

������ټ����ض�����ĺͻ�˳�����ݽ�������򣩴���ǰ׺�ͣ���˫ָ�뷨����Ӧʹ��vector�洢ǰ׺�ͣ�
����֧�� O(1) �����ѯ������˳��
�����Ч���������ض�������ǰ׺�ͣ����ֵƥ���ͳ�Ƴ��ִ���������ʹ��unordered_map�����ù�ϣ��� O(1) 
ƽ������ʱ���Ż�ͳ�Ʋ�����
*/


class Solution {
public:
    int subarraySum(std::vector<int>& nums, const int k) {
        int ans = 0;
        int sum = 0;
        // ���ڴ洢ǰ׺�ͼ�����ֵĴ���
        std::unordered_map<int, int> prefixSumCount;
        // ��ʼ��ǰ׺��Ϊ 0 ��������� 1 ��
        // ��һ������ҪҲ���������ǣ��������
        // �������� nums = [1, 2, 3, 4]��k = 3
        // ��[1,2]ǡ����3������ 3 -3 = 0 ��������ǰ׺�ͱ��У���ô��ʱ�����ִ���
        prefixSumCount[0] = 1;

        for (int& num : nums) {
            sum += num;
            // sum ��ʵ���� sum[j + 1] = sum[0] + ... + sum[j]
            // ����Ϊʲô��ǰ׺�ͱ��д��� sum - k ����ȷ����������������ĺ�==k��ͨ��һ�����ӽ���
            // �������� nums = [1, 2, 3, 4]��k = 5
            // �� sum[3] = sum[0] + sum[1] + sum[2] = 6ʱ����� 6 - 5 ������ǰ׺�ͱ���
            // ˵��  sum[3] - prefixSumCount[sum[3] - k] == k����ʾ sum[3] - sum[1] = sum[1] + sum[2] = 5
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                ans += prefixSumCount[sum - k];
            }

            prefixSumCount[sum]++;
        }

        return ans;
    }
};



