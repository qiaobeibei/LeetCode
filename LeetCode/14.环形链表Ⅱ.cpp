/*
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表
中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 
是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。
*/

// 快慢指针
/*
可以使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，fast指针每次移动两个节点，
slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。

为什么fast 走两个节点，slow走一个节点，有环的话，一定会在环内相遇呢，而不是永远的错开呢，
首先，快指针一定先进入环中，如果快慢指针相遇，一定是在换种相遇；其次，快慢指针一定是在
环的第一圈中相遇，因为快指针的移动位置是慢指针的两倍，如果慢指针在环中移动了一圈，那么
快指针一定会移动两圈，所以快慢指针必定在第一圈中相遇。

有了上面的解释，可得出一个等式x=z，x是从头节点到相遇点的距离，z是从相遇点到环入口的距离，
具体的证明可以看下面的网址。
所以当快慢指针相遇后，定义index1和index2指针，一个从头结点移动，一个从相遇点移动，当二者
相同时必定是入口的地址。

动画效果看下面的网站
https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* right = head, * left = head;
		ListNode* index1, * index2;
		// 因为快指针一次跳两个位置，所以必须判断right、right->next是否为空
		// 如果right为null,说明没有环，直接可以跳出
		while (right != nullptr and right->next != nullptr) {
			right = right->next->next;
			left = left->next;
			if (right == left) { // 快慢指针相遇，此时从head和相遇点，同时查找直至相遇
				index1 = head;
				index2 = left;
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;
				}
				return index1; // 环的入口
			}
		}

		return nullptr;
	}
};