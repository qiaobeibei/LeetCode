#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// �ڴ�֮ǰ��Ҫֱ����ô��������м��㣬��η�ת����
// ��������м��㣺https://leetcode.cn/problems/middle-of-the-linked-list/description/
// ��ת����https://leetcode.cn/problems/reverse-linked-list/description/?envType=study-plan-v2&envId=top-100-liked

class Solution {
private:
    // �������м���
    /*
    // ��ָ���൱����ָ�룬һ��ֻ��һ������ָ���൱�ڿ�ָ�룬һ�����������϶�����ָ�����ߵ����һ��������
       �ߵ����һ�����ָ��� nullptr ������Ϊ��ָ���ߵ��ٶ�����ָ������������Ե���ָ���ߵ���β��ʱ����ָ
       ��һ�����м�����м�ĵڶ���λ�ô���

       �����ж�ֻ��Ҫ�ж��������������ָ�����ָ�����һ���Ƿ�Ϊ�գ������ָ�����һ��Ҳ��Ϊ�գ���ʹ���²�
       ��nullptr����ָ��Ҳ�����ߵ�nullptr����

       �Լ���һ������ģ��һ�¾ͻᡣ
    */
    ListNode* middleNode(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;
        while (right and right->next) {
            left = left->next;
            right = right->next->next;
        }
        return left;
    }
    // ��ת����
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
    // �����м��㣬�ҵ��Ժ�ת�м���֮�������Ȼ��ǰ�������ͺ�����������α����ж��Ƿ���ͬ
    bool isPalindrome(ListNode* head) {
        ListNode* head2 = reverseList(middleNode(head));
        while (head2) {
            if (head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};