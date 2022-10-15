#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const static int MAX = 100;
    int dp[MAX][MAX], n;
    string s;

    int length(int x) {
        if (x == 1) return 0;
        int count = 0;
        while (x) count++, x /= 10;
        return count;
    }

    int solve(int start, int k) {
        if (k < 0) return MAX;
        if (n - start <= k || start >= n) return 0;
        if (dp[start][k] == -1) {
            dp[start][k] = MAX;
            int count[26] = {0}, most = 0;
            for (int i = start; i < n; ++i) {
                most = max(most, ++count[s[i] - 'a']);
                int remove = (i - start + 1) - most;
                dp[start][k] = min(dp[start][k], 1 + length(most) + solve(i + 1, k - remove));
            }
        }
        return dp[start][k];
    }

    int getLengthOfOptimalCompression(string str, int k) {
        memset(dp, -1, sizeof(dp));
        s = str, n = s.size();
        return solve(0, k);
    }
};
