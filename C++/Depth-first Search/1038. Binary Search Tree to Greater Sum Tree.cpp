#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *bstToGst(TreeNode *root) {
        int sum = 0;
        return dfs(root, sum);
    }

    TreeNode *dfs(TreeNode *node, int &sum) {
        if (node == nullptr) return nullptr;
        auto *result = new TreeNode();
        result->right = dfs(node->right, sum);
        sum += node->val;
        result->val = sum;
        result->left = dfs(node->left, sum);
        return result;
    }
};
