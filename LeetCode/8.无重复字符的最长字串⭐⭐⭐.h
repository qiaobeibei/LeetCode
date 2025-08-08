/*����һ���ַ��� s �������ҳ����в������ظ��ַ��� � �Ӵ� �ĳ��ȡ�*/

#pragma once
#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>

// ��������
//���������㷨��˼·��������
//1���������ַ��� S ��ʹ��˫ָ���е�����ָ�뼼�ɣ���ʼ�� left = right = 0��������������[left, right] ��Ϊһ�������ڡ���
//2�������Ȳ��ϵ����� right ָ�����󴰿�[left, right]��ֱ�������е��ַ�������Ҫ�󣨰����� T �е������ַ�����
//3����ʱ������ֹͣ���� right��ת���������� left ָ����С����[left, right]��ֱ�������е��ַ������ٷ���Ҫ�󣨲����� T �е������ַ��ˣ���
//   ͬʱ��ÿ������ left�����Ƕ�Ҫ����һ�ֽ����
//4���ظ��� 2 �͵� 3 ����ֱ�� right �����ַ��� S �ľ�ͷ��
//���˼·��ʵҲ���ѣ��� 2 ���൱����Ѱ��һ�������н⡹��Ȼ��� 3 �����Ż���������н⡹�������ҵ����Ž⡣
// ����ָ������ǰ�������ڴ�С�������������ڲ������һ�����


// ע��㣺erase����s[left]������c
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) return 0;
        else if (s.length() == 1) return 1;
       
        // aaavcgwrgdddddgethuk
        int ans = 0;
        std::unordered_set<int> window;
        for (int left = 0, right = 0; right < s.length(); right++) {
            char c = s[right];
            
            while (window.find(c) != window.end()) { // �ڴ����ڿ����ҵ� c
                window.erase(s[left]);
                left++;
            }

            window.emplace(c);
            ans = std::max(ans, right - left + 1);
        }
       
        return ans;
    }
};


