#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/partition-array-for-maximum-sum/
 * */

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int curMax = 0;
            for (int j = 1; j <= k && i - j >= 0; j++) {
                curMax = max(curMax, nums[i - j]);
                dp[i] = max(dp[i], dp[i - j] + curMax * j);
            }
        }
        return dp[n];
    }
};
