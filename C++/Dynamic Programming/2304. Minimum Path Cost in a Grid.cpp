#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < m; ++i) dp[0][i] = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int k = 0; k < m; ++k) {
                int node = grid[i][k];
                for (int j = 0; j < m; ++j) {
                    int cost = moveCost[node][j];
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + cost + node);
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; ++i)
            res = min(res, dp[n - 1][i] + grid[n - 1][i]);
        return res;
    }
};

