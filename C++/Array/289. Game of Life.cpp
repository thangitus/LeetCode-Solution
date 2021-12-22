#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int n = board.size(), m = board[0].size();
        const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                bool isLive = board[i][j];
                int countLive = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    countLive += board[x][y] > 0;
                }
                if (isLive) board[i][j] += countLive;
                else board[i][j] = -countLive;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                bool isLive = board[i][j] > 0;
                int countLive = abs(board[i][j]);
                if (isLive) {
                    if (countLive == 3 || countLive == 4) board[i][j] = 1;
                    else board[i][j] = 0;
                } else if (abs(countLive) == 3) board[i][j] = 1;
                else board[i][j] = 0;
            }
    }
};
