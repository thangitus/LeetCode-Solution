#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/design-hashmap/
 * */

struct Node {
public:
    int key, val;
    Node *next;

    Node(int k, int v, Node *n) {
        key = k;
        val = v;
        next = n;
    }
};

class MyHashMap {
public:
    const static int size = 19997;
    const static int mul = 12582917;
    Node *data[size];

    int hash(int key) {
        return (int) ((long) key * mul % size);
    }

    void put(int key, int val) {
        remove(key);
        int h = hash(key);
        Node *node = new Node(key, val, data[h]);
        data[h] = node;
    }

    int get(int key) {
        int h = hash(key);
        Node *node = data[h];
        for (; node; node = node->next)
            if (node->key == key) return node->val;
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        Node *node = data[h];
        if (!node) return;
        if (node->key == key) data[h] = node->next;
        else
            for (; node->next; node = node->next)
                if (node->next->key == key) {
                    node->next = node->next->next;
                    return;
                }
    }
};

