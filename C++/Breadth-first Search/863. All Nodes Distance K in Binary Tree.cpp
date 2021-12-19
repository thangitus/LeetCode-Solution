#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    unordered_map<TreeNode *, TreeNode *> parent;

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        buildParent(root);
        vector<int> result;
        queue<TreeNode *> queue;
        unordered_set<TreeNode *> set;
        queue.push(target);
        while (!queue.empty()) {
            for (int i = queue.size(); i > 0; i--) {
                auto cur = queue.front();
                queue.pop();
                set.insert(cur);
                result.push_back(cur->val);
                if (cur != root && !set.count(parent[cur]))
                    queue.push(parent[cur]);
                if (cur->left && !set.count(cur->left))
                    queue.push(cur->left);
                if (cur->right && !set.count(cur->right))
                    queue.push(cur->right);
            }
            if (k == 0) return result;
            else result.clear();
            k--;
        }
        return result;
    }

    void buildParent(TreeNode *node) {
        auto &left = node->left;
        auto &right = node->right;
        if (left) {
            parent[left] = node;
            buildParent(left);
        }
        if (right) {
            parent[right] = node;
            buildParent(right);
        }
    }
};
