/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
*/


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 双指针法
/*
首先定义一个cur指针，指向头结点，再定义一个pre指针，初始化为null。

然后就要开始反转了，首先要把 cur->next 节点用tmp指针保存一下，也就是保存一下这个节点。

为什么要保存一下这个节点呢，因为接下来要改变 cur->next 的指向了，将cur->next 指向pre ，此时已经反转了第一个节点了。

接下来，就是循环走如下代码逻辑了，继续移动pre和cur指针。

最后，cur 指针已经指向了null，循环结束，链表也反转完毕了。 此时我们return pre指针就可以了，pre指针就指向了新的头结点。
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* cur = head, * pre = nullptr;
        ListNode* temp = new ListNode; // 保存cur的下一个节点
        while (cur) {
            temp = cur->next;
            cur->next = pre;  // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        delete temp;
        return pre;
    }
};


// 迭代(下面的链接看动画演示)
// https://leetcode.cn/problems/reverse-linked-list/solutions/36710/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next) return head;
        // 先从头结点迭代到末端，末端识别到下一结点是空指针，返回当前结点
        // 1->2->3->4->5
        ListNode* cur = reverseList(head->next);  
        // 最后一个迭代即第四个迭代是4送5，5的下一个结点是null，返回5，此时跳转到第三个迭代
        head->next->next = head; // 第三个迭代相当于4.next.next = 4, 即5.next=4, 将5指向4
        head->next = nullptr; // 第三个迭代这里相当于4.next = null, 将4的下一个结点指向null，相当于末尾
        return cur; // 第三个迭代这里是4送5，返回5，此时cur是5
        // cur永远都只会是5，5相当于新链表的头结点
    }
};


// 暴力解法，定义一个新链表存储反转元素
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