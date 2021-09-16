#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/largest-submatrix-with-rearrangements/
 * */

class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        vector<int> height(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (matrix[i][j]) height[j]++;
                else height[j] = 0;
            auto sorted = height;
            sort(sorted.begin(), sorted.end());
            for (int j = 0; j < n; j++)
                result = max(result, sorted[j] * (n - j));
        }
        return result;
    }
};
