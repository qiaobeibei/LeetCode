// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<unordered_map>


class Solution {
private:
    // lower_bound ��ʵ���� 83.��������λ�� �Ľⷨ
    
    // lower_bound ������С������ nums[i] >= target ���±� i
    // �������Ϊ�գ������������� < target���򷵻� nums.size()
    // Ҫ�� nums �Ƿǵݼ��ģ��� nums[i] <= nums[i + 1]
    int lower_bound(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            /*
            �ʣ�ΪʲôҪд left + (right - left) / 2��

            �������Ի���ʵ�ʳ����У��㲻һ��֪������������ж೤����һ���鳤�ȴﵽ int ���ֵ��
            left + right ���ܻᷢ���ӷ��������Ȼ�����ֻ����������ݷ�Χ��д (left + right) / 2 
            Ҳ���ԡ����� Python ��˵������û��������������Կ���ֱ����ӡ�
            */
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        // ѭ�������� left = right+1
        // ��ʱ nums[left-1] < target �� nums[left] = nums[right+1] >= target
        // ���� left ���ǵ�һ�� >= target ��Ԫ���±�
        return left;
    }
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return { -1,-1 };
        }
        /*
        �ʣ������� end = lowerBound(nums, target + 1) - 1 ��δ��룿
        ��Ҫ���ҵ� ��target �����һ���������赥����дһ�����֡����ǿ������ҵ���������ұ��������֣�
        Ҳ���� >target �ĵ�һ������������������������ǰ���£�>target �ȼ��� ��target+1�������Ϳ��Ը�
        �������Ѿ�д�õĶ��ֺ����ˣ��� lowerBound(nums, target + 1)�������������±�󣬽����һ��
        �͵õ� ��target �����һ�������±ꡣ
        */
        int end = lower_bound(nums, target + 1) - 1;
        return { start,end };
    }
};
