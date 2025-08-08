/*
����һ���ַ��� s �����㷴ת�ַ����� ���� ��˳��

���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����

���� ���� ˳��ߵ��� ���� ֮���õ����ո����ӵĽ���ַ�����

ע�⣺�����ַ��� s�п��ܻ����ǰ���ո�β��ո���ߵ��ʼ�Ķ���ո񡣷��صĽ���ַ����У�
���ʼ�Ӧ�����õ����ո�ָ����Ҳ������κζ���Ŀո�
*/

/*
1.�Ƴ�����ո�
2.�������ַ�����ת
3.��ÿ�����ʷ�ת
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

    // ΪʲôҪ�Ƴ�����ո�
    // �����ַ��� s�п��ܻ����ǰ���ո�β��ո���ߵ��ʼ�Ķ���ո񡣷��صĽ���ַ����У�
    // ���ʼ�Ӧ�����õ����ո�ָ����Ҳ������κζ���Ŀո�
    void removeExtraSpaces(string& s) { //ȥ�����пո������ڵ���֮����ӿո�, ����ָ��
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] != ' ') { // ������һ������
                // ��� left ��Ϊ 0��˵�����ǵ�һ�����ʣ���Ҫ�ڵ�ǰ����ǰ���һ���ո񣬼� s[left++] = ' '
                if (left != 0) s[left++] = ' ';
                while (right < s.size() and s[right] != ' ')
                    s[left++] = s[right++];
            }
        }
        s.resize(left); // ɾ������ո�������µ���������С��ֻ������Ч�ַ�
    }

    std::string reverseWords(std::string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            // ����ע������Խ�磬�������right <s.size()
            while (s[right] != ' ' and right <s.size()) right++;
            reverse(s, left, right - 1);
            left = right + 1;
        }
        return s;
    }
};

