#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<int, TreeNode *> map;
        unordered_set<int> child;
        for (auto &item: descriptions) {
            if (!map.count(item[0]))
                map[item[0]] = new TreeNode(item[0]);
            if (!map.count(item[1]))
                map[item[1]] = new TreeNode(item[1]);
            if (item[2]) map[item[0]]->left = map[item[1]];
            else map[item[0]]->right = map[item[1]];
            child.insert(item[1]);
        }
        for (auto &item: descriptions)
            if (!child.count(item[0])) return map[item[0]];
        return nullptr;
    }
};
