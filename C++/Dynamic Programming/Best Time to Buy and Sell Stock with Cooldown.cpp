#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * Refs: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process
 * */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> buy(n), sell(n), rest(n);
        rest[0] = 0, buy[0] = -prices[0], sell[0] = INT_MIN;
        for (int i = 1; i < n; i++) {
            int price = prices[i];
            buy[i] = max(rest[i - 1] - price, buy[i - 1]);
            sell[i] = max(buy[i - 1] + price, sell[i - 1]);
            rest[i] = max(sell[i - 1], rest[i - 1]);
        }
        return max(sell[n - 1], rest[n - 1]);
    }
};
