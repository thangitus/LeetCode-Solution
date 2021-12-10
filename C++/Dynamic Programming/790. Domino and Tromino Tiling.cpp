#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1%2Bdpn-3
 * */

class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        long long dp[1001]{1, 1, 2, 5};
        for (int i = 4; i <= n; i++)
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
        return dp[n];
    }
};
