#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;


/**
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
 * */


class Solution {
private:
    void push(TreeNode *root, stack<TreeNode *> &stack, bool reverse = false) {
        auto curr = root;
        while (curr) {
            stack.push(curr);
            curr = reverse ? curr->right : curr->left;
        }
    }

public:
    bool findTarget(TreeNode *root, int k) {
        stack<TreeNode *> low, high;
        push(root, low);
        push(root, high, true);
        while (low.top()->val < high.top()->val) {
            int sum = low.top()->val + high.top()->val;
            if (sum == k) return true;
            TreeNode *top;
            if (sum < k) {
                top = low.top(), low.pop();
                top = top->right;
                push(top, low);
            } else {
                top = high.top(), high.pop();
                top = top->left;
                push(top, high, true);
            }
        }
        return false;
    }
};
