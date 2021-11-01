#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/n-queens-ii/
*/

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> col(n, -1);
        backtracking(result, col, n, 0);
        return result;
    }

    void backtracking(int &result, vector<int> &col, int n, int r) {
        if (r == n) {
            result++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (isValid(col, r, c)) {
                col[r] = c;
                backtracking(result, col, n, r + 1);
                col[r] = -1;
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