#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/binary-tree-preorder-traversal/
 */

class Solution {
public:
    vector<int> ans;

    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) return ans;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};