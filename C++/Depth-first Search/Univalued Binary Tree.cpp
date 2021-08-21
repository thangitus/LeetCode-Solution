#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/univalued-binary-tree/
 * */

class Solution {
public:
    bool isUnivalTree(TreeNode *root) {
        return dfs(root, root->val);
    }

    bool dfs(TreeNode *curr, int &value) {
        if (!curr) return true;
        if (curr->val != value) return false;
        return dfs(curr->left, value) && dfs(curr->right, value);
    }
};