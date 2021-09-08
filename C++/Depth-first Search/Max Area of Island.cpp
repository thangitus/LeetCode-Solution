#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/max-area-of-island/
 */

class Solution {
public:
    unsigned int n, m;

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, dfs(grid, i, j));
        return ans;
    }

    int dfs(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        int left = dfs(grid, x, y - 1);
        int right = dfs(grid, x, y + 1);
        int above = dfs(grid, x - 1, y);
        int under = dfs(grid, x + 1, y);
        return left + right + above + under + 1;
    }
};