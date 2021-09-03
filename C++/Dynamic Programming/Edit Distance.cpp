#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/edit-distance/
 * Refs: https://www.youtube.com/watch?v=We3YDTzNXEk
 * */

class Solution {
public:
    int minDistance(string word1, string word2) {
        unsigned int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                if (word1[j - 1] == word2[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }

        return dp[m][n];
    }
};