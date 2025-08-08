/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/

#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

// 前后缀分解
// 核心在于“水的高度由左右两侧较低的屏障决定”，某个位置能接雨水的前提是左边存在比它高的柱子（形成左屏障）；
// 并且右边存在比它高的柱子（形成右屏障），则装水的高度由左右屏障的最小高度决定。
// 如果当前位置在两个屏障中间，说明当前位置的高度肯定小于等于最高屏障，相当于一个水盆中间放了一个小木块，
// 求小木块垂直高度能有多少单位水，这个水量其实就是左右屏障最小值减去这个木块的高度，如果木块和屏障最小值
// 一样，说明没有水能够在这个木块上面，相当于这个木块的顶端在水面。

// 时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        std::vector<int> pre_max( n,0);
        // 计算前缀和，pre_max[i]等于从height[0]~height[i]的最大值
        pre_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            pre_max[i] = height[i] > pre_max[i - 1] ? height[i] : pre_max[i - 1];
        }
        // 计算后缀和，suf_max[i]等于从height[n-1]~height[i]的最大值
        std::vector<int> suf_max( n,0 );
        suf_max[n-1] = height[n - 1];
        for (int i = n-2; i >= 0; --i) {
            suf_max[i] = height[i] > suf_max[i + 1] ? height[i] : suf_max[i + 1];
        }
        // 能乘多少雨水就是当前位置处的最大前缀和最大后缀的最小值减去当前位置处的高度
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            ans += std::min(pre_max[i], suf_max[i]) - height[i];
        }

        return ans;
    }
};


// 双指针
// 时间复杂度O(n),空间复杂度O(1)
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
