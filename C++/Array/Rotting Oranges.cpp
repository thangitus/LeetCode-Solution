#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/rotting-oranges/
 * */

class Solution {
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

public:
    int orangesRotting(vector<vector<int>> &grid) {
        queue<pair<int, int>> queue;
        int fresh = 0, res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 2) queue.push(make_pair(i, j));
                else if (grid[i][j] == 1) fresh++;

        while (!queue.empty()) {
            for (unsigned int i = queue.size(); i > 0; i--) {
                auto cur = queue.front();
                queue.pop();
                for (int k = 0; k < 4; k++) {
                    int x = cur.first + dx[k];
                    int y = cur.second + dy[k];
                    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) continue;
                    if (grid[cur.first + dx[k]][cur.second + dy[k]] == 1) {
                        queue.push(make_pair(x, y));
                        grid[x][y] = 2;
                        fresh--;
                    }
                }
            }
            if (!queue.empty()) res++;
        }
        return fresh == 0 ? res : -1;
    }
};