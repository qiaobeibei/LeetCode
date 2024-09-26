/*
����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] 
���� i != j��i != k �� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ��
���㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
*/

#include <iostream>
#include <vector>
#include <algorithm>


// ˫ָ��
/*
���ȥ�أ�
����е���Ԫ�鲻������ͬ�ģ������Ѿ���һ��{3,-2,-1},�Ͳ�������{-2,-1,3}�ȵȡ�����
��Ҫ������������ȥ�أ�����a��b��c��Ӧ����nums[i]��nums[left]��nums[right],
a ����ظ�����ô�죬a��nums�������Ԫ�أ���ôӦ��ֱ������ȥ��
��������һ�����⣬���ж� nums[i] �� nums[i + 1]�Ƿ���ͬ�������ж� nums[i] �� nums[i-1] �Ƿ���ͬ��
���ʹ�����´������ȥ�أ�if (nums[i] == nums[i + 1]) continue;
    ��ô���ܻ�����{-1, -1 ,2} �������ݣ�����������һ��-1 ��ʱ���ж� ��һ��Ҳ��-1�����������ݾ�pass�ˣ�
    ���ᱻ��¼�� ������������-1��ͷ����Ԫ�鶼�ᱻȥ��������{-1,0,-1}��һ��Ҳ�ռ������ˣ�
��ȷ��ȥ��Ӧ��ʹ�ã�if (i > 0 && nums[i] == nums[i - 1]) continue;
    1���ٸ����ӣ�������{-1.-1��2}���Ԫ��ʱ����i���ڵ�һ��-1ʱ����Ԫ�鲻�ᱻȥ�������Ǳ���¼�������У�
    ����-1��ͷ������Ԫ��Ҳ����¼���ڣ�����{-1,0,1}��Щ���ᱻ��¼���ȵ�iλ�ڵڶ���-1ʱ����Ϊ-1��ͷ��
    һЩԪ���Ѿ����ռ�������{-1,0,1}����ô�Ͳ���Ҫ�ٴμ�¼�����ԾͿ����������ѭ������i+1��
    2������֮�⣬��ΪҪi��i-1���жϣ�Ϊ�˷�ֹԽ�磬��Ҫ��һ���ж�����i>0����Ȼi<0��ʹ����Խ�硣
    3����Ϊ�����Ѿ����ź���ģ�������ͬԪ��ֻ�������һ�𣬶��������ų��֣�����ֻ���ж����ŵ�
    ���������Ƿ���ͬ����

b��c���ȥ�أ�
    ������������-2,-1,-1,-1,-1,...,3,3,3,3,3
    ��ʱ��i����-2��λ�ã�left���ڵ�һ��-1��λ�ã�right�������һ��3��λ�ã���ô{-2,-1,3}�Ѿ�����¼����ô
    ʣ�µ�-1��3�ͱ���Ҫ����������b��c��ȥ�ر����ڵ�һ����Ԫ���ҵ��Ժ���ȥ�жϣ�������ܻ������������鲻��¼
    while (right > left and nums[right] == nums[right - 1]) right--;
    while (right > left and nums[left] == nums[left + 1]) left++;
    ֱ��left��right�������һ��-1�͵�һ��3��λ��
    ��Ϊ��Ԫ���Ѿ�����¼����������ָ�룬��������-2��ͷ��Ԫ��
*/
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> vec;

        if (nums.size() < 3) return vec;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return vec;  // ����������һ��Ԫ�ر���С��0�����򲻿��ܴ������֮�͵���0������

            if (i > 0 and nums[i] == nums[i - 1]) continue; // ��aȥ��

            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    vec.push_back({ nums[i], nums[left], nums[right] });
                    // ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮�󣬶�b �� cȥ��
                    while (right > left and nums[right] == nums[right - 1]) right--;
                    while (right > left and nums[left] == nums[left + 1]) left++;

                    right--;
                    left++;
                }
            }
        }
        return vec; 
    }
};