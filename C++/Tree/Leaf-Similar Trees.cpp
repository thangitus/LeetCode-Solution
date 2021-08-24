#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/leaf-similar-trees/
 */

class Solution {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        stack<TreeNode *> s1, s2;
        s1.push(root1);
        s2.push(root2);
        while (!s1.empty() && !s2.empty())
            if (dfs(s1) != dfs(s2)) return false;
        return s1.empty() && s2.empty();
    }

    int dfs(stack<TreeNode *> &s) {
        while (true) {
            TreeNode *node = s.top();
            s.pop();
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
            if (!node->left && !node->right) return node->val;
        }
    }
};