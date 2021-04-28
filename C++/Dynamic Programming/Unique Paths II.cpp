#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/unique-paths-ii/
 * */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][1] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j]) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) obstacleGrid[i][j] = 1;
                if (i > 0) obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                if (j > 0)obstacleGrid[i][j] += obstacleGrid[i][j - 1];
            }
        return obstacleGrid.back().back();
    }
};