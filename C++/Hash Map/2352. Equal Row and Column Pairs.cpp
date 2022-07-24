#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        map<vector<int>, int> count;
        int res = 0, n = grid.size();
        for (auto &row: grid) count[row]++;
        for (int j = 0; j < n; ++j) {
            vector<int> column;
            for (int i = 0; i < n; ++i)
                column.push_back(grid[i][j]);
            res += count[column];
        }
        return res;
    }
};