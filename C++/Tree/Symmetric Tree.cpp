#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// https://leetcode.com/problems/symmetric-tree/
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return traversal(root->left, root->right);
    }

    bool traversal(TreeNode *l, TreeNode *r) {
        if (!l && !r) return true;
        if (!l || !r) return false;
        if (l->val != r->val) return false;
        bool ans = traversal(l->right, r->left);
        ans = ans && traversal(l->left, r->right);
        return ans;
    }
};