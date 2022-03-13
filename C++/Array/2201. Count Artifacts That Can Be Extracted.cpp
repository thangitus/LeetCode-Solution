#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig) {
        vector<vector<bool>> matrix(n, vector<bool>(n));
        int result = 0;
        for (auto &item: dig)
            matrix[item[0]][item[1]] = true;
        for (auto &item: artifacts) {
            int x1 = item[0], y1 = item[1], x2 = item[2], y2 = item[3];
            bool valid = true;
            for (int i = x1; i <= x2; ++i)
                for (int j = y1; j <= y2 && valid; ++j)
                    if (!matrix[i][j])
                        valid = false;
            result += valid;
        }
        return result;
    }
};