#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/path-with-maximum-gold/
*/

class Solution {
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), result = 0;
        vector<vector<bool>> visited(n, vector<bool>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j])
                    result = max(result, backtracking(grid, i, j, visited));
            }
        return result;
    }

    int backtracking(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited) {
        const int dx[]{-1, 0, 0, 1};
        const int dy[]{0, -1, 1, 0};
        visited[x][y] = true;
        int result = 0;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size()) continue;
            if (grid[newX][newY] && !visited[newX][newY])
                result = max(result, backtracking(grid, newX, newY, visited));
        }
        visited[x][y] = false;
        return result + grid[x][y];
    }
};