#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/reshape-the-matrix/
 * */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        auto n = mat.size(), m = mat[0].size();
        if (n * m != r * c) return mat;
        vector<vector<int>> result(r, vector<int>(c));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int index = i * m + j;
                result[index / c][index % c] = mat[i][j];
            }
        return result;
    }
};
