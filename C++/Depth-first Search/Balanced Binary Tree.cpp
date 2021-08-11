#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/balanced-binary-tree/
 */

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
    bool ans = true;

    bool isBalanced(TreeNode *root) {
        balance(root);
        return ans;
    }

    int balance(TreeNode *node) {
        if (!node || !ans)return 0;
        int left = balance(node->left);
        int right = balance(node->right);
        if (abs(left - right) > 1) ans = false;
        return max(left, right) + 1;
    }
};