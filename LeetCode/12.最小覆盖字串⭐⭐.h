/*
����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t 
�����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
*/

#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

// ��������
// ʹ�ù�ϣ�������ڶ�ε���isCovered����ʱ����ж�β�ѯ����Ϊ��ϣ����ڹ�ϣ��ͻ����ϣ��������⣬����
// �ڽ����ڲ�ѯ��ʱ��Ч�ʻ���������

/*
ע��㣺
1.int ans_left = -1, ans_right = s.length();����������
2.  if (right - left < ans_right - ans_left) { // ��һ���ж�ʱ�϶��� right - left < ans_right - ans_left
            ans_left = left;
            ans_right = right;
        }
     �öδ������ڼ�¼�ִ����Ⱥ����
3. substr���÷�
4. isCovered���������жϼǵü�<=������<��i <= 'Z'��
*/

class Solution {
private:
    bool isCovered(std::unordered_map<char, int> cntS, std::unordered_map<char, int> cntT) {
        for (char i = 'A'; i <= 'Z'; i++) {
            if (cntS[i] < cntT[i]) { // cntS[i] >cntT[i] ������
                return false;
            }
        }

        for (int i = 'a'; i <= 'z'; i++) {
            if (cntS[i] < cntT[i]) {
                return false;
            }
        }

        return true;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() < t.size()) return {};

        int ans_left = -1, ans_right = s.length(); // �൱�ڵ������ĳ��׺ͳ�β
        std::string ans;
        std::unordered_map<char, int> cntS;
        std::unordered_map<char, int> cntT;

        for (char& c : t) { // ���ַ���t�������ַ��ĳ��ִ�����¼����ϣ��
            cntT[c]++;
        }

        for (int left = 0, right = 0; right < s.length(); right++) {
            cntS[s[right]]++; // �Ҷ˵���ĸ�����Ӵ�
            while (isCovered(cntS, cntT)) { // ����
                if (right - left < ans_right - ans_left) { // ��һ���ж�ʱ�϶��� right - left < ans_right - ans_left
                    ans_left = left;
                    ans_right = right;
                }
                cntS[s[left]]--;
                left++;
            }
        }

        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};


// ʹ������
class Solution {
private:
    bool isCovered(int cntS[], int cntT[]) {
        for (int i = 'A'; i <= 'Z'; i++) {
            if (cntS[i] < cntT[i]) {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (cntS[i] < cntT[i]) {
                return false;
            }
        }

        return true;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        int arr_left = -1;
        int arr_right = s.length();
        int cntS[128] = {};
        int cntT[128] = {};

        for (char& c : t) {
            cntT[c]++;
        }

        for (int left = 0, right = 0; right < s.length(); right++) {
            cntS[s[right]]++;
            while (isCovered(cntS, cntT)) {
                if (right - left < arr_right - arr_left) {
                    arr_left = left;
                    arr_right = right;
                }

                cntS[s[left]]--;
                left++;
            }
        }

        return arr_left < 0 ? "" : s.substr(arr_left, arr_right - arr_left + 1);
    }
};
