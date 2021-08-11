#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/binary-tree-paths/
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        string init = to_string(root->val);
        dfs(ans, init, root);
        return ans;
    }

    void dfs(vector<string> &ans, string curr, TreeNode *node) {
        if (!curr.empty()) curr += "->";
        curr += to_string(node->val);
        if (!node->left && !node->right) {
            ans.push_back(curr);
            return;
        }
        if (node->left) dfs(ans, curr, node->left);
        if (node->right) dfs(ans, curr, node->right);
    }
};