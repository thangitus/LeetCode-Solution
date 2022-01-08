#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[70][70][70] = {};

    int cherryPickup(vector<vector<int>> &grid) {
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0, grid[0].size() - 1);
    }

    int dfs(vector<vector<int>> &grid, int r, int c1, int c2) {
        if (r == grid.size()) return 0;
        if (dp[r][c1][c2] == -1) {
            for (int i = -1; i <= 1; ++i)
                for (int j = -1; j <= 1; ++j) {
                    int nc1 = c1 + i, nc2 = c2 + j, n = grid[0].size();
                    if (nc1 < 0 || nc1 >= n || nc2 < 0 || nc2 >= n) continue;
                    dp[r][c1][c2] = max(dp[r][c1][c2], dfs(grid, r + 1, nc1, nc2));
                }
        }
        int cherry = c1 != c2 ? grid[r][c1] + grid[r][c2] : grid[r][c1];
        return dp[r][c1][c2] + cherry;
    }
};
