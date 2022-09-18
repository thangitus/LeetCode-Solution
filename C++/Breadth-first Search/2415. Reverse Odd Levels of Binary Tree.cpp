#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;


class Solution {
public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        int level = 0;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            level++;
            vector<TreeNode *> arr;
            vector<int> nums;
            for (int i = queue.size(); i > 0; --i) {
                auto cur = queue.front();
                arr.push_back(cur);
                nums.push_back(cur->val);
                if (cur->left) {
                    queue.push(cur->left);
                    queue.push(cur->right);
                }
                queue.pop();
            }
            if (level % 2 == 0)
                reverse(nums.begin(), nums.end());
            for (int i = 0; i < arr.size(); ++i)
                arr[i]->val = nums[i];
        }
        return root;
    }
};