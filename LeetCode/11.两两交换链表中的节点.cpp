/*
����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ�����
����ɱ��⣨����ֻ�ܽ��нڵ㽻������
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ���������ڵ����ӵ�ǰ�ڵ㿪ʼ��������ǰ�ڵ����һ���ڵ�͵�ǰ�ڵ���һ���ڵ����һ���ڵ�
// ��������cur->next��cur->next->next
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