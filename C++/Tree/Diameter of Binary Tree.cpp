#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;


/**
 * https://leetcode.com/problems/diameter-of-binary-tree/
 * */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int result = 0;
        maxDepth(root, result);
        return result;
    }

    int maxDepth(TreeNode *cur, int &result) {
        if (!cur) return 0;
        int left = maxDepth(cur->left, result);
        int right = maxDepth(cur->right, result);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
};