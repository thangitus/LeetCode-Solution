#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == j || i == (m - j)) {
                    if (grid[i][j] == 0) return false;
                } else if (grid[i][j] != 0) return false;
            }
        }
        return true;
    }
};