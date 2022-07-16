#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/out-of-boundary-paths/
 * */

class Solution {
private:
    long memo[50][50][51];
    int MOD = 1e9 + 7;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo,-1, sizeof(memo));
        return dp(m, n, maxMove, startRow, startColumn);
    }

    long dp(int m, int n, int move, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return 1;
        if (move == 0) return 0;
        if (memo[row][col][move] != -1)
            return memo[row][col][move];
        memo[row][col][move] = 0;
        for (auto dir : dirs) {
            int x = dir[0] + row;
            int y = dir[1] + col;
            memo[row][col][move] += dp(m, n, move - 1, x, y) % MOD;
        }
        return memo[row][col][move] % MOD;
    }
};