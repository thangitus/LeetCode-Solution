#include <bits/stdc++.h>

using namespace std;
/*
 * https://leetcode.com/problems/russian-doll-envelopes/
 * */
class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        int ans = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        return ans;
    }
};