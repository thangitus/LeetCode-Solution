#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;
/**
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
 * */
class Solution {
public:
    long total, res = LONG_MIN;

    int maxProduct(TreeNode *root) {
        total = dfs(root);
        dfs(root);
        return (int) (res % (int) (1e9 + 7));
    }

    long dfs(TreeNode *curr) {
        if (!curr) return 0;
        long sum = curr->val + dfs(curr->left) + dfs(curr->right);
        res = max(res, (total - sum) * sum);
        return sum;
    }
};