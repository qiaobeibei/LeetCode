/*
����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣�������
���޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������
*/

#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
�������dummy->1->2->3->4->5->6->null
���ڵ�һ�ν����У�
    temp1 = cur->next;  // 1->2->3->4->5->6->null
    temp2 = cur->next->next->next; // 3->4->5->6->null

    cur->next = cur->next->next; // dummy->2->3->4->5->6->null
    cur->next->next = temp1; // dummy->2->1->2->3->4->5->6->null
    cur->next->next->next = temp2; // dummy->2->1->3->4->5->6->null
    cur = cur->next->next; // ��curת�� 1 ��
*/

// ע�⣺ѭ������Ҫ��ȷ
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head or !(head->next)) return head;

        ListNode dummy{ 0,head };
        ListNode* cur = &dummy;
        ListNode* temp1, * temp2;
        while (cur->next and cur->next->next) { // ����Ҫ��֤�ڱ�֮���������ڵ�
            temp1 = cur->next;
            temp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;
            cur = cur->next->next;

        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy{ 0,head };
        ListNode* p0 = &dummy;
        while (p0->next && p0->next->next) {
            ListNode* temp = p0->next;
            p0->next = p0->next->next;
            temp->next = p0->next->next;
            p0->next->next = temp;
            p0 = temp;
        }
        return dummy.next;
    }
};

