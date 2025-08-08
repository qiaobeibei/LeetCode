/*
����Ϊ �����ʹ�ã�LFU�������㷨��Ʋ�ʵ�����ݽṹ��

ʵ�� LFUCache �ࣺ

LFUCache(int capacity) - �����ݽṹ������ capacity ��ʼ������
int get(int key) - ����� key �����ڻ����У����ȡ����ֵ�����򷵻� -1 ��
void put(int key, int value) - ����� key �Ѵ��ڣ�������ֵ������������ڣ�������ֵ�ԡ�������ﵽ������ capacity ʱ����Ӧ���ڲ�������֮ǰ���Ƴ������ʹ�õ���ڴ������У�������ƽ�֣���������������������ͬʹ��Ƶ�ʣ�ʱ��Ӧ��ȥ�� ���δʹ�� �ļ���
Ϊ��ȷ�����ʹ�õļ�������Ϊ�����е�ÿ����ά��һ�� ʹ�ü����� ��ʹ�ü�����С�ļ������δʹ�õļ���

��һ�����״β��뵽������ʱ������ʹ�ü�����������Ϊ 1 (���� put ����)���Ի����еļ�ִ�� get �� put ������ʹ�ü�������ֵ���������

���� get �� put ������ O(1) ��ƽ��ʱ�临�Ӷ����С�
*/

#pragma once
#include<unordered_map>
#include<iostream>

// https://leetcode.cn/problems/lfu-cache/solutions/2457716/tu-jie-yi-zhang-tu-miao-dong-lfupythonja-f56h/

class Node {
public:
    int key;
    int value;
    int freq = 1; // ����ֻ����һ��
    Node* prev;
    Node* next;
    Node() = default;
    Node(int k, int v) : key(k), value(v) {}
};

class LFUCache {
private:
    int min_freq; // ��С��������
    int capacity;
    std::unordered_map<int, Node*> key_to_node;
    std::unordered_map<int, Node*> freq_to_dummy;

    Node* get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) { // û���Ȿ��
            return nullptr;
        }
        Node* node = it->second; // ���Ȿ��
        remove(node); // ���Ȿ������
        Node* dummy = freq_to_dummy[node->freq];
        if (dummy->prev == dummy) { // ��������������ǿյ�
            freq_to_dummy.erase(node->freq); // �Ƴ�������
            delete dummy; // �ͷ��ڴ�
            if (min_freq == node->freq) { // ������������ߵ�
                min_freq++;
            }
        }
        push_front(++node->freq, node); // �����ұ��������������
        return node;
    }

    // ����һ���µ�˫������
    Node* new_list() {
        Node* dummy = new Node(); // �ڱ��ڵ�
        dummy->prev = dummy;
        dummy->next = dummy;
        return dummy;
    }

    // ������ͷ���һ���ڵ㣨��һ������������棩
    void push_front(int freq, Node* x) {
        auto it = freq_to_dummy.find(freq);
        if (it == freq_to_dummy.end()) { // �������ǿյ�
            it = freq_to_dummy.emplace(freq, new_list()).first;
        }
        Node* dummy = it->second;
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    // ɾ��һ���ڵ㣨���һ���飩
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
        if (node) { // ���Ȿ��
            node->value = value; // ���� value
            return;
        }
        if (key_to_node.size() == capacity) { // ��̫����
            Node* dummy = freq_to_dummy[min_freq];
            Node* back_node = dummy->prev; // ���������������������
            key_to_node.erase(back_node->key);
            remove(back_node); // �Ƴ�
            delete back_node; // �ͷ��ڴ�
            if (dummy->prev == dummy) { // �������ǿյ�
                freq_to_dummy.erase(min_freq); // �Ƴ�������
                delete dummy; // �ͷ��ڴ�
            }
        }
        key_to_node[key] = node = new Node(key, value); // ����
        push_front(1, node); // ���ڡ����� 1 �Ρ���������
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
