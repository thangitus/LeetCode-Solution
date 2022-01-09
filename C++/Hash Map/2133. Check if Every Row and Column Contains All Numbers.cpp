#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<unordered_set<int>> row(n), col(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                row[i].insert(matrix[i][j]);
                col[j].insert(matrix[i][j]);
            }
        for (auto &item: row)
            if (item.size() != n) return false;
        for (auto &item: col)
            if (item.size() != n) return false;
        return true;
    }
};
