#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;


class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth, int curDepth = 1) {
        if (depth == 1) {
            auto *newNode = new TreeNode(val, root, nullptr);
            return newNode;
        } else if (depth == curDepth + 1) {
            if (!root) root = new TreeNode(val);
            else {
                root->left = new TreeNode(val, root->left, nullptr);
                root->right = new TreeNode(val, nullptr, root->right);
            }
        } else if (root) {
            addOneRow(root->left, val, depth, curDepth + 1);
            addOneRow(root->right, val, depth, curDepth + 1);
        }
        return root;
    }
};
