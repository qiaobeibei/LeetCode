/*
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
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
    // 按照 14.合并区间 的方法，先插入一个，后面逐个比较
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