/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 统计节点个数
        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            n++;
        }

        ListNode dummy(0, head);
        ListNode* p0 = &dummy;
        ListNode* pre = nullptr;
        ListNode* cur = head;

        // k 个一组处理
        for (; n >= k; n -= k) {
            for (int i = 0; i < k; i++) { // 同 92 题,反转当前的 k 个节点
                ListNode* nxt = cur->next;
                cur->next = pre; // 每次循环只修改一个 next
                pre = cur;
                cur = nxt;
            }

            // 见视频
            // 将反转后的这组节点正确地接入到原链表中
            /*
            假设存在链表dummy->1->2->3->4->5->6->nullptr    k = 2
            第一次转换完之后，pre = 2->1->nullptr  cur = 3->4->5->6->nullptr
            下列流程将反转的链表拼接到原链表中：
                ListNode* nxt = p0->next; // 记录 1->nullptr，记录反转链表的最后一位元素
                p0->next->next = cur; // 1->3->4->5->6->nullptr，将反转链表的最后一位元素与剩余链表的后半部分拼接
                p0->next = pre; // dummy->2->1->3->4->5->6->nullptr，将剩余链表的前半部分和反转链表的第一位元素拼接
                p0 = nxt; // 将 dummy 指向 1->3->4->5->6->nullptr，将哨兵移位到反转链表的最后一位
            */
            ListNode* nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy.next;
    }
};