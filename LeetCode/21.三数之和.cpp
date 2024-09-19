/*
����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] 
���� i != j��i != k �� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ��
���㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
*/

#include <iostream>
#include <vector>
#include <unordered_map>


// ˫ָ��
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3) return {};
        int len = 0;
        std::vector<std::vector<int>> vec;

        for (int i = 0, j = 1, k = nums.size() - 1;;) {    
            if (nums[i] + nums[j] + nums[k] == 0)
                vec[len++] = { nums[i], nums[j++], nums[k] };
                
            if (j >= k and i < k - 1) {
                i++;
                j = i + 1;
            }
            else if (i >= k - 1)
                break;
        }

        return vec;
        
    }
};