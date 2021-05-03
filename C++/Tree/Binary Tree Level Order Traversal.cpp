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

/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 * */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            vector<int> level;
            for (int i = queue.size() - 1; i >= 0; i--) {
                auto front = queue.front();
                if (front) {
                    level.push_back(front->val);
                    queue.push(front->left);
                    queue.push(front->right);
                }
                queue.pop();
            }
            if (!level.empty())
                ans.push_back(level);
        }
        return ans;
    }
};