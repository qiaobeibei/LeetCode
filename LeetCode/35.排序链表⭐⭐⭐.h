/*
���������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� ��
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
    // ���м��㣬�����غ�벿�֣���Ҫ��ǰ�벿�ֶϿ���
    ListNode* middleNode(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* left_head = head;
        while (right and right->next) {
            left_head = left;
            left = left->next;
            right = right->next->next;
        }
        left_head->next = nullptr;// �Ͽ� slow ��ǰһ���ڵ�� slow ������
        return left;
    }
    // �ϲ�������������
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
        // �ҵ��м�ڵ㣬���Ͽ� head2 ����ǰһ���ڵ������
        // ���� head=[4,2,1,3]����ô middleNode ���ý����� head=[4,2] head2=[1,3]
        ListNode* head2 = middleNode(head);
        // ����
        head = sortList(head); // ������ֺϲ�֮�󷵻ص���һ����������[2,4]
        head2 = sortList(head2); // [1,3]
        // �ϲ�
        return mergeTwoLists(head, head2); // �������������ٴκϲ�����[1,2,3,4]
    }
};