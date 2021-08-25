#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/search-in-a-binary-search-tree/
 * */

class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root || root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};