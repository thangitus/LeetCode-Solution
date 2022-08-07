#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<unordered_map<char, long>> dp(n);
        int mod = 1e9 + 7;
        dp[0]['a'] = dp[0]['e'] = dp[0]['i'] = dp[0]['o'] = dp[0]['u'] = 1;
        for (int i = 0; i < n - 1; ++i) {
            dp[i + 1]['a'] = (dp[i]['e'] + dp[i]['i'] + dp[i]['u']) % mod;
            dp[i + 1]['e'] = (dp[i]['a'] + dp[i]['i']) % mod;
            dp[i + 1]['i'] = (dp[i]['e'] + dp[i]['o']) % mod;
            dp[i + 1]['o'] = (dp[i]['i']) % mod;
            dp[i + 1]['u'] = (dp[i]['i'] + dp[i]['o']) % mod;
        }
        int res = 0;
        for (auto &i: dp.back())
            res += i.second, res %= mod;
        return res;
    }
};
