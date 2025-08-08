/*
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�
����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
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
            // �����½ڵ㲢���ӵ��������
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }

        return dummy.next;
    }
};