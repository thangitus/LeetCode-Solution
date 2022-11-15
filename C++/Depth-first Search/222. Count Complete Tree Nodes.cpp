#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int height(TreeNode *root) {
        return root == nullptr ? -1 : 1 + height(root->left);
    }

    int countNodes(TreeNode *root) {
        int h = height(root);
        return h < 0 ? 0 :
               height(root->right) == h - 1 ? (1 << h) + countNodes(root->right)
                                            : (1 << (h - 1)) + countNodes(root->left);
    }
};
