#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *convertBST(TreeNode *root) {
        int curSum = 0;
        return dfs(root, curSum);
    }

    TreeNode *dfs(TreeNode *root, int &curSum) {
        if (!root) return nullptr;
        root->right = dfs(root->right, curSum);
        root->val = curSum = curSum + root->val;
        root->left = dfs(root->left, curSum);
        return root;
    }
};
