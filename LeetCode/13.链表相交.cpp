#include <set>
#include <iostream>

/*
���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣
�����������û�н��㣬���� null ��
*/

// ��������������ڵ��ָ�룬���ǣ����㲻����ֵ��ͬ������ָ����ͬ������Ҫ
// ��ָ������ж϶�����ָ���ֵ��ֻҪ��һ���ڵ���ͬ����ô�ýڵ�ĵ�ַ��ͬ��
// ��ͬ��ַָ�����һ���ڵ�Ҳ��ͬ��˵����ͬ�ڵ��������нڵ��һ��

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ˫ָ�루�����
/*
���ֽⷨ�Ƚ�����A��β�ڵ����ӵ�����B��ͷ�ڵ㣬Ȼ������B��β�ڵ����ӵ�����A��ͷ�ڵ㡣������
��������ĳ��Ⱦ�����ˡ�Ȼ������ͬʱ������������ֱ���ҵ��ཻ�Ľڵ���������������

ֻҪ������������ڹ������㣬��ô�������������ݶ���ͬ��ֻҪA��B������������������A->B��B->A��
��ô�������µ��������󼸸��ڵ�ض�����ͬ�ġ�
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
			// ����һ��ָ����headB��ֵͬ�ĵ����������û�У�����s.end()
			if (s.find(headB) != s.end())
				return headB;
			headB = headB->next;
		}

		return nullptr;
	}
};