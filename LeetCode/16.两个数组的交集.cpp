/*
������������ nums1 �� nums2 ���������ǵĽ������������е�ÿ��Ԫ��һ����Ψһ�ġ�
���ǿ��Բ�������������˳�� ��

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

// ����+˫ָ��
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int>::iterator i = nums1.begin(), j = nums2.begin();
        std::set<int> temp;
        while (i != nums1.end() and j != nums2.end()) {
            if (*i == *j) {
                temp.insert(*i);
                i++;
                j++;
            }
            else if (*i < *j)
                i++;
            else
                j++;
        }
        std::vector<int> ans(temp.begin(), temp.end());
        return ans;
    }
};

// һ���ŵ�set,Ȼ�������һ������
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans;
        std::set<int> s(nums1.begin(), nums1.end());
        for (auto& x : nums2)
            // ���erase̫����
            if (s.erase(x)) // ɾ����x��ֵ��ͬ��Ԫ�أ�������ɾ���ĸ���
                ans.push_back(x);  // ��x���뵽endǰ��

        return ans;
    }
};


// ʹ��STL��
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans;
        std::set<int> s1(nums1.begin(), nums1.end());
        std::set<int> s2(nums2.begin(), nums2.end());

        std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), 
            std::insert_iterator<std::vector<int>>(ans, ans.begin()));
        return ans;
    }
};


// ����
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        std::vector<int> ans(1001, 0);
        int size = 0;
        for (int i = 0; i < nums1.size(); i++) 
            ans[nums1[i] % 1001]++;
        for (int j = 0; j < nums2.size(); j++) 
            if (ans[nums2[j] % 1001] != 0 and ans[nums2[j] % 1001] != -1) {
                ans[nums2[j] % 1001] = -1;
                size++;
            }

       std::vector<int> res(size, 0);
       for(int i=0;i<ans.size();i++)
            if (ans[i] == -1)
                res[--size] = i;
        return res;
    }
};