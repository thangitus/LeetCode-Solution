#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int res = 0;

    int averageOfSubtree(TreeNode *root) {
        dfs(root);
        return res;
    }

    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int sum = root->val + left.first + right.first, n = 1 + left.second + right.second;
        res += (sum / n == root->val);
        return {sum, n};
    }
};