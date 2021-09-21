#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n, curMin, curMax, result = 0;
        n = prices.size(), curMin = prices[0], curMax = prices[n - 1];
        vector<int> left(n, INT_MIN), right(n, INT_MIN);
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], prices[i] - curMin);
            curMin = min(curMin, prices[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], curMax - prices[i]);
            curMax = max(curMax, prices[i]);
        }
        for (int i = 1; i < n - 2; i++)
            result = max(result, left[i] + right[i + 1]);

        result = max(result, left.back()); //1 transaction
        return result;
    }
};
