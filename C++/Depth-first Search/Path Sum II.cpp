#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/path-sum-ii/
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
    vector<vector<int>> ans;

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> curr;
        dfs(root, curr, targetSum);
        return ans;
    }

    void dfs(TreeNode *node, vector<int> &curr, int remain) {
        if (node == nullptr) return;
        remain -= node->val;
        curr.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && remain == 0)
            ans.push_back(curr);
        dfs(node->left, curr, remain);
        dfs(node->right, curr, remain);
        curr.pop_back();
    }
};