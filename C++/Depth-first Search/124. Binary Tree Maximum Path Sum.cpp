#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;


class Solution {
public:
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode *cur) {
        if (!cur) return 0;
        int left = max(0, dfs(cur->left));
        int right = max(0, dfs(cur->right));
        maxSum = max(maxSum, cur->val + left + right);
        return max(left, right) + cur->val;
    }
};