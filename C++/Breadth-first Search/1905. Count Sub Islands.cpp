#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        int result = 0;
        for (int i = 0; i < grid1.size(); ++i)
            for (int j = 0; j < grid1[0].size(); ++j)
                result += isSubIsland(grid1, grid2, i, j);
        return result;
    }

    bool isSubIsland(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j) {
        if (!grid2[i][j]) return false;
        const int dx[]{-1, 0, 0, 1};
        const int dy[]{0, -1, 1, 0};
        bool result = grid1[i][j];
        queue<pair<int, int>> queue;
        queue.push({i, j});
        while (!queue.empty()) {
            auto u = queue.front();
            queue.pop();
            for (int k = 0; k < 4; ++k) {
                int x = u.first + dx[k], y = u.second + dy[k];
                if (x < 0 || x >= grid1.size() || y < 0 || y >= grid1[0].size())
                    continue;
                if (grid2[x][y]) {
                    if (grid1[x][y] == 0)
                        result = false;
                    grid2[x][y] = 0;
                    queue.push({x, y});
                }
            }
        }
        return result;
    }
};
