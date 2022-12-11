#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int maxNodes = 0;

    int longestUnivaluePath(TreeNode *root) {
        dfs(root);
        return maxNodes > 0 ? maxNodes - 1 : 0;
    }

    int dfs(TreeNode *cur) {
        if (!cur) return 0;
        int left = dfs(cur->left);
        int right = dfs(cur->right);
        int res = 1;
        bool acceptLeft = cur->left && cur->left->val == cur->val,
                acceptRight = cur->right && cur->right->val == cur->val;
        if (acceptLeft && acceptRight)
            maxNodes = max(maxNodes, left + right + 1);
        if (acceptLeft) res = left + 1;
        if (acceptRight) res = max(res, right + 1);
        maxNodes = max(maxNodes, res);
        return res;
    }
};