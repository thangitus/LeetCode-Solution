#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;


/**
 * https://leetcode.com/problems/invert-binary-tree/
 * */

class Solution {
public:
    int res;

    void inorder(TreeNode *root, int &k) {
        if (!root) return;
        inorder(root->left, k);
        if (--k == 0) res = root->val;
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k) {
        inorder(root, k);
        return res;
    }
};
