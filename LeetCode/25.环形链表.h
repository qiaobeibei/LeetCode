/*
����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���

�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� 
Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ��
�������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������

��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
*/

#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ����ָ��
// ��ָ����ٶ�����ָ�������������ָ��������һȦ֮�󣬿�ָ��������Ȧ������л���һ������ͬһ��λ������
// �������˿�����ϰ���������https://leetcode.cn/problems/linked-list-cycle-ii/description/
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
