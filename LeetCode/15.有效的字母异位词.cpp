/*
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ��

1 <= s.length, t.length <= 5 * 104
s �� t ������Сд��ĸ


��λ�ʣ������ַ�����ɵ��ַ���ͬ����˳����Բ�ͬ
���磺abbc��bbac������λ��
*/

#include <iostream>
#include <string>
#include <unordered_map>

// �������
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        int hash[26];
        std::memset(hash, 0, sizeof hash);
        for (int i = 0; i < s.size(); i++) 
            hash[s[i] - 'a']++;

        for (int i = 0; i < t.size(); i++) 
            hash[t[i] - 'a']--;

        for (int j = 0; j < 26; j++)
            if (hash[j]) return false;
        return true;
    }
};


// ʹ��map��c++11������
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;
        // һ�ֻ��ڹ�ϣ��ļ�ֵ������������֤Ԫ�ص�����
        std::unordered_map<char, int> dic;  
        for (char c : s) dic[c] += 1; // ��s�е�Ԫ�����ȡ�������洢��dic��
        for (char c : t) dic[c] -= 1; // ��t�е�Ԫ�����ȡ�������dic������ͬ��Ԫ�أ����Ԫ�ص�ֵ��һ
        for (const auto kv : dic) if (kv.second != 0) return false;
        return true;
    }
};