/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
*/

#include <iostream>
#include <string>

// 双指针
class Solution {
public:
    std::string reverseString(std::string& s, int start, int end) {
        int left = start, right = end;
        while (left <= right) {
            std::swap(s[left++], s[right--]);
        }
        return s;
    }
    std::string reverseStr(std::string s, int k) {
        if (s.size() < k) return reverseString(s, 0, s.size()-1);
        if (s.size() >= k and s.size() < 2 * k) return reverseString(s,0,k-1);

        for (int i = 0, j = 2 * k;;) {
            reverseString(s, i, i + k - 1);
            if (s.size() - j < k)
                return reverseString(s, j, s.size() - 1);
            else if (s.size() - j >= k and s.size() - j < 2 * k)
                return reverseString(s, j, j + k - 1);
            else {
                i = j;
                j += 2 * k;
            }
               
        }

    }
};


class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k <= s.size())
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.end());
        }
        return s;
    }
};

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        int pos = 0, len = s.size();
        while (pos < s.size()) {
            if (pos + k <= len) reverse(s.begin() + pos, s.begin() + pos + k);
            else reverse(s.begin() + pos, s.end());
            pos += 2 * k;
        }
        return s;

    }
};