/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部
条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按任意顺序返回答案 。
*/


// 双指针法
/*
四数之和和三数之和有个最大的区别：剪枝
1）这里不能根据nums[k] > target就直接判断无法满足给定条件，比如-4，-2，0，0 target=-6，此时-4>-6,但{-4，-2，0，0}满足条件
所以只有当target > 0时才能使用这个条件。

2）当判断需要剪枝时，最好不要直接return res，因为对i的剪枝，return会直接返回可能会忽略一些元组，因为i是第二层循环，不能直接
判断不满足条件，break跳出第二层循环。 对于k，如果剪枝条件满足，那么可以直接return，因为k前面没有别的循环了，k第一个值不能满足，
那么剩下的值也不可能满足
*/


#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;

        if (nums.size() < 4) return res;

        for (int k = 0; k < nums.size(); k++) {
            if (target > 0 and nums[k] >= target) break; 
            if (k > 0 and nums[k] == nums[k - 1])
                continue;

            for (int i = k + 1; i < nums.size(); i++) {
                if (target > 0 and nums[k] + nums[i] > target) break;
                if (i > k + 1 and nums[i] == nums[i - 1]) continue;

                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                        right--;
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                        left++;
                    else {
                        res.push_back({ nums[k], nums[i], nums[left], nums[right] });
                        while (right > left and nums[left] == nums[left + 1]) left++;
                        while (right > left and nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};