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
注意：
1. if (!head) return nullptr; 必须加，否则当只有一个 head 时，Node* new_head = head->next; 会报错
2. cur->next = new Node(cur->val, cur->next, nullptr);就可以了，没必要创建temp保存1之后的节点，让1'进行连接，
构造的时候已经将 cur->next 传递进去了
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // 复制每个节点，把新节点直接插到原节点的后面
        for (Node* cur = head; cur; cur = cur->next->next) {
            cur->next = new Node(cur->val, cur->next, nullptr);
        }

        // 遍历交错链表中的原链表节点
        for (Node* cur = head; cur; cur = cur->next->next) {
            if (cur->random) {
                // 要复制的 random 是 cur->random 的下一个节点
                cur->next->random = cur->random->next;
            }
        }

        // 把交错链表分离成两个链表
        Node* new_head = head->next;
        Node* cur = head;
        for (; cur->next->next; cur = cur->next) {
            Node* copy = cur->next;
            cur->next = copy->next; // 恢复原节点的 next
            copy->next = copy->next->next; // 设置新节点的 next
        }
        cur->next = nullptr; // 恢复原节点的 next

        return new_head;
    }
};
