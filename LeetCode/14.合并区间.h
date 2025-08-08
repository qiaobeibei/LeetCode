/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

/*
[1, 10] 和 [2, 5] 合并为 [1, 10]。因为 10 > 2 && 10 > 5。
[1, 10] 和 [3, 11] 合并为 [1, 11]。因为 10 > 3 && 10 < 11，合并后还需更新。
[1, 11] 和 [13, 14] 不能合并，因为 11 < 13, 故添在结果尾部。ans = {[1, 11], [13, 14]}

多个vector进行比较时，首先会比较第一个数字，第一个数字小的排在前面，如果第一个数字相同，则根据第二个数字大小：
{2, 3},{1, 5},{2, 1}经过排序后是{1,5}{2,1}{2,5}
*/


/*
注意点：
记得先对数组进行排序
*/
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty()) {
                ans.emplace_back(std::vector<int>(intervals[i]));
            }
            else {
                int first_left = ans.back()[1];
                int second_left = intervals[i][0];
                int second_right = intervals[i][1];
                if (first_left >= second_left and first_left < second_right) {
                    ans.back()[1] = second_right;
                }
                else if (first_left < second_left) {
                    ans.emplace_back(std::vector<int>(intervals[i]));
                }
            }
        }
        return ans;
    }
};
