///*
//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val 
//�Ľڵ㣬������ �µ�ͷ�ڵ� ��
//*/
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode() :val(0), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//// 1.����
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        if (head == nullptr) return head;
//
//        while (head != nullptr and head->val == val) {           // ���Ŀ����ͷ��㣬ɾ��ͷ���
//            ListNode* temp = head;
//            head = head->next;
//            delete temp;                                         // ͷ���ɾ�����ͷ��ڴ�
//        }
//
//        ListNode* cur = head;                                    // ������ʱָ��
//        while (cur != nullptr and cur->next != nullptr) {
//            if (cur->next->val == val) {
//                ListNode* temp = cur->next;
//                cur->next = cur->next->next;                     // ɾ����val��ȵķ�ͷ���
//                delete temp;
//            }
//            else
//                cur = cur->next;
//        }
//        return head;
//    }
//};
//
//// 2-1.�ݹ�
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        // ���ͷָ���ֵ����val��ɾ��
//        while (head != nullptr and head->val == val) {
//            ListNode* temp = head;
//            head = head->next;
//            delete temp;
//        }
//
//        // �ж�ͷָ���Ƿ�Ϊ��
//        if (head == nullptr) return head;
//
//        // ��ͷָ�벻Ϊ�գ�ɾ��ͷ�ڵ������ֵΪ val �Ľڵ�
//        head->next = removeElements(head->next, val);
// 
//        return head;
//    }
//};
//
//// 2-2.�ݹ�Ļ���(û���ͷ��ڴ�)
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        if (!head) return head;                             // ͷָ��Ϊ�գ�����
//
//        head->next = removeElements(head->next, val);       // ���ȴ���ͷָ�����Ľ��
//
//        return head->val == val ? head->next : head;
//    }
//};
//
//// 3.˫ָ��
///*
//����������ָ��ͷ�ڵ��ָ�룬pre����¼��ɾ���ڵ��ǰһ�ڵ㣩�� cur (��¼��ǰ�ڵ�)��
//
//���������������ҽڵ�ֵΪ val �Ľڵ㣬�ҵ���ɾ���ýڵ㣬����������ҡ�
//
//2.1 �ҵ�������ǰ�ڵ��ǰһ�ڵ㣨֮ǰ���һ��ֵ������ val �Ľڵ�(pre)�����ӵ���ǰ�ڵ㣨cur����
//��һ���ڵ㣨���� pre ����һ�ڵ�ָ�� cur ����һ�ڵ㣺pre->next = cur->next����
//
//2.2 û�ҵ����������һ��ֵ������ val �Ľڵ㣨�� pre = cur����������������cur = cur->next����
//*/
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        while (head != nullptr and head->val == val) {
//            ListNode* temp = head;
//            head = head->next;
//            delete temp;
//        }
//              
//        // ���ｫ����ָ��ָ��head�����ı��ַ�ڵ����ݣ���headҲ��ı�
//        ListNode* cur = head;                           // ��¼��ǰ�ڵ�
//        ListNode* pre = head;                           // ��¼��ɾ���ڵ��ǰһ�ڵ�
//
//        while (cur != nullptr) {
//            if (cur->val == val) pre->next = cur->next; // ���ڱ�ɾ���Ľ�㣬��pre���¸�ָ����������ַ�����ݸı䣬head��curҲ�ı�
//            else pre = cur;
//            cur = cur->next;                         
//        }
//
//        return head;
//    }
//};
//
//
//// �����ڱ�
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        auto dummy_head = new ListNode;
//        auto cur = new ListNode;
//        dummy_head->next = head;                        // ���������ڱ�����ʱͷ���Ϊdummy_head
//        cur = dummy_head;           
//        
//        // �������ڱ���ʼ��������ô��һ����cur->next��ʵ���Ǳ�����head
//        while (cur->next != nullptr) {
//            if (cur->next->val == val) cur->next = cur->next->next;
//            // cur�Ѿ���һ��ָ��������ˣ��������ﲢû�иı����е����ݣ�ֻ�Ƕ�һ��ԭ��ָ�����еı���������һ��ָ��
//            else cur = cur->next;   
//        }
//
//        delete cur;
//
//        // ����return head, ��Ϊԭ����ͷ�������Ѿ���ɾ������Ӧ��return�����ڱ�����һ�����
//        return dummy_head->next;
//    }
//};