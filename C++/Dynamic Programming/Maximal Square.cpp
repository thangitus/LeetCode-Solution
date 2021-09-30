#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/maximal-square/
 * */

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] == '1';
            result = max(result, dp[i][0] * dp[i][0]);
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] == '1';
            result = max(result, dp[0][j] * dp[0][j]);
        }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') continue;
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                result = max(result, dp[i][j] * dp[i][j]);
            }
        return result;
    }
};
