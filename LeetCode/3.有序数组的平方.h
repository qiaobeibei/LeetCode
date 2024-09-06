//#include <iostream>
//#include <vector>
//
//namespace day3 {
//    /*
//给你一个按 非递减顺序（递增） 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//*/
//
//
///*
//如果数组的元素都是正数，那么每个元素平方后仍按升序排列，但如果有负元素，负元素平方后的值可
//能会比其他正数元素更大。
//
//解法1：最直观的想法，莫过于：每个数平方之后，排个序；这个时间复杂度是 O(n + nlogn)，
//可以说是O(nlogn)的时间复杂度，但为了和下面双指针法算法时间复杂
//
//解法2：数组其实是有序的， 只不过负数平方之后可能成为最大数了。
//那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。
//此时可以考虑双指针法了，i指向起始位置，j指向终止位置。
//定义一个新数组result，和A数组一样的大小，让k指向result数组终止位置。
//
//如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j]; 。
//
//如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i]; 。
//*/
//
////双指针(初始数组升序排列)
//    class Solution {
//    public:
//        std::vector<int> sortedSquares(std::vector<int>& nums) {
//            std::vector<int> result(nums.size());
//            int k = nums.size() - 1;               //新数组元素的位序，从最大值开始存储
//            //i++,j__不放在循环中,取决于首尾哪个元素的值被放进了新数组result中
//            for (int i = 0, j = nums.size() - 1; i <= j;) {
//                //数组两端的值的平方肯定有一个是最大值，这里首先比较两端的大小，然后逐渐逼近中间
//                if (nums[i] * nums[i] > nums[j] * nums[j])
//                    result[k--] = nums[i] * nums[i++];
//                else
//                    result[k--] = nums[j] * nums[j--];
//            }
//            return result;
//        }
//    };
//
//
//    class Solution {
//    public:
//        std::vector<int> sortedSquares(std::vector<int>& nums) {
//            std::vector<int> result(nums.size());
//            int k = nums.size() - 1;
//            for (int i = 0, j = nums.size() - 1; i <= j;) {
//                if (nums[i] * nums[i] < nums[j] * nums[j])
//                    result[k--] = nums[j] * nums[j--];
//                else
//                    result[k--] = nums[i] * nums[i++];
//            }
//            return result;
//        }
//    };
//}