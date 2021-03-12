#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= amount; j++) {
                int coin = coins[i];
                if (j >= coin)
                    dp[j] = min(dp[j - coin] + 1, dp[j]);
            }
        return dp[amount] != INT_MAX - 1 ? dp[amount] : -1;
    }
};


