//
//#include <iostream>
//#include <vector>
//
//namespace day2 {
//    /*
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。
//然后返回 nums 中与 val 不同的元素的数量。
//
//假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
//
//1.更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
//2.返回 k。
//*/
//
//
///*
//本来通过两个for循环实现：1.遍历数组，寻找目标值  2.覆盖目标值，将数组后面的元素向前移动一位
//双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
//
//定义快慢指针
//
//快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
//慢指针：指向更新 新数组下标的位置
//*/
//
////双指针,时间复杂度O(n)
//    class Solution {
//    public:
//        int removeElement(std::vector<int>& nums, int val) {
//            //fast指针新数组需要的元素，slow是新数组元素的下标
//            int slow = 0;
//            for (int fast = 0; fast < nums.size(); fast++) {
//                if (nums[fast] != val)
//                    nums[slow++] = nums[fast];
//            }
//            //因为每一次添加完新元素之后，slow都会++，所以此时返回的slow不用+1，直接用来表示新数组的大小
//            return slow;
//        }
//    };
//}