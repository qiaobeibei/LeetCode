#include <set>
#include <iostream>

/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表没有交点，返回 null 。
*/

// 返回两个链表交点节点的指针，但是，交点不是数值相同，而是指针相同，这里要
// 用指针进行判断而不是指针的值，只要有一出节点相同，那么该节点的地址相同，
// 相同地址指向的下一个节点也相同，说明相同节点后面的所有节点均一样

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 双指针（最巧妙）
/*
这种解法先将链表A的尾节点连接到链表B的头节点，然后将链表B的尾节点连接到链表A的头节点。这样，
两个链表的长度就相等了。然后，我们同时遍历两个链表，直到找到相交的节点或遍历完整个链表。

只要这两个链表存在公共交点，那么交点后的所有数据都相同，只要A和B链表连接起来，比如A->B和B->A，
那么这两个新的链表的最后几个节点必定是相同的。
https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html#%E6%80%9D%E8%B7%AF
*/
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* A = headA, * B = headB;
		while (A != B) {
			A = A != nullptr ? A->next : headB;
			B = B != nullptr ? B->next : headA;
		}
		return A;
	}
};

// set
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		std::set<ListNode*> s;
		while (headA) {
			s.insert(headA);
			headA = headA->next;
		}
		while (headB) {
			// 返回一个指向与headB相同值的迭代器，如果没有，返回s.end()
			if (s.find(headB) != s.end())
				return headB;
			headB = headB->next;
		}

		return nullptr;
	}
};