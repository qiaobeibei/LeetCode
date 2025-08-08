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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* p0 = &dummy;
        for (int i = 0; i < left - 1; i++) { // ���ڱ��ƶ�����ת���ڵ����һλ
            p0 = p0->next;
        }

        ListNode* pre = nullptr;
        ListNode* cur = p0->next;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nxt = cur->next;
            cur->next = pre; // ÿ��ѭ��ֻ�޸�һ�� next�����������
            pre = cur;
            cur = nxt;
        }

        /*
        dummy->1->2->3->4->5->6->7->null  ������Ҫ�� 3->4->5 ��ת
        �� p0 ��ָ�� 2����ת�������ṹΪ��
        pre = 5->4->3->nullptr  cur = 6->7->null   p0 = 2->3->nullptr
        ���� p0->next->next = cur ���ǽ� 3 ��6ƴ�ӣ��� 2->3->6->7->null
        p0->next = pre �ǽ� 2 �� pre ƴ�ӣ��� 2->5->4->3->6->7->null
        */
        // ��ʹ����ת�ˣ������ڱ��Ծ�ָ��תǰ��Ԫ�أ������ p0->next ��ʵ���Ƿ�ת��������һλ
        p0->next->next = cur; // �÷�ת��������һλ��ƴ��ԭ����ĺ��ʣ�ಿ��
        p0->next = pre; // �ٽ�ǰ�벿�ֺͷ�ת����ƴ��

        return dummy.next;
    }
};