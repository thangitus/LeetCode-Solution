#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> heights;
    int n, m;

    int minimumEffortPath(vector<vector<int>> &matrix) {
        this->heights = matrix;
        n = heights.size(), m = heights[0].size();
        int left = 0, right = 1e6;
        while (left <= right) {
            int mid = (left + right) / 2;
            vector<vector<bool>> visited(n, vector<bool>(m));
            if (dfs(visited, mid, 0, 0))
                right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    bool dfs(vector<vector<bool>> &visited, int threshold, int x, int y) {
        const int dir[]{0, 1, 0, -1, 0};
        if (x == n - 1 && y == m - 1) return true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i], ny = y + dir[i + 1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny] || abs(heights[nx][ny] - heights[x][y]) > threshold) continue;
            visited[nx][ny] = true;
            if (dfs(visited, threshold, nx, ny)) return true;
        }
        return false;
    }
};
