#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/number-of-closed-islands/
 * */

class Solution {
public:
    int closedIsland(vector<vector<int>> &grid) {
        queue<pair<int, int>> queue;
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); ++j)
                result += !grid[i][j] && isClosedIsland(grid, i, j);
        return result;
    }

    bool isClosedIsland(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return false;
        if (grid[x][y]) return true;
        grid[x][y] = 1;
        bool top = isClosedIsland(grid, x - 1, y);
        bool down = isClosedIsland(grid, x + 1, y);
        bool left = isClosedIsland(grid, x, y - 1);
        bool right = isClosedIsland(grid, x, y + 1);
        return top && down && left && right;
    }
};

