/*
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

// ǰ��׺�ֽ�
// �������ڡ�ˮ�ĸ߶�����������ϵ͵����Ͼ�������ĳ��λ���ܽ���ˮ��ǰ������ߴ��ڱ����ߵ����ӣ��γ������ϣ���
// �����ұߴ��ڱ����ߵ����ӣ��γ������ϣ�����װˮ�ĸ߶����������ϵ���С�߶Ⱦ�����
// �����ǰλ�������������м䣬˵����ǰλ�õĸ߶ȿ϶�С�ڵ���������ϣ��൱��һ��ˮ���м����һ��Сľ�飬
// ��Сľ�鴹ֱ�߶����ж��ٵ�λˮ�����ˮ����ʵ��������������Сֵ��ȥ���ľ��ĸ߶ȣ����ľ���������Сֵ
// һ����˵��û��ˮ�ܹ������ľ�����棬�൱�����ľ��Ķ�����ˮ�档

// ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        std::vector<int> pre_max( n,0);
        // ����ǰ׺�ͣ�pre_max[i]���ڴ�height[0]~height[i]�����ֵ
        pre_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            pre_max[i] = height[i] > pre_max[i - 1] ? height[i] : pre_max[i - 1];
        }
        // �����׺�ͣ�suf_max[i]���ڴ�height[n-1]~height[i]�����ֵ
        std::vector<int> suf_max( n,0 );
        suf_max[n-1] = height[n - 1];
        for (int i = n-2; i >= 0; --i) {
            suf_max[i] = height[i] > suf_max[i + 1] ? height[i] : suf_max[i + 1];
        }
        // �ܳ˶�����ˮ���ǵ�ǰλ�ô������ǰ׺������׺����Сֵ��ȥ��ǰλ�ô��ĸ߶�
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            ans += std::min(pre_max[i], suf_max[i]) - height[i];
        }

        return ans;
    }
};


// ˫ָ��
// ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
class Solution {
public:
    int trap(std::vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int pre_max = 0;
        int suf_max = 0;

        while (left <= right) {
            pre_max = std::max(pre_max, height[left]);
            suf_max = std::max(suf_max, height[right]);
            if (pre_max < suf_max) {
                ans += pre_max - height[left++];
            }
            else{
                ans += suf_max - height[right--];
            }
        }

        return ans;
    }
};
