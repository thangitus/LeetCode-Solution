#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/spiral-matrix/
 * */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        int rowBegin, colBegin, rowEnd, colEnd;
        rowBegin = colBegin = 0, rowEnd = matrix.size() - 1, colEnd = matrix[0].size() - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; j++)  // Traverse Right
                result.push_back(matrix[rowBegin][j]);

            for (int i = ++rowBegin; i <= rowEnd; i++) // Traverse Down
                result.push_back(matrix[i][colEnd]);

            for (int j = --colEnd; rowBegin <= rowEnd && j >= colBegin; j--) // Traverse Left
                result.push_back(matrix[rowEnd][j]);

            for (int i = --rowEnd; colBegin <= colEnd && i >= rowBegin; i--) // Traver Up
                result.push_back(matrix[i][colBegin]);

            colBegin++;
        }
        return result;
    }
};
