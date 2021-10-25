#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/
 * */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid[0][0]) return -1;
        const int dx[]{-1, -1, -1, 0, 0, 1, 1, 1};
        const int dy[]{-1, 0, 1, -1, 1, -1, 0, 1};
        int n = grid.size(), result = 1;
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        while (!queue.empty()) {
            for (int i = queue.size(); i > 0; i--) {
                auto x = queue.front().first, y = queue.front().second;
                queue.pop();
                if (x == n - 1 && y == n - 1) return result;
                for (int j = 0; j < 8; j++) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
                    if (grid[newX][newY]) continue;
                    queue.push({newX, newY});
                    grid[newX][newY] = 1;
                }
            }
            result++;
        }
        return -1;
    }
};
