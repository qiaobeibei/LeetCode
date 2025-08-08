
/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。
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

// 哈希表
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

// 双指针
// 参考：https://leetcode.cn/problems/intersection-of-two-linked-lists/solutions/2958778/tu-jie-yi-zhang-tu-miao-dong-xiang-jiao-m6tg1/?envType=study-plan-v2&envId=top-100-liked
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
