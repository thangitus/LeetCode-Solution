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
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * */

class Solution {
private:
    vector<int> nums;
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        this->nums = nums;

        return sortedArrayToBST(0, nums.size() - 1);
    }

    TreeNode *sortedArrayToBST(int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        auto *ans = new TreeNode(nums[mid]);
        ans->left = sortedArrayToBST(left, mid - 1);
        ans->right = sortedArrayToBST(mid + 1, right);
        return ans;
    }
};