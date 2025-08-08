/*
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
*/

#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// ע��㣺ɾ�����ʱ��Ҫ�ֶ���ɾ���Ľ���ͷ�
// ˫ָ��
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ���ڿ��ܻ�ɾ������ͷ�������ڱ��ڵ�򻯴���
        ListNode dummy{ 0, head };
        ListNode* left = &dummy;
        ListNode* right = &dummy;
        while (n--) {
            right = right->next; // ��ָ���������� n ��
        }
        while (right->next) {
            left = left->next;
            right = right->next; // ����ָ��һ����
        }
        // ��ָ�����һ���ڵ���ǵ����� n ���ڵ�
        ListNode* nxt = left->next;
        left->next = left->next->next;
        delete nxt; // ɾ�����ʱ��Ҫ�ֶ���ɾ���Ľ���ͷ�
        return dummy.next;
    }
};

// ����������ת����
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
