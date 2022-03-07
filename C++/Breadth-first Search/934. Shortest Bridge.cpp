#include <bits/stdc++.h>
#include "../Tree/TreeNode.h"

using namespace std;

class Solution {
private:
    queue<pair<int, int>> queue;
public:
    int shortestBridge(vector<vector<int>> &grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; queue.empty() && j < n; ++j)
                paint(grid, i, j);
        while (!queue.empty()) {
            for (int k = queue.size(); k > 0; --k) {
                auto cur = queue.front();
                int i = cur.first, j = cur.second;
                queue.pop();
                for (int d = 0; d < 4; ++d) {
                    int x = i + dir[d], y = j + dir[d + 1];
                    if (min(x, y) >= 0 && max(x, y) < grid.size()) {
                        if (grid[x][y] == 1)
                            return grid[i][j] - 2;
                        if (grid[x][y] == 0) {
                            grid[x][y] = grid[i][j] + 1;
                            queue.push({x, y});
                        }
                    }
                }
            }
        }
        return 0;
    }

    int dir[5] = {0, 1, 0, -1, 0};

    void paint(vector<vector<int>> &grid, int i, int j) {
        if (min(i, j) >= 0 && max(i, j) < grid.size() && grid[i][j] == 1) {
            grid[i][j] = 2;
            queue.push({i, j});
            for (int d = 0; d < 4; ++d)
                paint(grid, i + dir[d], j + dir[d + 1]);
        }
    }
};
