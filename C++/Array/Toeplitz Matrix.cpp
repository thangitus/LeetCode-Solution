#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/toeplitz-matrix/
 */

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        unsigned int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int r = i, c = 0;
            while (r < m && c < n)
                if (matrix[r++][c++] != matrix[i][0])
                    return false;
        }
        for (int j = 0; j < n; j++) {
            int r = 0, c = j;
            while (r < m && c < n)
                if (matrix[r++][c++] != matrix[0][j])
                    return false;
        }
        return true;
    }
};