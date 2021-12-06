#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int result = 0;
    int longestZigZag(TreeNode *root) {
        dfs(root, true);
        return result;
    }

    int dfs(TreeNode *node, bool isLeft) {
        if (!node) return 0;
        int left = dfs(node->left, false);
        int right = dfs(node->right, true);
        result = max(result, left);
        result = max(result, right);
        return 1 + (isLeft ? left : right);
    }
};
