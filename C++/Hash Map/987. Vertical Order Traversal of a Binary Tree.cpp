#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        map<int, vector<int>> map;
        queue<pair<int, TreeNode *>> queue;
        queue.push({0, root});
        while (!queue.empty()) {
            vector<pair<int, TreeNode *>> row;
            while (!queue.empty()) row.push_back(queue.front()), queue.pop();
            sort(row.begin(), row.end(), [](pair<int, TreeNode *> &a, pair<int, TreeNode *> &b) {
                return a.second->val < b.second->val;
            });
            for (auto &cur: row) {
                map[cur.first].push_back(cur.second->val);
                if (cur.second->left)
                    queue.push({cur.first - 1, cur.second->left});
                if (cur.second->right)
                    queue.push({cur.first + 1, cur.second->right});
            }
        }
        vector<vector<int>> res;
        for (auto &item: map)
            res.push_back(item.second);
        return res;
    }
};