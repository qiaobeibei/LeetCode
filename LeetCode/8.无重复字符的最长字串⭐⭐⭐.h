/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。*/

#pragma once
#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>

// 滑动窗口
//滑动窗口算法的思路是这样：
//1、我们在字符串 S 中使用双指针中的左右指针技巧，初始化 left = right = 0，把索引闭区间[left, right] 称为一个「窗口」。
//2、我们先不断地增加 right 指针扩大窗口[left, right]，直到窗口中的字符串符合要求（包含了 T 中的所有字符）。
//3、此时，我们停止增加 right，转而不断增加 left 指针缩小窗口[left, right]，直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）。
//   同时，每次增加 left，我们都要更新一轮结果。
//4、重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。
//这个思路其实也不难，第 2 步相当于在寻找一个「可行解」，然后第 3 步在优化这个「可行解」，最终找到最优解。
// 左右指针轮流前进，窗口大小增增减减，窗口不断向右滑动。


// 注意点：erase的是s[left]而不是c
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) return 0;
        else if (s.length() == 1) return 1;
       
        // aaavcgwrgdddddgethuk
        int ans = 0;
        std::unordered_set<int> window;
        for (int left = 0, right = 0; right < s.length(); right++) {
            char c = s[right];
            
            while (window.find(c) != window.end()) { // 在窗口内可以找到 c
                window.erase(s[left]);
                left++;
            }

            window.emplace(c);
            ans = std::max(ans, right - left + 1);
        }
       
        return ans;
    }
};


