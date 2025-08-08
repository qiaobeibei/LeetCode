/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

#pragma once


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// 递归
// 1->2->3->4->5->null
// 步骤1：1->null，2->3->4->5->null
// 步骤2：2->1->null，3->4->5->null
// 步骤3：3->2->1->null，4->5->null
// 步骤4：4->3->2->1->null，5->null
// 步骤5：5->4->3->2->1->null，->null
// 断开的两条链表的null不是同一个，所以不是环形链表

// 反转链表Ⅰ
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = new ListNode;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            temp = cur->next; // 保存当前指向的下一个节点作为新循环的开始
            cur->next = pre; // 让当前指向的下一个节点指向上一次循环的指向
            pre = cur; 
            cur = temp;
        }
        delete temp;
        return pre;
    }
};


// 反转链表Ⅱ// 反转链表Ⅱ：https://leetcode.cn/problems/reverse-linked-list-ii/description/class 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* p0 = &dummy;
        for (int i = 0; i < left - 1; i++) { // 将哨兵移动到待转换节点的上一位
            p0 = p0->next;
        }

        ListNode* pre = nullptr;
        ListNode* cur = p0->next;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nxt = cur->next;
            cur->next = pre; // 每次循环只修改一个 next，方便大家理解
            pre = cur;
            cur = nxt;
        }

        /*
        dummy->1->2->3->4->5->6->7->null  假设需要将 3->4->5 反转
        则 p0 先指向 2，反转后的链表结构为：
        pre = 5->4->3->nullptr  cur = 6->7->null   p0 = 2->3->nullptr
        所以 p0->next->next = cur 就是将 3 和6拼接，即 2->3->6->7->null
        p0->next = pre 是将 2 和 pre 拼接，即 2->5->4->3->6->7->null
        */
        // 即使链表反转了，但是哨兵仍旧指向反转前的元素，这里的 p0->next 其实就是反转链表的最后一位
        p0->next->next = cur; // 让反转链表的最后一位先拼接原链表的后半剩余部分
        p0->next = pre; // 再将前半部分和反转链表拼接

        return dummy.next;
    }
};
