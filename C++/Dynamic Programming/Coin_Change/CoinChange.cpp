#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));
        for (auto &row:dp) row[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= amount; j++) {
                int coin = coins[i - 1];
                if (j >= coin)
                    dp[i][j] = min(dp[i][j - coin] + 1, dp[i - 1][j]);
                else dp[i][j] = dp[i - 1][j];
            }
        return dp[n][amount] != INT_MAX - 1 ? dp[n][amount] : -1;
    }
};

