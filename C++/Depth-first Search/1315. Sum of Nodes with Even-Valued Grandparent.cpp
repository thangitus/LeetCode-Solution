#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int sumEvenGrandparent(TreeNode *root) {
        return dfs(root);
    }

    int dfs(TreeNode *cur) {
        if (!cur) return 0;
        int sum = 0;
        if (!(cur->val & 1)) sum = dfsSum(cur, 2);
        sum = sum + dfs(cur->left) + dfs(cur->right);
        return sum;
    }

    int dfsSum(TreeNode *root, int level) {
        if (!root) return 0;
        return level ? dfsSum(root->left, level - 1) +
                       dfsSum(root->right, level - 1) : root->val;
    }
};
