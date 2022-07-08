#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[101][101][21] = {}, m, n;
    const int MAX_COST = 1e6 + 1;
    vector<int> houses;
    vector<vector<int>> cost;

    int dfs(int i, int target, int prevColor) {
        if (i >= m) return target == 0 ? 0 : MAX_COST;
        if (target < 0) return MAX_COST;
        int res = MAX_COST;
        if (houses[i])
            return dfs(i + 1, target - (prevColor != houses[i]), houses[i]);
        else {
            if (dp[i][target][prevColor])
                return dp[i][target][prevColor];
            for (int color = 1; color <= n; ++color) {
                int result = dfs(i + 1, target - (prevColor != color), color);
                res = min(res, cost[i][color - 1] + result);
            }
        }
        return dp[i][target][prevColor] = res;
    }

    int minCost(vector<int> &h, vector<vector<int>> &c, int row, int col, int target) {
        this->m = row, this->n = col;
        this->houses = h, this->cost = c;
        int res = dfs(0, target, 0);
        return res > 1e6 ? -1 : res;
    }
};
