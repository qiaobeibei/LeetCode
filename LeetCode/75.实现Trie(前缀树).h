// https://leetcode.cn/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=top-100-liked

#pragma once
#include <string>

#define LENGTH 26

struct Node {
    Node* son[LENGTH]{};
    bool end = false;
};

class Trie {
private:
    Node* root;

    int find(std::string word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr) {
                return 0;
            }
            cur = cur->son[c];
        }
        return cur->end ? 2 : 1;
    }

    void clear(Node* node) {
        for (int i = 0; i < LENGTH; ++i) {
            if (node->son[i]) {
                clear(node->son[i]);
            }
        }
        delete node;
    }
public:
    Trie() {
        root = new Node();
    }
    ~Trie() {
        clear(root);
    }

    void insert(std::string word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr) {
                cur->son[c] = new Node();
            }
            cur = cur->son[c];
        }
        cur->end = true;
    }

    bool search(std::string word) {
        return find(word) == 2;
    }

    bool startsWith(std::string prefix) {
        return find(prefix) != 0;
    }
};
