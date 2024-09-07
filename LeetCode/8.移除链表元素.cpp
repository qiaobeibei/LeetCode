/*
����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val 
�Ľڵ㣬������ �µ�ͷ�ڵ� ��
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 1.����
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;

        while (head != nullptr and head->val == val) {           // ���Ŀ����ͷ��㣬ɾ��ͷ���
            ListNode* temp = head;
            head = head->next;
            delete temp;                                         // ͷ���ɾ�����ͷ��ڴ�
        }

        ListNode* cur = head;                                    // ������ʱָ��
        while (cur != nullptr and cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;                     // ɾ����val��ȵķ�ͷ���
                delete temp;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};

// 2-1.�ݹ�
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // ���ͷָ���ֵ����val��ɾ��
        while (head != nullptr and head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // �ж�ͷָ���Ƿ�Ϊ��
        if (head == nullptr) return head;

        // ��ͷָ�벻Ϊ�գ�ɾ��ͷ�ڵ������ֵΪ val �Ľڵ�
        head->next = removeElements(head->next, val);
 
        return head;
    }
};

// 2-2.�ݹ�Ļ���(û���ͷ��ڴ�)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;                             // ͷָ��Ϊ�գ�����

        head->next = removeElements(head->next, val);       // ���ȴ���ͷָ�����Ľ��

        return head->val == val ? head->next : head;
    }
};

// 3.˫ָ��
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

    }
};