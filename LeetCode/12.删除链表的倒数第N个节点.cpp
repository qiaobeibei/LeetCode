/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 双指针
/*
1.定义fast指针和slow指针，初始值为虚拟头结点
2.fast首先走n + 1步 ，为什么是n+1呢，因为只有这样同时移动的时候slow才能指向
  删除节点的上一个节点（方便做删除操作）
3.fast和slow同时移动，直到fast指向末尾
4.删除slow指向的下一个节点
*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n < 0) return head;
		if (!head->next) return nullptr;
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* left = dummyHead, * right = dummyHead;
		do { right = right->next; } while (n--); // 先让右指针和左指针中间有n个节点
		while (right) { // 保持左右指针中间的n个节点差，然后一位一位右移，当右指针为空时，即可删除倒数第n个节点
			right = right->next;
			left = left->next;
		}
		left->next = left->next->next;

		return dummyHead->next;
	}
};