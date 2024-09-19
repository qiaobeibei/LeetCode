/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。
*/

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        std::vector<int> vec(26, 0);
        for (char x : magazine)
            vec[x - 'a']++;

        for (char y : ransomNote)
            vec[y - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (vec[i] < 0)
                return false;
        }
        return true;
    }
};