#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/combination-sum-iv/
 * */

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<long> dp(target + 1);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int &num:nums) {
                if (num > i) break;
                dp[i] += dp[i - num];
                if (dp[i] >= INT_MAX) dp[i] = 0;
            }
        }
        return dp[target];
    }
};
