#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/
 */

class Solution {
public:
    string smallestFromLeaf(TreeNode *root, string s = "") {
        if (root == nullptr) return "|";
        s = string(1, root->val + 'a') + s;
        return !root->left && !root->right ? s : min(smallestFromLeaf(root->left, s), smallestFromLeaf(root->right, s));
    }
};
