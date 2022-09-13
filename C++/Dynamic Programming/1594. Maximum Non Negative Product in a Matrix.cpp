#include <bits/stdc++.h>

using namespace std;

typedef long long LONG;

class Solution {
public:
    int maxProductPath(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), mod = 1e9 + 7;
        vector<vector<LONG>> highest(n, vector<LONG>(m));
        vector<vector<LONG>> lowest(n, vector<LONG>(m));
        highest[0][0] = lowest[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i)
            highest[i][0] = lowest[i][0] = (grid[i][0] * highest[i - 1][0]);
        for (int i = 1; i < m; ++i)
            highest[0][i] = lowest[0][i] = (grid[0][i] * highest[0][i - 1]);

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j) {
                LONG v = grid[i][j];
                auto maxVal = max(highest[i - 1][j], highest[i][j - 1]);
                auto minVal = min(lowest[i - 1][j], lowest[i][j - 1]);
                highest[i][j] = max(maxVal * v, minVal * v);
                lowest[i][j] = min(maxVal * v, minVal * v);
            }

        return highest[n - 1][m - 1] >= 0 ? int(highest[n - 1][m - 1] % mod) : -1;
    }
};
