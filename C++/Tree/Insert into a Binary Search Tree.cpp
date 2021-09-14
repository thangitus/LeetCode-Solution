#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;


/**
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/
 * */

class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        else if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};
