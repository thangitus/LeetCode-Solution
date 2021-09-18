#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/spiral-matrix-ii/
 * */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int rowBegin, colBegin, rowEnd, colEnd, k;
        rowBegin = colBegin = 0, rowEnd = n - 1, colEnd = n - 1, k = 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; j++)  // Traverse Right
                result[rowBegin][j] = k++;

            for (int i = ++rowBegin; i <= rowEnd; i++) // Traverse Down
                result[i][colEnd] = k++;

            for (int j = --colEnd; rowBegin <= rowEnd && j >= colBegin; j--) // Traverse Left
                result[rowEnd][j] = k++;

            for (int i = --rowEnd; colBegin <= colEnd && i >= rowBegin; i--) // Traver Up
                result[i][colBegin] = k++;

            colBegin++;
        }
        return result;
    }
};
