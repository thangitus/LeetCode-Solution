#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colSum) {
        vector<vector<int>> result(2, vector<int>(colSum.size()));
        for (int i = 0; i < colSum.size(); i++) {
            if (colSum[i] % 2 == 0)
                result[0][i] = result[1][i] = colSum[i] / 2;
            upper -= result[0][i];
            lower -= result[1][i];
        }
        for (int i = 0; i < colSum.size(); i++)
            if (colSum[i] == 1) {
                if (upper > 0) result[0][i] = 1, upper--;
                else if (lower > 0) result[1][i] = 1, lower--;
                else return {};
            }
        if (upper != 0 || lower != 0) return {};
        return result;
    }
};
