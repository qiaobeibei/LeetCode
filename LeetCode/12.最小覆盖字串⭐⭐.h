/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 
所有字符的子串，则返回空字符串 "" 。
*/

#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

// 滑动窗口
// 使用哈希表，但是在多次调用isCovered函数时会进行多次查询，因为哈希表存在哈希冲突、哈希计算等问题，所以
// 在仅用于查询的时候，效率会慢于数组

/*
注意点：
1.int ans_left = -1, ans_right = s.length();别忘记作用
2.  if (right - left < ans_right - ans_left) { // 第一次判断时肯定是 right - left < ans_right - ans_left
            ans_left = left;
            ans_right = right;
        }
     该段代码用于记录字串长度和起点
3. substr的用法
4. isCovered中条件的判断记得加<=而不是<（i <= 'Z'）
*/

class Solution {
private:
    bool isCovered(std::unordered_map<char, int> cntS, std::unordered_map<char, int> cntT) {
        for (char i = 'A'; i <= 'Z'; i++) {
            if (cntS[i] < cntT[i]) { // cntS[i] >cntT[i] 代表涵盖
                return false;
            }
        }

        for (int i = 'a'; i <= 'z'; i++) {
            if (cntS[i] < cntT[i]) {
                return false;
            }
        }

        return true;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) return {};

        int ans_left = -1, ans_right = s.length(); // 相当于迭代器的超首和超尾
        std::string ans;
        std::unordered_map<char, int> cntS;
        std::unordered_map<char, int> cntT;

        for (char& c : t) { // 将字符串t中所有字符的出现次数记录至哈希表
            cntT[c]++;
        }

        for (int left = 0, right = 0; right < s.length(); right++) {
            cntS[s[right]]++; // 右端点字母移入子串
            while (isCovered(cntS, cntT)) { // 涵盖
                if (right - left < ans_right - ans_left) { // 第一次判断时肯定是 right - left < ans_right - ans_left
                    ans_left = left;
                    ans_right = right;
                }
                cntS[s[left]]--;
                left++;
            }
        }

        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};


// 使用数组
class Solution {
private:
    bool isCovered(int cntS[], int cntT[]) {
        for (int i = 'A'; i <= 'Z'; i++) {
            if (cntS[i] < cntT[i]) {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (cntS[i] < cntT[i]) {
                return false;
            }
        }

        return true;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        int arr_left = -1;
        int arr_right = s.length();
        int cntS[128] = {};
        int cntT[128] = {};

        for (char& c : t) {
            cntT[c]++;
        }

        for (int left = 0, right = 0; right < s.length(); right++) {
            cntS[s[right]]++;
            while (isCovered(cntS, cntT)) {
                if (right - left < arr_right - arr_left) {
                    arr_left = left;
                    arr_right = right;
                }

                cntS[s[left]]--;
                left++;
            }
        }

        return arr_left < 0 ? "" : s.substr(arr_left, arr_right - arr_left + 1);
    }
};
