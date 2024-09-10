/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况
下完成本题（即，只能进行节点交换）。
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 交换两个节点必须从当前节点开始，交换当前节点的下一个节点和当前节点下一个节点的下一个节点
// 即，交换cur->next和cur->next->next
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        ListNode* temp1 = nullptr, * temp2 = nullptr;
        while (cur->next != nullptr and cur->next->next != nullptr) {
            temp1 = cur->next;
            temp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};