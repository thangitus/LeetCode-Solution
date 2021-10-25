#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/subsets/
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> cur;
        backTracking(result, 0, nums, cur);
        return result;
    }

    void backTracking(vector<vector<int>> &result, int start, vector<int> &nums, vector<int> &current) {
        result.push_back(current);
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backTracking(result, i + 1, nums, current);
            current.pop_back();
        }
    }
};