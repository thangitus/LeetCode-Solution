#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &a) {
        long res = 0, mod = 1e9 + 7;
        unordered_map<int, long> dp;
        std::sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); ++i) {
            int num = a[i];
            dp[num] = 1;
            for (int j = 0; j < i; ++j)
                if (num % a[j] == 0) {
                    dp[num] += dp[a[j]] * dp[num / a[j]];
                    dp[num] %= mod;
                }
            res = (res + dp[num]) % mod;
        }
        return res;
    }
};
