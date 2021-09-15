#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/validate-binary-search-tree/
 * */

class Solution {
public:
    bool isValidBST(TreeNode *root, long min = LONG_MIN, long max = LONG_MAX) {
        if (!root) return true;

        if (root->val > min && root->val < max)
            return isValidBST(root->left, min, root->val)
                   && isValidBST(root->right, root->val, max);

        return false;
    }
};
