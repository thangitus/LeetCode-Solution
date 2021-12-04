#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (!root1 && root2) return false;
        if (!root2 && root1) return false;
        if (!root1 && !root2) return true;
        if (root1->val != root2->val) return false;
        swapIfNeeded(root1);
        swapIfNeeded(root2);
        return flipEquiv(root1->left, root2->left) &&
               flipEquiv(root1->right, root2->right);
    }

    void swapIfNeeded(TreeNode *root) {
        TreeNode *&left = root->left;
        TreeNode *&right = root->right;
        if (left == nullptr && right)
            swap(left, right);
        if (left && right && left->val > right->val)
            swap(left, right);
    }
};
