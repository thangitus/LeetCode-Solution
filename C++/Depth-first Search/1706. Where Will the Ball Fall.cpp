#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        vector<int> result(grid[0].size());
        for (int i = 0; i < grid[0].size(); ++i)
            result[i] = dfs(grid, 0, i);
        return result;
    }

    int dfs(vector<vector<int>> &grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        if (x >= n) return y;
        if ((grid[x][y] == 1) && (y == m - 1 || grid[x][y + 1] == -1))
            return -1;
        if ((grid[x][y] == -1) && (y == 0 || grid[x][y - 1] == 1))
            return -1;
        return dfs(grid, x + 1, y + grid[x][y]);
    }
};
