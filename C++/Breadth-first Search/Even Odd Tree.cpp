#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/even-odd-tree/
 * */

class Solution {
public:
    bool isEvenOddTree(TreeNode *root) {
        queue<TreeNode *> queue;
        bool isEven = true;
        queue.push(root);
        while (!queue.empty()) {
            int prev = isEven ? INT_MIN : INT_MAX;
            for (int i = queue.size(); i > 0; i--) {
                TreeNode *cur = queue.front();
                queue.pop();
                if (cur->left) queue.push(cur->left);
                if (cur->right) queue.push(cur->right);
                int val = cur->val;
                if (isEven) {
                    if (val % 2 == 0) return false;
                    if (val <= prev) return false;
                } else {
                    if (val % 2) return false;
                    if (val >= prev) return false;
                }
                prev = val;
            }
            isEven = !isEven;
        }
        return true;
    }
};
