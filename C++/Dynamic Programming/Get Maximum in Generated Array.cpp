#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/get-maximum-in-generated-array/
 * */

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) return n;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        int res = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i / 2];
            dp[i] += i % 2 ? dp[i / 2 + 1] : 0;
            res = max(res, dp[i]);
        }
        return res;
    }
};