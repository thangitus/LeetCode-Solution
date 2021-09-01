#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/array-nesting/
 */

class Solution {
public:
    unordered_map<int, int> memo;

    int arrayNesting(vector<int> &nums) {
        int result = 0;
        for (int &num:nums)
            result = max(result, dfs(nums, num));
        return result;
    }

    int dfs(vector<int> &nums, int i) {
        if (memo[i]) return memo[i] - 1;
        memo[i] = 1;
        return dfs(nums, nums[i]) + 1;
    }
};