/*
����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������

����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
*/

#pragma once
#include<vector>
#include<iostream>

// �ο���https://leetcode.cn/problems/first-missing-positive/solutions/304894/zhao-zuo-wei-de-gu-shi-onyuan-di-jie-fa-by-java_le/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        // ��һ���������� [1, n] ��Χ�ڵ�����Ϊ 0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 || nums[i] > nums.size()) { // С��0���ߴ���size�����϶�������С��������
                nums[i] = 0;
            }
        }
        // �ڶ�������Ԫ�طŵ���ȷ��λ����
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]!=0 and nums[i] != i + 1) { // ����ǰλ�ò�Ϊ�㲢�Һ�Ŀ��ֵ�����ϣ�����λ���ˣ�
                int a = nums[i]; // �� a����
                nums[i] = 0; // ��λ���
                while (nums[a - 1] != a) { //ѭ��ֱ��a����λ��nums[a-1](������λ�õ�a��λ��)
                    if (nums[a - 1]==0) {  // �����λΪ�գ�aֱ������ȥ
                        nums[a - 1] = a;
                    }
                    else { // ���a��λ���ϻ�����
                        int other = nums[a - 1]; // �����������
                        nums[a - 1] = a; // ��a������
                        a = other; // other�൱���µ�a��ȥ���Լ�����λ(�ݹ����)
                    }
                }
            }
        }
        // ���������ҵ���һ��ȱʧ��������
        int i;
        for (i = 0; i < nums.size() && nums[i] != 0; ++i);
        /*
        ����ֵ�����������
        1����� i С������Ĵ�С��˵�����������ҵ���һ��λ�� i��ʹ�� nums[i] == 0������ζ���������У�
        ԭ��Ӧ����λ�� i + 1 ��������ȱʧ�ˣ����Է��� i + 1��
        2����� i ��������Ĵ�С��˵������������λ�õ�Ԫ�ض���Ϊ 0���������а����˴� 1 �� nums.size() 
        ����������������ôȱʧ����С���������� nums.size() + 1����ʱ i �պõ��� nums.size()������ i + 1 
        Ҳ����Ҫ��
        */
        return i + 1;
    }
};