/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// 分组+哈希表
// 先计算a+b的值，并存放map,然后计算-c-d是否在map中，并统计key的value
class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, 
        std::vector<int>& nums4) {
        int count = 0;
        std::unordered_map<int, int> map; // key放a和b两数之和， value放a和b两数之和出现的次数

        for (int a : nums1)
            for (int b : nums2) 
                    map[a + b]++; // 如果a+b在map中不存在，那么自动创建新的键值对，键是a+b，值初始化（int是0）
            
        for (int c : nums3)
            for (int d : nums4) 
                if (map.find(-c - d) != map.end())
                    count += map[-c - d];  

        return count;
    }
};