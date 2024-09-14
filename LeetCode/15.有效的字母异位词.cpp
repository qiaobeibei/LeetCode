/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母


异位词：两个字符串组成的字符相同，但顺序可以不同
比如：abbc和bbac就是异位词
*/

#include <iostream>
#include <string>
#include <unordered_map>

// 数组求解
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


// 使用map和c++11新特性
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;
        // 一种基于哈希表的键值对容器，不保证元素的排序
        std::unordered_map<char, int> dic;  
        for (char c : s) dic[c] += 1; // 将s中的元素逐个取出，并存储至dic中
        for (char c : t) dic[c] -= 1; // 将t中的元素逐个取出，如果dic中有相同的元素，则该元素的值减一
        for (const auto kv : dic) if (kv.second != 0) return false;
        return true;
    }
};