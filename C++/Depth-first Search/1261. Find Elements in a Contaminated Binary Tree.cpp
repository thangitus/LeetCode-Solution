#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class FindElements {
public:
    unordered_set<int> contain;

    FindElements(TreeNode *root) {
        dfs(root, 0);
    }

    void dfs(TreeNode *node, int val) {
        if (!node) return;
        contain.insert(val);
        dfs(node->left, val * 2 + 1);
        dfs(node->right, val * 2 + 2);
    }

    bool find(int target) {
        return contain.count(target);
    }
};
