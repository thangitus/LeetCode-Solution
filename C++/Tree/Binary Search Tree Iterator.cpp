#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;


/**
 * https://leetcode.com/problems/binary-search-tree-iterator/
 * */

class BSTIterator {
private:
    stack<TreeNode *> stack;

    void push(TreeNode *node) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root) {
        push(root);
    }

    int next() {
        TreeNode *curr = stack.top();
        stack.pop();
        push(curr->right);
        return curr->val;
    }

    bool hasNext() {
        return !stack.empty();
    }
};
