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
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};
        int level = -1;
        vector<vector<int>> ans;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            level++;
            vector<int> row;
            for (int i = queue.size() - 1; i >= 0; i--) {
                auto front = queue.front();
                if (front) {
                    row.push_back(front->val);
                    queue.push(front->left);
                    queue.push(front->right);
                }
                queue.pop();
            }
            if (level & 1) reverse(row.begin(), row.end());
            if (!row.empty())
                ans.push_back(row);
        }
        return ans;
    }
};