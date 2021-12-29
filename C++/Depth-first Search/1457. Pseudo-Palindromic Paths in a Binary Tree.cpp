#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode *root) {
        vector<int> count(10);
        return dfs(root, count);
    }

    int dfs(TreeNode *node, vector<int> &count) {
        int result = 0;
        if (!node) return result;
        count[node->val]++;
        if (!node->left && !node->right) {
            int cnt = 0;
            for (int i: count)
                cnt += i % 2;
            result = cnt <= 1;
        } else
            result = dfs(node->left, count)
                     + dfs(node->right, count);
        count[node->val]--;
        return result;
    }
};
