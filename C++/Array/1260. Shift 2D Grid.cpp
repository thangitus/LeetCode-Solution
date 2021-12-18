#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size(), size = m * n, nums[size], start = size - k % size;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                nums[i * n + j] = grid[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                grid[i][j] = nums[start % size];
                start++;
            }
        return grid;
    }
};
