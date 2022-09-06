#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *pruneTree(TreeNode *root) {
        if (!root) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 1 || root->left || root->right) return root;
        return nullptr;
    }
};
