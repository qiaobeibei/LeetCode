/*
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��
*/
// https://leetcode.cn/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>

/*
�ʣ���֤ m��n ��ʲô�ô���

����� m>n������û���� i=0 ��ʼö�١��� m=5,n=3 Ϊ����i=0 ʱ��b ������Ҫ�� 4 �����ڵ�һ�飬
�� n=3<4���޷���������֤ m��n ���������Ǵ� i=0 ��ʼö�٣�д���������㡣
*/

// ע�⣺m��n��ֵ�����ڲ���INT_MAX��INT_MIN֮ǰ�����֮ǰ��Ĳ�����ʵm��n
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            std::swap(nums1, nums2);
        }

        int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        // ���������nums1=[INT_MIN,x,x,x,x,INT_MAX],nums1[0] = INT_MIN,nums[n + 1] = INT_MAX


        // m + n ��ż��ʱ��j��(m+n)/2
        // m + n ������ʱ��Ҫ���һ��ȵڶ����һ�����֣���һ���СΪ(m+n+1)/2

        // ö�� nums1 �� i �����ڵ�һ��
        // ��ô nums2 �� (m + n + 1) / 2 - i �����ڵ�һ��
        int i = 0, j = (m + n + 1) / 2;
        while (true) {
            /*
            �ж�������ʵ�ǡ���һ������ֵ��<=���ڶ������Сֵ����
            std::max(nums1[i], nums2[j]) <=  std::min(nums1[i + 1], nums2[j + 1])
            ���ǣ�nums1[i] <= nums1[i + 1]���� nums2[j]<= nums2[j + 1]
            ���ԣ�ֻ���ж� nums1[i] <= nums2[j + 1] && nums2[j] <= nums1[i + 1]
            */
            if (nums1[i] <= nums2[j + 1] && nums2[j] <= nums1[i + 1]) {
                int max1 = std::max(nums1[i], nums2[j]); // ��һ������ֵ
                int min2 = std::min(nums1[i + 1], nums2[j + 1]); // �ڶ������Сֵ
                return (m + n) % 2 ? max1 : (max1 + min2) / 2.0;
            }
            i++;
            j--;
        }
    }
};