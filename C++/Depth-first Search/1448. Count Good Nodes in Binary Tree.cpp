#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int goodNodes(TreeNode *root, int curMax = INT_MIN) {
        if (root == nullptr) return 0;
        int res = root->val >= curMax;
        curMax = max(curMax, root->val);
        res += goodNodes(root->left, curMax);
        res += goodNodes(root->right, curMax);
        return res;
    }
};