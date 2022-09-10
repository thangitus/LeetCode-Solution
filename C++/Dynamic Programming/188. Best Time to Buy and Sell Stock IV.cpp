#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (!k || n < 2) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(n));
        for (int i = 0; i <= k; ++i) dp[i][0] = 0;
        for (int j = 0; j < n; j++) dp[0][j] = 0;

        // t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1])
        // prices[j] + t:0->j-1 max(dp[i-1][t-1]-prices[t])
        // maxTemp = t:0->j-1 max(dp[i-1][t-1]-prices[t])

        for (int i = 1; i <= k; ++i) {
            int maxTemp = -prices[0];
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxTemp);
                maxTemp = max(maxTemp, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp.back().back();
    }
};