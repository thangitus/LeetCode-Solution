#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/diagonal-traverse-ii/
 * */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        unordered_map<int, vector<int>> map;
        vector<int> result;
        int maxKey = 0;
        for (int i = matrix.size() - 1; i >= 0; i--)
            for (int j = 0; j < matrix[i].size(); j++) {
                map[i + j].push_back(matrix[i][j]);
                maxKey = max(maxKey, i + j);
            }
        for (int i = 0; i <= maxKey; i++)
            result.insert(result.end(), map[i].begin(), map[i].end());
        return result;
    }
};
