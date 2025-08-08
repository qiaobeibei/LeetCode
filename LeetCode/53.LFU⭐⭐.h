/*
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：

LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量 capacity 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最久未使用 的键。
为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。

当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。

函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

#pragma once
#include<unordered_map>
#include<iostream>

// https://leetcode.cn/problems/lfu-cache/solutions/2457716/tu-jie-yi-zhang-tu-miao-dong-lfupythonja-f56h/

class Node {
public:
    int key;
    int value;
    int freq = 1; // 新书只读了一次
    Node* prev;
    Node* next;
    Node() = default;
    Node(int k, int v) : key(k), value(v) {}
};

class LFUCache {
private:
    int min_freq; // 最小看过次数
    int capacity;
    std::unordered_map<int, Node*> key_to_node;
    std::unordered_map<int, Node*> freq_to_dummy;

    Node* get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) { // 没有这本书
            return nullptr;
        }
        Node* node = it->second; // 有这本书
        remove(node); // 把这本书抽出来
        Node* dummy = freq_to_dummy[node->freq];
        if (dummy->prev == dummy) { // 抽出来后，这摞书是空的
            freq_to_dummy.erase(node->freq); // 移除空链表
            delete dummy; // 释放内存
            if (min_freq == node->freq) { // 这摞书是最左边的
                min_freq++;
            }
        }
        push_front(++node->freq, node); // 放在右边这摞书的最上面
        return node;
    }

    // 创建一个新的双向链表
    Node* new_list() {
        Node* dummy = new Node(); // 哨兵节点
        dummy->prev = dummy;
        dummy->next = dummy;
        return dummy;
    }

    // 在链表头添加一个节点（把一本书放在最上面）
    void push_front(int freq, Node* x) {
        auto it = freq_to_dummy.find(freq);
        if (it == freq_to_dummy.end()) { // 这摞书是空的
            it = freq_to_dummy.emplace(freq, new_list()).first;
        }
        Node* dummy = it->second;
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    // 删除一个节点（抽出一本书）
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        Node* node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        Node* node = get_node(key);
        if (node) { // 有这本书
            node->value = value; // 更新 value
            return;
        }
        if (key_to_node.size() == capacity) { // 书太多了
            Node* dummy = freq_to_dummy[min_freq];
            Node* back_node = dummy->prev; // 最左边那摞书的最下面的书
            key_to_node.erase(back_node->key);
            remove(back_node); // 移除
            delete back_node; // 释放内存
            if (dummy->prev == dummy) { // 这摞书是空的
                freq_to_dummy.erase(min_freq); // 移除空链表
                delete dummy; // 释放内存
            }
        }
        key_to_node[key] = node = new Node(key, value); // 新书
        push_front(1, node); // 放在「看过 1 次」的最上面
        min_freq = 1;
    }
};

struct Node {
    int key;
    int val;
    int freq;
    Node* next;
    Node* prev;

    Node() = default;
    Node(int _k, int _v) : key(_k), val(_v), freq(1), next(nullptr), prev(nullptr) {}
};

class LFUCache {
private:
    int _min_freq;
    int _capacity;
    std::unordered_map<int, Node*> _key_to_node;
    std::unordered_map<int, Node*> _freq_to_dummy;

    Node* new_list() {
        Node* dummy = new Node{};
        dummy->next = dummy;
        dummy->prev = dummy;
        return dummy;
    }

    void erase(Node* x) {
        x->next->prev = x->prev;
        x->prev->next = x->next;
    }

    void push_front(int freq, Node* x) {
        auto it = _freq_to_dummy.find(freq);
        if (it == _freq_to_dummy.end()) {
            it = _freq_to_dummy.emplace(freq, new_list()).first;
        }
        Node* dummy = it->second;
        dummy->next->prev = x;
        x->prev = dummy;
        x->next = dummy->next;
        dummy->next = x;
    }

    Node* get_node(int key) {
        auto it = _key_to_node.find(key);
        if (it == _key_to_node.end()) {
            return nullptr;
        }
        Node* node = it->second;
        erase(node);
        Node* dummy = _freq_to_dummy[node->freq];
        if (dummy->next = dummy) {
            _freq_to_dummy.erase(node->freq);
            delete dummy;
            if (_min_freq == node->freq) {
                _min_freq++;
            }
        }
        push_front(++node->freq, node);
        return node;
    }
    
public:
    LFUCache(int capacity) {
        _min_freq = 1;
        _capacity = capacity;
    }

    int get(int key) {
        Node* node = get_node(key);
        return node == nullptr ? -1 : node->val;
    }

    void put(int key, int value) {
        Node* node = get_node(key);
        if (node) {
            node->val = value;
            return;
        }
        if (_capacity == _key_to_node.size()) {
            Node* dummy = _freq_to_dummy[_min_freq];
            Node* back_node = dummy->prev;
            erase(back_node);
            _key_to_node.erase(back_node->key);
            delete back_node;
            if (dummy->next == dummy) {
                _freq_to_dummy.erase(_min_freq);
                delete dummy;
            }
        }
        _key_to_node[key] = node = new Node(key, value);
        _min_freq = 1;
        push_front(_min_freq,node);
    }
};
