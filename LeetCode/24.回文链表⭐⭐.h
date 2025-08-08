#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 在此之前需要直到怎么找链表的中间结点，如何反转链表
// 求链表的中间结点：https://leetcode.cn/problems/middle-of-the-linked-list/description/
// 反转链表：https://leetcode.cn/problems/reverse-linked-list/description/?envType=study-plan-v2&envId=top-100-liked

class Solution {
private:
    // 求链表中间结点
    /*
    // 左指针相当于慢指针，一次只走一步；右指针相当于快指针，一次走两步，肯定是右指针先走到最后一个结点或者
       走到最后一个结点指向的 nullptr 处。因为右指针走的速度是左指针的两倍，所以当右指针走到结尾的时候，左指
       针一定在中间或者中间的第二个位置处。

       我们判断只需要判断走了两步后的右指针和右指针的下一步是否为空，如果右指针的下一步也不为空，即使下下步
       是nullptr，右指针也可以走到nullptr处。

       自己举一个例子模拟一下就会。
    */
    ListNode* middleNode(ListNode* head) {
        ListNode* left = head;
        ListNode* right = head;
        while (right and right->next) {
            left = left->next;
            right = right->next->next;
        }
        return left;
    }
    // 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = new ListNode;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        delete temp;
        return pre;
    }
public:
    // 先找中间结点，找到以后反转中间结点之后的链表，然后将前面的链表和后面的链表依次遍历判断是否相同
    bool isPalindrome(ListNode* head) {
        ListNode* head2 = reverseList(middleNode(head));
        while (head2) {
            if (head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};