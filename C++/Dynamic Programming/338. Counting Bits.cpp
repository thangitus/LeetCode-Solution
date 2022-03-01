#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        int cur = 1;
        while (cur <= n) {
            int i = 0;
            while (i < cur && i + cur <= n) {
                dp[i + cur] = dp[i] + 1;
                ++i;
            }
            cur <<= 1;
        }
        return dp;
    }
};
