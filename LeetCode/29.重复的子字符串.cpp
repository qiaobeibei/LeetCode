/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成
*/
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// KMP解法
class Solution {
public:
    vector<int> GetNext(string p) {
        std::size_t len = p.length();
        vector<int> next(len + 1, 0); 

        for (int j = 1, i = 0; j < len; j++) {
            while (i > 0 and p[i] != p[j]) i = next[i];
            if (p[i] == p[j]) i++;
            next[j + 1] = i;
        }
        next[0] = -1;
        return next;
    }

    void GetNextVal(vector<int>& next, string p) {
        for (int j = 1; j < p.length(); j++) {
            if (p[next[j]] == p[j])
                next[j] = next[next[j]];
        }
    }

    bool repeatedSubstringPattern(string s) {
        vector<int> next = GetNext(s);
        GetNextVal(next, s);
        // 字符串排除最长公共前后缀后的剩余字符串如果可以被主串整除，那么必定是最长重复子串
        // 由重复子串组成的字符串中，最长相等前后缀不包含的子串就是最小重复子串
        if (s.size() % (s.size() - next[s.size()] ) == 0 and next[s.size()] != 0)
            return true;
        return false;
    }
};


// 移动匹配 + KMP
// 将字符串s赋值给a和b，并将a的首字符和b的尾字符去除，如果a+b中有s的子串，那么s必定可以通过子串组成
class KMP {
public:
    vector<int> GetNext(string p) {
        std::size_t len = p.length();
        vector<int> next(len + 1, 0); // 初始化next数组，大小等于模式串长度+1

        // i是最长公共前后缀长度，j是模式串指针,从第二个字符开始
        // 因为如果模式串第一个字符与主串不匹配，那么主串会直接从主串的下一个字符开始重新匹配模式串
        for (int j = 1, i = 0; j < len; j++) {
            // i > 1时，说明在模式串中至少找到了一组相同的前后缀，此时判断该前后缀的下一个字符
            // （不是前后缀的最后一个字符）是否相同，如果相同，那么next[j] = i + 1
            // 如果不同，那么需要在该前后缀中找到最大公共前后缀的长度，作为新的next值
            // 可参考力扣的题目解析
            // 因为前后缀中的最大公共前后缀的长度相同，我们只需要在前缀中查找，因为i一定小于j
            // 所以该长度以及被next数组记录，该长度为next[i]，所以i= next[i]
            while (i > 0 and p[i] != p[j]) i = next[i];
            // 如果next[j-1]代表的公共前后缀后一位字符仍然相同，那么next[j]=next[j-1]+1,也就是next[j]=i+1，这里i++
            if (p[i] == p[j]) i++;
            // 因为我们是从j开始的，所以是next[j+1]
            next[j + 1] = i;
        }
        // 将模式串第一个字符不匹配的next值设为-1，方便主串跳过字符，该字符不能被模式串以任何组合匹配
        next[0] = -1;
        return next;
    }

    void GetNextVal(vector<int>& next, string p) {
        for (int j = 1; j < p.length(); j++) {
            if (p[next[j]] == p[j])
                next[j] = next[next[j]];
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;

        vector<int> next = GetNext(needle);
        vector<int> res;
        GetNextVal(next, needle);
        bool remake = false;

        for (int i = 0, j = 0; i < haystack.size(); i++) {
            // 匹配失败，根据next数组调整模式串指针j的位置
            while (j > 0 and haystack[i] != needle[j]) {
                j = next[j];
                if (j == -1) { // j == -1 时，表示模式串第一个字符也匹配失败，直接跳出循环，主串指针右移匹配下一个字符
                    j++;
                    remake = true;
                    break;
                }
            }

            if (remake) {
                remake = false;
                continue;
            }

            // 当前字符匹配成功，模式串指针右移一位
            if (haystack[i] == needle[j]) j++;
            // j到了子串末尾，说明完全匹配到了一个答案，记录结果，然后继续调整j寻找
            if (j == needle.size()) {
                res.push_back(i - j + 1);
                j = next[j];
            }

        }
        return res.size() > 0 ? res[0] : -1;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        if (s.size() <= 1) return true;
        std::string m = s, n = s;
        m.erase(m.begin());
        n.pop_back();
        int res = KMP().strStr(m + n, s);

        return res != -1 ? true : false;
    }
};