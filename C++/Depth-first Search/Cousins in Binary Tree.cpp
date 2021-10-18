#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/cousins-in-binary-tree/
 */

class Solution {
public:
    TreeNode *xParent = nullptr, *yParent = nullptr;
    int xDepth = -1, yDepth = -2;

    bool isCousins(TreeNode *root, int x, int y) {
        dfs(root, nullptr, x, y, 0);
        return xDepth == yDepth && xParent != yParent;
    }

    void dfs(TreeNode *root, TreeNode *parent, int x, int y, int depth) {
        if (root == nullptr) return;
        if (x == root->val) {
            xParent = parent;
            xDepth = depth;
        } else if (y == root->val) {
            yParent = parent;
            yDepth = depth;
        } else {
            dfs(root->left, root, x, y, depth + 1);
            dfs(root->right, root, x, y, depth + 1);
        }
    }
};