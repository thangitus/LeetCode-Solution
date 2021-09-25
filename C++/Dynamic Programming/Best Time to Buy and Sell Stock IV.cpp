#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * */

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (!k || len < 2) return 0;         // edge cases away
        // fixing k to be a meaningful, even number
        k = min(k * 2, len - len % 2);
        // declaring and setting up dp
        int dp[k];
        for (int i = 0; i < k; i++) dp[i] = i % 2 ? 0 : INT_MAX;
        for (int currPrice: prices) {
            // setting up the first dp element
            dp[0] = min(dp[0], currPrice);
            // updating dp with all the subsequent trades
            for (int i = 1; i < k; i++) {
                dp[i] = i % 2  ? max(dp[i], currPrice - dp[i - 1]) : min(dp[i], currPrice - dp[i - 1]);
            }
        }
        return dp[k - 1];
    }
};