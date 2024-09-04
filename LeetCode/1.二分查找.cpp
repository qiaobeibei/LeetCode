#include <iostream>
#include <vector>

/*给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写
一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。*/

//左闭右闭写法(升序)
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;                                   //左边界
        int right = nums.size() - 1;                    //右边界
        int middle = 0;                                 //中间值
        while (left <= right) {                         //左闭右闭区间中，left==right可以实现，这里应为left <= right
            middle = (left + right) / 2;
            if (nums[middle] > target)
                /*//因为nums[middle] > target，所以右边界不需要设置为middle，因为设置为middle后可能还
                会扫描一次右边界浪费资源，因为这里的右边界不可能是target，所以设置为middle-1*/
                right = middle - 1;
            else if (nums[middle] < target)
                left = middle + 1;                      //同理，不能设为middle浪费资源，设为middle+1
            else
                return middle;
        }
        return -1;
    }
};

//左闭右开写法(升序)
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;                    
        int middle = 0;                                 
        while (left < right) {                          //左闭右开区间中，left==right不可以实现，这里应为left < right
            middle = (left + right) / 2;
            if (nums[middle] > target)
                right = middle;                         //这里是左闭右开，不回扫描右边界所以应设为middle
            else if (nums[middle] < target)
                left = middle + 1;                      //左闭，所以左边界要加一，避免浪费资源
            else
                return middle;
        }
        return -1;
    }
};


//左闭右闭写法(降序)
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] < target)
                right = middle - 1;
            else if (nums[middle] > target)
                left = middle + 1;
            else
                return middle;
        }
        return -1;
    }
};