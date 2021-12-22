#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    set<int> set;

    int findSecondMinimumValue(TreeNode *root) {
        dfs(root);
        return set.size() > 1 ? *next(set.begin()) : -1;
    }

    void dfs(TreeNode *root) {
        if (!root) return;
        set.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
