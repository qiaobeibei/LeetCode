/*
�����ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ�� (i, j, k, l) �����㣺

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// ����+��ϣ��
// �ȼ���a+b��ֵ�������map,Ȼ�����-c-d�Ƿ���map�У���ͳ��key��value
class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, 
        std::vector<int>& nums4) {
        int count = 0;
        std::unordered_map<int, int> map; // key��a��b����֮�ͣ� value��a��b����֮�ͳ��ֵĴ���

        for (int a : nums1)
            for (int b : nums2) 
                    map[a + b]++; // ���a+b��map�в����ڣ���ô�Զ������µļ�ֵ�ԣ�����a+b��ֵ��ʼ����int��0��
            
        for (int c : nums3)
            for (int d : nums4) 
                if (map.find(-c - d) != map.end())
                    count += map[-c - d];  

        return count;
    }
};