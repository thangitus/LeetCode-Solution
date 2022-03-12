#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node *, Node *> map;
public:
    Node *copyRandomList(Node *head, Node *result = nullptr) {
        if (!head) return head;
        result = new Node(head->val);
        map[head] = result;
        result->next = copyRandomList(head->next, result->next);
        result->random = map[head->random];
        return result;
    }
};