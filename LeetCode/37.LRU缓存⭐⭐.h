/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，
则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/
// https://leetcode.cn/problems/lru-cache/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<chrono>

// 在LRU的基础上要求增加过期时间，过期的key要删除掉
// dummy在构造函数中需要分配new Node
struct Node {
	int value;
	int key;
	Node* next;
	Node* prev;

	Node() = default;
	Node(int _key, int _value) : key(_key),value(_value),next(nullptr),prev(nullptr){}
};

class LRUCache {
private:
	int capacity;
	Node* dummy;
	std::unordered_map<int, Node*> keyToNode;

	// 删除结点
	void erase(Node* x) {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}

	// 表头添加结点
	void push_front(Node* x) {
		x->next = dummy->next;
		x->prev = dummy;
		dummy->next = x;
		x->next->prev = x;
	}

	// 获取 key 对应的节点，同时把该节点移到链表头部
	Node* get_node(int key) {
		auto it = keyToNode.find(key);
		if (it == keyToNode.end()) {
			return nullptr;
		}
		Node* node = it->second;
		erase(node); // 删除该节点
		push_front(node); // 移动到链表头部
		return node;
	}
public:
	LRUCache(int capacity) : capacity(capacity), dummy(new Node) {
		dummy->next = dummy;
		dummy->prev = dummy;
    }

    int get(int key) {
		Node* node = get_node(key);
		return node ? node->value : -1;
    }

    void put(int key, int value) {
		Node* node = get_node(key);
		if (node) {
			node->value = value;
			return;
		}
		keyToNode[key] = node = new Node(key, value);
		push_front(node);
		if (keyToNode.size() > capacity) {
			Node* back_node = dummy->prev;
			keyToNode.erase(back_node->key);
			erase(back_node);
			delete back_node;
		}
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 在LRU的基础上要求增加过期时间，过期的key要删除掉

using Timestamp = std::chrono::time_point<std::chrono::steady_clock>;
// 定义链表节点结构
struct Node {
    int value;
    int key;
    Node* next;
    Node* prev;
    Timestamp expiration; // 新增过期时间字段

    Node() = default;
    Node(int _key, int _value, Timestamp _expiration) : key(_key), value(_value), next(nullptr), prev(nullptr), expiration(_expiration) {}
};

class LRUCache {
private:
    int capacity;
    Node* dummy;
    std::unordered_map<int, Node*> keyToNode;

    // 删除结点
    void erase(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    // 表头添加结点
    void push_front(Node* x) {
        x->next = dummy->next;
        x->prev = dummy;
        dummy->next = x;
        x->next->prev = x;
    }

    // 检查并删除过期节点
    void removeExpiredNodes() {
        auto now = std::chrono::steady_clock::now();
        Node* current = dummy->next;
        while (current != dummy) {
            if (current->expiration <= now) {
                Node* toRemove = current;
                current = current->next;
                keyToNode.erase(toRemove->key);
                erase(toRemove);
                delete toRemove;
            }
            else {
                current = current->next;
            }
        }
    }

    // 获取 key 对应的节点，同时把该节点移到链表头部
    Node* get_node(int key) {
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()) {
            return nullptr;
        }
        Node* node = it->second;
        if (node->expiration <= std::chrono::steady_clock::now()) {
            keyToNode.erase(key);
            erase(node);
            delete node;
            return nullptr;
        }
        erase(node); // 删除该节点
        push_front(node); // 移动到链表头部
        return node;
    }
public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node) {
        dummy->next = dummy;
        dummy->prev = dummy;
    }

    int get(int key) {
        Node* node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value, int expirationSeconds) {
        removeExpiredNodes();
        Node* node = get_node(key);
        if (node) {
            node->value = value;
            node->expiration = std::chrono::steady_clock::now() + std::chrono::seconds(expirationSeconds);
            return;
        }
        Timestamp expiration = std::chrono::steady_clock::now() + std::chrono::seconds(expirationSeconds);
        keyToNode[key] = node = new Node(key, value, expiration);
        push_front(node);
        if (keyToNode.size() > capacity) {
            Node* back_node = dummy->prev;
            keyToNode.erase(back_node->key);
            erase(back_node);
            delete back_node;
        }
    }

    ~LRUCache() {
        while (dummy->next != dummy) {
            Node* toRemove = dummy->next;
            erase(toRemove);
            delete toRemove;
        }
        delete dummy;
    }
};


