#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int result = 0;

    int distributeCoins(TreeNode *root) {
        dfs(root);
        return result;
    }

    int dfs(TreeNode *node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        result += abs(left) + abs(right);
        return node->val + left + right - 1;
    }
};
