/*
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������

��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
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