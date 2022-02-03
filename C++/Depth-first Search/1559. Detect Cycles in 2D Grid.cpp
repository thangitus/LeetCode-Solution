#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<int>> depth;

    bool containsCycle(vector<vector<char>> &grid) {
        this->grid = grid;
        depth = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j) {
                if (dfs(i, j, i, j)) return true;
            }
        return false;
    }

    bool dfs(int x, int y, int prevX, int prevY) {
        if (depth[x][y])
            return depth[prevX][prevY] - depth[x][y] >= 3;
        depth[x][y] = depth[prevX][prevY] + 1;
        const int dx[]{-1, 0, 0, 1};
        const int dy[]{0, -1, 1, 0};
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
                continue;
            if (grid[nx][ny] == grid[x][y] && dfs(nx, ny, x, y))
                return true;
        }
        return false;
    }
};