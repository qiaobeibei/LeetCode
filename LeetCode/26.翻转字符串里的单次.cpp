/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，
单词间应当仅用单个空格分隔，且不包含任何额外的空格。
*/

/*
1.移除多余空格
2.将整个字符串反转
3.将每个单词反转
*/
#include <iostream>
#include <string> 
using std::string;

class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
    }

    // 为什么要移除多余空格？
    // 输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，
    // 单词间应当仅用单个空格分隔，且不包含任何额外的空格
    void removeExtraSpaces(string& s) { //去除所有空格并在相邻单词之间添加空格, 快慢指针
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] != ' ') { // 遇到了一个单词
                // 如果 left 不为 0，说明不是第一个单词，需要在当前单词前添加一个空格，即 s[left++] = ' '
                if (left != 0) s[left++] = ' ';
                while (right < s.size() and s[right] != ' ')
                    s[left++] = s[right++];
            }
        }
        s.resize(left); // 删除多余空格后需重新调整容器大小，只包含有效字符
    }

    std::string reverseWords(std::string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            // 这里注意数组越界，必须加上right <s.size()
            while (s[right] != ' ' and right <s.size()) right++;
            reverse(s, left, right - 1);
            left = right + 1;
        }
        return s;
    }
};

