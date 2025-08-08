/*
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ��
����ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

/*
[1, 10] �� [2, 5] �ϲ�Ϊ [1, 10]����Ϊ 10 > 2 && 10 > 5��
[1, 10] �� [3, 11] �ϲ�Ϊ [1, 11]����Ϊ 10 > 3 && 10 < 11���ϲ�������¡�
[1, 11] �� [13, 14] ���ܺϲ�����Ϊ 11 < 13, �����ڽ��β����ans = {[1, 11], [13, 14]}

���vector���бȽ�ʱ�����Ȼ�Ƚϵ�һ�����֣���һ������С������ǰ�棬�����һ��������ͬ������ݵڶ������ִ�С��
{2, 3},{1, 5},{2, 1}�����������{1,5}{2,1}{2,5}
*/


/*
ע��㣺
�ǵ��ȶ������������
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
