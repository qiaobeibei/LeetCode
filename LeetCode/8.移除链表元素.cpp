/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 
的节点，并返回 新的头节点 。
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

// 1.迭代
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;

        while (head != nullptr and head->val == val) {           // 如果目标是头结点，删除头结点
            ListNode* temp = head;
            head = head->next;
            delete temp;                                         // 头结点删除后释放内存
        }

        ListNode* cur = head;                                    // 定义临时指针
        while (cur != nullptr and cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;                     // 删除和val相等的非头结点
                delete temp;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};

// 2-1.递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 如果头指针的值等于val，删除
        while (head != nullptr and head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // 判断头指针是否为空
        if (head == nullptr) return head;

        // 若头指针不为空，删除头节点后所有值为 val 的节点
        head->next = removeElements(head->next, val);
 
        return head;
    }
};

// 2-2.递归的化简(没有释放内存)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;                             // 头指针为空，返回

        head->next = removeElements(head->next, val);       // 首先处理头指针后面的结点

        return head->val == val ? head->next : head;
    }
};

// 3.双指针
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

    }
};