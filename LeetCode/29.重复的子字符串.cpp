/*
����һ���ǿյ��ַ��� s ������Ƿ����ͨ��������һ���Ӵ��ظ���ι���
*/
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// KMP�ⷨ
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
        // �ַ����ų������ǰ��׺���ʣ���ַ���������Ա�������������ô�ض�����ظ��Ӵ�
        // ���ظ��Ӵ���ɵ��ַ����У�����ǰ��׺���������Ӵ�������С�ظ��Ӵ�
        if (s.size() % (s.size() - next[s.size()] ) == 0 and next[s.size()] != 0)
            return true;
        return false;
    }
};


// �ƶ�ƥ�� + KMP
// ���ַ���s��ֵ��a��b������a�����ַ���b��β�ַ�ȥ�������a+b����s���Ӵ�����ôs�ض�����ͨ���Ӵ����
class KMP {
public:
    vector<int> GetNext(string p) {
        std::size_t len = p.length();
        vector<int> next(len + 1, 0); // ��ʼ��next���飬��С����ģʽ������+1

        // i�������ǰ��׺���ȣ�j��ģʽ��ָ��,�ӵڶ����ַ���ʼ
        // ��Ϊ���ģʽ����һ���ַ���������ƥ�䣬��ô������ֱ�Ӵ���������һ���ַ���ʼ����ƥ��ģʽ��
        for (int j = 1, i = 0; j < len; j++) {
            // i > 1ʱ��˵����ģʽ���������ҵ���һ����ͬ��ǰ��׺����ʱ�жϸ�ǰ��׺����һ���ַ�
            // ������ǰ��׺�����һ���ַ����Ƿ���ͬ�������ͬ����ônext[j] = i + 1
            // �����ͬ����ô��Ҫ�ڸ�ǰ��׺���ҵ���󹫹�ǰ��׺�ĳ��ȣ���Ϊ�µ�nextֵ
            // �ɲο����۵���Ŀ����
            // ��Ϊǰ��׺�е���󹫹�ǰ��׺�ĳ�����ͬ������ֻ��Ҫ��ǰ׺�в��ң���Ϊiһ��С��j
            // ���Ըó����Լ���next�����¼���ó���Ϊnext[i]������i= next[i]
            while (i > 0 and p[i] != p[j]) i = next[i];
            // ���next[j-1]����Ĺ���ǰ��׺��һλ�ַ���Ȼ��ͬ����ônext[j]=next[j-1]+1,Ҳ����next[j]=i+1������i++
            if (p[i] == p[j]) i++;
            // ��Ϊ�����Ǵ�j��ʼ�ģ�������next[j+1]
            next[j + 1] = i;
        }
        // ��ģʽ����һ���ַ���ƥ���nextֵ��Ϊ-1���������������ַ������ַ����ܱ�ģʽ�����κ����ƥ��
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
            // ƥ��ʧ�ܣ�����next�������ģʽ��ָ��j��λ��
            while (j > 0 and haystack[i] != needle[j]) {
                j = next[j];
                if (j == -1) { // j == -1 ʱ����ʾģʽ����һ���ַ�Ҳƥ��ʧ�ܣ�ֱ������ѭ��������ָ������ƥ����һ���ַ�
                    j++;
                    remake = true;
                    break;
                }
            }

            if (remake) {
                remake = false;
                continue;
            }

            // ��ǰ�ַ�ƥ��ɹ���ģʽ��ָ������һλ
            if (haystack[i] == needle[j]) j++;
            // j�����Ӵ�ĩβ��˵����ȫƥ�䵽��һ���𰸣���¼�����Ȼ���������jѰ��
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