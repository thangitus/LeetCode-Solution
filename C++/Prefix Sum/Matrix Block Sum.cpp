#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/matrix-block-sum/
 * Refs: https://leetcode.com/problems/matrix-block-sum/discuss/477036/JavaPython-3-PrefixRange-sum-w-analysis-similar-to-LC-30478
 */

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> rangeSum(m + 1, vector<int>(n + 1));
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                rangeSum[i + 1][j + 1] = rangeSum[i + 1][j] + rangeSum[i][j + 1] - rangeSum[i][j] + mat[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k), c1 = max(0, j - k);
                int r2 = min(m, i + k + 1), c2 = min(n, j + k + 1);
                result[i][j] = rangeSum[r2][c2] - rangeSum[r2][c1] - rangeSum[r1][c2] + rangeSum[r1][c1];
            }
        return result;

    }
};
