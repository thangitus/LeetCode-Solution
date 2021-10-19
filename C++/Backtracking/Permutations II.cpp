#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/permutations-ii/
*/

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        distinctPermutation(nums, 0, nums.size());
        return result;
    }

    bool shouldSwap(vector<int> &nums, int start, int end) {
        for (int i = start; i < end; i++)
            if (nums[i] == nums[end]) return false;
        return true;
    }

    void distinctPermutation(vector<int> &nums, int left, int right) {
        if (left >= right) {
            result.push_back(nums);
            return;
        }
        for (int i = left; i < right; i++) {
            if (shouldSwap(nums, left, i)) {
                swap(nums[left], nums[i]);
                distinctPermutation(nums, left + 1, right);
                swap(nums[left], nums[i]);
            }
        }
    }
};