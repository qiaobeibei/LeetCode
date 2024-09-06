//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//namespace day3_2 {
//    /*
//给定一个含有 n 个正整数的数组和一个正整数 target 。
//
//找出该数组中满足其总和大于等于 target 的长度最小的
//子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
//*/
//
//
////滑动窗口
//    class Solution {
//    public:
//        int minSubArrayLen(int target, std::vector<int>& nums) {
//            if (nums.empty())  return 0;
//            else if (nums.size() == 1)  return nums[0] >= target ? 1 : 0;
//            else if (nums[0] >= target)  return 1;
//
//            int sums = 0;                                       // 定义滑动窗口值之和
//            int result = INT_MAX;
//            // left是滑动窗口左指针，right是滑动窗口右指针
//            for (int left = 0, right = 0; right <= nums.size() - 1; right++) {
//                sums += nums[right];
//                // 当前滑动窗口满足值之和大于目标值，对该窗口进行缩减操作
//                while (sums >= target) {
//                    // 记录最短窗口长度
//                    result = result < right - left + 1 ? result : right - left + 1;
//                    // 缩减窗口长度
//                    sums -= nums[left++];
//                }
//            }
//            // 若result的值不变，那么没有子串满足条件，反之，满足
//            return result == INT_MAX ? 0 : result;
//        }
//    };
//
//
//    class Solution {
//    public:
//        int minSubArrayLen(int target, std::vector<int>& nums) {
//            int sum = 0;                                        // 滑动窗口数值之和
//            int subL;                                           // 滑动窗口长度
//            int result = INT_MAX;
//            // i是滑动窗口初始位置，j是滑动窗口终端位置，二者初始值均为0
//            for (int i = 0, j = 0; j <= nums.size() - 1; j++) {
//                sum += nums[j];
//                // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
//                while (sum >= target) {
//                    subL = j - i + 1;                           // 取滑动窗口长度
//                    result = result < subL ? result : subL;     // 取窗口的最小值
//                    // result = std::min(result, subL);
//                    // 这里体现出滑动窗口的精髓之处，如果子串和大于目标值，则不断变更i（子序列的起始位置）
//                    sum -= nums[i++];
//                }
//            }
//            // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
//            return result == INT_MAX ? 0 : result;
//        }
//    };
//
//
//}