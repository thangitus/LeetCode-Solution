#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        for (int i = 0; i < n; ++i)
            std::sort(grid[i].begin(), grid[i].end());
        for (int j = 0; j < m; ++j) {
            int maxVal = 0;
            for (int i = 0; i < n; ++i)
                maxVal = max(maxVal, grid[i][j]);
            res += maxVal;
        }
        return res;
    }
};
