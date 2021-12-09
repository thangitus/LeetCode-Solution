#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid, int result = 0) {
        queue<pair<int, int>> queue;
        for (auto i = 0; i < grid.size(); ++i)
            for (auto j = 0; j < grid[0].size(); ++j) {
                result += grid[i][j];
                if (i * j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1)
                    queue.push({i, j});
            }
        while (!queue.empty()) {
            auto x = queue.front().first, y = queue.front().second;
            queue.pop();
            if (x < 0 || y < 0 || x == grid.size() || y == grid[x].size() || grid[x][y] != 1)
                continue;
            grid[x][y] = 0;
            --result;
            queue.push({x + 1, y});
            queue.push({x - 1, y});
            queue.push({x, y + 1});
            queue.push({x, y - 1});
        }
        return result;
    }
};
