#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/minimum-falling-path-sum/
 * */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0] = matrix[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
                if (j < n - 1) dp[i][j] = min(dp[i - 1][j + 1], dp[i][j]);
                dp[i][j] += matrix[i][j];
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};