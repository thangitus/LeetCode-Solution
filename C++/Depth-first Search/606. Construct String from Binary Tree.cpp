#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    string tree2str(TreeNode *root) {
        if (!root) return "";
        string res = to_string(root->val);
        if (!root->right && root->left)
            res += "(" + tree2str(root->left) + ")";
        if (!root->left && root->right)
            res += "()(" + tree2str(root->right) + ")";
        if (root->right && root->left)
            res += "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
        return res;
    }
};
