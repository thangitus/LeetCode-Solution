#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 * */

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) return {};
        vector<vector<int>> ans{{root->val}};
        queue<Node *> queue;
        queue.push(root);
        while (!queue.empty()) {
            vector<int> level;
            for (int i = queue.size() - 1; i >= 0; i--) {
                auto front = queue.front();
                queue.pop();
                for (auto &item:front->children) {
                    queue.push(item);
                    level.push_back(item->val);
                }
            }
            if (!level.empty())
                ans.push_back(level);
        }
        return ans;
    }
};