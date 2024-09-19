/*
����һ����������nums��һ������Ŀ��ֵtarget�������ڸ��������ҳ���ΪĿ��ֵtarget �����������������������ǵ�
�����±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸣������㲻��ʹ��������ͬ��Ԫ�ء�

����԰�����˳�򷵻ش𰸡�
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// ������������vectorʱ��������{}�򻯷��أ�return {}��Ч��std::vector<int>()
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) // map�д���ƥ��ֵ
                return { iter->second, i };
            map[nums[i]] = i;
        }
        return {};
    }
};