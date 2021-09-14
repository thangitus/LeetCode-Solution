#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/subtree-of-another-tree/
 */

class Solution {
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root) return false;
        return isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        return root->val == subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
};
