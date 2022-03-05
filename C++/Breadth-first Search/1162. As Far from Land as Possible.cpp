#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        const int dx[]{-1, 0, 0, 1};
        const int dy[]{0, -1, 1, 0};
        queue<pair<int, int>> queue;
        int n = grid.size(), m = grid[0].size(), result = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j]) queue.push({i, j});
        if (queue.empty() || queue.size() == n * m) return -1;
        while (!queue.empty()) {
            result++;
            for (int i = queue.size(); i > 0; --i) {
                auto cur = queue.front();
                queue.pop();
                for (int k = 0; k < 4; k++) {
                    int x = cur.first + dx[k];
                    int y = cur.second + dy[k];
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    if (grid[x][y] == 0) {
                        queue.push({x, y});
                        grid[x][y] = 1;
                    }
                }
            }
        }
        return result;
    }
};
