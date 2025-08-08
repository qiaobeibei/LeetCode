/*
����һ���������飬ÿ�������Ѿ����������С�

���㽫��������ϲ���һ�����������У����غϲ��������
*/

#pragma once
#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (list1 and list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy.next;
    }
public:
    // ���� 14.�ϲ����� �ķ������Ȳ���һ������������Ƚ�
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* cur = &dummy;
        for (auto& list : lists) {
            if (!cur->next) {
                cur->next = list;
            }
            else {
                cur->next = mergeTwoLists(cur->next, list);
            }
        }
        return dummy.next;
    }
};