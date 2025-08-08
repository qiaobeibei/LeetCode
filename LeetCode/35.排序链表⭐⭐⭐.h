/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
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
private:
    // 找中间结点，并返回后半部分（需要将前半部分断开）
    ListNode* middleNode(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* left_head = head;
        while (right and right->next) {
            left_head = left;
            left = left->next;
            right = right->next->next;
        }
        left_head->next = nullptr;// 断开 slow 的前一个节点和 slow 的连接
        return left;
    }
    // 合并两个有序链表
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
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) return head;
        // 找到中间节点，并断开 head2 与其前一个节点的连接
        // 比如 head=[4,2,1,3]，那么 middleNode 调用结束后 head=[4,2] head2=[1,3]
        ListNode* head2 = middleNode(head);
        // 分治
        head = sortList(head); // 经过拆分合并之后返回的是一个升序链表[2,4]
        head2 = sortList(head2); // [1,3]
        // 合并
        return mergeTwoLists(head, head2); // 两个有序链表再次合并返回[1,2,3,4]
    }
};