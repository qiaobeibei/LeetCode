/*
����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���

���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
*/

#include <iostream>
#include <string>

// ˫ָ��
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