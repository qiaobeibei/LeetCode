/*
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ˫ָ��
/*
1.����fastָ���slowָ�룬��ʼֵΪ����ͷ���
2.fast������n + 1�� ��Ϊʲô��n+1�أ���Ϊֻ������ͬʱ�ƶ���ʱ��slow����ָ��
  ɾ���ڵ����һ���ڵ㣨������ɾ��������
3.fast��slowͬʱ�ƶ���ֱ��fastָ��ĩβ
4.ɾ��slowָ�����һ���ڵ�
*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n < 0) return head;
		if (!head->next) return nullptr;
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* left = dummyHead, * right = dummyHead;
		do { right = right->next; } while (n--); // ������ָ�����ָ���м���n���ڵ�
		while (right) { // ��������ָ���м��n���ڵ�Ȼ��һλһλ���ƣ�����ָ��Ϊ��ʱ������ɾ��������n���ڵ�
			right = right->next;
			left = left->next;
		}
		left->next = left->next->next;

		return dummyHead->next;
	}
};