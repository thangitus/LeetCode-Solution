#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/unique-paths-ii/
 * */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = obstacleGrid[0][0] == 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!obstacleGrid[i][j]) {
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        return obstacleGrid.back().back();
    }
};