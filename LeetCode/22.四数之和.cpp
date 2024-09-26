/*
����һ���� n ��������ɵ����� nums ����һ��Ŀ��ֵ target �������ҳ���������������ȫ��
�����Ҳ��ظ�����Ԫ�� [nums[a], nums[b], nums[c], nums[d]] ����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����

0 <= a, b, c, d < n
a��b��c �� d ������ͬ
nums[a] + nums[b] + nums[c] + nums[d] == target
����԰�����˳�򷵻ش� ��
*/


// ˫ָ�뷨
/*
����֮�ͺ�����֮���и��������𣺼�֦
1�����ﲻ�ܸ���nums[k] > target��ֱ���ж��޷������������������-4��-2��0��0 target=-6����ʱ-4>-6,��{-4��-2��0��0}��������
����ֻ�е�target > 0ʱ����ʹ�����������

2�����ж���Ҫ��֦ʱ����ò�Ҫֱ��return res����Ϊ��i�ļ�֦��return��ֱ�ӷ��ؿ��ܻ����һЩԪ�飬��Ϊi�ǵڶ���ѭ��������ֱ��
�жϲ�����������break�����ڶ���ѭ���� ����k�������֦�������㣬��ô����ֱ��return����Ϊkǰ��û�б��ѭ���ˣ�k��һ��ֵ�������㣬
��ôʣ�µ�ֵҲ����������
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