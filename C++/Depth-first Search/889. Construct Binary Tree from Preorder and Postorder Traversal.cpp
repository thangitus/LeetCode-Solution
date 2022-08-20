#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int preIndex = 0, postIndex = 0;

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        auto *root = new TreeNode(preorder[preIndex++]);
        if (root->val != postorder[postIndex])
            root->left = constructFromPrePost(preorder, postorder);
        if (root->val != postorder[postIndex])
            root->right = constructFromPrePost(preorder, postorder);
        postIndex++;
        return root;
    }
};