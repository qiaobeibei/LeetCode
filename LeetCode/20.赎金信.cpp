/*
���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�

������ԣ����� true �����򷵻� false ��

magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�
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