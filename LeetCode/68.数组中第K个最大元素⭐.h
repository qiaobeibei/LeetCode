// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <functional>

// 判断第k个元素是否在big中，判断条件需要加<=而不是<
class Solution {
private:
    int quickSelect(std::vector<int>& nums, int k) {
        // 随机选择基准数
        int pivot = nums[std::rand() % nums.size()];
        // 将大于、小于、等于 pivot 的元素划分至 big, small, equal 中
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

        // 第 k 大元素在 big 中，递归划分
        if (k <= big.size()) {
            return quickSelect(big, k);
        }
        // 第 k 大元素在 small 中，递归划分
        /*
        如果 big 向量和 equal 向量的元素个数之和小于 k，说明第 k 大的元素在 small 向量中。
        此时，需要在 small 向量中查找第 k - (big.size() + equal.size()) 大的元素，因为 big 
        向量和 equal 向量中的元素都比要找的元素大。
        */
        if (big.size() + equal.size() < k) {
            return quickSelect(small, k - (big.size() + equal.size()));
        }
        // 第 k 大元素在 equal 中，直接返回 pivot
        return pivot;
    }
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
};
