#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size(), m = matrix[0].size(), left = matrix[0][0], right = matrix[n - 1][m - 1], res;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k)
                res = mid, right = mid - 1;
            else left = mid + 1;
        }
        return res;
    }

    int countLessOrEqual(vector<vector<int>> &matrix, int mid) {
        int r = 0, c = matrix[0].size() - 1, res = 0;
        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] <= mid) res += c + 1, r++;
            else c--;
        }
        return res;
    }
};