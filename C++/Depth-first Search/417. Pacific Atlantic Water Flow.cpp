#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int n, m;

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int x, int y, int height) {
        if (x < 0 || x >= n || y < 0 || y >= m || ocean[x][y]) return;
        if (heights[x][y] < height) return;
        ocean[x][y] = true;
        for (int k = 0; k < 4; k++)
            dfs(heights, ocean, x + dx[k], y + dy[k], heights[x][y]);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific, atlantic;
        pacific = atlantic = vector<vector<bool>>(n, vector<bool>(m));

        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, pacific, i, 0, INT_MIN);
            dfs(heights, atlantic, i, m - 1, INT_MIN);
        }
        for (int j = 0; j < heights[0].size(); j++) {
            dfs(heights, pacific, 0, j, INT_MIN);
            dfs(heights, atlantic, n - 1, j, INT_MIN);
        }
        vector<vector<int>> result;
        for (int i = 0; i < heights.size(); i++)
            for (int j = 0; j < heights[0].size(); j++)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});

        return result;
    }
};
