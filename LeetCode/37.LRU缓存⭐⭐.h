/*
������Ʋ�ʵ��һ������  LRU (�������ʹ��) ���� Լ�������ݽṹ��
ʵ�� LRUCache �ࣺ
LRUCache(int capacity) �� ������ ��Ϊ���� capacity ��ʼ�� LRU ����
int get(int key) ����ؼ��� key �����ڻ����У��򷵻عؼ��ֵ�ֵ�����򷵻� -1 ��
void put(int key, int value) ����ؼ��� key �Ѿ����ڣ�����������ֵ value ����������ڣ�
���򻺴��в������ key-value ���������������¹ؼ����������� capacity ����Ӧ�� ��� ���δʹ�õĹؼ��֡�
���� get �� put ������ O(1) ��ƽ��ʱ�临�Ӷ����С�
*/
// https://leetcode.cn/problems/lru-cache/description/?envType=study-plan-v2&envId=top-100-liked
#pragma once
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<chrono>

// ��LRU�Ļ�����Ҫ�����ӹ���ʱ�䣬���ڵ�keyҪɾ����
// dummy�ڹ��캯������Ҫ����new Node
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

	// ɾ�����
	void erase(Node* x) {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}

	// ��ͷ��ӽ��
	void push_front(Node* x) {
		x->next = dummy->next;
		x->prev = dummy;
		dummy->next = x;
		x->next->prev = x;
	}

	// ��ȡ key ��Ӧ�Ľڵ㣬ͬʱ�Ѹýڵ��Ƶ�����ͷ��
	Node* get_node(int key) {
		auto it = keyToNode.find(key);
		if (it == keyToNode.end()) {
			return nullptr;
		}
		Node* node = it->second;
		erase(node); // ɾ���ýڵ�
		push_front(node); // �ƶ�������ͷ��
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
// ��LRU�Ļ�����Ҫ�����ӹ���ʱ�䣬���ڵ�keyҪɾ����

using Timestamp = std::chrono::time_point<std::chrono::steady_clock>;
// ��������ڵ�ṹ
struct Node {
    int value;
    int key;
    Node* next;
    Node* prev;
    Timestamp expiration; // ��������ʱ���ֶ�

    Node() = default;
    Node(int _key, int _value, Timestamp _expiration) : key(_key), value(_value), next(nullptr), prev(nullptr), expiration(_expiration) {}
};

class LRUCache {
private:
    int capacity;
    Node* dummy;
    std::unordered_map<int, Node*> keyToNode;

    // ɾ�����
    void erase(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    // ��ͷ��ӽ��
    void push_front(Node* x) {
        x->next = dummy->next;
        x->prev = dummy;
        dummy->next = x;
        x->next->prev = x;
    }

    // ��鲢ɾ�����ڽڵ�
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

    // ��ȡ key ��Ӧ�Ľڵ㣬ͬʱ�Ѹýڵ��Ƶ�����ͷ��
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
        erase(node); // ɾ���ýڵ�
        push_front(node); // �ƶ�������ͷ��
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


