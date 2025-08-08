/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

// 单调队列(从队首到队尾单调递减)，队尾加队首出
// 之所以会保持单调性是因为，每次入队的时候会将队尾元素和预加入值进行比较，如果队尾元素是小于预加入值则会将其删除，
// 这样就能保证每次添加进队列的值都比队尾元素小

// [1,3,-1,-3,5,3,6,7] k=3


/*
注意点：
1. 入队时需要考虑!q.empty()才可以剔除队尾元素
2. 出队的判断条件是 i - q.front() >= k，当然也可以是 dq.back() - dq.front()。因为这个出队就是为了判断是否存在
比如 4 3 2 1 这种情况，队尾的元素总是大于待插入值，这时候为了保持窗口大小需要手动将队首元素剔除。但是因为这种
连续递减情况下的元素肯定会被记录在队尾，i 和队尾的元素是相同的。
3. 记录的值是 nums[dq.front()] 而不是 dq.front()
*/
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, const int k) {
        if (nums.size() < k) return {};
        
        std::vector<int> ans;
        std::deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            // 1.入（将所有队尾小于nums[i]的值去掉，并将nums[i]代表的索引加入）
            while (!q.empty() and nums[q.back()] <= nums[i]) { // 队列不为空且队尾作为索引的nums元素小于nums[i]
                q.pop_back(); // 队尾索引代表的值已经比nums[i]小了，可以直接去
            }
            q.push_back(i); 

            // 2.出（去掉超出窗口范围的索引，如果窗口是 4 3 2 的话则入的时候队尾元素一个都不会删除，所以为了保持窗口长度）
            if (i - q.front() >= k) { // dq.back() - dq.front() + 1 > k 也对
                q.pop_front();
            }
            // 3.记录（队首到队尾是单调递减的，队首就是最大值）
            if (i >= k - 1) { // 第一次记录时索引等于 k-1
                ans.push_back(nums[q.front()]);
            }
        }

        return ans;

    }
};
