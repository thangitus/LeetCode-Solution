#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *trimBST(TreeNode *node, int low, int high) {
        if (!node) return nullptr;
        if (node->val < low)
            return trimBST(node->right, low, high);
        if (node->val > high)
            return trimBST(node->left, low, high);
        node->left = trimBST(node->left, low, high);
        node->right = trimBST(node->right, low, high);
        return node;
    }
};
