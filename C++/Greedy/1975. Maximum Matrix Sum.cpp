#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix) {
        long long sum = 0, countNeg = 0;
        int minVal = INT_MAX;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++) {
                minVal = min(minVal, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
                countNeg += matrix[i][j] < 0;
            }
        return countNeg % 2 ? sum - 2 * minVal : sum;
    }
};
