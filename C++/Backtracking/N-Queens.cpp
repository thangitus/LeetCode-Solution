#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/n-queens/
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n, -1);
        string row;
        while (row.length() < n) row += '.';
        vector<string> cur(n, row);
        vector<vector<string>> result;
        backtracking(result, cur, col, n, 0);
        return result;
    }

    void backtracking(vector<vector<string>> &result, vector<string> &cur, vector<int> &col, int n, int r) {
        if (r == n) {
            result.push_back(cur);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (isValid(col, r, c)) {
                col[r] = c;
                cur[r][c] = 'Q';
                backtracking(result, cur, col, n, r + 1);
                col[r] = -1;
                cur[r][c] = '.';
            }
        }
    }

    bool isValid(vector<int> &col, int r, int c) {
        for (int i = 0; i < r; i++)
            if (col[i] == c || abs(col[i] - c) == abs(i - r))
                return false;
        return true;
    }
};