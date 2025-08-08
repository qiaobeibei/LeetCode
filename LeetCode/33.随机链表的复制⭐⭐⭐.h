#pragma once
class Node {
public:
    int val;
    Node* next;
    Node* random;

    explicit Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
    Node(int _val, Node* _next, Node* _random) :
        val(_val),next(_next),random(_random) {}
};

/*
ע�⣺
1. if (!head) return nullptr; ����ӣ�����ֻ��һ�� head ʱ��Node* new_head = head->next; �ᱨ��
2. cur->next = new Node(cur->val, cur->next, nullptr);�Ϳ����ˣ�û��Ҫ����temp����1֮��Ľڵ㣬��1'�������ӣ�
�����ʱ���Ѿ��� cur->next ���ݽ�ȥ��
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // ����ÿ���ڵ㣬���½ڵ�ֱ�Ӳ嵽ԭ�ڵ�ĺ���
        for (Node* cur = head; cur; cur = cur->next->next) {
            cur->next = new Node(cur->val, cur->next, nullptr);
        }

        // �������������е�ԭ����ڵ�
        for (Node* cur = head; cur; cur = cur->next->next) {
            if (cur->random) {
                // Ҫ���Ƶ� random �� cur->random ����һ���ڵ�
                cur->next->random = cur->random->next;
            }
        }

        // �ѽ�������������������
        Node* new_head = head->next;
        Node* cur = head;
        for (; cur->next->next; cur = cur->next) {
            Node* copy = cur->next;
            cur->next = copy->next; // �ָ�ԭ�ڵ�� next
            copy->next = copy->next->next; // �����½ڵ�� next
        }
        cur->next = nullptr; // �ָ�ԭ�ڵ�� next

        return new_head;
    }
};
