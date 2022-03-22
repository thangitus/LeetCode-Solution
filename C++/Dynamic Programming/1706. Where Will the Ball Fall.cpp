#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> result(m);
        for (int i = 0; i < m; i++) result[i] = i;
        for (int i = 0; i < n; ++i)
            for (int &pos: result) {
                if (pos == -1) continue;
                if ((grid[i][pos] == 1) && (pos == m - 1 || grid[i][pos + 1] == -1)) {
                    pos = -1;
                    continue;
                }
                if ((grid[i][pos] == -1) && (pos == 0 || grid[i][pos - 1] == 1)) {
                    pos = -1;
                    continue;
                }
                pos += grid[i][pos];
            }
        return result;
    }
};
