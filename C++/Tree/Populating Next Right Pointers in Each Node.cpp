#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * */

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return root;
        queue<Node *> queue;
        queue.push(root);
        while (!queue.empty()) {
            Node *next = nullptr;
            for (auto i = queue.size(); i > 0; i--) {
                Node *cur = queue.front();
                queue.pop();
                cur->next = next;
                next = cur;
                if (cur->right) queue.push(cur->right);
                if (cur->left) queue.push(cur->left);
            }
        }
        return root;
    }
};