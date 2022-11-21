#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        const int dx[]{-1, 0, 0, 1};
        const int dy[]{0, -1, 1, 0};
        queue<pair<int, int>> queue;
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        int res = 0;
        visited[entrance[0]][entrance[1]] = true;
        queue.push({entrance[0], entrance[1]});
        while (!queue.empty()) {
            res++;
            for (int k = queue.size(); k > 0; --k) {
                auto cur = queue.front();
                queue.pop();
                for (int i = 0; i < 4; ++i) {
                    int newX = cur.first + dx[i], newY = cur.second + dy[i];
                    if (newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
                    if (!visited[newX][newY] && maze[newX][newY] == '.') {
                        if (newX == 0 || newX == n - 1 || newY == 0 || newY == m - 1) return res;
                        queue.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
        }
        return -1;
    }
};
