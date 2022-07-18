#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), res = 0, cur;
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j)
                matrix[i][j] += matrix[i][j - 1];
        unordered_map<int, int> count;
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                count.clear();
                count[0] = 1, cur = 0;
                for (int k = 0; k < n; ++k) {
                    cur += (matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0));
                    res += count[cur - target];
                    count[cur]++;
                }
            }
        }
        return res;
    }
};