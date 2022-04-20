#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"


using namespace std;

class BSTIterator {
public:
    stack<TreeNode *> stack;

    BSTIterator(TreeNode *root) {
        push(root);
    }

    void push(TreeNode *node) {
        auto cur = node;
        while (cur) {
            stack.push(cur);
            cur = cur->left;
        }
    }

    int next() {
        auto top = stack.top();
        stack.pop();
        push(top->right);
        return top->val;
    }

    bool hasNext() {
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */