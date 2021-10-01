#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/longest-common-subsequence/
 * */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        return dp[n][m];
    }
};
