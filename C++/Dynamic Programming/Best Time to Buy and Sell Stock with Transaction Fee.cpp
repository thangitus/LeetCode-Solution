#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * */

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0], sell[0] = 0;
        for (int i = 1; i < n; i++) {
            int price = prices[i];
            buy[i] = max(sell[i - 1] - price, buy[i - 1]);
            sell[i] = max(buy[i - 1] + price - fee, sell[i - 1]);
        }
        return sell[n - 1];
    }
};
