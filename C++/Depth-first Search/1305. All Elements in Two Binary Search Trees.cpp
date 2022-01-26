#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;


class Solution {
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> nums1, nums2, result;
        dfs(root1, nums1);
        dfs(root2, nums2);
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                result.push_back(nums1[i++]);
            else result.push_back(nums2[j++]);
        }
        while (i < nums1.size())
            result.push_back(nums1[i++]);
        while (j < nums2.size())
            result.push_back(nums2[j++]);
        return result;
    }

    void dfs(TreeNode *root, vector<int> &nums) {
        if (!root) return;
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
};
