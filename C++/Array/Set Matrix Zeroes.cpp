#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/set-matrix-zeroes/
 */

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstCol = false;
        for (int i = 0; i < n; i++) {
            if (!matrix[i][0]) firstCol = true;
            for (int j = 1; j < m; j++)
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j > 0; j--)
                if (!matrix[0][j] || !matrix[i][0])
                    matrix[i][j] = 0;
            if (firstCol) matrix[i][0] = 0;
        }
    }
};