#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * https://leetcode.com/problems/deepest-leaves-sum/
 * */

class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        queue<TreeNode *> queue;
        queue.push(root);
        int i, res = 0;
        while (!queue.empty()) {
            for (i = queue.size(), res = 0; i > 0; i--) {
                TreeNode *front = queue.front();
                queue.pop();
                res += front->val;
                if (front->left)
                    queue.push(front->left);
                if (front->right)
                    queue.push(front->right);
            }
        }
        return res;
    }
};