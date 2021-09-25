#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
 * */

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, int k) {
        const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
        int m = grid.size(), n = grid[0].size(), step = 0;
        vector<vector<int>> remains(m, vector<int>(n, INT_MIN));
        queue<vector<int>> queue;
        queue.push({0, 0, k}), remains[0][0] = k;
        while (!queue.empty()) {
            for (int k = queue.size(); k > 0; k--) {
                auto cur = queue.front();
                queue.pop();
                if (cur[0] == m - 1 && cur[1] == n - 1) return step;
                for (int i = 0; i < 4; i++) {
                    int x = cur[0] + dx[i], y = cur[1] + dy[i];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    int remain = cur[2] - grid[x][y];
                    if (remain >= 0 && remain > remains[x][y]) {
                        queue.push({x, y, remain});
                        remains[x][y] = remain;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
