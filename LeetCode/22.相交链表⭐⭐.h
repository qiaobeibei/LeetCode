
/*
���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣
����������������ཻ�ڵ㣬���� null ��
*/
#pragma once
#include<iostream>
#include<unordered_set>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	explicit ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// ��ϣ��
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		std::unordered_set<ListNode*> s;
		while (headA) {
			s.emplace(headA);
			headA = headA->next;
		}
		while (headB) {
			if (s.find(headB) != s.end()) {
				return headB;
			}
			headB = headB->next;
		}
		return nullptr;
    }
};

// ˫ָ��
// �ο���https://leetcode.cn/problems/intersection-of-two-linked-lists/solutions/2958778/tu-jie-yi-zhang-tu-miao-dong-xiang-jiao-m6tg1/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* p = headA;
		ListNode* q = headB;
		while (p != q) {
			p = p ? p->next : headB;
			q = q ? q->next : headA;
		}
		return p;
	}
};
