/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。
*/

#include <iostream>
#include <vector>
#include <algorithm>


// 双指针
/*
如何去重？
结果中的三元组不能有相同的，比如已经有一个{3,-2,-1},就不能再有{-2,-1,3}等等。。。
主要考虑三个数的去重，比如a、b、c对应的是nums[i]、nums[left]、nums[right],
a 如果重复了怎么办，a是nums里遍历的元素，那么应该直接跳过去。
但这里有一个问题，是判断 nums[i] 与 nums[i + 1]是否相同，还是判断 nums[i] 与 nums[i-1] 是否相同。
如果使用如下代码进行去重：if (nums[i] == nums[i + 1]) continue;
    那么可能会跳过{-1, -1 ,2} 这组数据，当遍历到第一个-1 的时候，判断 下一个也是-1，那这组数据就pass了，
    不会被记录， 乃至于其他以-1开头的三元组都会被去除，比如{-1,0,-1}这一组也收集不到了；
正确的去重应该使用：if (i > 0 && nums[i] == nums[i - 1]) continue;
    1）举个例子，当遇见{-1.-1，2}这个元组时，当i处于第一个-1时，该元组不会被去除，而是被记录在数组中，
    包括-1开头的其他元组也被记录在内，比如{-1,0,1}这些都会被记录；等到i位于第二个-1时，因为-1开头的
    一些元组已经被收集，比如{-1,0,1}，那么就不需要再次记录，所以就可以跳过这次循环，将i+1；
    2）除此之外，因为要i和i-1做判断，为了防止越界，需要加一个判定条件i>0，不然i<0会使数组越界。
    3）因为数组已经是排好序的，所以相同元素只会出现在一起，而不会跳着出现，所以只用判断连着的
    几个数字是否相同即可

b和c如何去重？
    比如以下排序-2,-1,-1,-1,-1,...,3,3,3,3,3
    此时，i处于-2的位置，left处于第一个-1的位置，right处于最后一个3的位置，那么{-2,-1,3}已经被收录，那么
    剩下的-1和3就必须要跳过，所以b和c的去重必须在第一个三元组找到以后再去判断，否则可能会跳过整个数组不记录
    while (right > left and nums[right] == nums[right - 1]) right--;
    while (right > left and nums[left] == nums[left + 1]) left++;
    直到left和right处于最后一个-1和第一个3的位置
    因为该元组已经被收录，所以缩减指针，求其他以-2开头的元组
*/
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> vec;

        if (nums.size() < 3) return vec;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return vec;  // 排序后数组第一个元素必须小于0，否则不可能达成三数之和等于0的条件

            if (i > 0 and nums[i] == nums[i - 1]) continue; // 对a去重

            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    vec.push_back({ nums[i], nums[left], nums[right] });
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left and nums[right] == nums[right - 1]) right--;
                    while (right > left and nums[left] == nums[left + 1]) left++;

                    right--;
                    left++;
                }
            }
        }
        return vec; 
    }
};