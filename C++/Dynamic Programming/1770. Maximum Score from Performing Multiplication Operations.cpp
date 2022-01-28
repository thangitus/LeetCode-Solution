#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, m, dp[1000][1000];

    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        n = nums.size(), m = multipliers.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums, multipliers);
    }

    int solve(int left, int i, vector<int> &nums, vector<int> &multipliers) {
        if (i == m) return 0;
        if (dp[left][i] == -1) {
            int leftPick = solve(left + 1, i + 1, nums, multipliers) + nums[left] * multipliers[i];
            int rightPick = solve(left, i + 1, nums, multipliers) + nums[n - (i - left) - 1] * multipliers[i];
            dp[left][i] = max(leftPick, rightPick);
        }
        return dp[left][i];
    }
};
