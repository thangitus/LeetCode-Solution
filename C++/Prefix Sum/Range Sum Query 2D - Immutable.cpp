#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/range-sum-query-2d-immutable/
 */

class NumMatrix {
private:
    vector<vector<int>> rangeSum;
    int m, n;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix.size(), n = matrix[0].size();
        rangeSum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                rangeSum[i + 1][j + 1] = rangeSum[i + 1][j] + rangeSum[i][j + 1] - rangeSum[i][j] + matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        col2 += 1, row2 += 1;
        return rangeSum[row2][col2] - rangeSum[row2][col1] - rangeSum[row1][col2] + rangeSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */