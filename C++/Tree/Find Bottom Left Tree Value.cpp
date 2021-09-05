#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/find-bottom-left-tree-value/
 */


class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        int result;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            result = queue.front()->val;
            for (int i = queue.size() - 1; i >= 0; i--) {
                TreeNode *front = queue.front();
                queue.pop();
                if (front->left) queue.push(front->left);
                if (front->right) queue.push(front->right);
            }
        }
        return result;
    }
};