#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *first, *second, *prev = new TreeNode(INT_MIN);

    void recoverTree(TreeNode *root) {
        dfs(root);
        swap(first->val, second->val);
    }

    void dfs(TreeNode *cur) {
        if (!cur) return;
        dfs(cur->left);
        if (first == nullptr && prev->val > cur->val)
            first = prev;
        if (prev->val > cur->val)
            second = cur;
        prev = cur;
        dfs(cur->right);
    }
};
