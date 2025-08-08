/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// 注意点：删除结点时需要手动将删除的结点释放
// 双指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 由于可能会删除链表头部，用哨兵节点简化代码
        ListNode dummy{ 0, head };
        ListNode* left = &dummy;
        ListNode* right = &dummy;
        while (n--) {
            right = right->next; // 右指针先向右走 n 步
        }
        while (right->next) {
            left = left->next;
            right = right->next; // 左右指针一起走
        }
        // 左指针的下一个节点就是倒数第 n 个节点
        ListNode* nxt = left->next;
        left->next = left->next->next;
        delete nxt; // 删除结点时需要手动将删除的结点释放
        return dummy.next;
    }
};

// 笨方法，反转两次
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = new ListNode;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        delete temp;
        return pre;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* revList = reverseList(head);
        ListNode dummy{0,revList};
        ListNode* cur = &dummy;
        while (--n) {
            cur = cur->next;
        }
        auto temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        return reverseList(dummy.next);
    }
};
