/*
���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
*/


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ˫ָ�뷨
/*
���ȶ���һ��curָ�룬ָ��ͷ��㣬�ٶ���һ��preָ�룬��ʼ��Ϊnull��

Ȼ���Ҫ��ʼ��ת�ˣ�����Ҫ�� cur->next �ڵ���tmpָ�뱣��һ�£�Ҳ���Ǳ���һ������ڵ㡣

ΪʲôҪ����һ������ڵ��أ���Ϊ������Ҫ�ı� cur->next ��ָ���ˣ���cur->next ָ��pre ����ʱ�Ѿ���ת�˵�һ���ڵ��ˡ�

������������ѭ�������´����߼��ˣ������ƶ�pre��curָ�롣

���cur ָ���Ѿ�ָ����null��ѭ������������Ҳ��ת����ˡ� ��ʱ����return preָ��Ϳ����ˣ�preָ���ָ�����µ�ͷ��㡣
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* cur = head, * pre = nullptr;
        ListNode* temp = new ListNode; // ����cur����һ���ڵ�
        while (cur) {
            temp = cur->next;
            cur->next = pre;  // ��ת����
            // ����pre �� curָ��
            pre = cur;
            cur = temp;
        }
        delete temp;
        return pre;
    }
};


// ����(��������ӿ�������ʾ)
// https://leetcode.cn/problems/reverse-linked-list/solutions/36710/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next) return head;
        // �ȴ�ͷ��������ĩ�ˣ�ĩ��ʶ����һ����ǿ�ָ�룬���ص�ǰ���
        // 1->2->3->4->5
        ListNode* cur = reverseList(head->next);  
        // ���һ�����������ĸ�������4��5��5����һ�������null������5����ʱ��ת������������
        head->next->next = head; // �����������൱��4.next.next = 4, ��5.next=4, ��5ָ��4
        head->next = nullptr; // ���������������൱��4.next = null, ��4����һ�����ָ��null���൱��ĩβ
        return cur; // ����������������4��5������5����ʱcur��5
        // cur��Զ��ֻ����5��5�൱���������ͷ���
    }
};


// �����ⷨ������һ��������洢��תԪ��
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* cur = head;
        ListNode* dummyNode = new ListNode(0);
        while (cur != nullptr) {
            ListNode* newNode = new ListNode(cur->val);
            newNode->next = dummyNode->next;
            dummyNode->next = newNode;
            cur = cur->next;
        } 
        return dummyNode->next;
    }
};