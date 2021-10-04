#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/island-perimeter/
 * */

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int perimeter = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    perimeter += 4;
                    if (i > 0 && grid[i - 1][j]) perimeter -= 1;
                    if (i < m - 1 && grid[i + 1][j]) perimeter -= 1;
                    if (j > 0 && grid[i][j - 1]) perimeter -= 1;
                    if (j < n - 1 && grid[i][j + 1]) perimeter -= 1;
                }
        return perimeter;
    }
};
