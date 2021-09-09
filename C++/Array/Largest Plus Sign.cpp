#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/largest-plus-sign/
 */

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto mine : mines) grid[mine[0]][mine[1]] = 0;
        vector<vector<int>> left, right, top, bot;
        left = right = top = bot = grid;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = n - i - 1;
                int y = n - j - 1;
                if ((i > 0) && top[i][j]) top[i][j] += top[i - 1][j];
                if ((j > 0) && left[i][j]) left[i][j] += left[i][j - 1];
                if ((x < n - 1) && bot[x][y]) bot[x][y] += bot[x + 1][y];
                if ((y < n - 1) && right[x][y]) right[x][y] += right[x][y + 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int minLength = min({left[i][j], right[i][j], top[i][j], bot[i][j]});
                ans = max(ans, minLength);
            }
        return ans;
    }
};
