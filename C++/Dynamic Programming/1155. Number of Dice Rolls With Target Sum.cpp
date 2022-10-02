#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
                for (auto t = j; t <= target; ++t) {
                    dp[i][t] += dp[i - 1][t - j];
                    dp[i][t] %= mod;
                }

        return dp[n][target];
    }
};
