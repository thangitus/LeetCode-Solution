#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/binary-tree-right-side-view/
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> queue;
        if (root) queue.push(root);
        while (!queue.empty()) {
            result.push_back(queue.front()->val);
            for (int i = queue.size(); i > 0; i--) {
                auto cur = queue.front();
                queue.pop();
                if (cur->right) queue.push(cur->right);
                if (cur->left) queue.push(cur->left);
            }
        }
        return result;
    }
};
