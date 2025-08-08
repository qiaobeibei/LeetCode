/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，
并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reverse1 = l1;
        ListNode* reverse2 = l2;
        ListNode dummy;
        ListNode* cur = &dummy;
        int carry = 0;

        while (reverse1 || reverse2 || carry) {
            int sum = carry;
            if (reverse1) {
                sum += reverse1->val;
                reverse1 = reverse1->next;
            }
            if (reverse2) {
                sum += reverse2->val;
                reverse2 = reverse2->next;
            }
            carry = sum / 10;
            // 创建新节点并连接到结果链表
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }

        return dummy.next;
    }
};