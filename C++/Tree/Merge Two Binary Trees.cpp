#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/merge-two-binary-trees/
 * */

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 && root2) {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
        if (!root2) return root1;
        return root2;
    }
};
