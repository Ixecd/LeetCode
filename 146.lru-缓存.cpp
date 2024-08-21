/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class LRUCache {
public:
    struct Node {
        Node(int value = -1) : val(value) {}

        int val{-1};
        int key{-1};
        Node *prev{nullptr};
        Node *next{nullptr};
    };

private:
    size_t cap;
    unordered_map<int, Node *> umap;
    Node *dummy;

private:
    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void push_front(Node *node) {
        node->prev = dummy;
        node->next = dummy->next;
        node->prev->next = node;
        node->next->prev = node;
    }

    Node *get_node(int k) {
        auto it = umap.find(k);
        if (it == umap.end()) {
            return nullptr;
        } else {
            remove(it->second);
            push_front(it->second);
            return it->second;
        }
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        dummy = new Node;
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    ~LRUCache() {
        delete dummy;
    }

    LRUCache &operator=(LRUCache &&) = delete;

    int get(int key) {
        auto it = umap.find(key);
        if (it == umap.end()) {
            return -1;
        }
        remove(it->second);
        push_front(it->second);
        return it->second->val;
    }

    void put(int key, int value) {
        Node *node = get_node(key);
        if (node == nullptr) {
            node = new Node(value);
            node->key = key;
            umap[key] = node;
            push_front(node);
            if (umap.size() > cap) {
                Node *tmp = dummy->prev;
                remove(tmp);
                umap.erase(tmp->key);
                delete tmp;
            }
        } else {
            node->val = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
