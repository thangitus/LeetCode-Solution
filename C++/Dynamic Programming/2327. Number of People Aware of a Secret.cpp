#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n + 1);
        dp[1] = 1;
        long sum = 0, mod = 1e9 + 7, res = 0;
        for (int i = 2; i <= n; ++i) {
            auto forgot = dp[max(i - forget, 0)];
            auto newPeople = dp[max(i - delay, 0)];
            sum = (sum + newPeople - forgot + mod) % mod;
            dp[i] = sum;
        }
        for (int i = n - forget + 1; i <= n; ++i)
            res = (res + dp[i]) % mod;
        return (int) res;
    }
};
