/*
����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ��������
�еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ������� pos 
�� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������

�������޸� ����
*/

// ����ָ��
/*
����ʹ�ÿ���ָ�뷨���ֱ��� fast �� slow ָ�룬��ͷ��������fastָ��ÿ���ƶ������ڵ㣬
slowָ��ÿ���ƶ�һ���ڵ㣬��� fast �� slowָ����;������ ��˵����������л���

Ϊʲôfast �������ڵ㣬slow��һ���ڵ㣬�л��Ļ���һ�����ڻ��������أ���������Զ�Ĵ��أ�
���ȣ���ָ��һ���Ƚ��뻷�У��������ָ��������һ�����ڻ�����������Σ�����ָ��һ������
���ĵ�һȦ����������Ϊ��ָ����ƶ�λ������ָ��������������ָ���ڻ����ƶ���һȦ����ô
��ָ��һ�����ƶ���Ȧ�����Կ���ָ��ض��ڵ�һȦ��������

��������Ľ��ͣ��ɵó�һ����ʽx=z��x�Ǵ�ͷ�ڵ㵽������ľ��룬z�Ǵ������㵽����ڵľ��룬
�����֤�����Կ��������ַ��
���Ե�����ָ�������󣬶���index1��index2ָ�룬һ����ͷ����ƶ���һ�����������ƶ���������
��ͬʱ�ض�����ڵĵ�ַ��

����Ч�����������վ
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
		// ��Ϊ��ָ��һ��������λ�ã����Ա����ж�right��right->next�Ƿ�Ϊ��
		// ���rightΪnull,˵��û�л���ֱ�ӿ�������
		while (right != nullptr and right->next != nullptr) {
			right = right->next->next;
			left = left->next;
			if (right == left) { // ����ָ����������ʱ��head�������㣬ͬʱ����ֱ������
				index1 = head;
				index2 = left;
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;
				}
				return index1; // �������
			}
		}

		return nullptr;
	}
};