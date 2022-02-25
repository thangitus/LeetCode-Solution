#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int numIslands(vector<vector<char>> &grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                result += dfs(grid, i, j);
        return result;
    }

    int dfs(vector<vector<char>> &grid, int x, int y) {
        if (grid[x][y] == '0') return 0;
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size()) continue;
            dfs(grid, newX, newY);
        }
        return 1;
    }
};
