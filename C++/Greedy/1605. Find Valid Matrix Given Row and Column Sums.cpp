#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        int row = rowSum.size(), col = colSum.size();
        vector<vector<int>> result(row, vector<int>(col));
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j) {
                int value = min(rowSum[i], colSum[j]);
                result[i][j] = value;
                rowSum[i] -= value, colSum[j] -= value;
            }
        return result;
    }
};

