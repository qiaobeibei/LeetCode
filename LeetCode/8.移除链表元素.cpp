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
/*
设置两个均指向头节点的指针，pre（记录待删除节点的前一节点）和 cur (记录当前节点)；

遍历整个链表，查找节点值为 val 的节点，找到即删除该节点，否则继续查找。

2.1 找到，将当前节点的前一节点（之前最近一个值不等于 val 的节点(pre)）连接到当前节点（cur）的
下一个节点（即将 pre 的下一节点指向 cur 的下一节点：pre->next = cur->next）。

2.2 没找到，更新最近一个值不等于 val 的节点（即 pre = cur），并继续遍历（cur = cur->next）。
*/
class Solution {
public:
   ListNode* removeElements(ListNode* head, int val) {
       while (head != nullptr and head->val == val) {
           ListNode* temp = head;
           head = head->next;
           delete temp;
       }
             
       // 这里将两个指针指向head，若改变地址内的内容，则head也会改变
       ListNode* cur = head;                           // 记录当前节点
       ListNode* pre = head;                           // 记录待删除节点的前一节点

       while (cur != nullptr) {
           if (cur->val == val) pre->next = cur->next; // 存在被删除的结点，将pre的下个指针跳过，地址的内容改变，head和cur也改变
           else pre = cur;
           cur = cur->next;                         
       }

       return head;
   }
};


// 虚拟哨兵
class Solution {
public:
   ListNode* removeElements(ListNode* head, int val) {
       auto dummy_head = new ListNode;
       auto cur = new ListNode;
       dummy_head->next = head;                        // 定义虚拟哨兵，此时头结点为dummy_head
       cur = dummy_head;           
       
       // 从虚拟哨兵开始遍历，那么第一个的cur->next其实就是本来的head
       while (cur->next != nullptr) {
           if (cur->next->val == val) cur->next = cur->next->next;
           // cur已经有一个指向的内容了，所以这里并没有改变序列的内容，只是对一个原本指向序列的变量换了另一个指向
           else cur = cur->next;   
       }

       // 不能return head, 因为原本的头结点可能已经被删除，而应该return虚拟哨兵的下一个结点
       return dummy_head->next;
   }
};