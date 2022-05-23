#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int count[2];
        for (auto &s: strs) {
            count[0] = count[1] = 0;
            for (char &c: s) count[c - '0']++;
            for (int i = m; i >= count[0]; --i)
                for (int j = n; j >= count[1]; --j)
                    dp[i][j] = max(dp[i][j],
                                   dp[i - count[0]][j - count[1]] + 1);
        }
        return dp[m][n];
    }
};
