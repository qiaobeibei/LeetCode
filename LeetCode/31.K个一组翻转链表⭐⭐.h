/*
���������ͷ�ڵ� head ��ÿ k ���ڵ�һ����з�ת�����㷵���޸ĺ������

k ��һ��������������ֵС�ڻ��������ĳ��ȡ�����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʽ��нڵ㽻����
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
        // ͳ�ƽڵ����
        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            n++;
        }

        ListNode dummy(0, head);
        ListNode* p0 = &dummy;
        ListNode* pre = nullptr;
        ListNode* cur = head;

        // k ��һ�鴦��
        for (; n >= k; n -= k) {
            for (int i = 0; i < k; i++) { // ͬ 92 ��,��ת��ǰ�� k ���ڵ�
                ListNode* nxt = cur->next;
                cur->next = pre; // ÿ��ѭ��ֻ�޸�һ�� next
                pre = cur;
                cur = nxt;
            }

            // ����Ƶ
            // ����ת�������ڵ���ȷ�ؽ��뵽ԭ������
            /*
            �����������dummy->1->2->3->4->5->6->nullptr    k = 2
            ��һ��ת����֮��pre = 2->1->nullptr  cur = 3->4->5->6->nullptr
            �������̽���ת������ƴ�ӵ�ԭ�����У�
                ListNode* nxt = p0->next; // ��¼ 1->nullptr����¼��ת��������һλԪ��
                p0->next->next = cur; // 1->3->4->5->6->nullptr������ת��������һλԪ����ʣ������ĺ�벿��ƴ��
                p0->next = pre; // dummy->2->1->3->4->5->6->nullptr����ʣ�������ǰ�벿�ֺͷ�ת����ĵ�һλԪ��ƴ��
                p0 = nxt; // �� dummy ָ�� 1->3->4->5->6->nullptr�����ڱ���λ����ת��������һλ
            */
            ListNode* nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy.next;
    }
};