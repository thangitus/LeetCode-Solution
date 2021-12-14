#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int sum = 0;

    int rangeSumBST(TreeNode *root, int low, int high) {
        if (!root) return 0;
        if (root->val > low)
            rangeSumBST(root->left, low, high);
        if (root->val < high)
            rangeSumBST(root->right, low, high);
        if (root->val >= low && root->val <= high)
            sum += root->val;
        return sum;
    }
};
