#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> degree(n, vector<int>(m));
        const int dx[]{-1, 0, 0, 1};
        const int dy[]{0, -1, 1, 0};
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < m; ++c)
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dx[i], nc = c + dy[i];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    degree[r][c] += matrix[nr][nc] < matrix[r][c];
                }
        int result = 0;
        queue<pair<int, int>> queue;
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < m; ++c)
                if (degree[r][c] == 0)
                    queue.push({r, c});
        while (!queue.empty()) {
            result++;
            for (int i = queue.size(); i > 0; --i) {
                int r = queue.front().first, c = queue.front().second;
                queue.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + dx[k], nc = c + dy[k];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (matrix[nr][nc] > matrix[r][c] && --degree[nr][nc] == 0)
                        queue.push({nr, nc});
                }
            }
        }
        return result;
    }
};
