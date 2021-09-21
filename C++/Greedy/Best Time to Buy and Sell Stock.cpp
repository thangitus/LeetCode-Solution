#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX, result = 0;
        for (int &price:prices) {
            minPrice = min(minPrice, price);
            result = max(result, price - minPrice);
        }
        return result;
    }
};
