#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long> dp(n + 10);
        int mod = 1e9 + 7;
        dp[0] = 1, dp[1] = 2;
        for (int i = 2; i <= n; ++i)
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        return dp[n] * dp[n] % mod;
    }
};