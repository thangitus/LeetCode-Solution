#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * */

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        if (!left) return right;
        else return left;
    }
};
