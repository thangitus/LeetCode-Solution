#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    int res = 0;
    unordered_set<TreeNode *> covered;

    int minCameraCover(TreeNode *root) {
        covered.insert(nullptr);
        dfs(root, nullptr);
        return res;
    }

    void dfs(TreeNode *cur, TreeNode *par) {
        if (cur) {
            auto left = cur->left, right = cur->right;
            dfs(left, cur);
            dfs(right, cur);
            if ((par == nullptr && !covered.count(cur)) || !covered.count(left) || !covered.count(right)) {
                res++;
                covered.insert(par);
                covered.insert(cur);
                covered.insert(left);
                covered.insert(right);
            }
        }
    }
};
