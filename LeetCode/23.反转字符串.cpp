/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            int temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
};

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            std::tie(s[left], s[right]) = std::make_tuple(s[right], s[left]);
            left++, right--;
        }
    }
};

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {                 
            std::swap(s[left++], s[right--]);
        }
    }
};